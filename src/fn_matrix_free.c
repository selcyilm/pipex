/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_matrix_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 17:49:09 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/28 17:50:06 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
