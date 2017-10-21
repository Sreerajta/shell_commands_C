#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<ctype.h>

void main(int argc, char *argv[]){
   DIR  *dir;
   struct dirent *file;
   int proctest;
   
   char path[256];
  
   dir = opendir("/proc");
  
   while((file = readdir(dir)) != NULL){
    if(file->d_type == DT_DIR && strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".") != 0){
      proctest = file->d_name[0];
      
      if(isdigit(proctest)){
         sprintf(path, "/proc/%s/comm",file->d_name);
         char buffer[1024];
         int fd;
         size_t nread;
         fd = open(path, O_RDONLY);
  
  while((nread = read(fd, buffer, 256)) > 0)
    if(strcmp(buffer, "\n") !=0)
    { buffer[strcspn(buffer, "\n")] = 0;
      printf("%s\t",buffer);  
      printf("%s", file->d_name);
      printf("\n");
    }
         }
      
    }
  }

}

