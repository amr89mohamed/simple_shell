#include "shell.h"
/*
 * @excut funcation will take the arg
 * @words from the main, then pass it
 * to @execve funcation
 * to create a process to excute it
 */void excut(char **words, char **envp)
{
pid_t pid = fork();
int pipefd[2];
int i;
if (pid == -1)
{
perror("Fork filed error: ");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(words[0], words, envp) == -1)
{
fprintf(stderr, "./hsh: 1: %s: command not found\n", words[0]);
exit(EXIT_FAILURE);
}
}
else
{
wait(&i);
if (strcmp(words[0], "/bin/ls") == 0)
{
char *args[] = {"/bin/ls", NULL};
pid_t ls_pid = fork();
if (ls_pid == -1)
{
perror("Fork failed error: ");
exit(EXIT_FAILURE);
}
else if (ls_pid == 0)
{
dup2(fileno(stdout), fileno(stderr));

pipe(pipefd);
dup2(pipefd[1], fileno(stdout));
close(pipefd[0]);
close(pipefd[1]);
execve(args[0], args, envp);
}
else
{
waitpid(ls_pid, NULL, 0);
}
}
}
for (i = 0; words[i]; i++)
{
free(words[i]);
}
free(words);
}
