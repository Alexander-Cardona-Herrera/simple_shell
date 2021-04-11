#include "holberton.h"

int main()
{
  repetir_acciones();
  return 0;
}

void repetir_acciones(void)
{
  	char *comando;
  	char **tokens;
  	int status = 1;
	
	while (status)
	{	
		comando = read_line();
    built_ins(comando);
		tokens= dividir_comandos(comando);
		status = process_ejecutables(tokens);
		free(comando);
		free(tokens);
  }
}
