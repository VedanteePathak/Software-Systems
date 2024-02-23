/*
============================================================================
Name : 23.c
Author : Vedantee Pathak
Description : Write a program to create a Zombie state of the running program.
Date: 4th Sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid=fork();
	if(pid>0)
	{
		sleep(50);
	}
	else
	{
		int cpid=getpid();
		printf("pid of child is %d\n",cpid);
		int ppid=getppid();
		printf("pid of parent is %d\n",ppid);
		exit(0);
	}
	return 0;
}
