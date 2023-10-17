#include "main.h"

/**
 * putts - writes a string to stdout
 * @c: string to be written
 *
 * Return: returns the total number of bytes written to stdout
 */
int putts(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			put_char(c[count]);
		}
	}
	return (count);
}
