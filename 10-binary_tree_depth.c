#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: depth or 0 if tree NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	depth = binary_tree_depth(tree->parent);

	return (depth + 1);
}
