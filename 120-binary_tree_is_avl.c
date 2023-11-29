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
 * is_bst_util - helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @prev: Pointer to the previously visited node's value
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_util(tree->left, prev))
		return (0);

	if (tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (is_bst_util(tree->right, prev));
}

/**
 * tree_is_bst - checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise or if tree is NULL
 */
int tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, &prev));
}

/**
 * binary_tree_is_avl - Checks if binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);

	if (tree_is_bst(tree) && abs(l_height - r_height) < 1)
		return (1);
	return (0);
}
