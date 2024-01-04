#include "binary_trees.h"


/**
 * balance_avl - Balances an AVL tree.
 * @tree: A pointer to the root node of the AVL tree.
 */
void balance_avl(avl_t **tree)
{
	if (tree == NULL || *tree == NULL)
		return;

	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	int balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor - Finds the next successor, i.e., the minimum node in the right subtree.
 * @node: A pointer to the node to check.
 * Return: The minimum value of the tree rooted at the given node.
 */
int get_successor(bst_t *node)
{
	if (node == NULL)
		return (0);

	int left = get_successor(node->left);

	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * remove_node_type - Removes a node based on its children.
 * @root: A pointer to the node to remove.
 * Return: 0 if it has no children, or the new value if it has.
 */
int remove_node_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		bst_t *child = (root->left) ? root->left : root->right;

		if (root->parent->right == root)
			root->parent->right = child;
		else
			root->parent->left = child;

		child->parent = root->parent;
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: A pointer to the root of the tree.
 * @value: The value of the node to remove.
 * Return: The updated tree.
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
		type = remove_node_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root of the tree.
 * @value: The value of the node to remove.
 * Return: The updated tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = (avl_t *)bst_remove((bst_t *)root, value);

	if (new_root == NULL)
		return (NULL);

	balance_avl(&new_root);
	return (new_root);
}
