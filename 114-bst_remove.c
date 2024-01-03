#include "binary_trees.h"

/**
 * find_successor - Finds the in-order successor of a node
 * @node: Pointer to the node to find the successor of
 *
 * Return: Pointer to the in-order successor node
 */
bst_t *find_successor(bst_t *node)
{
	bst_t *current = node->right;

	while (current && current->left)
		current = current->left;
	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: Pointer to the new root node after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (!root)
        return root;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (!root->left)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = find_successor(root);

        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }
    return root;
}
