#include "shell.h"

/**
 * strlen - returns e length of a string.
 * @s: string
 * Return: Always 0.
 */
int strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
