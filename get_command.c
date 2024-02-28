#include "shell.h"
/*
 * This @get_command funcation, will recive @buff which is the buffer
 * will store the input, and @n is the size of the input
 * the getline funcation will get the command from the stdin then
 * store it to the @buf
 * then return @buff to the main fun
 */
char *get_command(char *buff, size_t n)
{
int i = getline(&buff, &n, stdin);
if (i == -1)
{
if (feof(stdin))
{
free(buff);
perror("EOF reached");
exit(0);
}
else
{
free(buff);
perror("can't get the command");
exit(1);
}
}
else
return (buff);
}
