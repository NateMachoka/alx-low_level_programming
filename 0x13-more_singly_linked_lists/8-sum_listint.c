#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * sum_listint - prints sum of all data(n) in the linked list
 * @head: head of list
 *
 * Return: 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
