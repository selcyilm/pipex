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

int main(int ac, char **av, char **envs)
{
	t_pipex	*pipex;

	(void)av;
	if (ac < 5)
		return (EXIT_FAILURE);
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	pipex->heredoc = false;
	if (ft_strncmp("here_doc", av[1], 8) == 0)
		pipex->heredoc = true;
	if (fn_pipex_init(pipex, envs))
		return (fn_pipex_clear(&pipex), EXIT_FAILURE);
	fn_cmds_parse(pipex, av, ac);
	if (pipex->heredoc)
		fn_exec_heredoc(pipex, av[2]);
	//ft_lstiter(pipex->cmds, print_cmds);
	fn_pipex_clear(&pipex);
}