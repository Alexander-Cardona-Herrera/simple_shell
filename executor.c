#include "holberton.h"

/**
 * executable_processes - this process creates the child processes and executes
 * @tokens: tokens
 * @route: executor
 * @count: number of entries
 * @command: command
 */
void executable_processes(char **tokens, char *route, int count, char *command)
{
	int check = 0;
	char *token = tokens[0];

	built_ins(tokens, command);

	if (tokens[0] != NULL && token[0] != '/')
	{
		check = without_path(tokens);
		if (check == -1)
			_perror(tokens[0], route, count);
	}
	else
	{
		check = with_path(tokens);
		if (check == -1)
			_perror(tokens[0], route, count);
	}
}

/**
 * with_path - this process creates the child processes and executes
 * @tokens: tokens
 * Return: int
 */

int with_path(char **tokens)
{
	pid_t pid;

	if (stat(tokens[0], &st) == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(tokens[0], tokens, environ);
		wait(NULL);
		return (0);
	}
	return (-1);
}

/**
 * without_path - this process creates the child processes and executes
 * @tokens: tokens
 * Return: int
 */

int without_path(char **tokens)
{
	int count = 0;
	int i;
	pid_t pid;
	char *fullpath = NULL, *aux = NULL, *copy_path;
	char **paths = NULL;

	fullpath = _path();
	copy_path = _strdup(fullpath);
	paths = split_path(copy_path);

	while (paths[count] != NULL)
	{
		aux = str_concat(paths[count], tokens[0]);
		if (stat(aux, &st) == 0)
		{
			pid = fork();
			if (pid == 0)
				execve(aux, tokens, NULL);
			wait(NULL);
			free(aux);
			for (i = 0; paths[i] != NULL; i++)
				free(paths[i]);
			free(paths);
			free(copy_path);

			return (0);
		}
		free(aux);
		aux = NULL;
		count++;
	}
	for (i = 0; paths[i] != NULL; i++)
		free(paths[i]);
	free(paths);
	free(copy_path);
	return (-1);
}
