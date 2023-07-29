#include "shell.h"
/**
 * realloc - chane the size and copy the content
 * @ptr: malloc ponter to reallocate
 * @old_size: old number of bytes
 * @new_size: new umber of Bytes
 * Return: nothing */
void *realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
