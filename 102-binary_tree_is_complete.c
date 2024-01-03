#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 if not or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front = 0, rear = -1, size = 1024, full_node = 1;

	if (!tree)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return (0);
	queue[++rear] = (binary_tree_t *)tree;

	while (front <= rear)
	{
		binary_tree_t *node = queue[front++];

		if (!node->left)
			full_node = 0;
		else
		{
			if (!full_node)
			{
				free(queue);
				return (0);
			}
			queue[++rear] = node->left;
		}
		if (!node->right)
			full_node = 0;
		else
		{
			if (!full_node)
			{
				free(queue);
				return (0);
			}
			queue[++rear] = node->right;
		}
	}
	free(queue);
	return (1);
}
