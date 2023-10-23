#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: given character string
 *
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	convert_match p[] = {
		{"%s", printf_str}, {"%S", printf_S},
		{"%i", printf_int}, {"%d", printf_dec},
		{"%x", printf_hex}, {"%X", printf_HEX},
		{"%u", printf_u}, {"%b", printf_bin},
		{"%c", printf_char}, {"%%", printf_percent},
		{"%r", printf_strrev}, {"%R", printf_rot},
		{"%p", printf_pointer}, {"%o", printf_oct}
	};

	int i = 0, j, count = 0;
	va_list forms;

	va_start(forms, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (p[j].id[0] == format[i] && p[j].id[1] == format[i + 1])
			{
				count += p[j].f(forms);
				i += 2;
				goto Here;
			}
			j--;
		}
		put_char(format[i]);
		count++;
		i++;
	}
	va_end(forms);
	return (count);
}
