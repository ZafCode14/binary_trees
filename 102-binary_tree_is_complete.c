#include "binary_trees.h"
/**
 * tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree of if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t size, l, r;

	if (tree == NULL)
		return (0);

	l = tree_size(tree->left);
	r = tree_size(tree->right);
	size = l + r;

	return (size + 1);
}

/**
 * complete_recursive - checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @node_count: Number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int complete_recursive(const binary_tree_t *tree,
		size_t index, size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (complete_recursive(tree->left, 2 * index + 1, node_count) &&
			complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node_count;

	if (tree == NULL)
		return (0);

	node_count = tree_size(tree);

	return (complete_recursive(tree, 0, node_count));
}
