#include "holberton.h"

/**
 * _perror - Error message
 * @tokens: comandos tokenizados
 * @ruta: comandos tokenizados
 * @contador: comandos tokenizados
 * Return: void
 */

void _perror(char *tokens, char *ruta, int contador)
{
int j = 0;
char *string;
char str[j];

if (contador % 10 < 1 && contador < 10)
	j = 2;
if (contador % 100 < 1 && contador < 100 && contador >= 10)
	j = 3;
if (contador % 1000 < 1 && contador < 1000 && contador >= 100)
	j = 4;
string = my_itoa(contador, str, 10);

write(STDOUT_FILENO, ruta, _strlen(ruta));
write(STDOUT_FILENO, ": ", 3);
write(STDOUT_FILENO, string, _strlen(string));
write(STDOUT_FILENO, ": ", 3);
write(STDOUT_FILENO, tokens, _strlen(tokens));
write(STDOUT_FILENO, ": ", 3);
perror("");

}

/**
 * control_c - Error message
 * @sign: comandos tokenizados
 * Return: void
 */

void control_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, control_c);
}

/**
 * my_itoa - Error message
 * @num: comandos tokenizados
 * @str: comandos tokenizados
 * @base: comandos tokenizados
 * Return: strings
 */

char *my_itoa(int num, char *str, int base)
{
	int i = 0;

	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}

	if (num < 0 && base == 10)
	{
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / base;
	}

	str[i] = '\0';

	my_reverse(str, i);

	return (str);
}

/**
 * my_reverse - Error message
 * @str: comandos tokenizados
 * @len: comandos tokenizados
 * Return: void
 */

void my_reverse(char *str, int len)
{
	int start, end;
	char temp;

	for (start = 0, end = len - 1; start < end; start++, end--)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}
