#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: hight of tree or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r, max;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	max = (l > r) ? l : r;

	return (max + 1);
}
