#include "main.h"
/**
 * printf_u - prints unsigned integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last = n % 10, digit, exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		put_char('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			put_char(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	put_char(last + '0');
	return (i);
}