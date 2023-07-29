i#include "shell.h"
/**
 * iscd - finds if lin input is cd builtin
 * @p: input of user, aray of pointers
 * @loop: counter of lop
 * @v: arguments in inpu
 * @myenv: copy of environmnt variables
 * Return: -1 if not succes 0 if exist cd in args[0]
 */
int iscd(char **p, int loop, char *v[], char **myenv)
{
	char str[] = "cd";
	int i = 0, cont = 0, valor = -1;

	while (p[0][i] != '\0')
	{
		if (i < 2)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 2)
		cont++;

	if (cont == 3)
	{
		cd(p, loop, v, myenv);
		valor = 0;
	}
	else if (cont == 2)
	{
		put_err(p, loop, 3, v);
		valor = 0;
	}
	return (valor);
}

/**
 * cleancd - cleanuffer
 * @c: pointer to bf
 * Return: -1 if no success 0 if exist cd in args[0]
 */
void cleancd(char *c)
{
	int i;

	for (i = 0; i < 2048; i++)
		c[i] = 0;
}

/**
 * fullcd - fll buffer
 * @f: pointr to buf
 * @aux: poiter to aux
 * Return: - if not success 0 if exist cd in args[0]
 */
void fullcd(char *f, char *aux)
{
	int w;

	for (w = 0; aux[w] != '\0'; w++)
		f[w] = aux[w];
	for (; w < 2048; w++)
		f[w] = 0;
}
/**
 * cd - Changes th current directory of the process.
 * @a: input of use, array of pointers
 * @loop: loops couter
 * @v: arguments ininput
 * @myenv: copy of environment variables
 * Return:-1 if notd the directory or 0 if success
 */
void cd(char **a, int loop, char *v[], char **myenv)
{
	int valor = 0, z = 0;
	static char buf[2048];
	static int w = 1;
	char *home, aux[2048] = {0};

	currentstatus(&z);
	if (w == 1)
	{ home = gethome(myenv);
		if (!home)
			getcwd(home, 2048);
		updateoldpwd(getcwd(buf, 2048), myenv);
		fullcd(buf, gethome(myenv));
		w++;
	}
	if (a[1] == NULL)
	{
		cleancd(buf);
		getcwd(buf, 2048);
		updateoldpwd(buf, myenv);
		valor = chdir((const char *)gethome(myenv));
		updatepwd(gethome(myenv), myenv);
	}
	else if (a[1][0] == '-' && a[1][1] == '\0')
	{
		cleancd(aux), getcwd(aux, 2048);
		updateoldpwd(aux, myenv);
		write(STDOUT_FILENO, buf, 2048);
		write(STDOUT_FILENO, "\n", 1);
		valor = chdir((const char *) buf);
		updatepwd(buf, myenv), fullcd(buf, aux);
	}
	else
	{
		cleancd(buf), getcwd(buf, 2048);
		updateoldpwd(buf, myenv);
		valor = chdir((const char *)a[1]);
		updatepwd(a[1], myenv);
	}
	if (valor == -1)
		put_err(a, loop, 1, v);
}
