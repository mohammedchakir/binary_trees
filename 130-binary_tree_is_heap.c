#include "binary_trees.h"

/**
 * node_count - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 * 
 * Return: Number of nodes
 */
int node_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * is_heap_util - Utility function to check Max Heap property
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @num_nodes: Total number of nodes in the tree
 * 
 * Return: 1 if tree is a Max Heap, 0 otherwise
 */
int is_heap_util(const binary_tree_t *tree, int index, int num_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= num_nodes)
		return (0);

	return ((tree->left == NULL || (tree->n >= tree->left->n &&
					is_heap_util(tree->left, 2 * index + 1, num_nodes)))
			&& (tree->right == NULL || (tree->n >= tree->right->n && is_heap_util(tree->right, 2 * index + 2, num_nodes)));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * 
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
int num_nodes = node_count(tree);
return is_heap_util(tree, 0, num_nodes);
}
