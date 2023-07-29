#include "shell.h"
#include <limits.h>

void _type(char **p, int L, char *l, int i, char **v, char **m, int e, char *f)
{
	unsigned int c = 0, flag = 0;
	long int valor = 0;

	if (p[1] == NULL || (p[1][0] == '0' && p[1][1] == '\0'))
	{
		free(l), free(f), free_grid(p, i), free_grid(m, e);
		exit(currentstatus(NULL));
	}
	else
	{
		while (p[1][c] != '\0')
		{
			if ((p[1][0] != '+' && p[1][0] != '-') &&
			    (p[1][c] < '0' || p[1][c] > '9'))
			{
				flag = 1;
				break;
			}
			c++;
		}
		if (flag == 1)
			_put_err(p, L, 1, v);
		else
		{
			valor = _atoi(p[1]);
			if (!(valor > INT_MAX) && valor > 0)
			{
				valor = valor % 256;
				free(l), free(f), free_grid(p, i);
				free_grid(m, e), exit(valor);
			}
			else if (valor < 0)
			{
				_put_err(p, L, 1, v);
				free(l), free(f), free_grid(p, i);
				free_grid(m, e), exit(2);
			}
			else
				_put_err(p, L, 1, v);
		}
	}
}

int _isexit(char **p, int L, char *l, char **v, char **m, char *f)
{
	char str[] = "exit";
	int i, cont = 0, exit_status = -1, x = 0, e = 0;

	for (x = 0; p[x] != NULL; x++)
		;
	for (e = 0; m[e] != NULL; e++)
		;

	i = 0;
	while (p[0][i] != '\0')
	{
		if (i < 4)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 4)
		cont++;

	if (cont == 5)
	{
		_type(p, L, l, x, v, m, e, f);
		exit_status = 0;
	}
	else if (cont == 4)
	{
		exit_status = 0;
		_put_err(p, L, 3, v);
	}

	return (exit_status);
}

