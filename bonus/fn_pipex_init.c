/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_pipex_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 18:40:35 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 18:42:58 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_pipex_init_null(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->envp = NULL;
	pipex->envs = NULL;
	pipex->heredoc = false;
	pipex->cmd = NULL;
}

void	fn_pipex_init(t_pipex *pipex)
{
	
}