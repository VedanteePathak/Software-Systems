#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	char *fpath="myFIFO";
	char buff[BUFSIZ];
	int fd;

	fd=open(fpath,O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	read(fd,buff,sizeof(buff));
	close(fd);
	printf("Message recieved from FIFO: %s\n",buff);

	return 0;
}
