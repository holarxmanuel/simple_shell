#include "shell.h"

/**
 * gethome - funtionto get env HOME
 * @m: copy of enviroment variables
 *Return: string insie the HOME env variable
 */
char *gethome(char **m)
{
	int i, j, k, cont = 0;
	char str[] = "HOME=";
	char *home = NULL;

	for (i = 0; m[i] != NULL; i++)
	{
		for (j = 0; m[i][j] != '\0'; j++)
		{
			if (cont == 5)
				break;
			if (m[i][j] == str[j])
				cont++;
			else
				break;
		}
		if (cont == 5)
			break;
	}
	if (cont == 5)
	{
		home = m[i];
		for (k = 0; k < 5; k++)
		{
			home++;
		}
	}
	return (home);
}
