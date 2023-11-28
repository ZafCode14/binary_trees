#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at lease 1 child
 * @tree: Pointer to the root node of tree
 *
 * Return: count of nodes with 1 child or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes, l, r;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		l = binary_tree_nodes(tree->left);
		r = binary_tree_nodes(tree->right);
		nodes = l + r;

		return (1 + nodes);
	}

	return (0);
}
