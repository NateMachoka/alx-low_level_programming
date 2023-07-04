#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes head of a linked list
 * @head: head of linked list
 *
 * Return: 0 if list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *current;
	int n;

	if (*head == NULL)
	{
		return (0);
	}

	current = *head;
	n = current->n;
	*head = current->next;
	free(current);

	return (n);
}
