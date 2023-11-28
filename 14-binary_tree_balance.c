#include "binary_trees.h"

/**
 * tree_height - hight of tree
 * @tree: pointer to the root node of tree
 *
 * Return: height or 0
 */
int tree_height(const binary_tree_t *tree)
{
	int height, l, r;

	if (tree == NULL)
		return (0);

	l = tree_height(tree->left);
	r = tree_height(tree->right);
	height = 1 + (l > r ? l : r);

	return (height);
}

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: balance or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance, l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);
	balance = l_height - r_height;

	return (balance);
}
