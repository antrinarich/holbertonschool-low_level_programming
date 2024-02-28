#include "main.h"
/**
 *swap_int - Write a function that swaps the values of two integers
 *
 *@a: the first
 *@b:the seconde
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;

	*b = temp;
}
