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
