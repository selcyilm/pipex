/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 17:47:59 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/28 17:48:31 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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