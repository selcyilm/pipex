/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/31 22:11:32 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 16:45:02 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <time.h>

int	main(int ac, char **av, char **env)
{
	t_cmds	cmds;
	t_cmd	cmd[2];
	int		ret;

	if (ac != 5)
		return (EXIT_FAILURE);
	fn_cmds_init(&cmd[0], &cmd[1], env, av);
	cmds.left = &cmd[0];
	cmds.right = &cmd[1];
	ret = fn_exec_pipe(&cmds, &cmd[0], &cmd[1]);
	fn_cmd_clean(&cmd[0]);
	fn_cmd_clean(&cmd[1]);
	return (ret);
}
