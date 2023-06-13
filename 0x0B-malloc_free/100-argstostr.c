#include <stdlib.h>

/**
 * argstostr - converts arguments paseed in the program to strings
 * @ac: argument count
 * @av: argument vector
 *
 * Return: ...
 */

char *argstostr(int ac, char **av)
{
	int total_length = 0;
	int i, j, k;
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			total_length++;
		}
		total_length++;
	}
	result = (char *)malloc(sizeof(char) * (total_length + ac + 1));
	if (result == NULL)
		return (NULL);

	k = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[k] = av[i][j];
			k++;
		}
		result[k] = '\n';
		k++;
	}
	result[k] = '\0';

	return (result);
}
