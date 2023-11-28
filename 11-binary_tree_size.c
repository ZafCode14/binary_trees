#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree of if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size, l, r;

	if (tree == NULL)
		return (0);

	l = binary_tree_size(tree->left);
	r = binary_tree_size(tree->right);
	size = l + r;

	return (size + 1);
}
