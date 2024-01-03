#include "binary_trees.h"

/**
 * is_bst - Checks if a binary tree is a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value for the node's data.
 * @max: Maximum allowed value for the node's data.
 *
 * Return: 1 if the tree is a BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * check_height_balance - Calculates the height of a binary tree
 * and checks if it's balanced.
 * @tree: Pointer to the root node of the tree to check.
 * @is_balanced: Pointer to an integer flag that indicates
 * if the tree is balanced.
 *
 * Return: Height of the tree.
 */
int check_height_balance(const binary_tree_t *tree, int *is_balanced)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = check_height_balance(tree->left, is_balanced);
	right_height = check_height_balance(tree->right, is_balanced);

	if (abs(left_height - right_height) > 1)
		*is_balanced = 0;

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 * If tree is NULL, returns 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_balanced = 1;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	check_height_balance(tree, &is_balanced);
	return (is_balanced);
}
