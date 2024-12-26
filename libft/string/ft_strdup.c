/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:17:02 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:17:04 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*The strdup() function returns a pointer to a new string which 
is a duplicate of the string s.  Memory for the new string is 
obtained with malloc(3), and can be freed with free(3).
RETURN VALUES
On success, the strdup() function returns a pointer to the
duplicated string.  It returns  NULL  if  insufficient memory 
was available, with errno set to indicate the cause of the error.*/
char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
