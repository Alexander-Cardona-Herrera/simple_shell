# ifndef HOLBERTON_H
# define HOLBERTON_H
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>


/*interpreter file prototypes*/
char *read_line(void);

/*built ins file prototypes*/
void built_ins(char *command);


/*string aux file prototypes*/
int _strncmp(char *string1, char *string2, size_t number);
int count_words(char *string);
char *str_concat(char *string1, char *string2);
char *_strdup(char *str);
int _strlen(char *string);

/*command aux file prototypes*/
void _perror(char *tokens, char *route, int count);
void my_reverse(char *string, int length);
char *my_itoa(int num, char *str, int base);

/*paths file prototypes*/
char *_path(void);
char **split_path(char *aux);
extern char **environ;

/*commands file prototypes*/
char **split_commands(char *command);
void control_c(int sign);

/*executor file prototypes*/
void executable_processes(char **tokens, char *route, int count);

# endif
