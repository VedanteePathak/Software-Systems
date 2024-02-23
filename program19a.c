#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
	execlp("mknod","mknod","fifo2","p",NULL);
	return 0;
}
