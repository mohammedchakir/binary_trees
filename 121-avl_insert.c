#include "binary_trees.h"

/**
 * perform_rotations - Helper function to perform rotations on an AVL tree node.
 * @node: The AVL tree node to perform rotation on.
 * Return: Pointer to the new root after rotation.
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
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
            (*tree)->left = binary_tree_node(*tree, value);
        else
            avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
            (*tree)->right = binary_tree_node(*tree, value);
        else
            avl_insert(&((*tree)->right), value);
    }
    else
        return (*tree);

    *tree = perform_rotations(*tree);
    return *tree;
}
