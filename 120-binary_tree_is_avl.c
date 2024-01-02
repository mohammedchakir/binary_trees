#include "binary_trees.h"

/**
 * is_bst - Checks if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value.
 * @max: Maximum allowed value.
 * Return: 1 if tree is a BST, 0 otherwise.
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max));
}

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: The height of the tree.
 */
static int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

/**
 * abs_diff - Calculates the absolute difference between two integers.
 * @a: First integer.
 * @b: Second integer.
 * Return: Absolute difference between a and b.
 */
static int abs_diff(int a, int b)
{
    if (a > b)
        return (a - b);
    else
        return (b - a);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    if (abs_diff(left_height, right_height) > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
