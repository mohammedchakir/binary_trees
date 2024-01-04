#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return NULL;

	return sorted_array_to_avl_helper(array, 0, size - 1, NULL);
}

/**
 * sorted_array_to_avl_helper - helper that builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @lo: lower bound index
 * @hi: upper bound index
 * @parent: pointer to the parent node
 *
 * Return: pointer to the root node of the created AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t lo, size_t hi, avl_t *parent)
{
	if (lo > hi)
		return NULL;

	size_t middle = (lo + hi) / 2;
	avl_t *new_node = binary_tree_node(parent, array[middle]);

	if (new_node == NULL)
		return NULL;

	new_node->left = sorted_array_to_avl_helper(array, lo, middle - 1, new_node);
	new_node->right = sorted_array_to_avl_helper(array, middle + 1, hi, new_node);

	return new_node;
}
