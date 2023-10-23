#include "main.h"

/**
 * print_format - formats string
 * @specifier: identifier to be converted
 * @forms: pointer to argument specifiers
 *
 * Return: number of characters printed
int print_format(char specifier, va_list forms)
{
	int count = 0;

	if (specifier == '%')
		count += put_char('%');
	else if (specifier == 'c')
		count += put_char(va_arg(forms, int));
	else if (specifier == 's')
		count += printf_str(va_arg(forms, char *));
	else if (specifier == 'd')
		count += printf_dec(forms);
	else if (specifier == 'i')
		count += printf_int(forms);
	else if (specifier == 'u')
		count += printf_u(forms);
	else if (specifier == 'x')
		count += printf_hex(forms);
	else if (specifier == 'X')
		count += printf_HEX(forms);
	else if (specifier == 'o')
		count += printf_oct(forms);
	else if (specifier == 'b')
		count += printf_bin(forms);
	else if (specifier == 'S')
		count += printf_S(forms);
	else if (specifier == 'p')
		count += printf_pointer(forms);
	else if (specifier == 'R')
		count += printf_rot(forms);
	else
	{
		put_char('%');
		write(1, &specifier, 1);
		count += 2;
	}
	return (count);
}
*/
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
