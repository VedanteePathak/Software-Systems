#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
        struct rlimit lim, new_lim;
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

	lim.rlim_cur=4;
	lim.rlim_max=1024;

	if(setrlimit(RLIMIT_NOFILE, &lim)==-1)
	{
		printf("Failed\n");
	}

	if(getrlimit(RLIMIT_NOFILE,&new_lim)==0)
	{
		printf("resource soft limit is %ld\t",lim.rlim_cur);
		printf("resource hard limit is %ld\t",lim.rlim_max);
	}

        return 0;
}
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
~                                                                         
-- INSERT --                                            1,1           All

