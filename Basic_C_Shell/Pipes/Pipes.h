#ifndef PIPES_H
#define PIPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "../tokenize/makeArgs.h"

int containsPipe(char *s);//strlen(),loop,
int containsRedirect(char* s);
char** parsePreRedirect(char* s,int* preCount,char* redirect);
char** parsePostRedirect(char* s,int* postCount,char* redirect);

char** parsePrePipe(char*s, int* preCount);//makeargs
char** parsePostPipe(char*s, int* postCount);
void pipeIt(char** prePipe, char** postPipe);
void redirectIt(char** command,char** file,char dir);
#endif 
