#include "binary_trees.h"

/**
 * Helper function to recursively build AVL tree from sorted array.
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *root = binary_tree_node(NULL, array[mid]);

    if (!root)
        return NULL;

    root->left = sorted_array_to_avl_helper(array, start, mid - 1);
    if (root->left)
        root->left->parent = root;

    root->right = sorted_array_to_avl_helper(array, mid + 1, end);
    if (root->right)
        root->right->parent = root;

    return root;
}

/**
 * Builds an AVL tree from a sorted array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size) {
    if (!array || size == 0)
        return NULL;

    return sorted_array_to_avl_helper(array, 0, size - 1);
}
