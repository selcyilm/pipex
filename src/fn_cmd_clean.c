/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmd_clean.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 18:00:32 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 15:49:50 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fn_cmd_clean(t_cmd *cmd)
{
	fn_matrix_free(cmd->argv);
	fn_matrix_free(cmd->envp);
	if (cmd->file)
		free(cmd->file);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->in_fd != -1)
		close(cmd->in_fd);
	if (cmd->out_fd != -1)
		close(cmd->out_fd);
}
