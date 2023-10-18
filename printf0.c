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

	unsigned int len = 0, count = 0;
	char c, *str;
	va_list forms;

	va_start(forms, format);
	if (format == NULL || *(format++) == '\0')
		return (-1);
	while (*format && *format != '\0')
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '%')
			{
				count += write(1, format, 1);
			}
			else if (*format == 'c')
			{
				c = va_arg(forms, int);
				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
			str = va_arg(forms, char *);
			len = strlen(str);
			count += write(1, str, len);
			}
		}
		format++;
	}
	va_end(forms);
	return (count);
}
