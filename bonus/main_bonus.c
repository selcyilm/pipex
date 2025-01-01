#include "pipex_bonus.h"

int main(int ac, char **av, char **envs)
{
	if (ac < 5)
		return (EXIT_FAILURE);
	char **split = fn_env_get_path(envs);
	char *cmd_path = fn_env_get_exec_path(av[1], split);
	fn_matrix_print(split);
	ft_printf("\nExecutable path: %s\n", cmd_path);
	free(cmd_path);
	fn_matrix_free(split);
	ft_printf("Hello world!\n");
}