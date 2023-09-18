#include "main.h"

/**
* _strncpy - copies a string
* @dest: The destination string.
* @src: The source string.
* @n: The maximum number of bytes to copy from source string.
*
* Return: A pointer to the destination string.
*/
char *_strncpy(char *dest, char *src, int n)
{
	char *destCopy = dest;

	while (*dest)
	{
		if (n == 0)
			break;
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = '\0';
		n--;
	}

	return (destCopy);
}
