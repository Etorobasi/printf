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
	va_list forms;
	int count = 0;
	char c, *str;

	if (format == NULL || (*format == '%' && *format++ == '\0'))
		return (-1);
	va_start(forms, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(forms, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(forms, char *);
				write(1, str, strlen(str));
				count += strlen(str);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
		}
		format++;
	}
	va_end(forms);
	return (count);
}
