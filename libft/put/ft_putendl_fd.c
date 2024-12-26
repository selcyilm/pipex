/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putendl_fd.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:15:16 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:15:18 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Outputs the string ’s’ to the given file descriptor
followed by a newline.*/
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
