#include "binary_trees.h"
#include <limits.h>

/**
 * Checks if a binary tree is a BST.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);
    if (tree->n <= min || tree->n >= max)
        return (0);
    return (is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max));
}

/**
 * Calculates the height of a binary tree and checks if it's balanced.
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
 * Checks if a binary tree is a valid AVL Tree.
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
