/*
============================================================================
Name : 8.c
Author : Vedantee Pathak
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 16th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char str[1000] = "";
	char ch;
	int i=0;

	int fd = open("file1.txt",O_RDONLY);
	while(read(fd,&ch,1)>0)
	{
		if(ch=='\n')
		{
			printf("Line %d : %s\n", i, str);
			i++;
			strcpy(str,"");
		}
		else
		{
			strncat(str,&ch,1);
		}
	}
	close(fd);
	return 0;
}
