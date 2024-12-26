/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstlast_bonus.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:12:48 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:12:51 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Returns the last node of the list.
RETURN VALUE
Last node of the list*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
