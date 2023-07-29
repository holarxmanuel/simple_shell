#include "shell.h"

/**
 * main - shell skeleton
 * @argc: number of arguments in the input
 * @argv: arguments in the input
 * @envp: environment variables
 * Return: 0 on Success
 */
int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
	{
		_noargv(argv, envp);
	}
	else if (argc == 2)
	{
		_yesargv(argv, envp);
	}
	else
	{
		write(STDOUT_FILENO, "NO ADMITTED AMOUNT OF ARGUMENTS\n", 31);
	}
	return (0);
}

