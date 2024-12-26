/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memcmp.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:14:14 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:14:16 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	i = 0;
	new_s2 = (unsigned char *)s2;
	new_s1 = (unsigned char *)s1;
	if (n == 0)
		return (0);
	while (new_s1[i] == new_s2[i] && i < n - 1)
	{
		i++;
		if (i == n)
			return (0);
	}
	return (new_s1[i] - new_s2[i]);
}
