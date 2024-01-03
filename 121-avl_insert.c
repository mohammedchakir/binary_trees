#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 * 
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    avl_t *node = *tree;
    if (node == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    } else
    {
        if (value < node->n)
        {
            if (node->left == NULL)
            {
                node->left = binary_tree_node(node, value);
                node = node->left;
            } else
            {
                node = avl_insert(&(node->left), value);
            }
        } else if (value > node->n)
        {
            if (node->right == NULL)
            {
                node->right = binary_tree_node(node, value);
                node = node->right;
            } else
            {
                node = avl_insert(&(node->right), value);
            }
        } else
        {
            return (NULL);
        }
    }

    int balance = binary_tree_balance(node);

    if (balance > 1)
    {
        if (value < node->left->n)
        {
            return binary_tree_rotate_right(node);
        } else
        {
            node->left = binary_tree_rotate_left(node->left);
            return binary_tree_rotate_right(node);
        }
    }

    if (balance < -1)
    {
        if (value > node->right->n)
        {
            return binary_tree_rotate_left(node);
        } else
        {
            node->right = binary_tree_rotate_right(node->right);
            return binary_tree_rotate_left(node);
        }
    }

    return node;
}
