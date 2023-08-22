#include "main.h"

/**
 * handle_char - prints a char
 * @arg: list of arg pointing to char to be printed
 *
 * Return: 1
 */

unsigned int handle_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

/**
 * handle_string - prints a string
 * @arg: list of arg pointing to integer to be printed
 *
 * Return: the length of the string
 */

unsigned int handle_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	unsigned int len = 0;

	if (str)
	{
		while (str[len])
		{
			len++;
		}
		write(1, str, len);
	}
	return (len);
}

/**
 * handle_percent - prints the '%' sign
 * @arg: list of arg pointing to '%' sign to print
 *
 * Return: 1
 */

unsigned int handle_percent()
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}
