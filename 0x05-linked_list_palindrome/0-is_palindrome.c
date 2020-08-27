#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - Write a function in C that checks if
 * a singly linked list is a palindrome.
 * @head: head to the linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *_head;
	int num_arr[3000];
	int i = 0, j;

	if (!head || !(*head) || !((*head)->next))
		return (1);

	_head = *head;

	while (_head)
	{
		num_arr[i] = _head->n;
		i++;
		_head = _head->next;
	}
	i--;
	for (j = 0; j < i; j++, i--)
	{
		if (num_arr[i] == num_arr[j])
			continue;
		else
			return (0);
	}
	return (1);
}
