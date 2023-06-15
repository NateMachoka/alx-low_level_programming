#include <stdlib.h>
#include <stdio.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: string to append
 * @n: number of characters to append from s2
 *
 * Return: pointer to the newly allocated concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, k = 0, l = 0;
	char *new_str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i])
		i++;
	while (s2[k])
		k++;

	if (n >= k)
		l = i + k;
	else
		l = i + n;

	new_str = malloc(sizeof(char) * (l + 1));

	if (new_str == NULL)
		return (NULL);

	for (k = 0; k < l; k++)
	{
		if (k < i)
		{
			new_str[k] = s1[k];
		}
		else
		{
			new_str[k] = s2[j];
			j++;
		}
	}

	new_str[k] = '\0';
	return (new_str);
}
