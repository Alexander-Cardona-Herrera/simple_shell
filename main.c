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
	
	while (status)
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

void control_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, control_c);
}
