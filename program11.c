/*
============================================================================
Name : 11.c
Author : Vedantee Pathak
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 17th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int old_fd;
	int new_fd;
	old_fd=open("file1.txt",O_WRONLY|O_APPEND);
	//dup2(old_fd,new_fd);
	//
	

	char arr[50];
	strcpy(arr,"old file write.\n");


	write(old_fd, arr,strlen(arr));
	new_fd=dup(old_fd);

	strcpy(arr,"new file write.\n");
	//dup2(old_fd,new_fd);
	lseek(new_fd,0,SEEK_END);
	write(new_fd,arr,strlen(arr));



	return 0;
}
