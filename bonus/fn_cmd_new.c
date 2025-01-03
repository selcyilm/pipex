/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_cmd_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 19:49:46 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/02 21:07:26 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_cmd	*fn_cmd_new(char *cmd, char **argv)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->exec_cmd = cmd;
	new->argv = argv;
	return (new);
}
