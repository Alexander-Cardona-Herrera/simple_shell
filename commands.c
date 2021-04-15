#include "holberton.h"

/**
 * split_commands - simple shell command tokenizer
 * @command: passed commands
 * main - Return
 * Return: void
 */
char **split_commands(char *command)
{
	int position = 0;
	char *token = NULL;
	char **tokens = NULL;

	tokens = malloc((count_words(command) + 1) * sizeof(char *));

	if (tokens == NULL)
		return (NULL);

	token = strtok(command, " \t\r\n");

	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		token = strtok(NULL, " \t\r\n");
		position++;
	}
	tokens[position] = NULL;

	return (tokens);
}
