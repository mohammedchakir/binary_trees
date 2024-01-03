#include "binary_trees.h"

/* Declare helper functions */
int bst_check(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max);
int is_avl(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max);
int tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	return (bst_check(tree, NULL, NULL) && is_avl(tree, NULL, NULL));
}

/**
 * bst_check - Checks if a binary tree is a valid Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value a node can have (exclusive)
 * @max: Pointer to the maximum value a node can have (exclusive)
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int bst_check(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) || (max != NULL && tree->n >= max->n))
		return (0);

	return (bst_check(tree->left, min, tree) &&
			bst_check(tree->right, tree, max));
}

/**
 * is_avl - Checks if a binary tree satisfies AVL properties
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value a node can have (exclusive)
 * @max: Pointer to the maximum value a node can have (exclusive)
 *
 * Return: 1 if tree satisfies AVL properties, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (is_avl(tree->left, min, tree) && is_avl(tree->right, tree, max));
}

/**
 * tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
