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
	int count = 0, str_count, i;

	if (!format || (*format == '%' && *(format++) == '\0'))
		return (-1);
	va_start(forms, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			put_char(format[i]);
			count++;
		}
		else if (format[i + 1] == 'c')
		{
			put_char(va_arg(forms, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			str_count = putts(va_arg(forms, char *));
			i++;
			count += (str_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			put_char('%');
		}
		count += 1;
	}
	va_end(forms);
	return (count);
}
