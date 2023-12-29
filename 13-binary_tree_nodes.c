#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one
 * child in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least one child in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left || tree->right)
	{
		return (1 + binary_tree_nodes(tree->left)
				+ binary_tree_nodes(tree->right));
	}

	return (0);
}
