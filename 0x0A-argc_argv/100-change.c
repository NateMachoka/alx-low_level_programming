#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - calculates minimum of coins needed to make change
 * for an amount of money
 * @argc: number of arguments passed in the program
 * @argv: an array of pointers to the arguments
 *
 * Return: -1 if the number of arguments is not exactly one, otherwise 0
 */

int main(int argc, char *argv[])
{
	int cents, coins, i;
	int coinValues[] = {25, 10, 5, 2, 1};
	int numCoinValues = sizeof(coinValues) / sizeof(coinValues[0]);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	coins = 0;
	for (i = 0; i < numCoinValues; i++)
	{
		coins += cents / coinValues[i];
		cents %= coinValues[i];
	}

	printf("%d\n", coins);
	return (0);
}
