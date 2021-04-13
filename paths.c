#include "holberton.h"

/**
 * _path - tells where executable programs are located on the system
 * main - Return
 * Return: void
 */

char *_path(void)
{
	int i = 0;
	char *aux = NULL;

	while (environ[i] != NULL)
	{
		if (!_strncmp(environ[i], "PATH=", 5))
		{
			aux = environ[i] + 5;
		}
		i++;
	}
	return (aux);
}

/**
 * dividir_path - tokenize the path
 * @aux: contains information on the path to tokenize
 * main - Return
 * Return: void
 */

char **dividir_path(char *aux)
{
	int posicion = 0;
	int i;
	int conteo = 1;
	char *aux1 = NULL;
	char *path = NULL;

	for (i = 0; aux[i] != '\0'; i++)
	{
		if (aux[i] == ':')
			conteo++;
	}
	char **paths = malloc((conteo + 2) * sizeof(char *));
	if (paths != NULL)
	{
		aux1 = _strdup(aux);
		path = strtok(aux1, ":");

		while (path != NULL)
		{
			paths[posicion] = path;
			posicion++;
			path = strtok(NULL, ":");
		}
		paths[posicion] = NULL;
	}
	free(aux1);
	return (paths);
}
