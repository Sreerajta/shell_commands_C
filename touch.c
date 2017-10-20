#include<stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <utime.h>
#include <unistd.h>

void main(int argc,char *argv[])
{
	int f1;
	int i;
	
	if(argc<1) 
	{
		printf("Invalid Number Of Arguments\n");
	}
	
	for(i=0;i<argc;i++)
	{	
		if(access(argv[i],F_OK)==0) 
		{
			if( utime(argv[i],NULL)!=0 ) 
				printf("Error\n");
		}
		
		else
		{
			f1=open(argv[i],O_CREAT|O_RDWR,0777); 
			if( f1 <= 0 ) 
				printf("error\n");
		}
	}

}
