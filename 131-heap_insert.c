#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * @value: The value to be inserted
 *
 * Return: A pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *current;
	int tree_size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	tree_size = binary_tree_size(tree);
	leaves = tree_size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	current = new_node;
	for (; current->parent &&
			(current->n > current->parent->n); current = current->parent)
	{
		tmp = current->n;
		current->n = current->parent->n;
		current->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure the size of
 *
 * Return: Size of the tree, 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
