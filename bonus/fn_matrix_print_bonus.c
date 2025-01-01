/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_matrix_print_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/01 20:41:19 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 20:42:15 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fn_matrix_print(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		printf("%s\n", matrix[i++]);
}