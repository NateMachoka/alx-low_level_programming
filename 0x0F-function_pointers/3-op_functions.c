#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add - Adds two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * subtract - Subtracts two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * multiply - Multiplies two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * divide - Divides two integers
 * @a: The first integer (dividend)
 * @b: The second integer (divisor)
 *
 * Return: The quotient of a divided by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * modulo - Computes the modulo of two integers
 * @a: The first integer (dividend)
 * @b: The second integer (divisor)
 *
 * Return: The remainder of a divided by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
