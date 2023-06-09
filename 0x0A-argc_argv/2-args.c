#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments passed in the program
 *
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
