#include "holberton.h"

/**
 * built_ins - simple shell built-in commands
 * @comando: receives commands to tokenize
 * main - Return
 * Return: void
 */

void built_ins(char *comando)
{
	int i = 0;

	if (_strncmp(comando, "exit", 5) == 0)
	{
		free(comando);
		exit(0);
	}

	if (_strncmp(comando, "env", 4) == 0)
	{
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}

	}
}
