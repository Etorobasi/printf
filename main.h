#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

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

/**
 ** struct flag_s - A new type defining a flags struct.
 ** @flag: A character representing a flag.
 ** @value: The integer value of the flag.
 **/
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int printf_percent(void);
int printf_char(va_list val);
int put_char(char c);
int printf_str(va_list args);
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
unsigned char handle_flags(const char *flags, char *index);
#endif
