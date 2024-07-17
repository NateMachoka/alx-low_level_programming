#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list
 *             of integers using the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present or head is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, prev_index;
	listint_t *prev, *current;

	if (list == NULL || size == 0)
		return NULL;

	jump = (size_t)sqrt(size);
	prev = NULL;
	current = list;

	while (current->index < size && current->n < value)
	{
		prev = current;
		prev_index = current->index;
		for (size_t i = 0; current->next && i < jump; i++)
			current = current->next;
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev_index, current->index);
	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return prev;
		prev = prev->next;
	}
	return NULL; // Value not found
}
