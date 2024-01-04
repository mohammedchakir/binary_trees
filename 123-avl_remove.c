#include "binary_trees.h"

/**
 * balance_tree - Balances an AVL tree
 * @tree: Pointer to the tree to be balanced
 */
void balance_tree(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_tree(&(*tree)->left);
	balance_tree(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the successor (min node in the right subtree)
 * @node: Node to find the successor for
 * Return: The minimum value of the right subtree
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = find_successor(node->left);
		if (left == 0)
			return (node->n);
		return (left);
	}
}

/**
 * remove_node - Removes a node from the BST based on its children
 * @node: Node to be removed
 * Return: 0 if it has no children, otherwise a different value
 */
int remove_node(bst_t *node)
{
	int new_value = 0;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		bst_t *child = (node->left) ? node->left : node->right;

		if (node->parent->right == node)
			node->parent->right = child;
		else
			node->parent->left = child;

		child->parent = node->parent;
		free(node);
		return (0);
	}
	else
	{
		new_value = find_successor(node->right);
		node->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree
 * @root: Root of the tree
 * @value: Value of the node to remove
 * Return: Modified tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Root of the tree
 * @value: Value of the node to remove
 * Return: Modified tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);

	balance_tree(&root_a);
	return (root_a);
}
