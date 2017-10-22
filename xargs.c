#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int pid=1;

void main(int argc,char *argv[]){

char *buffer;
char *arg[10];
char line[100];
int token_counter=1;
buffer=fgets(buffer,1024,stdin);
buffer[strcspn(buffer, "\n")] = 0;

for (char *p = strtok(buffer," \n"); p != NULL; p = strtok(NULL, " ")){
    arg[token_counter]=strdup(p);
    token_counter++;
}
  arg[0]="./a.out";
  
  
pid=fork();
if(pid==0){
execv(argv[1],arg);
}


}
