#include "holberton.h"

char **dividir_comandos(char *comando)
{
	int posicion = 0;
	char **tokens = malloc((contar_palabras(comando) + 1) * sizeof(char*));
	char *token;
	token = strtok(comando, " \t\r\n");

	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		token = strtok(NULL, " \t\r\n");
	}
	tokens[posicion] = NULL;
	return tokens;
}