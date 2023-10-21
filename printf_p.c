#include "main.h"

/**
 * printf_pointer - handles the conversion specifier '%p'
 * @args: argument for formatting
 *
 * Return: the number of bytes printed
 */
int printf_pointer(va_list args)
{
	void *p;
	char *s;
	long int x;
	int y, i;

	s = "(nil)";
	p = va_arg(args, void *);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			put_char(s[i]);
			return (i);
		}
	}
	x = (unsigned long int)p;
	put_char('0');
	put_char('x');
	y = printf_newHex(x);
	return (y + 2);
}
