#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * get_nodeint_at_index - gets the nth node of a linked list
 * @head: head of list
 * @index: index of the node
 *
 * Return: NULL if node doesn't exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;

	while (current != NULL && index > 0)
	{
		current = current->next;
		index--;
	}

	if (current != NULL)
	{
		return (current);
	}

	return (NULL);
}
