#include "holberton.h"

/**
 * main - entry point.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *comando;
	char **tokens;
	int status = 1;

	signal(SIGINT, control_c);

	if (isatty(STDIN_FILENO) == 1)
		while (status)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 10);
			comando = read_line();
			built_ins(comando);
			tokens = dividir_comandos(comando);
			process_ejecutables(tokens);
			free(comando);
			free(tokens);
		}
	else
		{
		comando = read_line();
		built_ins(comando);
		tokens = dividir_comandos(comando);
		process_ejecutables(tokens);
		free(comando);
		free(tokens);
		}

	return (0);
}
