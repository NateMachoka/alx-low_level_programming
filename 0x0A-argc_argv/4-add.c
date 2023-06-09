#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * is_digit - checks if character is a number
 * @c: character to check
 *
 * Return: if character is digit
 */

int is_digit(char c)
{
	return (c >= 48 && c <= 57);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments passed in the program
 *
 * Return: 0 success, 1 failure
 */

int main(int argc, char *argv[])
{
	int i;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		char *num = argv[i];
		int is_valid = 1;

		while (*num)
		{
			if (!is_digit(*num))
			{
				is_valid = 0;
				break;
			}
			num++;
		}

		if (!is_valid)
		{
			printf("Error\n");
			return (1);
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
