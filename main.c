#include "shell.h"
/*
 * this the main funcation, will print a prompot to
 * stdio, get the enter by the user by the @get_command
 * funcation, and store it @command thin pass it to
 * @argv funcation, which will toknize and return @words
 * wich will be passed to @excut funcation
 */int main(void)
{
char *buff = NULL, *command;
size_t size = 0;
char **words;
if (isatty(STDIN_FILENO))
while (1)
{
write(1, "$ ", 2);
command = get_command(buff, size);
words = argv(command);
if (strcmp(words[0], "exit") == 0)
{
free(command);
free(words);
break;            }
excut(words);
}
else
{
command = get_command(buff, size);
words = argv(command);
excut(words);
}
return (0);
}

