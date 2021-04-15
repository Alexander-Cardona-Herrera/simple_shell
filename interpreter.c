#include "holberton.h"

/**
 * read_line - simple shell command tokenizer
 * Return: void
 */

char *read_line(void)
{
	ssize_t bytes_read;
	size_t number_bytes = 0;
	char *command = NULL;

	bytes_read = getline(&command, &number_bytes, stdin);

	if (bytes_read == EOF)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 2);
		free(command);
		exit(0);
	}

	command[bytes_read - 1] = '\0';

	return (command);
}
