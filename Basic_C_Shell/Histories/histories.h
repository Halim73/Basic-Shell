#ifndef H_HISTORIES
#define H_HISTORIES

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include "../utils/myUtils.h"

struct history{
    char* command;
};
typedef struct history History;
void* buildFileHistory(FILE* file);
void* buildHistory(char* input);
void printHistory(void* ptr);
void cleanHistory(void* ptr);
#endif