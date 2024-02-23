#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

void main()
{
	int fifostatus;
	long maxfile;
	long sizeofpipe;

	fifostatus=mkfifo("FIFO2",S_IRWXU);

	if(fifostatus==-1)
	{
		printf("error");
	}
	else
	{
		maxfile=sysconf(_SC_OPEN_MAX);
		if(maxfile==-1)
		{
			printf("error");
		}
		else
		{
			printf("maximum no of file that can be opened %ld\n",maxfile);
		}

		sizeofpipe = pathconf("FIFO2",_PC_PIPE_BUF);
		if(sizeofpipe==-1)
		{
			printf("error");
		}
		else
		{
			printf("maximum size of pipe %ld\n",sizeofpipe);
		}
	}
}

