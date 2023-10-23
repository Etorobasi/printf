#include "main.h"

/**
 * printf_str - prints a string
 * @str: string to be printed
 *
 * Return: number of bytes printed to stdout
 */
int printf_str(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0, len = 0, i;

	if (str == NULL)
		str = "(null)";
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		count += put_char(str[i]);
	}
	return (count);
}
