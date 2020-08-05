#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/**
 * struct node_deep - found the height
 *
 * @deep: a depper
 * @node: a node
*/
typedef struct node_deep
{
	int deep;
	heap_t *node;
} node_deep_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
node_deep_t insert(heap_t *node);
heap_t *order_nodes(heap_t *node);



#endif /* _BINARY_TREES_H_ */
