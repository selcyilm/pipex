#include "pipex_bonus.h"

void	print_cmds(void *cmd)
{
	t_cmd	*current;

	current = cmd;
	printf("-------\n");
	printf("cmd path: %s\n", current->exec_cmd);
	printf("cmd args: ");
	fn_matrix_print(current->argv);
	printf("-------\n");
}

void	fn_child(t_pipex *pipex, t_list *start, int *fd)
{
	t_cmd	*cmd;

	cmd = start->content;
	close(fd[0]);
	if (start->next && dup2(fd[1], STDOUT_FILENO) == -1)
		return ;
	if (!start->next && dup2(pipex->out_fd, STDOUT_FILENO) == -1)
		return ;
	close(fd[1]);
	//close(pipex->in_fd);
	//close(pipex->out_fd);
	execve(cmd->exec_cmd, cmd->argv, pipex->envp);
	perror(cmd->exec_cmd);
	fn_pipex_clear(&pipex);
	exit(EXIT_FAILURE);
}

void	*fn_pipex(t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;
	t_list	*start;

	start = pipex->cmds;
	if (dup2(pipex->in_fd, STDIN_FILENO) == -1)
		return (NULL);
	while (start)
	{
		if (pipe(fd) == -1)
			return (NULL);
		if ((pid = fork()) == -1)
			return (NULL);
		else if (pid == 0)
			fn_child(pipex, start, fd);
		close(fd[1]);
		if (start->next && dup2(fd[0], STDIN_FILENO) == -1)
			return (NULL);
		waitpid(pid, NULL, 0);
		close(fd[0]);
		start = start->next;
	}
	return (NULL);
}

int main(int ac, char **av, char **envs)
{
	t_pipex	*pipex;

	if (ac < 5)
		return (EXIT_FAILURE);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	pipex->heredoc = false;
	if (ft_strncmp("here_doc", av[1], 8) == 0)
		pipex->heredoc = true;
	if (fn_pipex_init(pipex, envs, av, ac))
		return (fn_pipex_clear(&pipex), EXIT_FAILURE);
	fn_cmds_parse(pipex, av, ac);
	if (pipex->heredoc)
	{
		fn_exec_heredoc(pipex, av[2]);
		pipex->in_fd = open(HEREDOC_PATH, O_RDONLY);
	}
	fn_pipex(pipex);
	fn_pipex_clear(&pipex);
}