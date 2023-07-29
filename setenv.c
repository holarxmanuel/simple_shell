#include "shell.h"

/**
 * issetenv - finds if line input is setenv
 * @p: input o user, array of pointers
 * @myenv: cop of environmental variables
 * @loop: numbr of loops
 * @e: number f elements in m
 * @v: argument
 * Return: -1 if fails or 0 if succes
 */
int issetenv(char **p, char ***myenv, int *e, int loop, char *v[])
{
	char str[] = "setenv";
	int i = 0, cont = 0, salida = -1;

	i = 0;
	while (p[0][i] != '\0')
	{
		if (i < 6)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 6)
		cont++;
	if (cont == 7)
	{
		if (p[1] != NULL && p[2] != NULL)
			setenv(p, myenv, e, loop, v);
		else
			put_err(p, loop, 5, v);
		salida = 0;
		currentstatus(&salida);
	}
	else if (cont == 6)
	{
		salida = 0;
		put_err(p, loop, 3, v);
		currentstatus(&salida);
	}
	return (salida);
}
/**
 * setenv - function to add or modify an environment variable
 * environ ponts to an array of pointers to strings called the "environment"
 * @myenv: icpy of environmental
 * @loop: nmber of loops
 * @p: input of user
 * @e: numbof elements in m
 * @v: argunts
 */
void setenv(char **p, char ***myenv, int *e, int loop, char *v[])
{
	int i, lg, j, k = 0, cont = 0, p2len = 0, myenvlen = 0;
	char *entirenv, *withequal;

	lg = strlen(p[1]);
	withequal = str_concat(p[1], "=");
	entirenv = str_concat(withequal, p[2]);
	for (i = 0; (*myenv)[i] != NULL; i++, cont = 0)
	{
		for (j = 0; p[1][j] != '\0' && j < lg; j++)
		{
			if (p[1][j] == (*myenv)[i][j])
				cont++;
		}
		if (cont == lg)
			break;
	}
	if (cont == lg)
	{
		myenvlen = strlen((*myenv)[i]), p2len = strlen(p[2]);
		if (p2len < myenvlen)
		{
			for (k = 0; entirenv[k] != '\0'; k++)
				(*myenv)[i][k] = entirenv[k];
			for (; k < myenvlen; k++)
				(*myenv)[i][k] = 0;
		}
		else
		{
			(*myenv)[i] = realloc((*myenv)[i], myenvlen, strlen(entirenv));
			for (k = 0; entirenv[k] != '\0'; k++)
				(*myenv)[i][k] = entirenv[k];
		} free(withequal), free(entirenv), *e = *e;
	}
	else if (cont != lg && p[1] != NULL && p[2] != NULL)
	{
		setenvcreat(myenv, e, entirenv);
		ree(withequal), free(entirenv);
	}
	else
		put_err(p, loop, 5, v);
}
/**
 * setenvcreat - fuction to add or modify an environment variable
 * environ points to an array of pointers to strings called the "environment"
 * @myenv: icopy of nvironmental
 * @e: number of eleents in m
 * @entirenv: concatnate arguments
 */
void setenvcreat(char ***myenv, int *e, char *entirenv)
{
	int i = 0, k = 0;
	char **new = NULL;

	new = calloc(*e + 2, sizeof(char *));
	for (i = 0; (*myenv)[i] != NULL; i++)
	{
		for (k = 0; (*myenv)[i][k]; k++)
			;
		new[i] = calloc(k + 1, sizeof(char));
		for (k = 0; (*myenv)[i][k] != '\0'; k++)
			new[i][k] = (*myenv)[i][k];
	}
	new[i] = calloc(strlen(entirenv) + 1, sizeof(char));
	for (k = 0; entirenv[k] != '\0'; k++)
		new[i][k] = entirenv[k];
	new[i + 1] = NULL;
	*e = *e + 1;
	free_grid((*myenv), *e);
	(*myenv) = new;
}
