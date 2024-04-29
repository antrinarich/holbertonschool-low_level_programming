#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @n: an integer
 * @index: index of the bit to extract
 * Return: the value of the bit or -1 if an error occured
*/
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}