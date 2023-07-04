#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: head of linked list
 *
 * Return: pointer to first node
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev;
	listint_t *current;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (NULL);

	prev = NULL;
	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}
