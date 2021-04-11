# ifndef HOLBERTON_H
# define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*main file prototypes*/
void repetir_acciones(void);

/*interpreter file prototypes*/
char *read_line(void);

/*built ins file prototypes*/
void built_ins(char *comando);

/*string aux file prototypes*/
int _strncmp (char *s1, char *s2, size_t n);
int contar_palabras(char *frase);
char *str_concat(char *s1, char *s2);


/*paths file prototypes*/
extern char** environ;
char *_path(void);
char **dividir_path(char *aux);

/*commands file prototypes*/
char **dividir_comandos(char *comando);

/*executor file prototypes*/
int process_ejecutables(char **tokens);

# endif
