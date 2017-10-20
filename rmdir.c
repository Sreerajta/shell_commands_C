#include <stdio.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		printf("Wrong format");
		return ;
	}

	if( access( argv[1], F_OK ) != -1 )
	{
		if(rmdir(argv[1])!=0)
		{
			printf("error");
		}
	}
	else
	{
		printf("error, no such dir");
	}
	
	
}
