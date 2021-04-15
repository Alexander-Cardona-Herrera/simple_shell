#include "holberton.h"

/**
 * built_ins - simple shell built-in commands
 * @command: receives commands to tokenize
 * main - Return
 * Return: void
 */

void built_ins(char *command)
{
	int i = 0;

	if (_strncmp(command, "exit", 5) == 0)
	{
		free(command);
		exit(0);
	}

	if (_strncmp(command, "env", 4) == 0)
	{
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}

	}
}
