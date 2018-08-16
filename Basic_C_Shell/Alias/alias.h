#ifndef ALIAS_H
#define ALIAS_H

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

struct alias{
    char* alias;
    char* command;
};
typedef struct alias Alias;

void* buildFileAlias(FILE* file);
void* buildAlias(char* input);
void printAlias(void* ptr);
void cleanAlias(void* ptr);
int compareAlias(const void* a1,const void* a2);
int isAlias(char* buff);
int isUnAlias(char* buff);
#endif