/*
============================================================================
Name : 16.c
Author : Vedantee Pathak
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 28th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd;
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	printf("Opening the file :\n");
	fd=open("file.txt",O_WRONLY);
	printf("Implementing the write lock :\n");
	fcntl(fd,F_SETLKW,&fl);
	printf("Enter anything to unlock :\n");
	getchar();
	printf("Unlocking the file :\n");
	fl.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&fl);

	close(fd);

	return 0;
	
}
