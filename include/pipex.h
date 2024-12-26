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


#endif