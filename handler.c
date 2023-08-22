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

unsigned int handle_percent(va_list arg)
{
	(void)arg;
	{
		char c = '%';

		write(1, &c, 1);
		return (1);
	}
}

/**
 * handle_di - prints an integer/decimal
 * @arg: list of arg pointing to int/decimal to print
 *
 * Return: len of digits
 */

unsigned int handle_di(va_list arg)
{
	int num = va_arg(arg, int);

	int num_copy = num;
	int temp;
	int num_digits = 1;
	int i;
	char *digits;
	unsigned int len = 0;

	if (num_copy < 0)
	{
		write(1, "-", 1);
		len++;
		num_copy = -num_copy;
	}
	temp = num_copy;

	while (temp >= 10)
	{
		temp /= 10;
		num_digits++;
	}

	digits = malloc(num_digits * sizeof(char));

	if (!digits)
	{
		write(1, "Memory allocation failed\n", 24);
		return (1);
	}

	for (i = num_digits - 1; i >= 0; i--)
	{
		digits[i] = num_copy % 10 + '0';
		num_copy /= 10;
	}
	write(1, digits, num_digits);
	len += num_digits;
	free(digits);
	return (len);
}
