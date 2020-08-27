#include "lists.h"

/**
 * reverse_linked_list - reverses a linked list
 * @head: double pointer to head of list
 */
void reverse_linked_list(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

/**
 * compare_lists - compares two linked lists
 * @a: pointer to head of first list
 * @b: pointer to head of second list
 * Return: 1 if true, 0 if false
 */
int compare_lists(listint_t *a, listint_t *b)
{
	for (; a && b; a = a->next, b = b->next)
		if (a->n != b->n)
			return (0);
	return (!a && !b);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if true, 0 if false
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *prev = *head;
	int res = 0;

	if (!fast || !fast->next)
		return (1);
	while (fast && fast->next)
	{
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (fast)
	{
		fast = slow;
		slow = slow->next;
	}
	prev->next = NULL;
	reverse_linked_list(&slow);
	res = compare_lists(*head, slow);
	reverse_linked_list(&slow);
	if (fast)
	{
		prev->next = fast;
		fast->next = slow;
	}
	else
		prev->next = slow;
	return (res);
}
