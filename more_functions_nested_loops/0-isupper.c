#include "main.h"
/**
 *  _isupper - Write a function that checks for uppercase character
 *@c: the char to check
 * Return:0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
