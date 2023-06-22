#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
  * print_char - Prints a character of char type
  * @value: ...
  *
  * Return: Nothing
  */
void print_char(char value)
{
	printf("%c", value);
}

/**
  * print_int - Prints a character of integer type
  * @value: ...
  *
  * Return: Nothing
  */

void print_int(int value)
{
	printf("%d", value);
}

/**
  * print_float - Prints a character of float type
  * @value: ...
  *
  * Return: Nothing
  */
void print_float(float value)
{
	printf("%f", value);
}

/**
  * print_str - Prints strimg
  * @value: ...
  *
  * Return: Nothing
  */
void print_str(char *value)
{
	if (value == NULL)
		printf("(nil)");
	else
		printf("%s", value);
}

/**
  * print_all - Prints anything
  * @format: The conversion specifier to prints
  *
  * Return: Nothing
  */

void print_all(const char * const format, ...)
{
	va_list args;
	const char *format_ptr = format;
	int count = 0;

	va_start(args, format);

	while (*format_ptr != '\0' && count < 9)
	{
		if (count > 0)
			printf(", ");

		if (*format_ptr == 'c')
			print_char(va_arg(args, int));
		else if (*format_ptr == 'i')
			print_int(va_arg(args, int));
		else if (*format_ptr == 'f')
			print_float((float)va_arg(args, double));
		else if (*format_ptr == 's')
			print_str(va_arg(args, char *));

		format_ptr++;
		count++;
	}

	va_end(args);

	printf("\n");
}
