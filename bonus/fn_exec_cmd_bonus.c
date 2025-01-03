/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_cmd_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 14:15:38 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 20:00:41 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_exec_child(t_pipex *pipex)
{
	//execve(cmd->cmd, cmd->argv, cmd->envp);
	//perror(cmd->cmd);
	//fn_cmd_clean(cmds->left);
	//fn_cmd_clean(cmds->right);
	//exit(EXIT_FAILURE);
	(void)pipex;
}

int	fn_exec_cmd(t_pipex *pipex)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		fn_exec_child(pipex);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}