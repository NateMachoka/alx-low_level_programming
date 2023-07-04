#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a linked list
 * @head: head of list
 *
 * Return: number of nodes in list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		if (head <= head->next)
		{
			printf("-> [%p] %d\n", (void *)head->next, head->
			       next->n);
			break;
		}

		head = head->next;
	}

	return (count);
}
