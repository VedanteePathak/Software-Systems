#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pipefd[2];
	pipe(pipefd);
	if(!fork())
	{
		close(1);
		dup(pipefd[1]);
		close(pipefd[0]);
		execlp("ls","ls",NULL);
	}
	else
	{
		close(0);
		dup(pipefd[0]);
		close(pipefd[1]);
		execlp("wc","wc",NULL);
	}
	return 0;
}
