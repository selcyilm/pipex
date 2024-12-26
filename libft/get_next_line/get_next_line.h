/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/19 13:03:21 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/19 13:03:22 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}				t_node;

char	*get_next_line(int fd);
void	create_nodes(int fd, t_node **node);
void	append_to_last(t_node **node, char *buf);
t_node	*find_last(t_node *node);
int		newline_len(t_node *node);
char	*get_line_x(t_node *node);
void	free_all(t_node **node, t_node *clean, char *buf, bool flag);
void	leftover(t_node **node);
bool	check_all_list(t_node *node);
void	copy_str(t_node *node, char *str);

#endif
