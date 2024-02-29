#include "shell.h"
/*
 * this the find_excutable for find the path
 * where is @token will store the tokinize
 * @path_copy where is the pass will be copied
 * @excutable path is the link to make the path
 * execut
 */ char *find_executable(char *command, char *path)
{
char *token;
char *path_copy = strdup(path);
char *executable_path = NULL;
token = strtok(path_copy, ":");
while (token != NULL)
{
executable_path = malloc(strlen(token) + strlen(command) + 2);
strcpy(executable_path, token);
strcat(executable_path, "/");
strcat(executable_path, command);
if (access(executable_path, X_OK) == 0)
{
free(path_copy);
return (executable_path);
}
free(executable_path);
token = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}
