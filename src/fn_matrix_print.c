/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_matrix_print.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 17:54:43 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 14:50:52 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fn_matrix_print(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		printf("%s\n", matrix[i++]);
}
