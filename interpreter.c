#include "holberton.h"

/**
 * read_line - simple shell command tokenizer
 * Return: void
 */

char *read_line(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	char *comando = NULL;

	bytes_leidos = getline(&comando, &numero_bytes, stdin);

	if (bytes_leidos == EOF)
	{
		write(STDOUT_FILENO, "\n", 2);
		free(comando);
		exit(0);
	}

	comando[bytes_leidos - 1] = '\0';

	return (comando);
}
