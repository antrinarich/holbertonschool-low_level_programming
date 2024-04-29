#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an
 * unsigned int
 * @b: bit to convert
 * Return: the converted number or 0 if there is one char not 0 or 1,
 * or if b is null
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int index = 0;

	if (b == NULL)
		return (0);

	while (b[index] != '\0')
	{
		if (b[index] == '1')
		{
			result = result * 2 + 1;
		}
		else if (b[index] == '0')
		{
			result *= 2;
		}
		else
		{
			return (0);
		}
		index++;
	}

	return (result);

}