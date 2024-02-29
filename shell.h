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
void excut(char **words, char **envp);
char *get_command(char *buff, size_t n);
void handle_int(int end);
void handle_quit(int end);
void handle_stp(int end);
void the_prompt(void);
char *find_executable(char *command, char *path);

#endif
