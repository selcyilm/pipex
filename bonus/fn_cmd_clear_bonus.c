/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmd_clear_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 14:43:20 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 21:05:31 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_cmd_clear(void *cmds)
{
	t_cmd *cmd = cmds;
	if (!cmd)
		return ;
	if (cmd->argv)
		fn_matrix_free(cmd->argv);
	if (cmd->exec_cmd)
		free(cmd->exec_cmd);
	free(cmd);
	cmd = NULL;
}