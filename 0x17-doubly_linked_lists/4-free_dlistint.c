#include "lists.h"

/**
 * free_dlistint - a function that frees a dlistint_t list.
 * @head: a pinter to the head of a list
 *
 * Return: none
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
