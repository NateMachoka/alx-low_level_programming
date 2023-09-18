#include "main.h"

/**
* *_strpbrk - searches for a substring match in a string if any
* character matches.
* @s: The string to search.
* @accept: The substring to search for.
*
* Return: a pointer to the byte in s that matches a byte
* in accept, otherwise NULL
*/
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;
	char *ptr;

	ptr = s;

	while (*ptr)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*ptr == accept[i])
			{
				return (ptr);
			}
		}
		ptr++;
	}
	return (0);
}
