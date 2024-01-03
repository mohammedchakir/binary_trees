#include "binary_trees.h"


/**
 * recursive_insert - recursively inserts a node in an AVL tree.
 * @root: A pointer to the root node of the AVL tree.
 * @parent: The parent node of the current node.
 * @new_node: A pointer to the new node to be inserted.
 * @value: The value to be inserted.
 * Return: A pointer to the new root after insertion, otherwise NULL.
 */
avl_t *recursive_insert(avl_t **root, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*root == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*root)->n > value)
	{
		(*root)->left = recursive_insert(&(*root)->left, *root, new_node, value);
		if ((*root)->left == NULL)
			return (NULL);
	}
	else if ((*root)->n < value)
	{
		(*root)->right = recursive_insert(&(*root)->right, *root, new_node, value);
		if ((*root)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*root);
	}

	balance_factor = binary_tree_balance(*root);

	if (balance_factor > 1 && (*root)->left->n > value)
		*root = binary_tree_rotate_right(*root);
	else if (balance_factor > 1 && (*root)->left->n < value)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		*root = binary_tree_rotate_right(*root);
	}
	else if (balance_factor < -1 && (*root)->right->n < value)
		*root = binary_tree_rotate_left(*root);
	else if (balance_factor < -1 && (*root)->right->n > value)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		*root = binary_tree_rotate_left(*root);
	}

	return (*root);
}

/**
 * avl_insert - inserts a value into an AVL tree.
 * @root: A pointer to the root node of the AVL tree to insert into.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the inserted node, or NULL if it fails.
 */
avl_t *avl_insert(avl_t **root, int value)
{
	avl_t *new_node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	recursive_insert(root, *root, &new_node, value);
	return (new_node);
}
