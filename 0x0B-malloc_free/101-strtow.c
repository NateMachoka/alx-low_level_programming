#include <stdlib.h>
#include "main.h"

/**
 * countWords - Counts the number of words in a string
 * @str: Input string
 *
 * Return: Number of words in the string
 */

int countWords(char *str)
{
	int wordCount = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
		{
			i++;
		}

		if (str[i] != '\0')
		{
			wordCount++;

			while (str[i] != '\0' && str[i] != ' ')
			{
				i++;
			}
		}
	}

	return (wordCount);
}

/**
 * freeWords - Frees the memory allocated for the array of words
 * @words: Pointer to the array of words
 * @wordCount: Number of words in the array
 */

void freeWords(char **words, int wordCount)
{
	int i;

	for (i = 0; i < wordCount; i++)
	{
		free(words[i]);
	}
	free(words);
}

/**
 * extractWords - Extracts words from a string and stores them in an array
 * @str: Input string
 * @wordCount: Number of words in the string
 *
 * Return: Pointer to the array of words, NULL if malloc fails
 */

char **extractWords(char *str, int wordCount)
{
	int i = 0, j = 0;
	int wordIndex = 0;
	char **words;
	int wordLen;

	words = malloc((wordCount + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
		{
			i++;
		}
		if (str[i] != '\0')
		{
			int start = i;

			while (str[i] != '\0' && str[i] != ' ')
			{
				i++;
			}
			wordLen = i - start;
			words[wordIndex] = (char *)malloc((wordLen + 1) * sizeof(char));
			if (words[wordIndex] == NULL)
			{
				freeWords(words, wordIndex);
				return (NULL);
			}
			for (j = 0; j < wordLen; j++)
			{
				words[wordIndex][j] = str[start + j];
			}
			words[wordIndex][wordLen] = '\0';
			wordIndex++;
		}
	}
	words[wordIndex] = NULL;
	return (words);
}

/**
 * strtow - Splits a string into words
 * @str: Input string to split
 *
 * Return: Pointer to an array of strings (words)
 */

char **strtow(char *str)
{
	int wordCount;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	wordCount = countWords(str);
	if (wordCount == 0)
		return (NULL);

	words = extractWords(str, wordCount);

	return (words);
}
