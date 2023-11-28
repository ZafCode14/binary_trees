#include "binary_trees.h"

/**
 * is_perfect_recursive - helper function to check if a binary tree is perfect
 * @tree: Pointer to the root of the tree
 * @height: Height of the tree
 * @level: Current level being checked
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree,
		int height, int level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (height == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, height, level + 1) &&
			is_perfect_recursive(tree->right, height, level + 1));
}
/**
 * tree_height - measures the height of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Height of tree or 0 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);

	return (is_perfect_recursive(tree, height, 0));
}
