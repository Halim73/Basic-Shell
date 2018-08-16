#include "makeArgs.h"

void clean(int argc, char** argv){
    int i=0;
    for(i=0;i<argc;i++){
        free(argv[i]);
        argv[i] = NULL;
    }
    free(argv);
    argv = NULL;
}// end clean

void printargs(int argc, char** argv){
	int x;
	for(x = 0; x < argc; x++)
		printf("%s\n", argv[x]);

}// end printargs

int makeargs(char* s, char*** argv){
    char copy[MAX];
    strcpy(copy,s);
    
    int count = 0;
    char* savePointer = NULL;
    
    char* token = strtok_r(copy," ",&savePointer);
    
    while(token != NULL){
        count++;
        token = strtok_r(NULL," ",&savePointer);
    }
    
    if(count == 0){
        return -1;
    }
    
    (*argv) = (char**)(calloc(count+1,sizeof(char*)));
    
    token = strtok_r(s," ",&savePointer);
    (*argv)[0] = (char*)(calloc(strlen(token)+1,sizeof(char)));
    strcpy((*argv)[0],token);
    
    int x;
    for(x=1;x<count;x++){
        token = strtok_r(NULL," ",&savePointer);
        (*argv)[x] = (char*)(calloc(strlen(token)+1,sizeof(char)));
        strcpy((*argv)[x],token);
    }
    //printf("finished making args with size %d\n",count);
    return count;
}// end makeArgs
