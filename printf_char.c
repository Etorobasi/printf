#include "main.h"

/**
 * printf_char - formats the conversion specifier 'c'
 * @val: arguments
 *
 * Return: number of bytes printed
 */
int printf_char(va_list val)
{
	char s;
	int count = 0;

	s = va_arg(val, int);
	count += put_char(s);
	return (count);
}
