#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - function to insert a number into a sorted singly linked list
 * @head: head of the link list
 * @number: number
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL, *prev = NULL, *current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	if (head == NULL)
	{
		current = new;
		new->next = NULL;
		return (new);
	}
	if (new)
	{
		new->n = number;
		new->next = current;
		if (new->n <= current->n || !new->next)
			current = new;
		else
		{
			do
			{
				prev = new->next;
				new->next = prev->next;
			} while (new->next && new->n > new->next->n);
		}
		if (prev)
			prev->next = new;
	}
	return (new);
}
