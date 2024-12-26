#include "pipex.h"

//prapare files,
//execute left child
//execute right child
//write to a outfile

void	fn_cmd_clean(t_cmd *cmd);

void	fn_matrix_print(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		printf("%s\n", matrix[i++]);
}

void	fn_matrix_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**fn_env_get_path(char **env)
{
	int		i;
	char	**split;

	split = NULL;
	i = 0;
	while(env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			split = ft_split(env[i] + 5, ':');
			if (!split)
				return (NULL);
			return (split);
		}
		i++;
	}
	return (NULL);
}

char	*fn_env_get_exec_path(char *command, char **split)
{
	int		i;
	char	*join;

	join = NULL;
	i = 0;
	while (split[i])
	{
		join = ft_strjoin_with(split[i], command, '/');
		if (join == NULL)
			return (NULL);
		if (access(join, X_OK) == 0)
			return (join);
		free(join);
		i++;
	}
	return (ft_strdup(command));
}

char	**fn_argument_split(char *cmd)
{
	char	**split;

	split = ft_split(cmd, ' ');
	if (split == NULL)
		return (NULL);
	return (split);
}

int	fn_execute_left_child(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	cmd->in_fd = open(cmd->file, O_RDONLY);
	if (cmd->in_fd == -1)
		return (EXIT_FAILURE);
	dup2(cmd->in_fd, STDIN_FILENO);
	close(cmd->in_fd);
	pid = fork();
	if (pid == -1)
		return(EXIT_FAILURE);
	if (pid == 0)
	{
		execve(cmd->cmd, cmd->argv, cmd->envp);
		perror(cmd->cmd);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

int	fn_execute_right_child(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	cmd->out_fd = open(cmd->file, O_RDONLY);
	if (cmd->in_fd == -1)
		return (EXIT_FAILURE);
	dup2(cmd->out_fd, STDIN_FILENO);
	close(cmd->out_fd);
	pid = fork();
	if (pid == -1)
		return(EXIT_FAILURE);
	if (pid == 0)
	{
		execve(cmd->cmd, cmd->argv, cmd->envp);
		perror(cmd->cmd);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

void	fn_cmd_clean(t_cmd *cmd)
{
	fn_matrix_free(cmd->argv);
	fn_matrix_free(cmd->envp);
	free(cmd->file);
	free(cmd->cmd);
}

void	fn_cmds_init(t_cmd *cmd1, t_cmd *cmd2, char **env, char **av)
{
	cmd1->envp = fn_env_get_path(env);
	cmd2->envp = fn_env_get_path(env);
	cmd1->argv = fn_argument_split(av[2]);
	cmd2->argv = fn_argument_split(av[2]);
	cmd1->cmd = fn_env_get_exec_path(cmd1->argv[0], cmd1->envp);
	cmd2->cmd = fn_env_get_exec_path(cmd2->argv[0], cmd2->envp);
	cmd1->file = ft_strdup(av[1]);
	cmd2->file = ft_strdup(av[4]);
	cmd1->in_fd = 0;
	cmd1->out_fd = 0;
	cmd2->in_fd = 0;
	cmd2->out_fd = 0;
}

int main(int ac, char **av, char **env)
{
	t_cmd	cmd[2];

	if (ac != 5)
		return (EXIT_FAILURE);
	fn_cmds_init(&cmd[0], &cmd[1], env, av);
	if (fn_execute_left_child(&cmd[0]))
		return (fn_cmd_clean(&cmd[0]), fn_cmd_clean(&cmd[1]), EXIT_FAILURE);

	printf("done\n");
	fn_cmd_clean(&cmd[0]);
	fn_cmd_clean(&cmd[1]);
}
