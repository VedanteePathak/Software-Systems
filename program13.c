/*
============================================================================
Name : 13.c
Author : Vedantee Pathak
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 18th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>
#include<sys/time.h>
#include<fcntl.h>

int main()
{
	fd_set rfds;
	struct timeval tv;
	int retval;
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	retval = select(1, &rfds, NULL, NULL, &tv);

	if(retval == -1)
	{
		perror("select()");
	}
	else if(retval)
	{
		printf("Data is available from STDIN within 10 seconds.\n");
	}
	else
	{
		printf("No data available from STDIN within 10 seconds.\n");
	}
	return 0;
}
