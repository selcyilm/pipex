/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_pipe_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/07 14:59:10 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/07 15:17:02 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	fn_exec_left(t_pipex *pipex, int *pipefd)
{
	int	status;

	close(pipefd[0]);
	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->in_fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(pipefd[1]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	status = fn_exec_cmd(pipex, pipex->cmds->content);
	fn_pipex_clear(&pipex);
	exit(status);
}

static void	fn_exec_right(t_pipex *pipex, int *pipefd)
{
	int	status;

	dup2(pipex->out_fd, STDOUT_FILENO);
	close(pipex->out_fd);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		close(pipefd[0]);
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	status = fn_exec_cmd(pipex, pipex->cmds->next->content);
	fn_pipex_clear(&pipex);
	exit(status);
}

static int	fn_close_pipefd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int	fn_exec_pipe(t_pipex *pipex)
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
		fn_exec_left(pipex, pipefd);
	pid[1] = fork();
	if (pid[1] == -1)
		return (EXIT_FAILURE);
	if (pid[1] == 0)
		fn_exec_right(pipex, pipefd);
	fn_close_pipefd(pipefd);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}