#include "main.h"

/**
 * clear_bit - function that sets the value of a bit to 0 at a given index
 * @n: unsigned long int
 * @index: index of the bit to change
 * Return: 1 if it worked or -1 if error
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}