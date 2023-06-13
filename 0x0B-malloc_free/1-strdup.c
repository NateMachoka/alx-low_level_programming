#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointyer to duplicated string
 */

char *_strdup(char *str)
{
	char *new_str;
	size_t i;
	size_t len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	len++;

	new_str = malloc(len * sizeof(char));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}
