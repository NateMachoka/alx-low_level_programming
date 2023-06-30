#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - prins all the elements of a list
 * @h: a linked list
 *
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	if (h == NULL)
	{
		printf("[0] (nil)\n");
		return (count);
	}

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%lu] %s\n", (unsigned long)_strlen
			       (h->str), h->str);
		}

		count++;
		h = h->next;
	}

	return (count);
}

/**
 * free_list - frees memory allocated to linked list
 * @h: a linked list
 *
 * Return: ...
 */

void free_list(list_t *h)
{
	while (h != NULL)
	{
		list_t *temp = h;

		h = h->next;
		free(temp->str);
		free(temp);
	}
}

/**
  * _strlen - Returns the length of a string
  * @s: String to count
  *
  * Return: String length
  */
int _strlen(char *s)
{
	int c = 0;

	for (; *s != '\0'; s++)
	{
		c++;
	}

	return (c);
}
