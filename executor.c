#include "holberton.h"
/**
 * executable_processes - this process creates the child processes and executes
 * @tokens: tokenized commands
 * @route: executor
 * @count: number of entries
 * @command: command
 */
void executable_processes(char **tokens, char *route, int count, char *command)
{
	int check = 0; /*check if any error occurred*/
	char *token = tokens[0];
	/*run builtint*/
	built_ins(tokens, command);
	/*evaluates if tokens is not null and does not include path /bin/ls*/
	if (tokens[0] != NULL && token[0] != '/')
	{
		check = without_path(tokens); /*if it is -1 it throws the error message*/
		if (check == -1)
			_perror(tokens[0], route, count);
	}
	else /*when it includes path*/
	{
		/*if it is -1 it throws the error message*/
		check = with_path(tokens);
		if (check == -1)
			_perror(tokens[0], route, count);
	}
}
/**
 * with_path - this process creates the child processes and executes
 * @tokens: tokenized commands
 * Return: int file status
 */
int with_path(char **tokens)
{
	pid_t pid; /*child process*/
	/*parse if it is executable or not with stat*/
	if (stat(tokens[0], &st) == 0)
	{
		/*create child process*/
		pid = fork();
		if (pid == 0) /*if it is the child process run*/
			execve(tokens[0], tokens, environ);
		/*the parent process waits for the child processes to finish*/
		wait(NULL);
		return (0); /*on success, return (0)*/
	}
	/*if it is not executable it returns (-1)*/
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
	pid_t pid; /*child process*/
	char *fullpath = NULL, *aux = NULL, *copy_path;
	char **paths = NULL;

	fullpath = _path();			   /*fullpath receives the path of the function*/
	copy_path = _strdup(fullpath); /*copy of fullpath*/
	paths = split_path(copy_path); /*path receives the split path from copypath*/

	while (paths[count] != NULL)
	{
		/*as long as path is different from null, concatenate*/
		/*the tokenized command with the path*/

		/*aux stores the command with the patch concatenated*/
		aux = str_concat(paths[count], tokens[0]);
		if (stat(aux, &st) == 0)
		{
			pid = fork(); /*create child process*/
			if (pid == 0) /*if it is the child process run*/
				execve(aux, tokens, NULL);
			/*the parent process waits for the child processes to finish*/
			wait(NULL);
			free(aux); /*freeing up memory*/
			for (i = 0; paths[i] != NULL; i++)
				free(paths[i]);
			free(paths);
			free(copy_path);
			return (0); /*on success, return (0)*/
		}
		free(aux);
		aux = NULL;
		count++;
	}
	for (i = 0; paths[i] != NULL; i++) /*freeing up memory in case of error*/
		free(paths[i]);
	free(paths);
	free(copy_path);
	return (-1); /*if it is not executable it returns (-1)*/
}
