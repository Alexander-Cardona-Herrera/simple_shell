#include "holberton.h"

/**
 * main - entry point.
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0.
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *command = NULL;
	char **tokens = NULL;
	int status = 1;
	char *ruta = argv[0];
	int count = 0;
	ssize_t bytes_read;
	size_t number_bytes = 0;
	int i;

	signal(SIGINT, control_c);

	while (status)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		else
			status = 0;
		bytes_read = getline(&command, &number_bytes, stdin);
		if (bytes_read == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				write(STDOUT_FILENO, "\n", 2);
				free(command);
				exit(0);
			}
		}
		command[bytes_read - 1] = '\0';

		count++;
		tokens = split_commands(command);
		executable_processes(tokens, ruta, count, command);
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);
		free(command);
	}

	return (0);
}
