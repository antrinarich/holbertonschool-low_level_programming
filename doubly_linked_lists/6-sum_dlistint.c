#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of all the data (n)
 * of a dobble linked list
 * @head: pointer to the head node of the list
 * Return: sum of all the data
*/

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	if (head)
	{
		while (current != NULL)
		{
			sum += (current->n);
			current = current->next;
		}
	}
	return (sum);
}