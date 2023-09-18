#include "main.h"

/**
* _strncat - concatenates two strings.
* @dest: The destination string.
* @src: The source string.
* @n: The maximum number of bytes to copy from source string.
*
* Return: A pointer to the destination string.
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, length = 0;

	while (dest[length] != '\0')
		length++;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[length + i] = src[i];
	dest[length + i] = '\0';

	return (dest);
}
