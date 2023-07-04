#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts node at a given position
 * @head: head of list
 * @idx: index where new node should be added
 * @n: value of new index
 * Return: address of new node, NULL on failure
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current;
	listint_t *previous;
	unsigned int count;
	listint_t *new_node = (listint_t *)malloc(sizeof(listint_t));

	if (head == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	previous = NULL;
	count = 0;

	while (current != NULL && count < idx)
	{
		previous = current;
		current = current->next;
		count++;
	}
	if (count < idx)
		return (NULL);

	new_node->next = current;
	previous->next = new_node;

	return (new_node);
}
