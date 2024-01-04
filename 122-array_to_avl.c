#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int a;
	avl_t *root = NULL;

	for (a = 0; a < size; a++)
		avl_insert(&root, array[a]);

	return (root);
}
