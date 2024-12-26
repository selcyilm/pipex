#include "pipex.h"

//prapare files,
//execute left child
//execute right child
//write to a outfile

int main(void)
{
	int fd[2];
	if (pipe(fd) == -1)
		return (perror("error"), 1);
	int pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		int x;
		printf("input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		printf("readed %d\n", y);
		close(fd[0]);
	}
	wait(NULL);


}
