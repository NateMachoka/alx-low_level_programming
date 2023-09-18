#include "main.h"

/**
 * _abs - Computes absolute value of an integer.
 * @num: integer to get absolute value of.
 *
 * Description: Computes absolute value of an integer
 * Return: The absolute value
 */
int _abs(int num)
{
	if (num < 0)
	{
		num *= -1;
		return (num);
	}
	return (num);
}
