#include"process.h"

void forkIt(char** argv){
    int status = 0;
    pid_t child = fork();
    
    if(child == -1){
        perror("can't fork");
        exit(1);
    }
    
    if(child != 0){
        //printf("parent process waiting\n");
        waitpid(child,&status,0);
        //printf("parent process returning\n");
    }else{
        //printf("child process going with %s\n",*argv);
        execvp(argv[0],argv);
        //printf("child process ending\n");
        exit(0);
    }
}
