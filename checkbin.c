#include "shell.h"

/**
 * verifypath - check if the path has a : at the begining
 * or if exi
 *@path: string insidATH env varible
 *@pwd: string inside env variable
 *Return: path, or pw concatenated to path if there is a : at the begining or
 *pwd concatenated whn there is ::
 */
char *verifypath(char *path, char *pwd)
{
	int a = 0, c = 0, i = 0;
	char *newpath = NULL;

	while (path[c] != '\0')
		c++;
	while (path[a] != '\0')
	{
		if (path[0] == ':')
		{
			newpath = calloc(c + 1, sizeof(char));
			newpath[0] = pwd[0];
			for (i = 0; path[i] != '\0'; i++)
				newpath[i + 1] = path[i];
			free(path);
			path = newpath;
			a++;
			c++;
		}
		else if (path[a] == ':' && path[a + 1] == ':')
		{
			newpath = calloc(c + 1, sizeof(char));
			for (i = 0; i <= a; i++)
				newpath[i] = path[i];
			newpath[i] = pwd[0];
			for (i = i + 1; path[i] != '\0'; i++)
				newpath[i] = path[i - 1];
			free(path);
			a++;
			path = newpath;
		}
		a++;
	}
	return (path);
}
/**
 * getpath - get he string in PATH env
 * @m: environmenariables
 * Return: stringinside PATH env variable
 */
char *getpath(char **m)
{
	int i, j, k = 0, w = 0, cont = 0;
	char str[] = "PATH=";
	char *path;

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
	k = cont;
	if (cont == 5)
	{
		while (m[i][k] != '\0')
		{
			w++;
			k++;
		}
		if (w == 0)
			return (NULL);
		path = calloc(w + 1, sizeof(char));
		if (path == NULL)
			return (NULL);
		k = 5;
		while (m[i][k] != '\0')
		{
			path[k - 5] = m[i][k];
			k++;
		}
		return (path);
	}
	return (NULL);
}
/**
 * checkbin - cheks if arg[0] has /bin/
 * @b: inputof user, array of pointers
 * @m: copy f environment variables
 * Return: 0.
 */

char **checkbin(char **b, char **m)
{
	unsigned int i = 0, j = 0, k = 0;
	struct stat veri;
	char *path, *tokens, *buf, *newpath;
	char *valor;

	i = strlen(b[0]);
	if (b == NULL || i == 0)
		return (NULL);
	path = getpath(m);
	if (path == NULL)
		return (b);
	newpath = verifypath(path, ".");
	tokens = strtoky(newpath, ":");
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		while (tokens[j] != '\0')
			j++;
		buf = calloc((j + 2), sizeof(char));
		if (buf == NULL)
			perror("No memory");
		for (k = 0; k < j; k++)
			buf[k] = tokens[k];
		buf[k] = '/';
		valor = str_concat(buf, b[0]);
		if (stat(valor, &veri) == 0)
		{
			b[0] = realloc2(buf, b[0], i, strlen(valor));
			free(buf), free(valor);
			free(newpath);
			return (b);
		}
		tokens = strtoky(NULL, ":");
		j = 0;
		free(buf), free(valor);
	}
	free(newpath);
	return (b);
}
