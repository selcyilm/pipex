#ifndef PIPEX_BONUS
# define PIPEX_BONUS
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_cmd
{
	char	**argv;
	char	*exec_cmd;
}	t_cmd;

typedef struct s_pipex
{
	bool			heredoc;
	int				in_fd;
	int				out_fd;
	char			**envs;
	char			**envp;
	struct s_cmd	*cmd;
}	t_pipex;

//ENV UTILS
char	**fn_env_get_path(char **env);
char	*fn_env_get_exec_path(char *command, char **split);
void	fn_matrix_free(char **matrix);
void	fn_matrix_print(char **matrix);

void	fn_cmd_clear(t_cmd **cmd);
void	fn_pipex_clear(t_pipex **pipex);

#endif