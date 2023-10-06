#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 * Return: none
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *current = ht->array[i];

		while (current)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			current = current->next;
			first = 0;
		}
	}
	printf("}\n");
}
