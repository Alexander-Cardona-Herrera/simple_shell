#include "holberton.h"

/**
 * _perror - prints the right error
 * @tokens: tokens
 * Return: void
 */
void _perror(char *tokens)
{
char *a, *b;

a = str_concat((tokens + 1), ": ");
b = str_concat("shell: ", a);
write(STDOUT_FILENO, b, _strlen(b));
perror("");
}

/**
 * control_c - this procces check nulls control+c
 * @sign: int
 * Return: void
 */
void control_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, control_c);
}
