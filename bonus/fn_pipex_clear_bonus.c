/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_pipex_clear_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 14:42:36 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/08 10:46:37 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_close_fd(t_pipex *pipex)
{
	if (pipex->in_fd >= 0)
	{
		close(pipex->in_fd);
		pipex->in_fd = -1;
	}
	if (pipex->out_fd >= 0)
	{
		close(pipex->out_fd);
		pipex->out_fd = -1;
	}
}

void	fn_pipex_clear(t_pipex **pipex)
{
	if (!pipex || !*pipex)
		return ;
	if ((*pipex)->cmds)
		ft_lstclear(&(*pipex)->cmds, fn_cmd_clear);
	if ((*pipex)->envs)
		fn_matrix_free((*pipex)->envs);
	if ((*pipex)->envp)
		fn_matrix_free((*pipex)->envp);
	fn_close_fd(*pipex);
	free(*pipex);
	*pipex = NULL;
	unlink(HEREDOC_PATH);
}