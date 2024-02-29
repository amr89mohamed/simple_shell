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
extern char **environ;
/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */typedef struct list_path
{
char *dir;
struct list_path *p;
} list_path;

char **argv(char *buff);
void excut(char **words, char **envp);
char *get_command(char *buff, size_t n);
void handle_int(int end);
void handle_quit(int end);
void handle_stp(int end);
void the_prompt(void);
char *find_executable(char *command, char *path);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);
int _strlen(char *s);
int _putchar(char c);
char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);
void free_list(list_path *head);
#endif
