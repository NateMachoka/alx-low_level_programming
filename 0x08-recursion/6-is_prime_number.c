#include <stdio.h>
#include "main.h"

/**
 * is_prime_number_helper - checks if a number is prime or not
 * @n: number to check if prime or not
 * @divisor: divisor used to check
 *
 * Return: 1 if prime, 0 if composite
 */

int is_prime_number_helper(int n, int divisor)
{
	if (divisor <= 1)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_prime_number_helper(n, divisor - 1));
}

/**
 * is_prime_number - returns if the number is prime
 * @n: number to check
 *
 * Return: integer value
 */

int is_prime_number(int n)
{
	int divisor;

	if (n <= 1)
		return (0);

	divisor = n - 1;
	return (is_prime_number_helper(n, divisor));
}
