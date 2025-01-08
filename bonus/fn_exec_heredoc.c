#include "pipex_bonus.h"

void	fn_write_heredoc(char *limeter, int fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (!ft_strncmp(limeter, line, ft_strlen(limeter)))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
}

void	fn_create_heredoc(char *limeter)
{
	int	fd;

	fd = open(HEREDOC_PATH, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("heredoc");
		exit(EXIT_FAILURE);
	}
	fn_write_heredoc(limeter, fd);
	close(fd);
	//return (open(HEREDOC_PATH, O_RDONLY));
}

void	fn_heredoc_child(t_pipex *pipex, char *limeter)
{
	close(pipex->in_fd);
	fn_create_heredoc(limeter);
	if (pipex->in_fd == -1)
		exit(EXIT_FAILURE);
	//fn_pipex_clear(&pipex);
	exit(EXIT_SUCCESS);
}


int	fn_exec_heredoc(t_pipex *pipex, char *limeter)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
		fn_heredoc_child(pipex, limeter);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}