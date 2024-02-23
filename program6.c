/*
============================================================================
Name : 6.c
Author : Vedantee Pathak
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 12th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	char buff[200];
	int i;
	while(1)
	{
		i=read(0,buff,sizeof(buff));
		if(i>1)
		{
			write(1,buff,i);
		}
	}
}

