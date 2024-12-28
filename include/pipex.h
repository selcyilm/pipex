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

void	fn_matrix_free(char **matrix);
char	*fn_env_get_exec_path(char *command, char **split);
char	**fn_env_get_path(char **env);
void	fn_cmd_clean(t_cmd *cmd);
void	fn_cmds_init(t_cmd *cmd1, t_cmd *cmd2, char **env, char **av);
int		fn_exec_cmd(t_cmd *cmd);
int		fn_exec_pipe(t_cmd *cmd1, t_cmd *cmd2);

#endif