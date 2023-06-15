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
	unsigned int i, j;
	char *array;
	char *char_array;

	if (nmemb <= 0 || size <= 0)
		return (NULL);

	array = malloc(size * nmemb);

	char_array = array;

	for (i = 0; i < nmemb; i++)
	{
		for (j = 0; j < size; j++)
		{
			char_array[i * size + j] = 0;
		}
	}

	return (array);
}
