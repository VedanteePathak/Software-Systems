#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/file.h>
#include<fcntl.h>
#include<error.h>

int main()
{
	char buf[20];
	int a[2];
	
	if(pipe(a)==-1)
	{
        	perror("pipe");
		exit(1);
	}
	int pid=fork();
	if(pid>0)
	{
		close(pipefd(a[0]);
		write(pipefd(a[1],argv[1],strlen(argv[1]);
		close(pipefd(a[1]));
		wait(NULL);
		exit(EXIT_STATUS);
	}
	else
	{
		close(pipefd[1]);

		while(read(pipefd[0]
	}
	
}
