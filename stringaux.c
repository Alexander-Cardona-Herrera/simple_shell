#include "holberton.h"

/**
 * _strncmp - function that compares two strings
 * @string1: first variable to compare
 * @string2: second variable to compare
 * @number: size
 * main - Return
 * Return: void
 */

int _strncmp(char *string1, char *string2, size_t number)
{
	size_t count;

	for (count = 0; count < number; count++)
	{
		int aux1 = 0;
		int aux2 = 0;

		if (string1[count] == string2[count])
		{
			if (count == (number - 1))
				return (0);
		}
		aux1 = (int) string1[count];
		aux2 = (int) string2[count];

		if (aux1 > aux2)
			return (1);
		if (aux2 > aux1)
			return (-1);
	}
	return (0);
}

/**
 * count_words - function that counts words
 * @string: sentence containing the words to count
 * main - Return
 * Return: void
 */

int count_words(char *string)
{
	int cont1, cont2 = 0;

	for (cont1 = 0; string[cont1]; cont1++)
	{
		if (string[cont1] == 32 && string[cont1 + 1] != 32 && string[cont1 + 1] != 0)
			count2++;
	}

	if (string[0] != 32)
		count2++;

	return (count2);
}

/**
 * str_concat - function that concatenates two strings
 * @string1: first word to concatenate
 * @string2: second word to concatenate
 * main - Return
 * Return: void
 */

char *str_concat(char *string1, char *string2)
{
	char *aux;
	int count1, count2, count3;

	if (string1 == NULL)
		string1 = "";

	if (string2 == NULL)
		string2 = "";

	for (count1 = 0; string1[count1] != '\0'; count1++)
	{
	}
	count1++;

	for (count2 = 0; string2[count2] != '\0'; count2++)
	{
	}
	count2++;

	aux = malloc((count1 + count2) * sizeof(char));

	if (!aux)
		return (NULL);

	for (count3 = 0; string1[count3] != '\0'; count3++)
		aux[count3] = string1[count3];

	aux[count3++] = '/';

	for (count3 = 0; string2[count3] != '\0'; count3++)
		aux[count1 + count3] = string2[count3];

	return (aux);
}

/**
 * _strdup - function that duplicates a strings
 * @str: strings to duplicate
 * main - Return
 * Return: void
 */

char *_strdup(char *str)
{
	char *aux;
	int count1;
	int count2;

	if (str == 0)
		return (NULL);

	for (count1 = 0; str[count1] != '\0'; count1++)
	{
	}
	count1++;

	aux = malloc((count1 + 1) * sizeof(char));

	if (!aux)
		return (NULL);

	for (count2 = 0; count2 < count1; count2++)
		aux[count2] = str[count2];

	return (aux);
}

/**
 * _strlen - function that returns size of a string
 * @string: string
 * main - Return
 * Return: void
 */

int _strlen(char *string)
{
	int count;

	for (count = 0; *string != '\0'; count++)
		{
		string++;
		}
	return (count);
}
