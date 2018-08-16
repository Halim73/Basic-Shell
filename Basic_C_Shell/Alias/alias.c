#include "alias.h"

void* buildFileAlias(FILE* file){
    Alias* alias = calloc(1,sizeof(Alias));
    
    char buff[100];
    
    fgets(buff,sizeof(buff),file);
    char* savePtr = NULL;
    char* token;// = calloc(100,sizeof(char));
    
    token = strtok_r(buff,"=",&savePtr);
    alias->alias = calloc(100,sizeof(char));
    strcpy(alias->alias,token);
    //printf("now alias is %s and token is %s\n",alias->alias,token);
    
    token = strtok_r(NULL,"\n",&savePtr);
    alias->command = calloc(100,sizeof(char));
    strcpy(alias->command,token);
    //printf("now command is %s and token is %s\n",alias->command,token);
    
    //free(token);
    return alias;
}

void* buildAlias(char* input){
    Alias* alias = calloc(1,sizeof(Alias));
    
    char aux[strlen(input+1)];
    strcpy(aux,input);
    
    char* savePtr = NULL;
    char* token = strtok_r(aux,"=",&savePtr);
  
    //printf("building alias from %s\n",token);
    if(token != NULL){
        char toBreak[strlen(input+1)];
        strcpy(toBreak,input+6);//alias plus space has 6 characters so skip
        
        token = strtok_r(toBreak,"=",&savePtr);
        
        alias->alias = calloc((strlen(token)+1),sizeof(char));
        strcpy(alias->alias,token);
        //printf("alias is %s \n",alias->alias);
        
        token = strtok_r(NULL,"",&savePtr);
        
        alias->command = calloc((strlen(token)+1),sizeof(char));
        strcpy(alias->command,token);
        //printf("command is %s \n",alias->command);
    }else{
        return NULL;
    }
    return alias;
}
void printAlias(void* ptr){
    if(ptr == NULL){
        perror("ptr is null");
        exit(-123);
    }
    
    Alias* alias = (Alias*)ptr;
    printf("%s=%s\n",alias->alias,alias->command);
}
void cleanAlias(void* ptr){
    Alias* alias = (Alias*)(ptr);
    
    free(alias->alias);
    free(alias->command);
    
    alias->alias = NULL;
    alias->command = NULL;
    
    free(alias);
    alias = NULL;
}
int compareAlias(const void* a1,const void* a2){
    Alias* lhs = (Alias*)(a1);
    Alias* rhs = (Alias*)(a2);
    
    if(strcmp(lhs->alias,rhs->alias) != 0){
        return strcmp(lhs->command,rhs->command);
    }
    return 0;
}
int isAlias(char* buff){
    char* contains = strstr(buff,"=");
    
    char token[strlen(buff+1)];
    
    if(contains != NULL){
        strncpy(token,buff,7);
        token[6] = '\0';
        //printf("checking if alias\n");
        return (strstr(token,"alias") != NULL)?0:1;
    }
    return -1;
}
int isUnAlias(char* buff){
    char* contains = strstr(buff,"=");
    
    char token[strlen(buff+1)];
    
    if(contains != NULL){
        strncpy(token,buff,9);
        token[8] = '\0';
        //printf("checking if unalias\n");
        return (strstr(token,"unalias") != NULL)?0:1;
    }
    return -1;
}