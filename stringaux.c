#include "holberton.h"

/**
 * _strncmp - function that compares two strings
 * @s1: first variable to compare
 * @s2: second variable to compare
 * @n: size
 * main - Return
 * Return: void
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		int a1 = 0;
		int a2 = 0;

		if (s1[i] == s2[i])
		{
			if (i == (n - 1))
				return (0);
		}
		a1 = (int) s1[i];
		a2 = (int) s2[i];

		if (a1 > a2)
			return (1);
		if (a2 > a1)
			return (-1);
	}
	return (0);
}

/**
 * contar_palabras - function that counts words
 * @frase: sentence containing the words to count
 * main - Return
 * Return: void
 */

int contar_palabras(char *frase)
{
	int i, count = 0;

	for (i = 0; frase[i]; i++)
	{
		if (frase[i] == 32 && frase[i + 1] != 32 && frase[i + 1] != 0)
			count++;
	}

	if (frase[0] != 32)
		count++;

	return (count);
}

/**
 * str_concat - function that concatenates two strings
 * @s1: first word to concatenate
 * @s2: second word to concatenate
 * main - Return
 * Return: void
 */

char *str_concat(char *s1, char *s2)
{
	char *aux;
	int i, j, k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
	{
	}
	i++;

	for (k = 0; s2[k] != '\0'; k++)
	{
	}
	k++;

	aux = malloc((i + k) * sizeof(char));

	if (!aux)
		return (NULL);

	for (j = 0; s1[j] != '\0'; j++)
		aux[j] = s1[j];

	aux[j++] = '/';

	for (j = 0; s2[j] != '\0'; j++)
		aux[i + j] = s2[j];

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
	int i;
	int j;

	if (str == 0)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
	}
	i++;

	aux = malloc((i + 1) * sizeof(char));

	if (!aux)
		return (NULL);

	for (j = 0; j < i; j++)
		aux[j] = str[j];

	return (aux);
}

/**
 * _strlen - function that returns size of a string
 * @s: string
 * main - Return
 * Return: void
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; *s != '\0'; c++)
		{
		s++;
		}
	return (c);
}
