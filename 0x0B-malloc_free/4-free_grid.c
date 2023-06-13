#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a 2D grid
 * @grid: grid to free
 * @height: height of grid
 *
 * Return: Nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
