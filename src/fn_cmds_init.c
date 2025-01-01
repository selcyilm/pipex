/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmds_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 17:55:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 20:15:18 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define LEFT 1
#define RIGHT 0

static void	fn_init_null(t_cmd *cmd)
{
	cmd->argv = NULL;
	cmd->cmd = NULL;
	cmd->envp = NULL;
	cmd->file = NULL;
	cmd->in_fd = 0;
	cmd->out_fd = 0;
}

static int	fn_open_files(t_cmd *cmd, int left_or_rigt)
{
	if (left_or_rigt == LEFT)
	{
		cmd->in_fd = open(cmd->file, O_RDONLY);
		if (cmd->in_fd == -1)
		{
			if (errno == ENOENT || errno == EACCES)
			{
				cmd->in_fd = 0;
				perror(cmd->file);
				return (EXIT_SUCCESS);
			}
			perror(cmd->file);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		cmd->out_fd = open(cmd->file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (cmd->out_fd == -1)
		{
			perror(cmd->file);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static	int	fn_cmd_init(t_cmd *cmd, char **env, char **av, int left_or_right)
{
	fn_init_null(cmd);
	cmd->envp = fn_env_get_path(env);
	if (!cmd->envp)
		return (EXIT_FAILURE);
	if (left_or_right)
		cmd->argv = ft_split(av[2], ' ');
	else
		cmd->argv = ft_split(av[3], ' ');
	if (!cmd->argv[0] || !cmd->argv)
		return (EXIT_FAILURE);
	cmd->cmd = fn_env_get_exec_path(cmd->argv[0], cmd->envp);
	if (!cmd->cmd)
		return (EXIT_FAILURE);
	if (left_or_right)
		cmd->file = ft_strdup(av[1]);
	else
		cmd->file = ft_strdup(av[4]);
	if (!cmd->file)
		return (EXIT_FAILURE);
	cmd->in_fd = -1;
	cmd->out_fd = -1;
	return (EXIT_SUCCESS);
}

void	fn_cmds_init(t_cmd *cmd1, t_cmd *cmd2, char **env, char **av)
{
	if (fn_cmd_init(cmd1, env, av, LEFT) || fn_open_files(cmd1, LEFT))
	{
		fn_cmd_clean(cmd1);
		ft_putendl_fd("Error: Init left command!", 2);
		exit(EXIT_FAILURE);
	}
	if (fn_cmd_init(cmd2, env, av, RIGHT) || fn_open_files(cmd2, RIGHT))
	{
		fn_cmd_clean(cmd1);
		fn_cmd_clean(cmd2);
		ft_putendl_fd("Error: Init right command!", 2);
		exit(EXIT_FAILURE);
	}
}
