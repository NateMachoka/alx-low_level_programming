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
	unsigned char opcode;
	int byte_count = 0;

	FILE *file = fopen("a.out", "rb");
		if (file == NULL)
		{
			printf("Error: Unable to open binary file\n");
			exit(1);
		}

	while (fread(&opcode, sizeof(unsigned char), 1, file) && byte_count <
	       num_bytes)
	{
		printf("%02x ", opcode);
		byte_count++;
	}

	fclose(file);
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
