#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    avl_t *root = NULL;
    avl_t *node = NULL;

    for (size_t i = 0; i < size; ++i)
    {
        node = avl_insert(&root, array[i]);
        if (!node) {
        }
    }

    return root;
}
