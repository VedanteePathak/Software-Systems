#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int fd1[2];
	pipe(fd1);

	if(!fork())
	{
		dup2(fd1[1],1);
		close(fd1[0]);
		execlp("ls","ls","-l",(char*)0);
	}
	else
	{
		int fd2[2];
		pipe(fd2);
		dup2(fd1[0],0);
		close(fd1[1]);

		if(!fork())
		{
			dup2(fd2[1],1);
			close(fd2[0]);
			execlp("grep","grep","^d",(char*)0);
		}
		else
		{
			dup2(fd2[0],0);
			close(fd2[1]);
			execlp("wc","wc",(char*)0);
		}
	}
	return 0;

}
