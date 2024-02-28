#include "shell.h"
/*
 * @argv fun
 * recive @buff and pass it
 * to strtok fun, with the delim arg
 * and store the return of @strtok
 * strtok will return an array of cahr pointers
 * this pointers will be stored in @words
 * @words will be returned to the main funcation
 */char **argv(char *buff)
{
char **words = malloc(sizeof(char *));
char *delim = " \n";
int i = 0;
char *token;
token = strtok(buff, delim);
while (token != NULL)
{
words[i] = strdup(token);
if (words[i] == NULL)
{
perror("Error in strdup token");
exit(EXIT_FAILURE);
}
i++;
words = realloc(words, (i + 1) * sizeof(char *));
if (words == NULL)
{
perror("Error to realloc memmory for word");
exit(EXIT_FAILURE);
}
token = strtok(NULL, delim);
}
words[i] = NULL;
return (words);
}


