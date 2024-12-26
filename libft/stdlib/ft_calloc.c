/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_calloc.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:09:38 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:09:41 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* The calloc() function allocates memory for an array of nmemb 
elements of size bytes each and returns a pointer to the allocated 
memory. The memory is set to zero. If nmemb or size is 0, then 
calloc() returns either NULL, or a unique  pointer  value  that can 
later be successfully passed to free(). If the multiplication of 
nmemb and size would result in integer overflow, then calloc() 
returns an error.
RETURN VALUE
The malloc() and calloc() functions return a pointer to the allocated memory,
which is suitably aligned for any built-in type. On  error, these 
functions return NULL. NULL may also be returned by a successful call 
to malloc() with a size of zero, or by a successful call to calloc() 
with nmemb or size equal to zero.*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
