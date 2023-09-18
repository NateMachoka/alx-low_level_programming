#include "main.h"

/**
* _puts - prints a string to stdout.
* @str: address of the string
*
* Return: void
*/
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i++]);
	}
	_putchar('\n');
}
