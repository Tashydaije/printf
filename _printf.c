#include "main.h"

/**
 * _printf -  function that produces output according to a format
 * @format: A character string
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int printed_chars = 0;
	const char *ptr = format;

	handler_t handlers[] = {
		 {'c', handle_char},
		 {'s', handle_string},
		 {'%', handle_percent,},
		 {'d', handle_di},
		 {'i', handle_di},
		 {'b', handle_binary},
		 {'o', handle_octal}
	};
	if (ptr == NULL)
		return (-1);

	va_start(args, format);

	while (*ptr)
	{
		unsigned int found_handler = 0;

		if (*ptr != '%')
		{
			write(1, ptr, 1);
			printed_chars++;
		} else
		{
			ptr++;

			if (*ptr)
			{
				unsigned long int i;

				for (i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++)
				{
					if (*ptr == handlers[i].specifier)
					{
						printed_chars += handlers[i].handler(args);
						found_handler = 1;
						break;
					}
				}
			}
			if (!found_handler)
			{
				write(1, "%", 1);
				printed_chars++;
			}
			if (*ptr == '\0')
				break;
		}
		ptr++;
	}
	va_end(args);
	return (printed_chars);
}
