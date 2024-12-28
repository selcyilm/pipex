/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmd_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 17:55:52 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/28 18:04:07 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fn_cmds_init(t_cmd *cmd1, t_cmd *cmd2, char **env, char **av)
{
	cmd1->envp = fn_env_get_path(env);
	cmd2->envp = fn_env_get_path(env);
	cmd1->argv = ft_split(av[2], ' ');
	cmd2->argv = ft_split(av[3], ' ');
	cmd1->cmd = fn_env_get_exec_path(cmd1->argv[0], cmd1->envp);
	cmd2->cmd = fn_env_get_exec_path(cmd2->argv[0], cmd2->envp);
	cmd1->file = ft_strdup(av[1]);
	cmd2->file = ft_strdup(av[4]);
	cmd1->in_fd = 0;
	cmd1->out_fd = 0;
	cmd2->in_fd = 0;
	cmd2->out_fd = 0;
}