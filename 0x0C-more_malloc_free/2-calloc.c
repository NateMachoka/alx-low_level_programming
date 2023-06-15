#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of members in the array
 * @size: size of the array
 *
 * Return: ...
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *array;

	if (nmemb <= 0 || size <= 0)
		return (NULL);

	array = malloc(sizeof(size) * nmemb);

	for (i = 0; i < nmemb; i++)
	{
		array[i] = 0;
	}

	return (array);
}
