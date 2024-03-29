#include "shell.h"
/**
 * put_err - writes the error
 * @p: inputpointer
 * @loop: conter of loops
 * @sig: sigal
 * @v: argumnts in input
 * Return: Nothing.
 */
void put_err(char **p, int loop, int sig, char *v[])
{
	static int pr = 1;


	if (sig == 0)
		pr = 0;
	pr++;
	if (sig == 3)
		pr = 3;
	if (sig == 4)
		pr = 4;
	if (sig == 5)
		pr = 5;
	if (pr == 2 || (pr == 3 && sig == 3) || (pr == 4 && sig == 4)
	    || (pr == 5 && sig == 5))
	{
		write(STDERR_FILENO, v[0], strlen(v[0]));
		write(STDERR_FILENO, ": ", 2);
		print_number(loop);
		write(STDERR_FILENO, ": ", 2);
	}
	if (pr == 2)
		builtinerr(p);
	else if (pr == 3 && sig == 3)
	{
		errorgarbage(p);
		pr = 1;
	}
	else if (pr == 4 && sig == 4)
	{
		write(STDERR_FILENO, p[0], strlen(p[0]));
		write(STDERR_FILENO, ": Permission denied\n", 20);
	}
	else if (pr == 5 && sig == 5)
		builtinerr2(p);
}

/**
 * builtinerr - wites the error
 * @p: iput pointer
 * Return: nothing.
 */
void builtinerr(char **p)
{
	char str1[3] = "cd", str2[5] = "exit", str3[5] = "help";
	int i = 0, j = 0, cont = 0, cont2 = 0;

	while (p[0][j] != '\0')
		j++;
	if (j == 2)
	{
		for (; i < 2; i++)
			if (p[0][i] == str1[i])
				cont++;
		if (cont == 2)
			errorcd(p);
	}
	if (j == 4)
	{
		for (i = 0 ; i < 4; i++)
			if (p[0][i] == str2[i])
				cont++;
		if (cont == 4)
			errorexit(p);
		for (i = 0; i < 4; i++)
			if (p[0][i] == str3[i])
				cont2++;
		if (cont2 == 4)
			errorhelp(p);
	}
}
/**
 * builtinerr2 - writes the error
 * @p: input poiner
 * Return: nothing
 */
void builtinerr2(char **p)
{
	char str1[9] = "unsetenv", str2[7] = "setenv";
	int i = 0, j = 0, cont = 0;

	while (p[0][j] != '\0')
		j++;
	if (j == 8)
	{
		for (; i < 8; i++)
			if (p[0][i] == str1[i])
				cont++;
		if (cont == 8)
			errorenv(p);
	}
	if (j == 6)
	{
		for (; i < 6; i++)
			if (p[0][i] == str2[i])
				cont++;
		if (cont == 6)
			errorenv(p);
	}
}
