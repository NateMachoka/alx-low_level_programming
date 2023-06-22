#include "variadic_functions.h"
#include <stdarg.h>

/**
  * sum_them_all - returns the sum of all its parameters
  * @n: parameters to sum
  *
  * Return: ...
  */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	va_list args;
	int value;
	unsigned int i;

	if (n == 0)
		return (0);

	sum = 0;
	va_start(args, n);

	for (i = 0; i < n; ++i)
	{
		value = va_arg(args, int);
		sum += value;
	}

	va_end(args);
	return (sum);
}
