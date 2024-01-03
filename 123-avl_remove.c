#include "binary_trees.h"

/**
 * in_order_successor - Finds the in-order successor of a node in an AVL tree.
 * @root: Pointer to the root of the subtree.
 * Return: Pointer to the in-order successor.
 */
avl_t *in_order_successor(avl_t *root)
{
    avl_t *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/**
 * perform_rotations - Performs necessary rotations to balance an AVL tree.
 * @node: The root node of the AVL tree.
 * Return: New root after potential rotations.
 */
static avl_t *perform_rotations(avl_t *node)
{
    int balance, balance_left, balance_right;

    balance = binary_tree_balance(node);
    if (balance > 1)
    {
        balance_left = binary_tree_balance(node->left);
        if (balance_left < 0)
            node->left = binary_tree_rotate_left(node->left);
        return binary_tree_rotate_right(node);
    }
    if (balance < -1)
    {
        balance_right = binary_tree_balance(node->right);
        if (balance_right > 0)
            node->right = binary_tree_rotate_right(node->right);
        return binary_tree_rotate_left(node);
    }
    return node;
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the AVL tree.
 * @value: Value to be removed from the tree.
 * Return: Pointer to the new root node of the tree after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    // BST deletion
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;
            if (temp == NULL)
                temp = root, root = NULL;
            else
                *root = *temp, free(temp);
        }
        else
        {
            avl_t *temp = in_order_successor(root->right);
            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return root;

    // AVL rebalancing
    root = perform_rotations(root);
    return root;
}
