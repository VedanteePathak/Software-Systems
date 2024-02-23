/*
============================================================================
Name : 3.c
Author : Vedantee Pathak
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call 
Date: 12th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd;
	fd=creat("randomfile", S_IRWXU);
	printf("%d\n",fd);
	return 0;
}
