#include "holberton.h"

void built_ins(char *comando)
{
    char *fullpath;
    char **paths;
    int i;

	if(_strncmp(comando, "exit", 5) == 0)
	{
        free(comando);
   		exit(0);
    }

    if(_strncmp(comando, "env", 4) == 0)
	{
        int i = 0;
        char *aux = NULL;

        while (environ[i] != NULL)
        {
            write(STDOUT_FILENO, environ[i], strlen(environ[i]));
            write(STDOUT_FILENO, "\n", 1);
            i++;
        }
	}
    
    /*	if (tokens[0] == "\n" && tokens[1] == NULL)
		read_line();*/
}