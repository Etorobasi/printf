#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
int printf_str(char *str);
int _printf(const char *format, ...);
int printf_int(va_list args);
int printf_dec(va_list args);
int printf_u(va_list args);
int printf_oct(va_list val);
int printf_HEX(va_list val);
int printf_hex(va_list val);
int printf_bin(va_list val);
int printf_S(va_list args);
int printf_newHEX(unsigned int num);
int printf_pointer(va_list args);
int printf_newHex(unsigned long int num);
int printf_rot(va_list args);
int printf_strrev(va_list args);
int _strlenx(const char *s);
int str_len(char *s);
#endif
