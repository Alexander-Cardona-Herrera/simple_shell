# ifndef HOLBERTON_H
# define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>


/*interpreter file prototypes*/
char *read_line(void);

/*built ins file prototypes*/
void built_ins(char *comando);


/*string aux file prototypes*/
int _strncmp(char *s1, char *s2, size_t n);
int contar_palabras(char *frase);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *s);

/*command aux file prototypes*/
void _perror(char *tokens, char *ruta, int contador);
void my_reverse (char str [], int len);
char * my_itoa (int num, char * str, int base);

/*paths file prototypes*/
char *_path(void);
char **dividir_path(char *aux);
extern char **environ;

/*commands file prototypes*/
char **dividir_comandos(char *comando);
void control_c(int sign);

/*executor file prototypes*/
void process_ejecutables(char **tokens, char *ruta, int contador);

# endif
