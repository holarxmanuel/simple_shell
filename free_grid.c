#include "shell.h"
/**
 * free_grid - fe a matrix
 * @grid: it s the matrix
 * @height: hight of the matrix
 * Return: nothing
 */
void free_grid(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
