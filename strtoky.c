#include "shell.h"

/**
 * _search_char - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if found, 0 if not
 */
int _search_char(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cuts a string into tokens depending on the delimiters
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *last;
	int i = 0, j = 0;

	if (!s)
		s = last;
	while (s[i] != '\0')
	{
		if (!_search_char(d, s[i]) && s[i + 1] == '\0')
		{
			last = s + i + 1;
			*last = '\0';
			s = s + j;
			return (s);
		}
		else if (!_search_char(d, s[i]) && !_search_char(d, s[i + 1]))
			i++;
		else if (!_search_char(d, s[i]) && _search_char(d, s[i + 1]))
		{
			last = s + i + 1;
			*last = '\0';
			last++;
			s = s + j;
			return (s);
		}
		else if (_search_char(d, s[i]))
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

/**
 * _strtoky2 - function tokenization with ;
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky2(char *s, char *d)
{
	static char *last;
	int i = 0, j = 0;

	if (!s)
		s = last;
	while (s[i] != '\0')
	{
		if (!_search_char(d, s[i]) && s[i + 1] == '\0')
			i++;
		else if (!_search_char(d, s[i]) && !_search_char(d, s[i + 1]))
			i++;
		else if (!_search_char(d, s[i]) && _search_char(d, s[i + 1]))
		{
			last = s + i + 1;
			*last = '\0';
			last++;
			s = s + j;
			return (s);
		}
		else if (_search_char(d, s[i]))
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

