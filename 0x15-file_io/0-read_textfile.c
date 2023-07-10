#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
  * read_textfile - reads a text file and prints it to the POSIX stdout
  * @filename: The source file
  * @letters: Number of letters to reads and prints
  *
  * Return: actual number of letters it could read and print.
  * 0 if file is NULL, can't be opened, or fals to write expected amount
  * of bytes
  */

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t bytesRead;
	ssize_t bytesWritten;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");

	if (file == NULL)
		return (0);
	buffer = (char *)malloc((letters + 1) * sizeof(char));

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	bytesRead = fread(buffer, sizeof(char), letters, file);
		if (bytesRead <= 0)
		{
			fclose(file);
			free(buffer);
			return (0);
		}
	bytesWritten = fwrite(buffer, sizeof(char), bytesRead, stdout);

	if (bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	fclose(file);
	free(buffer);

	return (bytesWritten);
}
