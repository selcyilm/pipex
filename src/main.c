/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/31 22:11:32 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 14:49:59 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <time.h>

int	main(int ac, char **av, char **env)
{
	t_cmd	cmd[2];
	int		ret;

	if (ac != 5)
		return (EXIT_FAILURE);
	fn_cmds_init(&cmd[0], &cmd[1], env, av);
	ret = fn_exec_pipe(&cmd[0], &cmd[1]);
	fn_cmd_clean(&cmd[0]);
	fn_cmd_clean(&cmd[1]);
	return (ret);
}
