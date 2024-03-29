#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to delete (starting from 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}
	for (i = 0; current != NULL; i++)
	{
		if (i == index)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			free(current);
			return (1);
		}
		current = current->next;
	}
	return (-1);
}
