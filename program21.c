/*
============================================================================
Name : 21.c
Author : Vedantee Pathak
Description : Write a program, call fork and print the parent and child process id.
Date: 1st Sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid = fork();
	if(pid>0)
	{
		printf("This is a parent process\n");
		printf("%d",getpid());
	}
	else
	{
		printf("This is a child process\n");
		printf("%d",getpid());
	}

	return 0;
}
