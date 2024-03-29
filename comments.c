#include "shell.h"

/**
 * semicolon - searcn the input there is a ";" or a ";;"
 * @line: coete input of user
 * @loop: nur of actual loop
 * @argv: int argument
 * Return: 1  find ";" or ";;" or 0 if not
 */
int semicolon(char *line, int loop, char **argv)
{
	int valid = 0, cont = 0;

	while (line[cont] != '\0')
	{
		if (line[0] == ';')
		{
			valid = 1;
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			print_number(loop);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Syntax error: ", 14);
			write(STDERR_FILENO, ";", 1);
			write(STDERR_FILENO, " unexpected\n", 12);
			break;
		}
		if (line[cont] == ';' && line[cont + 1] == ';')
		{
			valid = 1;
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			print_number(loop);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Syntax error: ", 14);
			write(STDERR_FILENO, ";;", 2);
			write(STDERR_FILENO, " unexpected\n", 12);
			break;
		}
		cont++;
	}
	return (valid);
}
/**
 *_comments - remove commentaries
 *@line: input of user
 * Return: the new input
 */
char *_comments(char *line)
{
	int a = 0, c = 0, flag = 0;

	while (line[c] != '\0')
		c++;
	while (line[a] != '\0')
	{
		if (line[0] == '#')
		{
			flag = 1;
			break;
		}
		if (line[a] == '#' && line[a - 1] == ' ')
		{
			flag = 1;
			break;
		}
		a++;
	}
	if (flag == 1)
	{
		for (; a < c; a++)
			line[a] = 0;
	}
	return (line);
}
