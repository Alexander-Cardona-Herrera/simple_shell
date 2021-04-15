#include "holberton.h"

/**
 * built_ins - simple shell built-in commands
 * @tokens: receives commands to tokenize
 * @command: command
 * main - Return
 * Return: void
 */

void built_ins(char **tokens, char *command)
{
	int i = 0;

	if (_strncmp(tokens[0], "exit", 5) == 0)
	{
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);
		free(command);
		exit(0);
	}

	if (_strncmp(tokens[0], "env", 4) == 0)
	{
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
}
