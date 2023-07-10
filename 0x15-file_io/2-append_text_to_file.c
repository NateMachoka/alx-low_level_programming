#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 if file exist. .-1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	char *ch;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		file = fopen(filename, "r");
		if (file == NULL)
		{
			return (-1);
		}
		else
		{
			fclose(file);
			return (1);
		}
	}

	file = fopen(filename, "a");

	if (file == NULL)
	{
		return (-1);
	}

	ch = text_content;

	while (*ch != '\0')
	{
		fputc(*ch, file);
		ch++;
	}

	fclose(file);
	return (1);
}
