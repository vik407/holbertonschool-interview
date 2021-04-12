#include "binary_trees.h"
/**
* isBST - determine whether a tree is BST or not
*
* @tree: pointer to node root
* Return: if tree is BST or not
*/
int isBST(const binary_tree_t *tree)
{
	return (BSTUtil(tree, INT_MIN, INT_MAX));
}
/**
* BSTUtil - Check if a Binary Tree is a BST
*
* @tree: pointer to node root
* @min: min value
* @max: max value
* Return: if a Binary Tree is a BST or not
*/
int BSTUtil(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (BSTUtil(tree->left, min, tree->n - 1) &&
			BSTUtil(tree->right, tree->n + 1, max));
}
/**
* height - compute the heigth for a tree
*
* @tree: pointer to node root
* Return: height of tree
*/
int height(const binary_tree_t *tree)
{
	int h_left, h_right;

	/*Base Case*/
	if (tree == NULL)
		return (0);

	h_left =  height(tree->left);
	h_right = height(tree->right);

	if (h_left > h_right)
		return (1 + h_left);
	else
		return (1 + h_right);
}
/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
* @tree: pointer to node root
* Return: 1 if tree is a valid AVL Tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h_l, h_r, diff;

	if (tree == NULL)
		return (1);
	if (!isBST(tree))
		return (0);

	h_l = height(tree->left);
	h_r = height(tree->right);
	diff = h_l > h_r ? h_l - h_r : h_r - h_l;

	if (diff <= 1 &&  binary_tree_is_avl(tree->left) &&
	    binary_tree_is_avl(tree->right))
		return (1);
	return (0);
}
