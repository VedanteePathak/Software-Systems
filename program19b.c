#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	execlp("mkfifo","mkfifo","fifo1",NULL);
	return 0;
}
