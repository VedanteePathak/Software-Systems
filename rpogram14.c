#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
	int a[2];
	char buff[20];

	if(pipe(a)==-1)
	{
		perror("pipe");
		exit(1);
	}
	write(a[1], "Pipe Program",20);
  	printf("\n");

	read(a[0],buff, 20);

	printf("%s",buff);	

}
