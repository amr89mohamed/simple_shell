#ifndef SHELL_H_
#define SHELL_H_
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#define MAX_COMMAND_LENGTH 100
char **argv(char *buff);
void excut(char **words);
char *get_command(char *buff, size_t n);




#endif
