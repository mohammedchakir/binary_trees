#include "binary_trees.h"

/**
 * check_bst - Helper function to check if binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (check_bst(tree->left, min, tree->n)
			&& check_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}
