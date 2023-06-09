#include <stdio.h>
#include "main.h"

/**
 * main - a program that prints its name
 * @argv: the arguments passed in the program
 * @argc: number of arguments
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s\n", argv[0]);

	return (0);
}
