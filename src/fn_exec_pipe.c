/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_pipe.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 22:20:36 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 16:46:32 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fn_exec_left(t_cmds *cmds, t_cmd *cmd, int *pipefd)
{
	int	status;

	close(pipefd[0]);
	dup2(cmd->in_fd, STDIN_FILENO);
	close(cmd->in_fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	status = fn_exec_cmd(cmd);
	fn_cmd_clean(cmds->left);
	fn_cmd_clean(cmds->right);
	exit(status);
}

static void	fn_exec_right(t_cmds *cmds, t_cmd *cmd, int *pipefd)
{
	int	status;

	dup2(cmd->out_fd, STDOUT_FILENO);
	close(cmd->out_fd);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(pipefd[0]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	status = fn_exec_cmd(cmd);
	fn_cmd_clean(cmds->left);
	fn_cmd_clean(cmds->right);
	exit(status);
}

static int	fn_close_pipefd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int	fn_exec_pipe(t_cmds *cmds, t_cmd *cmd1, t_cmd *cmd2)
{
	pid_t	pid[2];
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		return (EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == -1)
		return (EXIT_FAILURE);
	if (pid[0] == 0)
		fn_exec_left(cmds, cmd1, pipefd);
	pid[1] = fork();
	if (pid[1] == -1)
		return (EXIT_FAILURE);
	if (pid[1] == 0)
		fn_exec_right(cmds, cmd2, pipefd);
	fn_close_pipefd(pipefd);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
