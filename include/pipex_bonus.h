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

# define HEREDOC_PATH "here_doc"

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
	t_list			*cmds;
}	t_pipex;

//ENV UTILS
char	**fn_env_get_path(char **env);
char	*fn_env_get_exec_path(char *command, char **split);
void	fn_matrix_free(char **matrix);
void	fn_matrix_print(char **matrix);

void	fn_cmd_clear(void *cmds);
void	fn_pipex_clear(t_pipex **pipex);

t_cmd	*fn_cmd_new(char *cmd, char **argv);
int		fn_pipex_init(t_pipex *pipex, char **envs, char **av, int ac);

int		fn_cmds_parse(t_pipex *pipex, char **av, int ac);

int	fn_exec_heredoc(t_pipex *pipex, char *limeter);
int	fn_exec_pipe(t_pipex *pipex);
int	fn_exec_cmd(t_pipex *pipex, t_cmd *cmd);

#endif