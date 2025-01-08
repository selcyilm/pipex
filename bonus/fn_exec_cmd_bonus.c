/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_cmd_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 14:15:38 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/08 20:49:33 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_exec_child(t_pipex *pipex, t_cmd *cmd)
{
	execve(cmd->exec_cmd, cmd->argv, pipex->envp);
	perror(cmd->exec_cmd);
	fn_pipex_clear(&pipex);
	exit(EXIT_FAILURE);
}

int	fn_exec_cmd(t_pipex *pipex, t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		fn_exec_child(pipex, cmd);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}