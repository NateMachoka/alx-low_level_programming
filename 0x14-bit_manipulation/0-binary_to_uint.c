#include <stdlib.h>

/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 * @b:binary string to convert
 *
 * Return: unsigned number converted from binary, 0 if b iS NULL
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int result;
	int i;

	if (b == NULL)
		return (0);

	result = 0;
	i = 0;

	while (b[i] != '\0')
	{
		if (b[i] == '0')
		{
			result <<= 1;
		}
		else if (b[i] == '1')
		{
			result = (result << 1) | 1;
		}
		else
		{
			return (0);
		}
		i++;
	}

	return (result);
}
