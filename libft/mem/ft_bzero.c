/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_bzero.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:09:17 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:09:20 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*The  bzero()  function  erases  the  data in the n bytes
of the memory starting at the location pointed to by s, by 
writing zeros (bytes containing '\0') to that area.*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
