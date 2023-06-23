#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"


/**
  * print_a_char - Prints the content of pointer to char type
  * @separator: The separator of the character
  * @args: A list of variadic arguments
  *
  * Return: Nothing
  */
void print_a_char(char *separator, va_list args)
{
	char value = va_arg(args, int);

	printf("%s%c", separator, value);
}

/**
  * print_an_integer - Prints a character of integer type
  * @separator: The separator of the character
  * @args: A list of variadic arguments
  *
  * Return: Nothing
  */

void print_an_integer(char *separator, va_list args)
{
	int value = va_arg(args, int);

	printf("%s%d", separator, value);
}

/**
  * print_a_float - Prints a character of float type
  * @separator: The separator of the character
  * @args: A list of variadic arguments
  *
  * Return: Nothing
  */
void print_a_float(char *separator, va_list args)
{
	double value = va_arg(args, double);

	printf("%s%f", separator, value);
}

/**
  * print_a_char_ptr - Prints the content of pointer to char type
  * @separator: The separator of the character
  * @args: A list of variadic arguments
  *
  * Return: Nothing
  */

void print_a_char_ptr(char *separator, va_list args)
{
	char *value = va_arg(args, char *);
	if (value == NULL)
		printf("%s(nil)", separator);

	else
		printf("%s%s", separator, value);
}

/**
  * print_all - Prints all parameters
  * @format: The conversion specifier to prints
  *
  * Return: Nothing
  */

void print_all(const char * const format, ...)
{
	va_list args;
	f_dt form_types[] = {
		{ "c", print_a_char },
		{ "i", print_an_integer },
		{ "f", print_a_float },
		{ "s", print_a_char_ptr }
	};
	unsigned int i = 0;
	unsigned int j = 0;
	char *separator = "";

	va_start(args, format);

	while (format[i])
	{
		for (j = 0; j < sizeof(form_types) / sizeof(form_types[0]); j++)
		{
			if (format[i] == *(form_types[j].identifier))
			{
				form_types[j].f(separator, args);
				separator = ", ";
				break;
			}
		}
		i++;
	}

	va_end(args);

	printf("\n");
}
