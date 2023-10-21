#include "main.h"
#include <stdlib.h>
/**
 * printf_newHex - prints an hexadecimal number
 * @num: number to be printed
 * Return: counter.
 */
int printf_newHex(unsigned long int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		put_char(array[i] + '0');
	}
	free(array);
	return (counter);
}
