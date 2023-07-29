#include "shell.h"

/**
 * _strlen - returnslength of a string.
 * @s: strig
 * Return: Aays 0.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
