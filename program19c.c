#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main()
{
	if(!fork())
	{
		printf("\nUsing mkfifo:\n");
		execlp("strace","strace","-c","mkfifo","fifo1",NULL);
	}
	else
	{
		wait(0);
		printf("\nUsing mknod:\n");
		execlp("strace","strace","-c","mknod","fifo2","p",NULL);
	}
	return 0;
}
