#include "main.h"

/**
 * print_format - formats string
 * @specifier: identifier to be converted
 * @forms: pointer to argument specifiers
 *
 * Return: number of characters printed
 */
int print_format(char specifier, va_list forms)
{
	int len = 0, count = 0;
	char *str;

	if (specifier == '%')
		count += put_char('%');
	else if (specifier == 'c')
		count += put_char(va_arg(forms, int));
	else if (specifier == 's')
	{
		str = va_arg(forms, char *);
		if (str == NULL)
			str = "(null)";
		len = strlen(str);
		count += write(1, str, len);
	}
	else
	{
		put_char('%');
		write(1, &specifier, 1);
		count += 2;
	}
	return (count);
}
/**
 * _printf - produces output according to a format
 * @format: given character string
 *
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{

	unsigned int count = 0;
	va_list forms;

	va_start(forms, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				return (-1);
			}
			else
				count += print_format(*format, forms);
		}
		format++;
	}
	va_end(forms);
	return (count);
}
