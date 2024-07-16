#include "search_algos.h"

/**
 * print_array - Prints the array being searched
 * @array: The array to print
 * @left: The left index of the subarray to print
 * @right: The right index of the subarray to print
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	for (i = left; i <= right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The index where value is located, or -1 if value is not
 *         present in the array or if the array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left, right, mid;

	if (array ==  NULL)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		print_array(array, left, right);
		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
