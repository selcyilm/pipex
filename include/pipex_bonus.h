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

//ENV UTILS
char	**fn_env_get_path(char **env);
char	*fn_env_get_exec_path(char *command, char **split);
void	fn_matrix_free(char **matrix);
void	fn_matrix_print(char **matrix);

#endif