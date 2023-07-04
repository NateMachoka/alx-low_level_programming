#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 * @head: head
 *
 * Return: address of the node where loop staets, NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (head == NULL || head->next == NULL)
		return (NULL);

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		{
			if (slow == fast)
			{
				slow = head;
			}
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			printf("Loop starts at [%p] %d\n", (void *)slow,
			       slow->n);
			return (slow);
		}
	}

	return (NULL);
}
