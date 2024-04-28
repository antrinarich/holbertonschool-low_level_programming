#include "lists.h"

/**
 * dlistint_len - funtion that returns the number of elements in a linked
 * list
 * @h : dobble linked list of integer
 * Return: number of elements
*/
size_t dlistint_len(const dlistint_t *h)
{
	int nbElements = 0;

	while (h && h->prev)
		h = h->prev;

	while (h)
	{
		nbElements++;
		h = h->next;
	}

	return (nbElements);
}