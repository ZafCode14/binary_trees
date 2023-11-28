#include "binary_trees.h"

/**
 * bst_free - frees a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST
 *
 * Return: void
 */
void bst_free(bst_t *tree)
{
	if (tree != NULL)
	{
		bst_free(tree->left);
		bst_free(tree->right);
		free(tree);
	}
}

/**
 * array_to_bst - builds a Binary Search Tree (BST) from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			bst_free(root);
			return (NULL);
		}
	}

	return (root);
}
