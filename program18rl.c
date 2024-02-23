/*
============================================================================
Name : 18.c
Author : Vedantee Pathak
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28th Aug, 2023.
============================================================================
*/


#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>

int main(){
int i, fd;
struct {
int rollno;
int marks;
} db;
struct flock fl;
fd = open("records.txt", O_RDONLY);

printf("Enter the record number: \n");
scanf("%d", &i);
fl.l_type = F_RDLCK;
fl.l_whence = SEEK_SET;
fl.l_start = (i-1)*sizeof(db);
fl.l_len = sizeof(db);
fl.l_pid = getpid();
printf("Before locking the record for reading\n");
fcntl(fd, F_SETLKW, &fl);
printf("Read lock acquired successfully....\n");
read(fd, &db, sizeof(db));
printf("The record details are:\n");
printf("Roll No: %d\n", db.rollno);
printf("Marks: %d\n", db.marks);
printf("Enter to unlock...\n");
getchar();
getchar();
fl.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &fl);
printf("Finish\n");
return 0;
}

