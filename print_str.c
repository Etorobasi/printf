#include "main.h"

/**
 * printf_str - prints a string
 * @str: string to be printed
 *
 * Return: number of bytes printed to stdout
 */
int printf_str(char *str)
{
	int count = 0, len = 0;

	if (str == NULL)
		str = "(null)";
	len = strlen(str);
	count += write(1, str, len);
	return (count);
}
