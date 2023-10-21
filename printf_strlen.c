#include "main.h"
/**
 * str_len - Returns the length of a string.
 * @s: type char pointer
 * Return: x.
 */
int str_len(char *s)
{
	int x;

	for (x = 0; s[x] != 0; x++)
		;
	return (x);
}
/**
 * _strlenx - strlen function applied to cons char pointer s
 * @s: type char pointer
 * Return: x
 */
int _strlenx(const char *s)
{
	int x;

	for (x = 0; s[x] != 0; x++)
		;
	return (x);
}
