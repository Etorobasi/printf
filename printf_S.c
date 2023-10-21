#include "main.h"

/**
 * printf_S - handles the custom specifier 'S' for formatted printing
 * @args: argument string to be formatted
 *
 * Return: the number of bytes that has been printed
 */
int printf_S(va_list args)
{
	int i, count = 0;
	char *str;
	int value;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			put_char('\\');
			put_char('x');
			count += 2;
			value = str[i];
			if (value < 16)
			{
				put_char('0');
				count++;
			}
			count += printf_newHEX(value);
		}
		else
		{
			put_char(str[i]);
			count++;
		}
	}
	return (count);
}
