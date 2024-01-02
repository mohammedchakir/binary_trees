#include "binary_trees.h"

/**
 * check_bst - Checks if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value.
 * @max: Maximum allowed value.
 * Return: 1 if tree is a BST, 0 otherwise.
 */
static int check_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (check_bst(tree->left, min, tree->n) &&
            check_bst(tree->right, tree->n, max));
}

/**
 * check_height - Checks the height of the tree and if it's balanced.
 * @tree: Pointer to the root node of the tree to check.
 * Return: Height of the tree if it's balanced, -1 if not.
 */
static int check_height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = check_height(tree->left);
    if (left_height == -1) return (-1);  // Left subtree is not balanced

    right_height = check_height(tree->right);
    if (right_height == -1) return (-1);  // Right subtree is not balanced

    if (abs(left_height - right_height) > 1)
        return (-1);  // Current tree is not balanced

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (!check_bst(tree, INT_MIN, INT_MAX))
        return (0);

    return (check_height(tree) != -1);
}
