#include "holberton.h"

int _strncmp (char *s1, char *s2, size_t n)
{
	int i;

	for(int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
        {
            if(i == (n-1))
                return 0;
        }

        int a1 = (int) s1[i];
        int a2 = (int) s2[i];
		
        if(a1 > a2)
            return 1;
        if(a2 > a1)
            return -1;
    }
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
