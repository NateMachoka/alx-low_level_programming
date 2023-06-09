#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments passed through the program
 *
 * Return: 0 success
 */

int main(int argc, __attribute__((unused)) char *argv[])
{
	int num_args = argc - 1;

	printf("%d\n", num_args);
	return (0);
}
