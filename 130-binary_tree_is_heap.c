#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the tree node
 * @nodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
			is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * is_heap - Checks if a binary tree is a heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);
	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (is_heap(tree->left) && is_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t nodes = binary_tree_size(tree);
	size_t index = 0;

	if (tree == NULL)
		return (0);

	if (is_complete(tree, index, nodes) && is_heap(tree))
		return (1);

	return (0);
}
