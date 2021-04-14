#include "holberton.h"
/**
 * process_ejecutables - this process creates the child processes and executes
 * @tokens: tokens
 * @ruta: executor
 * @contador: number of entries
 */
void process_ejecutables(char **tokens, char *ruta, int contador)
{
	pid_t pid;
	int i = 0;
	char *token = tokens[0], *fullpath = NULL, *aux = NULL;
	char **paths = NULL;
	struct stat st;

	pid = fork();
	fullpath = _path();
	paths = dividir_path(fullpath);
	if (pid == 0)
	{
		if (tokens[0] != NULL && token[0] != '/')
		{
			while (paths[i] != NULL)
			{
				aux = str_concat(paths[i], tokens[0]);
				if (stat(aux, &st) == 0)
					execve(aux, tokens, NULL);
				i++;
			}
			if (stat(aux, &st) == -1)
			{
				_perror(tokens[0], ruta, contador);
				free(aux);
				exit(0);
			}
		}
		else if (execve(tokens[0], tokens, environ) == -1 && token[0] != '\n')
		{
			_perror(tokens[0], ruta, contador);
			free(tokens);
			exit(0);
		}
	}
	else
	wait(NULL);
	free(token);
	free(aux);
	free(paths);
}
