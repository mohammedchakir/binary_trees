#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @start: Start index of the current segment of the array
 * @end: End index of the current segment of the array
 *
 * Return: A pointer to the root node of the created AVL tree segment, or
 * NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *root = binary_tree_node(NULL, array[mid]);

    if (!root)
        return NULL;

    root->left = sorted_array_to_avl_helper(array, start, mid - 1);
    if (root->left)
        root->left->parent = root;

    root->right = sorted_array_to_avl_helper(array, mid + 1, end);
    if (root->right)
        root->right->parent = root;

    return root;
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on
 * failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    return sorted_array_to_avl_helper(array, 0, size - 1);
}
