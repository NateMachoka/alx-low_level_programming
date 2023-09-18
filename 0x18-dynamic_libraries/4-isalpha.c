#include "main.h"

/**
 * _isalpha - Checks if a charcter is alphabetic [a-zA-Z]
 * @c: An integer representing an alphabetic character
 *
 * Description: Checks if a character is lowercase or uppercase alphabetic
 * Return: 1 if alphabetic, 0 otherwise.
 */
int _isalpha(int c)
{
	if ((unsigned char) c >= 97 && ((unsigned char) c) <= 122)
	{
		return (1);
	}
	else if ((unsigned char) c >= 65 && ((unsigned char) c) <= 90)
	{
		return (1);
	}
		return (0);
}
