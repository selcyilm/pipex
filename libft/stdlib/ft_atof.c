/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_atof.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/11/17 13:17:57 by selcyilm       #+#    #+#                */
/*   Updated: 2024/11/17 13:17:59 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	int		len;

	res = ft_atoll(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	res2 = ft_atoll(str);
	len = ft_strlen(str);
	while (len--)
		res2 /= 10;
	if (res > 0)
		return (res + res2);
	return (res - res2);
}
