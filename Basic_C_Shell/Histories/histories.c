#include"histories.h"
void* buildFileHistory(FILE* file){
    History* command = calloc(1,sizeof(History));
    
    command->command = calloc(100,sizeof(char));
    fgets(command->command,sizeof(command->command),file);
    strip(command->command);
    return command;
}
void* buildHistory(char* input){
    History* command = calloc(1,sizeof(History));
    command->command = calloc(strlen(input)+1,sizeof(char));
    
    strcpy(command->command,input);
    
    return command;
}
void printHistory(void* ptr){
    if(ptr == NULL){
        perror("ptr is null");
        exit(231);
    }
    History* command = (History*)(ptr);
    strip(command->command);
    printf("%s\n",command->command);
}
void cleanHistory(void* ptr){
    History* command = (History*)(ptr);
    
    free(command->command);
    command->command = NULL;
    
    free(command);
    command= NULL;
}