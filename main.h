#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 ** struct format - match the conversion specifiers for printf
 ** @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 ** @f: type pointer to function for the conversion specifier
 **
 **/

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int putts(char *c);
int put_char(char c);
int _printf(const char *format, ...);
int printf_int(va_list args);
int printf_dec(va_list args);
int printf_unsigned(va_list args);
int printf_oct(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
#endif
