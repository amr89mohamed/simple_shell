#ifndef SHELL_H_
#define SHELL_H_
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

char **argv(char *buff);
void excut(char **words);
char *get_command(char *buff, size_t n);




#endif
