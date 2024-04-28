#include "lists.h"

/**
 * delete_dnodeint_at_index - function that deletes the node at index
 * of a dobble linked list
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if succeeded, -1 if failed
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int indexOfCurrentNode = 0;
	dlistint_t *current = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)/*delete first node*/
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current && indexOfCurrentNode < index)
	{
		current = current->next;
		indexOfCurrentNode++;
	}

	if (current == NULL) /*index out of range*/
		return (-1);

	if (current->next == NULL) /*delete last node*/
	{
		current->prev->next = NULL;
		free(current);
		return (1);
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
	return (1);
}
