#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * insert_node - function to insert a number into a sorted singly linked list
 * @head: head of the link list
 * @number: number
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *curr = NULL;
	listint_t *new_node = NULL;

	if (!head)
		return (NULL);
	curr = *head;
	new_node = malloc(sizeof(listint_t));
	new_node->n = number;
	new_node->next = NULL;
	if (!curr)
	{
		*head = new_node;
		return (new_node);
	}

	if (number < curr->n)
	{
		new_node->next = curr;
		*head = new_node;
		return (new_node);
	}

	while (curr->next && curr->next->n <= number)
		curr = curr->next;
	new_node->next = curr->next;
	curr->next = new_node;
	return (new_node);
}
