#include "holberton.h"
#include <sys/stat.h>

void process_ejecutables(char **tokens)
{
	pid_t pid;
	int i = 0;
	char *token = tokens[0], *fullpath, *aux;
	char **paths;
	struct stat st;

	pid = fork();
	wait(NULL);

	fullpath = _path();
	paths = dividir_path(fullpath);

	if (pid == 0)
	{
	
		if (tokens[0] != NULL && token[0] != '/')
		{
			tokens[0] = str_concat("/", tokens[0]);
			while (paths[i] != NULL)
			{
				aux = str_concat(paths[i], tokens[0]);
				if (stat(aux, &st) == 0)
				{
					execve(aux, tokens, NULL);
				}
				i++;
			}
			if (stat(aux, &st) == -1)
			perror("Error");
			free(aux);
			exit(0);
		}
		else if (execve(tokens[0], tokens, environ) == 0 && token[0] != '\n')
		{
			perror("Error");
			free(tokens);
			exit(0);
		}
		free(paths);
	}
}
