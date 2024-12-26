/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strjoin.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:17:32 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:17:35 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
RETURN VALUE
The new string.
NULL if the allocation fails.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*p;

	size = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (p);
}
