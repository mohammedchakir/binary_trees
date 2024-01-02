#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = -1, size = 1024;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return;

	queue[++rear] = (binary_tree_t *)tree;

	while (front <= rear)
	{
		binary_tree_t *node = queue[front++];

		func(node->n);
		if (node->left)
			queue[++rear] = node->left;
		if (node->right)
			queue[++rear] = node->right;
	}

	free(queue);
}
