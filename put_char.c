#include "main.h"

/**
 * put_char - writes the character c to stdout
 * @c: character to be written
 *
 * Return: 1 on success
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
