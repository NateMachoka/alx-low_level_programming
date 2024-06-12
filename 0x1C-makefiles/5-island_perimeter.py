#!/usr/bin/python3
"""
This module contains the function `island_perimeter` which calculates the
perimeter of the island described in a grid. The grid is represented as a
list of lists of integers where 0 represents a water
zone and 1 represents a land zone. The grid is completely surrounded by water
and contains exactly one island without any lakes.
"""

def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in the grid.

    Args:
        grid (list): A list of lists where 0 is water and 1 is land

    Returns:
        int: The perimeter of the island.
    """
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i-1][j] == 1:  # Check cell above
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:  # Check cell to the left
                    perimeter -= 2

    return perimeter
