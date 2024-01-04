#include "binary_trees.h"
void heapify_up(heap_t *node);
/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * @value: The value to insert
 *
 * Return: A pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return NULL;

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	heap_t *current = *root;
	int tree_size = binary_tree_size(current);
	int leaves = tree_size;

	int level, sub, bit;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		current = leaves & bit ? current->right : current->left;

	heap_t *new_node = binary_tree_node(current, value);
	leaves & 1 ? (current->right = new_node) : (current->left = new_node);

	heapify_up(new_node);

	return new_node;
}

/**
 * heapify_up - Moves the newly inserted node up to maintain heap property
 * @node: The node to move up
 */
void heapify_up(heap_t *node)
{
	heap_t *current = node;
	int tmp;

	while (current->parent && (current->n > current->parent->n))
	{
		tmp = current->n;
		current->n = current->parent->n;
		current->parent->n = tmp;
		current = current->parent;
	}
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
		return 0;

	return binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
}
