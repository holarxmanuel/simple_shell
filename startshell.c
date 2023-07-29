#include "shell.h"
/**
 * main - shell leton
 * @argc: number arguments in the input
 * @argv: argumein the input
 * @envp: environt variables
 * Return: 0 on uccess
 */
int main(int argc, char *argv[], char *envp[])
{

	if (argc == 1)
	{
		noargv(argv, envp);
	}
	else if (argc == 2)
	{
		yesargv(argv, envp);
	}
	else
	{
		write(STDIN_FILENO, "NO ADMITTED AMOUNT OF ARGUMENTS", 31);
		write(STDIN_FILENO, "\n", 1);
	}
	return (0);
}
