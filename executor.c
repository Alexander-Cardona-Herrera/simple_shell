#include "holberton.h"
#include <sys/stat.h>

int process_ejecutables(char **tokens)
{
	pid_t pid;
	char *token = tokens[0];
	char **paths;
	char *fullpath;
	struct stat st;
	pid = fork();
	wait(NULL);
	int i = 0;
	fullpath = _path();
	paths = dividir_path(fullpath);
	char *aux;
	
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
		}
		
		else if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("Error");
			exit(0);
		}
		free(paths);
	}
}
