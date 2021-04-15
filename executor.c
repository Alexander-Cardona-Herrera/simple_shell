#include "holberton.h"
/**
 * executable_processes - this process creates the child processes and executes
 * @tokens: tokens
 * @route: executor
 * @count: number of entries
 */
void executable_processes(char **tokens, char *route, int count)
{
	pid_t pid;
	int count2 = 0;
	char *token = tokens[0], *fullpath = NULL, *aux = NULL, *copy_path;
	char **paths = NULL;
	struct stat st;

	built_ins(token);
	pid = fork();
	fullpath = _path();
	copy_path = _strdup(fullpath);
	paths = split_path(copy_path);
	if (pid == 0)
	{
		if (tokens[0] != NULL && token[0] != '/')
		{
			while (paths[count2] != NULL)
			{
				aux = str_concat(paths[count2], tokens[0]);
				if (stat(aux, &st) == 0)
					execve(aux, tokens, NULL);
				count2++;
			}
			if (stat(aux, &st) == -1)
			{
				_perror(tokens[0], route, count);
				free(aux);
				exit(0);
			}
		}
		else if (execve(tokens[0], tokens, environ) == -1 && token[0] != '\n')
		{
			_perror(tokens[0], route, count);
			free(tokens);
			exit(0);
		}
	}
	wait(NULL);
	free(token);
	free(aux);
	free(paths);
}
