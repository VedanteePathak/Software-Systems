#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main()
{
	int a[2];
	pipe(a);
	if(!fork())
	{
		dup(a[1]);
		close(a[0]);
		execlp("ls","ls","-l",NULL);
	}
	else
	{
		close(0);
		dup(a[0]);
		close(a[1]);
		execlp("wc","wc",NULL);
	}
}
