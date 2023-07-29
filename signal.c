#include "shell.h"

/**
 * signal - hadle SIGINT signal
 * @s: signa to catch
 */
void signal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
