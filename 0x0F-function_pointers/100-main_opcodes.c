#include <stdio.h>
#include <stdlib.h>

/**
  * print_opcodes - ...
  * @num_bytes: ...
  *
  * Return: ...
  */

#include <stdio.h>
#include <stdlib.h>

void print_opcodes(int num_bytes)
{
	unsigned char *ptr = (unsigned char *)__builtin_return_address(0);
	int i;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x ", ptr[i]);
	}

	printf("\n");
}

/**
 * main - ...
 * @argc: ...
 * @argv: ...
 *
 * Return: ...
 */

int main(int argc, char *argv[])
{
	int num_bytes;

	if (argc != 2)
	{
		printf("Error: Incorrect number of arguments\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error: Number of bytes cannot be negative\n");
		return (2);
	}

	print_opcodes(num_bytes);

	return (0);
}
