#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc,char *argv[])
{
	int f1,f2;
    int r_size;
	char *buffer;
	
    if(argc!=3) 
	{
		printf("Invalid number of args\n");
	}

	if(access(argv[1],F_OK)==0) 
	{
		f1=open(argv[1],O_RDONLY); 
		if(f1 > 0)
		{	
			f2=open(argv[2],O_CREAT|O_WRONLY,0777); 
			if(f2 > 0)
			{
				while((r_size=read(f1,&buffer,sizeof(buffer)))>0) 
					write(f2,&buffer,r_size);

				close(f2); 
				close(f1);
			}
			
		}
		else
		{
			printf("error\n");
		}
	}
	else
	{  
		printf("error\n"); 
	}
	
}
