#include "holberton.h"

/**
 * main - entry point.
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0.
 */

int main(int __attribute__((unused))argc, char **argv)
{
	char *comando = NULL;
	char **tokens = NULL;
	int status = 1;
	char *ruta = argv[0];
	int contador = 0;


		signal(SIGINT, control_c);

		while (status)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "#cisfun$ ", 10);

			comando = read_line();
			contador++;
			tokens = dividir_comandos(comando);
			process_ejecutables(tokens, ruta, contador);
			free(comando);
			free(tokens);
		}

	return (0);
}
