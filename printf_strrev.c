#include "main.h"
/**
 * printf_strrev - func that prints a string in reverse
 * Aargs: type struc va_arg
 * Return: the string
 */
int printf_strrev(va_list args)
{
	char *s = va_arg(args, char*);
	int x;
	int y = 0;

	if (s == NULL)
		s = "(null)";
	while (s[y] != '\0')
		y++;
	for (x = y - 1; x >= 0; x--)
		put_char(s[x]);
	return (y);
}
