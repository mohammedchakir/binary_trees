#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - Creates an AVL tree node from a sub-array.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the sub-array.
 * @end: Ending index of the sub-array.
 * Return: Pointer to the root node of the AVL subtree created.
 */
avl_t *create_avl_node(int *array, int start, int end)
{
    int mid;
    avl_t *node;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    node = binary_tree_node(NULL, array[mid]);
    if (node == NULL)
        return (NULL);

    if (start != mid)
        node->left = create_avl_node(array, start, mid - 1);

    if (end != mid)
        node->right = create_avl_node(array, mid + 1, end);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return create_avl_node(array, 0, size - 1);
}
