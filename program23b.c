/*
============================================================================
Name : 24.c
Author : Vedantee Pathak
Description : Write a program to create an orphan process.
Date: 4th Sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int pid;
	//pid=fork();

	if(!fork())
	{
		int cpid=getpid();
		printf("Child PID is %d\n",cpid);
		int ppid=getppid();
		printf("Parent PID is %d\n",ppid);
		sleep(160);
		cpid=getpid();
		printf("Child PID is %d\n",cpid);
		ppid=getppid();
		printf("Parent ID is %d\n",ppid);
		printf("Child process\n");
	}
	else{printf("Parent Process\n");exit(0);}
	return 0;
}
