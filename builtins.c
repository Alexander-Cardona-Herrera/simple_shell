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
	int count = 0; /*accountant */

	/*compares if the command entered is equal to exit*/
	if (_strncmp(tokens[0], "exit", 5) == 0)
	{
		/*loop tokens to free memory*/
		for (count = 0; tokens[count] != NULL; count++)
			free(tokens[count]);
		free(tokens);
		free(command);
		exit(0);
	}

	/*compares if the command entered is equal to exit*/
	if (_strncmp(tokens[0], "env", 4) == 0)
	{
		while (environ[count] != NULL) /*print enviromen*/
		{
			write(STDOUT_FILENO, environ[count], _strlen(environ[count]));
			write(STDOUT_FILENO, "\n", 1);
			count++;
		}
	}
}
