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
	/*no output signal with control c*/
	signal(SIGINT, control_c);
	while (status) /*provided that 1*/
	{
		/*indicates whether the file descriptor is connected to a terminal or not*/
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		/*reading the commands*/
		bytes_read = getline(&command, &number_bytes, stdin);

		if (bytes_read == EOF) /*output with D control*/
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				write(STDOUT_FILENO, "\n", 2);
			}
			free(command); /*free up memory when exiting*/
			exit(0);
		}
		/*terminated in null and not in line break*/
		command[bytes_read - 1] = '\0';
		count++;
		/*count the number of times a command is entered*/
		tokens = split_commands(command);
		executable_processes(tokens, ruta, count, command);
		/*freeing up memory*/
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		free(tokens);
	}
	free(command);
	return (0);
}
