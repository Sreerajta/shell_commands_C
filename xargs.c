#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int pid=1;;


void main(int argc,char *argv[]){

char *buffer;
char *arg[10];
int token_counter=0;
char line[100];

buffer=fgets(buffer,1024,stdin);
buffer[strcspn(buffer, "\n")] = 0;

for (char *p = strtok(buffer," \n"); p != NULL; p = strtok(NULL, " ")){
    arg[token_counter]=strdup(p);
    token_counter++;
}
  


for(int i=0;i<token_counter;++i){
    pid=fork();

    if(pid==0){
        execl(argv[1],"pname",arg[i]);
        exit(0);
    }
}


}
