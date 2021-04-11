#include "holberton.h"

char *read_line(void)
{
	ssize_t bytes_leidos;
	size_t numero_bytes = 0;
	char *comando = NULL;
	write(STDIN_FILENO, "#cisfun$ ", 10);

	bytes_leidos = getline(&comando, &numero_bytes, stdin);
	comando[bytes_leidos - 1] = '\0';

	if (bytes_leidos == EOF)
	{	
		write(STDIN_FILENO, "\n", 2);
		exit(0);
	}
	
	else if (bytes_leidos == -1)
	{
		write(STDIN_FILENO, "Error.", 7);
	}
	return (comando);
}