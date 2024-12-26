/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstmap_bonus.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/08 14:13:03 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/08 14:13:06 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* PARAMS:
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.
RETURN VALUE:
The new list.
NULL if the allocation fails.
DESCRIPTION:
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_obj;
	void	*data;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	new_obj = NULL;
	while (lst)
	{
		data = f(lst->content);
		new_obj = ft_lstnew(data);
		if (!new_obj)
		{
			del(data);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_obj);
		lst = lst->next;
	}
	return (new_lst);
}

/*void	*increment(void *content)
{
	int *new_value = malloc(sizeof(int));
	if (new_value == NULL)
		return (NULL);
	*new_value = *(int *)content + 1;
	return (new_value);
}

void	del(void *content)
{
	free(content);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_lst;
	int *val1 = malloc(sizeof(int));
	int *val2 = malloc(sizeof(int));
	int *val3 = malloc(sizeof(int));
	if (!val1 || !val2 || !val3)
	{
		return 1;
	}

	*val1 = 1;
	*val2 = 2;
	*val3 = 3;
	lst = ft_lstnew(val1);
	ft_lstadd_back(&lst, ft_lstnew(val2));
	ft_lstadd_back(&lst, ft_lstnew(val3));

	printf("Original list: ");
	print_list(lst);

	new_lst = ft_lstmap(lst, increment, del);

	printf("Mapped list: ");
	print_list(new_lst);

	ft_lstclear(&lst, del);
	ft_lstclear(&new_lst, del);
}*/