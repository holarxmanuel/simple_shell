#include "shell.h"

/**
 * free_grid - free a matrix
 * @grid: the matrix to be freed
 * @height: height of the matrix
 * Return: nothing
 */
void free_grid(char **grid, int height)
{
    int i;

    if (grid == NULL)
        return;

    for (i = 0; i < height; i++)
    {
        if (grid[i] != NULL)
            free(grid[i]);
    }
    free(grid);
}

