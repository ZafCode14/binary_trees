#include "binary_trees.h"

/**
 * tree_size_ - Calculates the size of the tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t tree_size_(const binary_tree_t *tree)
{
	size_t size_left = 0;
	size_t size_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		size_left = 1 + tree_size_(tree->left);

	if (tree->right)
		size_right = 1 + tree_size_(tree->right);

	return (size_left + size_right);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Sorted array of integers (descending order), or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *array = NULL;

	if (heap == NULL || !size)
		return (NULL);

	*size = tree_size_(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
