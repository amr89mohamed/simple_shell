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
char *executable_path;
if (isatty(STDIN_FILENO))
{
while (1) {
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
executable_path = find_executable(words[0], getenv("PATH"));
if (executable_path == NULL)
{
fprintf(stderr, "%s: command not found\n", words[0]);
free(command);
free(words);
continue;
}
excut(words, envp);
free(executable_path);
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
return 0;
}

