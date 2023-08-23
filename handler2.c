#include "main.h"

/**
 * handle_ui - prints an usigned integer
 * @arg: list of arg pointing to an unsigned int to print
 *
 * Return: number of chars printed
 */

unsigned int handle_ui(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int num_copy = num;
	int num_digits = 1;
	int i;
	char *digits;
	unsigned int len = 0;

	while (num_copy >= 10)
	{
		num_copy /= 10;
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
		digits[i] = num % 10 + '0';
		num /= 10;
	}

	write(1, digits, num_digits);
	len = num_digits;
	free(digits);
	return (len);
}

/**
 * handle_octal - prints integers in octal format
 * @arg: list of args pointing to octal to print
 *
 * Return: length of octal
 */

unsigned int handle_octal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int temp = num;
	int i;
	char *octal;
	unsigned int len;
	int num_digits = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (temp > 0)
	{
		temp /= 8;
		num_digits++;
	}
	octal = (char *)malloc(num_digits + 1);

	if (!octal)
	{
		write(1, "Memory allocation failed\n", 24);
		return (1);
	}
	for (i = num_digits - 1; i >= 0; i--)
	{
		octal[i] = (num & 7) + '0'; /*extract lowest 3bits*/
		num >>= 3; /*shift right by 3 bits*/
	}
	octal[num_digits] = '\0';

	write(1, octal, num_digits);
	len = num_digits;
	free(octal);
	return (len);
}

/**
 * handle_hexadecimal - prints lower/uppercase hexadecimals
 * @arg: list of args pointing the hexa to print
 * @uppercase: det whether to print upper/lower case
 *
 * Return: length of hexa
 */

unsigned int handle_hexadecimal(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int i;
	char *hex;
	unsigned int len;
	int num_digits = 1;
	unsigned int uppercase = 0;
	char specifier = va_arg(arg, int);

	if (specifier == 'X')
		uppercase = 1;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		num /= 16;
		num_digits++;
	}
	hex = (char *)malloc(num_digits + 1);

	if (!hex)
	{
		write(1, "Memory allocation failed\n", 24);
		return (1);
	}
	for (i = num_digits - 1; i >= 0; i--)
	{
		int digit = va_arg(arg, int);

		if (digit < 10)
			hex[i] = digit + '0';
		else
		{
			if (uppercase)
				hex[i] = digit - 10 + 'A';
			else
				hex[i] = digit - 10 + 'a';
		}
		num >>= 4;
	}
	hex[num_digits] = '\0';
	write(1, hex, num_digits);
	len = num_digits;
	free(hex);
	return (len);
}
