#include "main.h"

/**
* _strcmp - compares two strings in lexical order.
* @s1: The first string.
* @s2: The second string.
*
* Return: 0 if the strings are equal, otherwise the lexical (alphabetical)
* difference in the order of the strings.
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			continue;
		}
		break;
	}
	return (*s1 - *s2);
}
