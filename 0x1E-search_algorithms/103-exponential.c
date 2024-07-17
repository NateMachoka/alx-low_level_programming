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
 * binary_search - Searches for a value in a sorted array of integers using
 *                 the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @low: Starting index of the subarray to search.
 * @high: Ending index of the subarray to search.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */

int binary_search_range(int *array, size_t low, size_t high, int value)
{
    size_t mid;

    while (low <= high)
    {
        print_array(array, low, high);
        mid = low + (high - low) / 2;
        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, low, high, result;

	if (array == NULL || size == 0)
		return (-1);

	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	result = binary_search_range(array, low, high, value);
	return (result);
}
