#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - safely frees a linked list
 * @h: head
 *
 * Return: sized of free'd list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL)
		return (0);

	current = *h;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		count++;

		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (count);
}
