#include "binary_trees.h"
size_t heap_size(heap_t *root);
/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (heap == NULL || size == NULL)
    {
        return NULL;
    }

    *size = heap_size(heap);

    int *sorted_array = malloc(*size * sizeof(int));
    if (sorted_array == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < *size; ++i)
    {
        sorted_array[i] = heap_extract(&heap);
    }

    return sorted_array;
}

/**
 * heap_size - Calculates the size of the heap
 * @root: Pointer to the root of the heap
 * Return: The size of the heap
 */
size_t heap_size(heap_t *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + heap_size(root->left) + heap_size(root->right);
}
