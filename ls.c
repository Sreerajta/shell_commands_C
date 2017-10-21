#include<stdio.h>
#include <dirent.h>
#include<unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{ DIR *directory; 
  struct dirent *file;
  
  
  for(int i=1;i<=argc-1;i++)
		{
			if(!access(argv[i],F_OK)) 
			{
				directory=opendir(argv[i]); 

				if(directory!=NULL)
				{
					while((file=readdir(directory))!=NULL) 
                    {   if(strcmp(".",file->d_name)!=0&&strcmp("..",file->d_name)!=0)
                        printf("%s\t",file->d_name);}
					printf("\n");
                }
            
                
            }
        
            
            
}
}
  
