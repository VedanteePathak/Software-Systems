/*
============================================================================
Name : 12.c
Author : Vedantee Pathak
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 17th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd=open("file1.txt", O_RDONLY);
	int rval = fcntl(fd,F_GETFL);
	int flag = rval & O_ACCOMODE;

	return 0;
}
