#include<stdio.h>
#include <dirent.h>
#include<unistd.h>
#include<string.h>


void parsedir(char *path);

void main(int argc, char *argv[])
{ 
   parsedir(argv[1]);         
            
}



void parsedir(char *path){

  DIR *directory; 
  struct dirent *file;
  
  
			if(!access(path,F_OK)) 
			{
				directory=opendir(path); 

				if(directory!=NULL)
				{
					while((file=readdir(directory))!=NULL) 
                    {   if(strcmp(".",file->d_name)!=0&&strcmp("..",file->d_name)!=0){
                        if(file->d_type != DT_DIR)
                        {printf("\x1B[37m%s\t",file->d_name);}
                        else{
                           printf("\x1B[34m%s\t",file->d_name);
                           //printf("\n");
                           //strcat(path,"/");
                           //parsedir(strcat(path,file->d_name));
                                                   
                            
                        }
                    }
                        
                    }
                    
                    directory=opendir(path); 
                    while((file=readdir(directory))!=NULL) 
                    {   if(strcmp(".",file->d_name)!=0&&strcmp("..",file->d_name)!=0){
                
                           if(file->d_type == DT_DIR){
                           printf("\x1B[34m\n\n%s:",file->d_name);
                           printf("\n");
                           strcat(path,"/");
                           parsedir(strcat(path,file->d_name));
                           }              
                            
                        
                    }
                        
                    }
                    
                    
                    
                    
                    
					printf("\n");
                }
            
                
            
            }     
    
    
}






  
