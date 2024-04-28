#include "lists.h"

/**
 * add_dnodeint - function that adds a new node at the beginning of
 * a dobble linked list of integer
 * @head: pointer to the head list
 * @n: integer to add
 * Return: the address of the new element or NULL if it failed
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newData;

	newData = malloc(sizeof(dlistint_t));
	if (newData == NULL)
		return (NULL);

	newData->n = n;
	newData->prev = NULL;

	if (*head == NULL)
	{
		newData->next = NULL;
		*head = newData;
	}
	else
	{
		newData->next = *head;
		if (*head)
			(*head)->prev = newData;
		*head = newData;
	}

	return (newData);
}
