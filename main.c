#include "holberton.h"

/**
 * main - entry point.
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0.
 */

int main(int __attribute__((unused))argc, char **argv)
{
	char *command = NULL;
	char **tokens = NULL;
	int status = 1;
	char *ruta = argv[0];
	int count = 0;


		signal(SIGINT, control_c);

		while (status)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "#cisfun$ ", 10);

			command = read_line();
			count++;
			tokens = split_commands(command);
			executable_processes(tokens, ruta, count);
			free(command);
			free(tokens);
		}

	return (0);
}
