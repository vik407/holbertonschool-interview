#ifndef AVL_TREE
#define AVL_TREE
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
int binary_tree_is_avl(const binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *);
int height(const binary_tree_t *tree);
binary_tree_t *basic_tree(void);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int isBST(const binary_tree_t *tree);
int BSTUtil(const binary_tree_t *tree, int min, int max);

#endif
