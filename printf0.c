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
	va_list forms;

	va_start(forms, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				put_char(va_arg(forms, int));
				count++;
			}
			else if (*format == 's')
			{
			len += putts(va_arg(forms, char *));
			count += (len - 1);
			}
		}
		format++;
	}
	va_end(forms);
	return (count);
}
