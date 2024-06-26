#include "lists.h"

/**
 * free_dlistint - function that frees a dobble linked list
 * @head: pointer to the head of list
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

}