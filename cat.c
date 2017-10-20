#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main(int argc, char *argv[])
{
	int f1, f2;
	int count,i;
	char buffer[100];
	
	if(argc < 2)
	{
		printf("Invalid number of arguments\n");
	}
	
	if(argc == 2)
	{
		if((access(argv[1],F_OK))==0)
		{
			f1 = open(argv[1], O_RDONLY);
			if(f1 > 0)
			{
				while((count = read(f1, buffer, sizeof(buffer))) > 0)
				{
					write(1, buffer, count);
				}
				close(f1); 
			}	
		}
	

		printf("\n\n");
	}
	
	else if(!strcmp(argv[2],">"))
	{
		if(access(argv[1],F_OK)==0) 
		{
			f1=open(argv[1],O_RDONLY); 
			if(f1>0)
			{	
				f2=open(argv[3],O_CREAT|O_WRONLY|O_TRUNC,0777); 
				
					while((count=read(f1,&buffer,sizeof(buffer)))>0) 
						write(f2,&buffer,count);

					close(f2); 
					close(f1); 
				}
	}
    }
	
	else if(!strcmp(argv[2],">>"))
	{
		if(!access(argv[1],F_OK)) 
			f1=open(argv[1],O_RDONLY); 
			if(f1>0)
			{	
				f2=open(argv[3],O_CREAT|O_WRONLY|O_APPEND,0777); 
				if(f2>0)
				{
					while((count=read(f1,&buffer,sizeof(buffer)))>0) 
						write(f2,&buffer,count);

					close(f2); 
					close(f1); 
				}
    
			}
			
		}

		
	
	
	else if(!strcmp(argv[1],">"))
	{
		f1 = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0777);
		if(f1 > 0)
		{
			while((count=read(0,&buffer,sizeof(buffer)))>0) 
				write(f1,&buffer,count);

					close(f1); 
					
		}	 
	}
	else if(!strcmp(argv[1],">>"))
	{
		f1 = open(argv[2],O_CREAT|O_WRONLY|O_APPEND,0777);
		if(f1 > 0)
		{
			while((count=read(0,&buffer,sizeof(buffer)))>0) 
				write(f1,&buffer,count);

					close(f1); 
					
		}
	}
	else
	{
		for(i=1;i<argc;i++)
		{
			if(!(access(argv[i],F_OK)))
			{
				f1 = open(argv[i], O_RDONLY);
				if(f1 > 0)
				{
					while((count = read(f1, buffer, sizeof(buffer))) > 0)
					{
						write(1, buffer, count);
					}
					close(f1); 
				}	

			}
			printf("\n");
		}

}

}
