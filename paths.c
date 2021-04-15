#include "holberton.h"

/**
 * _path - tells where executable programs are located on the system
 * main - Return
 * Return: void
 */

char *_path(void)
{
	int count = 0;
	char *aux = NULL;

	while (environ[count] != NULL)
	{
		if (!_strncmp(environ[count], "PATH=", 5))
		{
			aux = environ[count] + 5;
		}
		count++;
	}
	return (aux);
}

/**
 * split_path - tokenize the path
 * @aux: contains information on the path to tokenize
 * main - Return
 * Return: void
 */

char **split_path(char *aux)
{
	int position = 0;
	int count1 = 0;
	int count2 = 1;
	char *path = NULL;
	char **paths = NULL;

	for (count1 = 0; aux[count1] != '\0'; count1++)
	{
		if (aux[count1] == ':')
			count2++;
	}
	paths = malloc((count2 + 2) * sizeof(char *));

	if (paths != NULL)
	{

		path = strtok(aux, ":");
		while (path != NULL)
		{
			paths[position] = _strdup(path);
			path = strtok(NULL, ":");
			position++;
		}
		paths[position] = NULL;
	}
	return (paths);
}
