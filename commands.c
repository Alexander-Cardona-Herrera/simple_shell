#include "holberton.h"

/**
 * split_commands - simple shell command tokenizer
 * @command: passed commands
 * Return: char double pointer
 */
char **split_commands(char *command)
{
	int position = 0;
	char *token = NULL;
	char **tokens = NULL;
	/*allocate memory to pointer tokens*/
	tokens = malloc((count_words(command) + 1) * sizeof(char *));

	if (tokens == NULL)
		return (NULL);

	/* pointer receiving tokenized command*/
	token = strtok(command, " \t\r\n");

	/*as long as tokens is different from null it makes a copy of token in token*/
	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		/*end in null*/
		token = strtok(NULL, " \t\r\n");
		position++;
	}
	tokens[position] = NULL;

	return (tokens);
}
