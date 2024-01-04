#include "binary_trees.h"

/**
 * sorted_array_to_avl - Converts a sorted array into an AVL tree
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t middle;

	if (!array || size == 0)
		return (NULL);

	middle = (size - 1) / 2;
	root = binary_tree_node(NULL, array[middle]);

	build_avl_tree(&root, array, -1, middle);
	build_avl_tree(&root, array, middle, size);

	return (root);
}

/**
 * build_avl_tree - Helper function to build an AVL tree from an array
 * @root: Double pointer to the root node of the subtree
 * @array: Pointer to the first element of the array
 * @lo: Lower bound index
 * @hi: Upper bound index
 */
void build_avl_tree(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new_node = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		new_node = binary_tree_node(*root, array[middle]);

		if (array[middle] > (*root)->n)
			(*root)->right = new_node;
		else if (array[middle] < (*root)->n)
			(*root)->left = new_node;

		build_avl_tree(&new_node, array, lo, middle);
		build_avl_tree(&new_node, array, middle, hi);
	}
}
