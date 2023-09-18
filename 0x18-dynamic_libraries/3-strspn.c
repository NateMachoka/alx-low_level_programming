#include "main.h"

/**
* _strspn - Counts the number of bytes
* in the initial segement of a string whose
* bytes are in the substring.
*
* @s: The string to search.
* @accept: The substring to search for.
*
* Return: The number of bytes in a string that match a substring.
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, numberOfBytes = 0;

	while (*s)
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				numberOfBytes++;
				break;
			}
			else if (accept[i + 1] == '\0')
				return (numberOfBytes);
		}
		s++;
	}
	return (numberOfBytes);
}
