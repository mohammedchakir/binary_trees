#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    heap_t *root = NULL;
    for (size_t i = 0; i < size; i++)
    {
        heap_insert(&root, array[i]);
    }

    return (root);
}
