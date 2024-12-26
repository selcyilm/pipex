/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstiter_bonus.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:12:36 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:12:38 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Parameters
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
RETURN VALUE: NONE
DESCRIPTION:
Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (!current)
		return ;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
