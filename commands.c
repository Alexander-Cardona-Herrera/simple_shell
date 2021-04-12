#include "holberton.h"

char **dividir_comandos(char *comando)
{
	int posicion = 0;
	char *token;

	char **tokens = malloc((contar_palabras(comando) + 1) * sizeof(char*));

	if (tokens == NULL)
		return (NULL);

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