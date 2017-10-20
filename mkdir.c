#include <stdio.h>
#include <sys/stat.h>

void main (int argc,char *argv[])
{

	if(argc!=2) 
	{
		printf("Invalid number of arguments\n");
	}

	if(mkdir(argv[1],0775)!=0) 
		printf("error");
}

