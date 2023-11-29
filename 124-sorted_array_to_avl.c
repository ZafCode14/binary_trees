#include "binary_trees.h"

/**
 * build_avl_tree - Recursive function to build an AVL tree from a sorted array
 * @node: Pointer to the current node
 * @array: Pointer to the sorted array
 * @size: Size of the array
 * @side: Indicator for left (1) or right (2) insertion
 */
void build_avl_tree(avl_t **node, int *array, size_t size, int side)
{
	size_t middle;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (side == 2)
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		build_avl_tree(&((*node)->right), array, middle, 1);
		build_avl_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
	else if (side == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		build_avl_tree(&((*node)->left), array, middle, 1);
		build_avl_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the sorted array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);
	build_avl_tree(&root, array, middle, 1);
	build_avl_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}
