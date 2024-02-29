#include "shell.h"
/*
 * prompt function is diplayed a fixed
 * prompt to the stdout
 */ void the_prompt(void)
{
write(1, "#cisfun$ ", 9);
fflush(stdin);
}
