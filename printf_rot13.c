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
		for (j = 0; norm[j]; j++)
		{
			if (s[i] == norm[j])
			{
				put_char(rot[j]);
				counter++;
			}
		}
			else
			{
				put_char('%');
				put_char('R');
				counter += 2;
			}
		}
	}
	return (counter);
}
