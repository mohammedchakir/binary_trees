#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_balance(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/**
 * Insert a value in an AVL Tree.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    } else if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            (*tree)->left = binary_tree_node(*tree, value);
            return (*tree)->left;
        } else
        {
            return avl_insert((avl_t **)&((*tree)->left), value);
        }
    } else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            (*tree)->right = binary_tree_node(*tree, value);
            return (*tree)->right;
        } else
        {
            return avl_insert((avl_t **)&((*tree)->right), value);
        }
    }

    int balance = binary_tree_balance(*tree);

    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);

    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);

    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }

    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return *tree;
}
