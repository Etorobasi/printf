#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int putts(char *c);
int put_char(char c);
int _printf(const char *format, ...);
int printf_int(va_list args);
int printf_dec(va_list args);
#endif
