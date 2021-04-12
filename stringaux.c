#include "holberton.h"

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == s2[i])
		{
			if (i == (n - 1))
				return (0);
		}

		int a1 = (int) s1[i];
		int a2 = (int) s2[i];

		if (a1 > a2)
			return (1);
		if (a2 > a1)
			return (-1);
	}
	return (0);
}

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

	aux = malloc((i + k - 1) * sizeof(char));

	if (!aux)
		return (NULL);

	for (j = 0; s1[j] != '\0'; j++)
		aux[j] = s1[j];

	for (j = 0; s2[j] != '\0'; j++)
		aux[i - 1 + j] = s2[j];

	return (aux);
}

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

	aux = malloc(i * sizeof(char));

	if (!aux)
		return (NULL);

	for (j = 0; j < i; j++)
		aux[j] = str[j];

	return (aux);
}

int _strlen(char *s)
{
	int c;

	for (c = 0; *s != '\0'; c++)
		{
		s++;
		}
	return (c);
}
