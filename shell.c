#include "shell.h"
/*
 * this the main funcation, will print a prompot to
 * stdio, get the enter by the user by the @get_command
 * funcation, and store it @command thin pass it to
 * @argv funcation, which will toknize and return @words
 * wich will be passed to @excut funcation
 */ int main(void)
{
char *buff = NULL, *command;
size_t size = 0;
char **words;
char *envp[] = { NULL };
char *path;
char *filename;
char *full_path;
list_path *path_list;
if (isatty(STDIN_FILENO))
{
while (1)
{
the_prompt();
command = get_command(buff, size);
if (strcmp(command, "\n") == 0)
{
free(command);
continue;
}
words = argv(command);
if (strcmp(words[0], "exit") == 0)
{
free(command);
free(words);
break;
}
excut(words, envp);
free(command);
free(words);
}
}
else
{
command = get_command(buff, size);
words = argv(command);
excut(words, envp);
free(command);
free(words);
}
path = _getenv("PATH");    
path_list = linkpath(path);
filename = "file";
full_path = _which(filename, path_list);
if (full_path != NULL)
{
printf("Found executable at: %s\n", full_path);
}
else
{
printf("Executable not found in PATH\n");
}
free_list(path_list);
return (0);
}

