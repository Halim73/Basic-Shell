#include"Pipes.h"

int containsRedirect(char* s){
    char* contains = strstr(s,">");
    char* contains2 = strstr(s,">");
    int ret = 0;//1 = forward 2 = backward <= 0 false;
    
    if(contains != NULL){
        //printf("contains redirect >\n");
        return 1;
    }else if(contains2 != NULL){
        //printf("contains redirect <\n");
        return 2;
    }
    return -1;
}
char** parsePreRedirect(char* s,int* preCount,char* redirect){
    //printf("parsing pre");
    char temp[100];
    
    strcpy(temp,s);
    
    char* savePtr = NULL;
    char* token = strtok_r(temp,redirect,&savePtr);
    //printf("pre token is %s",token);
    
    char** parsedRedirect;
    *preCount = makeargs(token,&parsedRedirect);
    
    return parsedRedirect;
}
char** parsePostRedirect(char* s,int* postCount,char* redirect){
    char temp[100];
    
    strcpy(temp,s);
    
    char* savePtr = NULL;
    char dir;
    if(strcmp(redirect,">") == 0){
        dir = '>';
    }else{
        dir = '<';
    }
    
    char* token = (strrchr(temp,dir)+1);
    //printf("post token is %s",token);
    
    if(token == NULL){
        perror("only one command");
        exit(1);
    }
    
    char** parsedRedirect;
    *postCount = makeargs(token,&parsedRedirect);
    
    return parsedRedirect;
}
void redirectIt(char** command,char** file,char dir){
    int status = 0;
    int fd[2];
    
    pid_t parent = fork();
    if(parent != 0){
        waitpid(parent,&status,0);
    }else{
        if(dir == '>'){
            close(1);
            FILE* fout = fopen(file[0],"wb+");
            pid_t main = fork();

            if(main == -1){
                perror("can't fork");
                exit(99);
            }
        
            if(main == 0){
                execvp(command[0],command);
                exit(0);
            }else{
                waitpid(main,&status,0);
                fclose(fout);
                open(1);
                exit(0);
            }
        }else{
            close(0);
            FILE* fin = fopen(file[0],"r");

            pid_t main = fork();

            if(main == -1){
                perror("can't fork");
                exit(99);
            }

            if(main == 0){
                execvp(command[0],command);
                exit(0);
            }else{
                waitpid(main,&status,0);
                fclose(fin);
                open(0);
                exit(0);
            }
        }
    }
}

int containsPipe(char* s){
    //int i, length = strlen(s);
    char* contains = strstr(s,"|");
    
    if(contains != NULL)return 1;
    
    return 0;
}
char** parsePrePipe(char* s, int* preCount){
    char temp[100];
    
    strcpy(temp,s);
    
    char* savePtr = NULL;
    char* token = strtok_r(temp,"|",&savePtr);
    //printf("the token is %s",token);
    
    char** parsedPipe;
    *preCount = makeargs(token,&parsedPipe);
    
    return parsedPipe;
}
char** parsePostPipe(char* s, int* postCount){
    char temp[100];
    
    strcpy(temp,s);
    
    char* savePtr = NULL;
    char* token = (strrchr(temp,'|')+1);
    
    if(token == NULL){
        printf("only one command");
        exit(1);
    }
    
    char** parsedPipe;
    *postCount = makeargs(token,&parsedPipe);
    
    return parsedPipe;
}
void pipeIt(char** prePipe, char** postPipe){
    int status = 0;
    pid_t main = fork();
    
    if(main == -1){
        perror("can't fork");
        exit(99);
    }
    
    if(main != 0){
        waitpid(main,&status,0);
    }else{
        int fd[2];
        pipe(fd);
        
        pid_t pid = fork();
        
        if(pid == -1){
            perror("can't fork");
            exit(1);
        }
        
        if(pid != 0){
            dup2(fd[0],0);
            close(fd[1]);
            execvp(postPipe[0],postPipe);
            exit(0);
        }else{
            close(fd[0]);
            close(1);
            dup(fd[1]);
            close(fd[1]);
            execvp(prePipe[0],prePipe);
            exit(0);
        }
    }
}
