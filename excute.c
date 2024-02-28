#include "shell.h"
/*
 * @excut funcation will take the arg
 * @words from the main, then pass it
 * to @execve funcation
 * to create a process to excute it
 */void excut(char **words)
{
char *envp[] = { NULL };
pid_t pid = fork();
int i, k = 0;

while (words[k])
{
k++;
}
if (pid == -1)
{
perror("Fork filed error: ");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (k > 1)
{
printf("Usage: %s [command]\n", words[0]);
exit(EXIT_FAILURE);
}
else if (execve(words[0], words, envp) == -1)
{
perror("./hsh");
exit(EXIT_FAILURE);
}
}
else
{
wait(&i);
free(words);
}
}
