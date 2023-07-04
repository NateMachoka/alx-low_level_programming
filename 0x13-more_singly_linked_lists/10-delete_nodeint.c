#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index in a linked list
 * @head: head of list
 * @index: index of node to delete
 *
 * Return: 1 success, -1 on failure
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *current;
	listint_t *previous;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	previous = NULL;
	count = 0;

	while (current != NULL && count < index)
	{
		previous = current;
		current = current->next;
		count++;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);
	return (1);
}
