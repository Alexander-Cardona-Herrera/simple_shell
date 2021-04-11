#include "holberton.h"

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

char **dividir_path(char *aux)
{
	int posicion = 0;
    int i;
    int conteo = 1;
	char *aux1;
    char *path;

    for(i = 0; aux[i] != '\0'; i++)
        if (aux[i] == ':')
            conteo++;

	char **paths = malloc((conteo + 1) * sizeof(char*));
	aux1 = strdup(aux);
	path = strtok(aux1, ":");

	while (path != NULL)
	{
		paths[posicion] = path;
		posicion++;
		path = strtok(NULL, ":");
	}
	paths[posicion] = NULL;
	return (paths);
}
