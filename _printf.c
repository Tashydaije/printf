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
<<<<<<< HEAD
<<<<<<< HEAD
		 {'u', handle_ui}
=======
		 {'o', handle_octal}
>>>>>>> ea8c28e3d351102e9f4e9720eda96fbec9ba2f5c
=======
		 {'u', handle_ui}
>>>>>>> 1af838adc2af8137aae3fb097660a2377e092081
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
