#include "shell.h"
/**
 * _isenv - finds ne input is env
 * @p: input of us array of pointers
 * @myenv: copy ofironmental variables
 * Return: -1 if fs or 0 if success
 */
int _isenv(char **p, char **myenv)
{
	char str[4] = "env";
	int i = 0, j = 0, cont = 0;

	while (p[0][j] != '\0')
		j++;
	if (j == 3)
	{
		while (i < 3)
		{
			if (p[0][i] == str[i])
				cont++;
			i++;
		}
		if (cont == 3)
		{
			_env(myenv);
			return (0);
		}
	}
	return (-1);
}
/**
 * create_env - cre a copy of the environmental variables
 * @envp: environmes
 * Return: array ofers that stores each element of environ variables
 */
char **create_env(char *envp[])
{
	int i, j = 0, c = 0;
	static char **myenv;

	for (i = 0; envp[i] != NULL; i++)
		;
	myenv = _calloc(i + 1, sizeof(char *));
	if (!myenv)
		return (NULL);
	while (envp[j] != NULL)
	{
		c = 0;
		while (envp[j][c] != '\0')
			c++;
		myenv[j] = _calloc(c + 1, sizeof(char));
		if (myenv[j] == NULL)
		{
			free_grid(myenv, j);
			return (NULL);
		}
		for (i = 0; i < c; i++)
			myenv[j][i] = envp[j][i];
		j++;
	}
	myenv[j] = NULL;
	return (myenv);
}
/**
 * _env - funco print the environment variables
 * environ poian array of pointers to strings called the "environment"
 * @myenv: ic ronmental
 */
void _env(char **myenv)
{
	int i;

	for (i = 0; myenv[i] != NULL; i++)
	{
		write(STDOUT_FILENO, myenv[i], _strlen(myenv[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
