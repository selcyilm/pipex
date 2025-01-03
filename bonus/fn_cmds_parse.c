/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmds_parse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 20:42:40 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 20:57:21 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	fn_cmds_parse(t_pipex *pipex, char **av, int ac)
{
	int		i;
	t_cmd	*new;
	char	**split_arg;
	char	*exec_path;

	if (pipex->heredoc)
		i = 3;
	else
		i = 2;
	split_arg = NULL;
	while (i < ac - 1)
	{
		split_arg = ft_split(av[i], ' ');
		if (split_arg == NULL)
			return (EXIT_FAILURE);
		exec_path = fn_env_get_exec_path(split_arg[0], pipex->envp);
		if (exec_path == NULL)
			return (EXIT_FAILURE);
		new = fn_cmd_new(exec_path, split_arg);
		if (new == NULL)
			return (EXIT_FAILURE);
		ft_lstadd_back(&pipex->cmds, ft_lstnew(new));
		i++;
	}
	return (EXIT_SUCCESS);
}
