#include "shell.h"

/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of bytes
 * Return: pointer to the newly reallocated memory block
 */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = _calloc(new_size, sizeof(char));
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
		p = _calloc(new_size, sizeof(char));
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = ptr[i];
		free(ptr);
	}
	else
	{
		p = _calloc(new_size, sizeof(char));
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = ptr[i];
		free(ptr);
	}

	return (p);
}

