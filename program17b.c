/*
============================================================================
Name : 17.c
Author : Vedantee Pathak
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28th Aug, 2023.
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
	int tno;
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start =0;
	fl.l_len =0;
	fl.l_pid = getpid();
	fd=open("ticket.txt",O_RDWR);
	read(fd,&tno,sizeof(tno));
	printf("Before entering into critical section.. \n");
	fcntl(fd,F_SETLKW,&fl);
	tno++;
	printf("The current ticket number is: %d\n",tno);
	lseek(fd,0l,SEEK_SET);
	write(fd,&tno,sizeof(tno));
	printf("Enter anything to unlock: \n");
	getchar();
	printf("Unlocking the file: \n");
	fl.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&fl);

	close(fd);

	return 0;

}
