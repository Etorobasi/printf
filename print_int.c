#include "main.h"
/**
 * printf_int - prints integer
 * @args: argument to print
 * Return: number of character printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
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
#include "main.h"
/**
 * printf_dec - prints decimal number in the printf function created
 * @args: argument to print
 * Return: number of character printed
 */
int printf_dec(va_list args)
{
	int n = va_arg(args, int);
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
