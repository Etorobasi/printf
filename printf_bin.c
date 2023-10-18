#include "main.h"
#include <stdlib.h>
/**
 * printf_bin - prints a binary number.
 * @val: arguments.
 * Return: 1
 */
int printf_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			put_char(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		put_char('0');
	}
	return (cont);
}
