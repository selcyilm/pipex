/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_args_parse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 20:08:17 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 21:07:02 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	fn_args_parse(t_pipex *pipex, char **av, int ac)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		pipex->heredoc = true;
	if (pipex->heredoc)
	{
		if (ac < 6)
			return (EXIT_FAILURE);
		
	}
	return (EXIT_SUCCESS);
	
}
