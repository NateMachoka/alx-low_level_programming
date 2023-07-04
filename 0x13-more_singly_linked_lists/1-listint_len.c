#include <stddef.h>
#include "lists.h"

/**
 * listint_len gives number of elements in a linked list
 * @h: head of linked list
 * Return: number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return(count);
}
