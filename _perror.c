#include "holberton.h"

void _perror(char *tokens)
{
char *a, *b;

a = str_concat((tokens + 1), ":");
b = str_concat("shell: ", a);
write (STDOUT_FILENO, b, _strlen(b));
write (STDOUT_FILENO, " command not found \n", 20);
}
