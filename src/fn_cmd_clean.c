/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmd_clean.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 18:00:32 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/28 18:01:05 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fn_cmd_clean(t_cmd *cmd)
{
	fn_matrix_free(cmd->argv);
	fn_matrix_free(cmd->envp);
	free(cmd->file);
	free(cmd->cmd);
}
