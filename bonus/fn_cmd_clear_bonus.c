/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmd_clear.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 14:43:20 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 18:23:05 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_cmd_clear(t_cmd **cmd)
{
	if (!cmd || !*cmd)
		return ;
	if ((*cmd)->argv)
		fn_matrix_free((*cmd)->argv);
	if ((*cmd)->exec_cmd)
		free((*cmd)->exec_cmd);
	free(*cmd);
	*cmd = NULL;
}