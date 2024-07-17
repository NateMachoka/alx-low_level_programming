#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @low: The starting index of the subarray to print
 * @high: The ending index of the subarray to print
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches for a value in a sorted
 *                             array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @low: Starting index of the subarray to search.
 * @high: Ending index of the subarray to search.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array.
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = low + (high - low) / 2;

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (advanced_binary_recursive(array, low, mid, value));
	}
	if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));

	return (advanced_binary_recursive(array, low, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   using a modified binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
