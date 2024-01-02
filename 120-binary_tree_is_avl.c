#include "binary_trees.h"

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed for nodes in the tree (for checking)
 * @max: Maximum value allowed for nodes in the tree (for checking)
 * Return: 1 if tree is a valid BST, 0 otherwise
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
 * binary_tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    int left_height, right_height;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (abs(left_height - right_height) <= 1 && is_bst(tree, INT_MIN, INT_MAX))
    {
        int left_avl = binary_tree_is_avl(tree->left);
        int right_avl = binary_tree_is_avl(tree->right);

        if ((left_avl && right_avl) || (!tree->left && !tree->right))
            return (1);
    }

    return (0);
}
