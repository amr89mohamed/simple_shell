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
while (1)
{
write(1, "#cisfun$ ", 9);
command = get_command(buff, size);
words = argv(command);
excut(words);
}
return (0);
}
