#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: return a pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	node_deep_t new_node_parent;

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);
	if (!(*root))
	{
		*root = new;
		new->n = value;
		return (new);
	}
	new_node_parent = insert(*root);
	new->parent = new_node_parent.node;
	new->n = value;

	if (new_node_parent.node->left == NULL)
	{
		new_node_parent.node->left = new;
	}
	else
	{
		new_node_parent.node->right = new;
	}
	return (order_nodes(new));
}

/**
 * insert - receive a node
 * @node: a node
 * Return: if node is null return 0
 */
node_deep_t insert(heap_t *node)
{
	node_deep_t left, right, def;

	if (node->left == NULL || node->right == NULL)
	{
		def.deep = 0;
		def.node = node;
		return (def);
	}

	left = insert(node->left);
	right = insert(node->right);

	if (left.deep <= right.deep)
	{
		left.deep += 1;
		return (left);
	}
	right.deep += 1;
	return (right);
}

/**
 * order_nodes - change position of nodes
 * @node: Receive the node
 * Return: an ordered node
*/
heap_t *order_nodes(heap_t *node)
{
	int swapper;

	while (node->parent)
	{
		if (node->n > node->parent->n)
		{
			swapper = node->n;
			node->n = node->parent->n;
			node->parent->n = swapper;

			node = node->parent;
			continue;
		}
		return (node);
	}
	return (node);
}
