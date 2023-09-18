#include <stdio.h>
#include "main.h"

/**
* _strcpy - copies the second string argument onto the first one.
* @dest: destination string;
* @src: source string
*
* Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int n = 0;

	while (*src && *(src + n) != '\0')
	{
		dest[n] = *(src + n);
		n++;
	}
	dest[n] = '\0';

	return (dest);
}
