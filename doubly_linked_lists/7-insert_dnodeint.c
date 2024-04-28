#include "lists.h"

/**
 * insert_dnodeint_at_index - function that inserts a new node at a
 * given position
 * @h: pointer to the head node
 * @idx: index of the list where the new node should be add
 * @n: n int value of the new node
 * Return: address of the new node
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int indexOfCurrentNode = 0;
	dlistint_t *newData, *current;

	if (idx == 0) /*insert at the begining*/
		return (add_dnodeint(h, n));

	newData = malloc(sizeof(dlistint_t));
	if (newData == NULL)
		return (NULL);
	newData->n = n;
	newData->next = NULL;
	newData->prev = NULL;

	current = *h;
	while (current && indexOfCurrentNode < idx)
	{
		current = current->next;
		indexOfCurrentNode++;
	}

	if (indexOfCurrentNode == idx && current != NULL)/*insert in the middle*/
	{
		if (current->prev)
			current->prev->next = newData;
		newData->prev = current->prev;
		newData->next = current;
		current->prev = newData;
		return (newData);
	}
	else if (indexOfCurrentNode == idx && current == NULL) /*insert at the end*/
	{
		free(newData);
		return (add_dnodeint_end(h, n));
	}

	free(newData);
	return (NULL);

}