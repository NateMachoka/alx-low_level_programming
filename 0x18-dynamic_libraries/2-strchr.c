#include "main.h"

/**
* *_strchr - locates a character in a string
* @s: The string to search.
* @c: A character to search.
*
* Return: A pointer to the location of the found character, otherwise NULL
*/
char *_strchr(char *s, char c)
{
	char *ptr;
	unsigned int i;

	ptr = s;
	for (i = 0; *ptr != c && ptr[i + 1] != '\0'; i++)
	{
		ptr++;
	}

	return (s + i);
}
