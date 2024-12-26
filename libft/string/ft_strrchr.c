/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strrchr.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:18:57 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:18:58 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*The strrchr() function shall locate the last occurrence of c
(converted to a char) in the string pointed to by s.  The
terminating NUL character is considered to be part of the string.*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
