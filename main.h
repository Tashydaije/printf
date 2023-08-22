#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct handler - A new type defining a conversion handler struct
 * @specifier: A char representing a conversion specifier
 * @handler: A pointer to a conversion handler func for a specifier
 */

typedef struct handler_s
{
	unsigned char specifier;
	unsigned int (*handler)(va_list arg);
} handler_t;


/* prototypes for used functions */
int _printf(const char *format, ...);

unsigned int handle_char(va_list arg);
unsigned int handle_string(va_list arg);
unsigned int handle_percent(va_list arg);
unsigned int handle_di(va_list arg);
unsigned int handle_binary(va_list arg);
unsigned int handle_ui(va_list arg);

#endif
