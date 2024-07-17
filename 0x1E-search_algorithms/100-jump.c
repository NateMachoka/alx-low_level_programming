#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 *               the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev;

	if (array == NULL || size == 0)
		return (-1);

	step = (size_t)sqrt(size);
	prev = 0;

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		if (step >= size)
			break;
		prev = step;
		step += (size_t)sqrt(size);
	}
	step = prev - (size_t)sqrt(size) + 1;
	while (step <= prev && step < size)
	{
		printf("Value checked array[%lu] = [%d]\n", step, array[step]);
		if (array[step] == value)
			return (step);
		step++;
	}
	return (-1);
}
