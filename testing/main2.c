#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/*
 * this the dissplay image funcation
 * will display the prompot to the screen
 */void display_prompt(void)
{
printf("#cisfun$ ");
}

/*
 * this the main funcation
 */int main(int argc, char *argv[])
{
char command[MAX_COMMAND_LENGTH];
char *args[3];

if (argc > 2)
{
printf("Usage: %s [command]\n", argv[0]);
return (EXIT_FAILURE);
}
while (1)
{
if (argc == 2)
{
snprintf(command, MAX_COMMAND_LENGTH, "/bin/%s", argv[1]);
args[0] = command;
args[1] = "-l";
args[2] = NULL;
}
else
{
display_prompt();
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
if (feof(stdin))
{
printf("\n");
break;
}
else
{
perror("Error reading command");
continue;
}
}
command[strcspn(command, "\n")] = '\0';
args[0] = command;
args[1] = NULL;
}
pid_t pid = fork();
if (pid < 0)
{
perror("Fork error");
continue;
}
else if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
perror("Execution error");
exit(EXIT_FAILURE);
}
}
else
{
int status;
if (waitpid(pid, &status, 0) == -1)
{
perror("Wait error");
exit(EXIT_FAILURE);
}
}
}
return (0);
}

