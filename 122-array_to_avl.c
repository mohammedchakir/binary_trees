#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to create from
 * @size: size of the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return NULL;

    avl_t *root = binary_tree_node(NULL, array[0]);

    if (root == NULL)
        return NULL;

    for (size_t i = 1; i < size; i++)
    {
        avl_insert(&root, array[i]);
    }

    return root;
}
