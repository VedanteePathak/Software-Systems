#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int result = mkfifo("f1.fifo",S_IRWXU);
	if(result<0)
	{
		perror("mkfifo");
		exit(1);
	}
	return 0;
}
