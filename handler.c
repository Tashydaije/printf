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

/**
 * handle_binary - prints an unsigned int in binary
 * @arg: list of arg pionting to an unsigned int to print
 *
 * Return: number of chars printed
 */

unsigned int handle_binary(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;
	int i;
	char *binary;
	unsigned int len;
	int num_bits = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (temp > 0)
	{
		temp >>= 1;
		num_bits++;
	}

	binary = (char *)malloc(num_bits + 1);

	if (!binary)
	{
		write(1, "Memory allocation failed\n", 24);
		return (1);
	}

	for (i = num_bits - 1; i >= 0; i--)
	{
		binary[i] = (num & 1) + '0';
		num >>= 1;
	}
	binary[num_bits] = '\0';

	write(1, binary, num_bits);
	len = num_bits;

	free(binary);
	return (len);
}
