#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>



void main(int argc,char *argv[]){
    int f1;
    char buffer[1024];
    int r_size;
    
	
      f1=open(argv[1],O_CREAT|O_WRONLY,0777); 
  
    
    
     
     while((r_size=read(0,&buffer,sizeof(buffer)))>0) {
					write(f1,&buffer,r_size);
                    write(1,&buffer,r_size);
     }

     close(f1); 
     
}     
