/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_pipex_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 18:40:35 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 20:24:04 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	fn_pipex_init_null(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->envp = NULL;
	pipex->envs = NULL;
	pipex->heredoc = false;
	pipex->cmds = NULL;
}

int	fn_pipex_init(t_pipex *pipex, char **envs)
{
	fn_pipex_init_null(pipex);
	pipex->in_fd = dup(STDIN_FILENO);
	if (pipex->in_fd == -1)
		return (EXIT_FAILURE);
	pipex->out_fd = dup(STDOUT_FILENO);
	if (pipex->out_fd == -1)
		return (EXIT_FAILURE);
	pipex->envp = fn_env_get_path(envs);
	if (!pipex->envp[0] || pipex->envp == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
