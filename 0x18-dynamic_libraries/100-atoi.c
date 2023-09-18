#include <stdio.h>
#include "main.h"

int positive_or_negative(unsigned int number, int negativeSignCount);

/**
* positive_or_negative - returns a positive or negative
* number.
* @number: integer
* @negativeSignCount: - The number of negative signs.
*
* Return: a positive or negative integer.
*/
int positive_or_negative(unsigned int number, int negativeSignCount)
{
	if (negativeSignCount % 2 != 0)
		number *= -1;
	return (number);
}

/**
* _atoi - converts a string into an integer.
* @s: string
*
* Return: signed integer.
*/
int _atoi(char *s)
{
	int sIndex;
	unsigned int convertedNumber = 0;
	unsigned int *convertedNumberPointer;
	int negativeSignCount = 0;
	int multiplier = 1;

	convertedNumberPointer = &convertedNumber;
	sIndex = 0;
	while (s[sIndex] != '\0')
	{
		if (s[sIndex] >= '0' && s[sIndex] <= '9')
		{
			if (multiplier < 10)
			{
				*convertedNumberPointer = s[sIndex] - '0';
				multiplier *= 10;
			}
			else
			{
				*convertedNumberPointer *= multiplier;
				*convertedNumberPointer += s[sIndex] - '0';
			}
		}
		else
		{
			if (multiplier >= 10)
				break;
			else if (s[sIndex] == '-')
			{
				negativeSignCount++;
			}
		}
		sIndex++;
	}
	if (multiplier == 1)
		return (0);
	convertedNumber = positive_or_negative(convertedNumber, negativeSignCount);
	return (convertedNumber);
}
