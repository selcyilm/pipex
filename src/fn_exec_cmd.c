/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_cmd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 22:14:31 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 16:46:10 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fn_exec_cmd(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		execve(cmd->cmd, cmd->argv, cmd->envp);
		perror(cmd->cmd);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
