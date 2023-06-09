#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments passed through the program
 *
 * Return: 0 success, 1 error
 */

int main(int argc, char *argv[])
{
	int i;
	int mul = 1;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		mul *= atoi(argv[i]);
	}

	printf("%d\n", mul);

	return (0);
}
