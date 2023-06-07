#include <stdio.h>
#include "main.h"

/**
 * _sqrt_helper - a helper function that performs a recursive binary search
 * @n: number for which square root is to be found
 * @start: starting point of search range
 * @end: ending point of search range
 * Return: square root, or -1
 */

int _sqrt_helper(int n, int start, int end)
{
	int mid;
	int square;

	if (start > end)
	{
		return (-1);
	}

	mid = (start + end) / 2;
	square = mid * mid;

	if (square == n)
	{
		return (mid);
	}
	else if (square > n)
	{
		return (_sqrt_helper(n, start, mid - 1));
	}
	else
	{
		return (_sqrt_helper(n, mid + 1, end));
	}
}

/**
 * _sqrt_recursion - entry point for calculating natural sqrt
 * @n: the number foe which the square root is to be found
 *
 * Return: square root value, or error
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (_sqrt_helper(n, 0, n));
}
