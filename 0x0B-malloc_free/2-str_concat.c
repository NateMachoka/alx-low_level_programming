#include <stdlib.h>
#include "main.h"

/**
 * str_concat - a function that concatates two strings
 * @s1: first string
 * @s2: string to append
 *
 * Return: concat string
 */

char *str_concat(char *s1, char *s2)
{
	size_t i = 0, j = 0, k = 0;
	size_t l = 0;
	char *new_str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i])
		i++;

	while (s2[j])
		j++;

	l = i + j;
	new_str = malloc((sizeof(char) * l) + 1);

	if (new_str == NULL)
		return (NULL);

	for (k = 0; k < l; k++)
	{
		if (k < i)
			new_str[k] = s1[k];

		else
		{
			new_str[k] = s2[k - i];
		}
	}

	new_str[k] = '\0';

	return (new_str);
}
