/*
============================================================================
Name : 9.c
Author : Vedantee Pathak
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 16th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	struct stat FileStat;
	int fd=open("file.txt",O_RDONLY);
	if(fd==-1)
	{
		perror("Open ");
	}
	fstat(fd, &FileStat);
	printf("The information for the given file is: ");
	printf("-------------------------------------\n");
	printf("The inode number is %ld \n ",FileStat.st_ino);
	printf("Number of hard links is %ld \n ", FileStat.st_nlink);
	printf("Uid is %c \n", FileStat.st_uid);
	printf("gid is %c \n", FileStat.st_gid);
	printf("Total file size is %ld \n", FileStat.st_size);
	printf("Optimal block size of I/O is %ld \n", FileStat.st_blksize);
	return 0;
}
