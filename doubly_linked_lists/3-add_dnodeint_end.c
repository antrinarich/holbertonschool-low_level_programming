#include "lists.h"

/**
 * add_dnodeint_end - function that adds a new node at the end
 * @head: pointer to head node
 * @n: integer data
 * Return: address of the new element or NULL if it failed
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newData, *current;

	newData = malloc(sizeof(dlistint_t));
	if (newData == NULL)
		return (NULL);

	newData->n = n;
	newData->next = NULL;
	newData->prev = NULL;

	if (*head == NULL)
	{
		*head = newData;
		return (newData);
	}

	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newData;
	newData->prev = current;

	return (newData);

}