#include "binary_trees.h"

/**
 * tree_depth - measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: depth or 0 if tree NULL
 */
size_t tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	depth = tree_depth(tree->parent);

	return (depth + 1);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;
	int diff;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = tree_depth(first);
	depth_second = tree_depth(second);

	for (diff = depth_first - depth_second; diff > 0; diff--)
		first = first->parent;

	for (diff = depth_second - depth_first; diff > 0; diff--)
		second = second->parent;

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
