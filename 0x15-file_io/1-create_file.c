#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	FILE *file;
	size_t length;
	size_t written;

	if (filename == NULL)
		return (-1);

	file = fopen(filename, "w");

	if (file == NULL)
		return (-1);

	if (text_content != NULL)
	{
		length = _strlen(text_content);
		written = fwrite(text_content, sizeof(char), length, file);

		if (written != length)
		{
			fclose(file);
			return (-1);
		}
	}

	fclose(file);

	if (chmod(filename, S_IRUSR | S_IWUSR) != 0)
		return (-1);

	return (1);
}

/**
  * _strlen - Returns the length of a string
  * @str: String to count
  *
  * Return: String length
  */
int _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
