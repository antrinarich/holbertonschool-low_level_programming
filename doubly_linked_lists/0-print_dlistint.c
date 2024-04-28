#include "lists.h"

/**
 * print_dlistint - function that prints all the elements of
 * a dlistin_t list
 * @h: list of int elements to print
 * Return: number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t nbNode = 0;

	if (!h)
		return (0);

	while (h && h->prev)
		h = h->prev;

	while (h)
	{
		printf("%d\n", h->n);
		nbNode++;
		h = h->next;
	}

	return (nbNode);
}