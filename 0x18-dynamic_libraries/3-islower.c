#include "main.h"

/**
 * _islower - Checks if a charcter is lowercase or uppercase.
 * @c: An integer representing an alphabetic character
 *
 * Description: Checks if a character is lowercase or uppercase.
 * Return: 1 if lowercase, else 0 if not lowercase.
 */
int _islower(int c)
{
	if ((unsigned char) c >= 97 && ((unsigned char) c) <= 122)
	{
		return (1);
	}
	return (0);
}
