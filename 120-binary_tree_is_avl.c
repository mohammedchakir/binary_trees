#include "binary_trees.h"

/**
 * check_bst - Checks if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value.
 * @max: Maximum value.
 *
 * Return: 1 if tree is a BST, 0 otherwise.
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (check_bst(tree->left, min, tree->n - 1) &&
            check_bst(tree->right, tree->n + 1, max));
}

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    return (right_height + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int balance;

    if (tree == NULL)
        return (0);

    if (!check_bst(tree, INT_MIN, INT_MAX))
        return (0);

    balance = height(tree->left) - height(tree->right);
    if (abs(balance) > 1)
        return (0);

    return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
