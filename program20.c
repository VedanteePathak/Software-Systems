#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main()
{
	int fd;
	char *msg="Hey,there!!";
	mkfifo("myFIFO",0666);
	fd=open("myFIFO",O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd,msg,strlen(msg)+1);
	close(fd);
	return 0;
}
