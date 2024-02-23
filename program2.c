#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	struct rlimit lim;
	getrlimit(RLIMIT_AS,&lim);
	if(getrlimit(RLIMIT_AS,&lim)==0)
	{
		printf("resource soft limit is %ld\t",lim.rlim_cur);
		printf("resource hard limit is %ld\t",lim.rlim_max);
	}
	else
	{
		printf("Failed: \n");
	}
	return 0;
}
