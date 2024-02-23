/*
============================================================================
Name : 4.c
Author : Vedantee Pathak
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 12th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd = open("myfileghbhbjhgj12.txt", O_EXCL|O_CREAT, 0744);
	if(fd==-1)
	{
		printf("File already exists");
	}
	for (;;){}
	return 0;
}
