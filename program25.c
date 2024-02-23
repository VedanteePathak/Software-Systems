/*
============================================================================
Name : 25.c
Author : Vedantee Pathak
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 8th Sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int i,stat;
	pid_t pid[3];
	for(int i=0;i<3;i++)
	{
		if((pid[i]=fork())==0)
		{
			sleep(1);
			exit(100+i);
		}
	}
	for(int i=0;i<3;i++)
	{
		pid_t cpid = waitpid(pid[i],&stat,0);
	}
	printf("Child Finished\n");

}
