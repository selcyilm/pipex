/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/31 22:11:49 by selcyilm      #+#    #+#                 */
/*   Updated: 2025/01/01 16:45:19 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
	char	**envp;
	char	*file;
	int		in_fd;
	int		out_fd;
}	t_cmd;

typedef struct s_cmds
{
	struct s_cmd	*left;
	struct s_cmd	*right;
}	t_cmds;

void	fn_matrix_free(char **matrix);
char	*fn_env_get_exec_path(char *command, char **split);
char	**fn_env_get_path(char **env);
void	fn_cmd_clean(t_cmd *cmd);
void	fn_cmds_init(t_cmd *cmd1, t_cmd *cmd2, char **env, char **av);
int		fn_exec_cmd(t_cmd *cmd);
int		fn_exec_pipe(t_cmds *cmds, t_cmd *cmd1, t_cmd *cmd2);

#endif