#include "main.h"

/**
 * flip_bits - function that return the number ot bits you would
 * need to flip to get from one number to another
 * @n: one number
 * @m: another number
 * Return: number of flip
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int opposite = n ^ m;
	unsigned int count = 0;

	while (opposite != 0)
	{
		count += opposite & 1;
		opposite >>= 1;
	}

	return (count);
}
