/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_split.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:16:32 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:16:34 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
RETURN VALUE
The array of new strings resulting from the split.
NULL if the allocation fails.*/

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	int		i;
	bool	flag;

	i = 0;
	words = 0;
	flag = false;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && !flag)
		{
			flag = true;
			words++;
		}
		else if (s[i] == c)
			flag = false;
		i++;
	}
	return (words);
}

static size_t	substr_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*create_substr(const char *s, char c)
{
	size_t	len;
	char	*substr;

	len = substr_len(s, c);
	if (len == 0)
		return (NULL);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	else
		ft_strlcpy(substr, s, len + 1);
	return (substr);
}

static char	**check_alloc_fail(char **result, int index)
{
	while (index >= 0)
	{
		free(result[index]);
		index--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**result;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			result[i] = create_substr(s, c);
			if (result[i] == NULL)
				return (check_alloc_fail(result, i));
			s += substr_len(s, c);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

/*int	main(int ac, char **av)
{
	char **s;

	s = NULL;
	if (ac == 2)
	{
		printf("%ld words!\n", count_words(av[1], ' '));
		s = ft_split(av[1], ' ');
		if (!s)
			printf("NULL RETURNED");
		int i;

		i = 0;
		while (s[i])
		{
			printf("Line %d: |%s|\n", i, s[i]);
			i++;
		}
	}

	int i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}*/
