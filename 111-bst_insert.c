#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * 
 * Return: Pointer to the created node, or NULL on failure or if value exists
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *node, *current, *parent;

    if (!tree)
        return (NULL);

    /* Create a new node */
    node = malloc(sizeof(bst_t));
    if (!node)
        return (NULL);

    node->n = value;
    node->left = node->right = node->parent = NULL;

    /* If the tree is empty, insert the new node as the root */
    if (!*tree)
    {
        *tree = node;
        return (node);
    }

    /* Find the appropriate parent node for the new node */
    current = *tree;
    while (current)
    {
        parent = current;
        if (value < current->n)
            current = current->left;
        else if (value > current->n)
            current = current->right;
        else
        {
            /* Value already exists in the tree */
            free(node);
            return (NULL);
        }
    }

    /* Insert the new node as a child of the found parent node */
    if (value < parent->n)
        parent->left = node;
    else
        parent->right = node;
    node->parent = parent;

    return (node);
}
