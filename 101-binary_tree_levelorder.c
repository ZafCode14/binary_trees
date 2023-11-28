#include "binary_trees.h"
/**
 * tree_height - measures the height of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: hight of tree or 0
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t l, r, max;

	if (tree == NULL)
		return (0);

	l = tree_height(tree->left);
	r = tree_height(tree->right);

	max = (l > r) ? l : r;

	return (max + 1);
}

/**
 * print_given_level - prints nodes at a given level
 * @tree: Pointer to the root node of the tree
 * @level: Level to print
 * @func: Pointer to a function to call for each node
 *
 * Return: void
 */
void print_given_level(const binary_tree_t *tree, int level,
		void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		print_given_level(tree->left, level - 1, func);
		print_given_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - performs level-order traversal using recursion
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree,
		void (*func)(int))
{
	size_t height;
	size_t level;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree);
	for (level = 1; level <= height; level++)
		print_given_level(tree, level, func);
}
