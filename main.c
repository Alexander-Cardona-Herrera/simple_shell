#include "holberton.h"

int main(void)
{
	char *comando;
	char **tokens;
	int status = 1;
	/*signal(SIGINT, control_c);*/
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

/*void control_c(void)
	{
		signal(SIGINT, control_c);
		fflush(stdout);
	}
	*/


