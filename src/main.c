#include "pipex.h"

int main(int ac, char **av, char **env)
{
	t_cmd	cmd[2];

	if (ac != 5)
		return (EXIT_FAILURE);
	fn_cmds_init(&cmd[0], &cmd[1], env, av);
	fn_exec_pipe(&cmd[0], &cmd[1]);
	//fn_exec_cmd(&cmd[0]);
	//fn_exec_cmd(&cmd[1]);
	fn_cmd_clean(&cmd[0]);
	fn_cmd_clean(&cmd[1]);
}

//pipe
//fork
//init left child
//write pipe fd
//init right child
//read it from fd that is written
//exec command
//redirect out to a file
