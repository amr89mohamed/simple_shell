#include "shell.h"
/*
 * handle_int - Signal handler (Ctrl+C)
 * @end: Signal number
 * Nothing to be returned
 */void handle_int(int end)
{
(void) end;
printf("\n");
the_prompt();
}
/*
 * handle_quit - Signal handler (Ctrl+\)
 * @end: Signal number
 * Nothing to be returned
 */void handle_quit(int end)
{
(void) end;
perror("End-(core dumped occur)\n");
exit(EXIT_SUCCESS);
}
/*
 * handle_sigstp  handler (Ctrl+Z)
 * @end: Signal number
 * Nothing to be returned
 */void handle_stp(int end)
{
(void) end;
printf("\n");
the_prompt();
}
