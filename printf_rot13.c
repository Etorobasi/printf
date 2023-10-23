#include "main.h"

/**
 * printf_rot - prints the rot13'ed string
 * @args: arguments
 *
 * Return: number of bytes printed
 */
int printf_rot(va_list args)
{
	int i, j, k = 0, counter = 0;
	char *s = va_arg(args, char *);
	char norm[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char rot[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; norm[j] && !k; j++)
		{
			if (s[i] == norm[j])
			{
				put_char(rot[j]);
				counter++;
				k = 1;
			}
		}
		if (!k)
		{
			put_char(s[i]);
			counter++;
		}
	}
	return (counter);
}
