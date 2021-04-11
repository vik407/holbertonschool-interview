#include "list.h"
/**
 * add_node_begin - adds a new node at the beginning of list
 * @list: head
 * @str: String
 * Description: adds a new node at the beginning of a list.
 * Return: address of the new element, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *last, *node = NULL;

	node = malloc(sizeof(List));

	if (node == NULL)
		return (NULL);
	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
		return (node);
	}
	last = (*list)->prev;
	node->next = (*list);
	node->prev = last;
	(*list)->prev = last->next = node;
	*list = node;

	return (node);
}
/**
 * add_node_end - adds a new node at the end
 * @list: head
 * @str: String
 * Description: adds a new node at the end of a double linked list.
 * Return: address of the new element, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *last, *node = NULL;

	node = malloc(sizeof(List));

	if (node == NULL || str == NULL)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
		return (node);
	}
	last = (*list)->prev;
	last->next = node;
	node->next = *list;
	node->prev = last;
	(*list)->prev = node;

	return (node);
}
