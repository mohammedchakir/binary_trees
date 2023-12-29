#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    size_t left_height = tree->left ? binary_tree_height(tree->left) : 0;
    size_t right_height = tree->right ? binary_tree_height(tree->right) : 0;

    return (left_height > right_height ? left_height : right_height) + (tree->left || tree->right);
}
