#include "holberton.h"

/**
 * _perror - Error message
 * @tokens: comandos tokenizados
 * @route: executable name
 * @count: count
 * Return: void
 */

void _perror(char *tokens, char *route, int count)
{
	char *string; /*stores the number converted to string*/
	char str[5];  /*buffer itoa*/

	/*converting number to string*/
	string = my_itoa(count, str, 10);

	write(STDOUT_FILENO, route, _strlen(route));
	write(STDOUT_FILENO, ": ", 3);
	write(STDOUT_FILENO, string, _strlen(string));
	write(STDOUT_FILENO, ": ", 3);
	write(STDOUT_FILENO, tokens, _strlen(tokens));
	write(STDOUT_FILENO, ": not found", 13);
}

/**
 * control_c - not to get out with control c
 * @sign: handle signals
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
 * @number: comandos tokenizados
 * @str: comandos tokenizados
 * @base: comandos tokenizados
 * Return: strings
 */

char *my_itoa(int number, char *str, int base)
{
	int count = 0;

	if (number == 0)
	{
		str[count] = '0';
		str[count + 1] = '\0';
		return (str);
	}

	if (number < 0 && base == 10)
	{
		number = -number;
	}

	while (number != 0)
	{
		int rem = number % base;

		str[count++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		number = number / base;
	}

	str[count] = '\0';

	my_reverse(str, count);

	return (str);
}

/**
 * my_reverse - Error message
 * @string: comandos tokenizados
 * @length: comandos tokenizados
 * Return: void
 */

void my_reverse(char *string, int length)
{
	int start, end;
	char temp;

	for (start = 0, end = length - 1; start < end; start++, end--)
	{
		temp = *(string + start);
		*(string + start) = *(string + end);
		*(string + end) = temp;
	}
}
