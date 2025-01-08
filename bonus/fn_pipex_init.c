/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_pipex_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 18:40:35 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/08 12:25:01 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	fn_pipex_init_null(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->envp = NULL;
	pipex->envs = NULL;
	//pipex->heredoc = false;
	pipex->cmds = NULL;
}

int	fn_pipex_init(t_pipex *pipex, char **envs, char **av, int ac)
{
	fn_pipex_init_null(pipex);
	if (pipex->heredoc)
		pipex->in_fd = open(av[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else
		pipex->in_fd = open(av[1], O_RDONLY);
	if (pipex->in_fd == -1)
		return (EXIT_FAILURE);
	if (pipex->heredoc)
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		pipex->out_fd = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->out_fd == -1)
		return (EXIT_FAILURE);
	pipex->envp = fn_env_get_path(envs);
	if (!pipex->envp[0] || pipex->envp == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
