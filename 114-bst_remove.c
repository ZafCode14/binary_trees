#include "binary_trees.h"

/**
 * bst_min - finds the minimum value node in a BST
 * @root: Pointer to the root node of the BST
 *
 * Return: Pointer to the node containing the minimum value
 */
bst_t *bst_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from the Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @node: Node to be deleted from the BST
 *
 * Return: Pointer to the root node of the BST after
 *			deletion, ensuring the BST
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (!parent ? node->right : root);
	}

	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (!parent ? node->left : root);
	}

	successor = bst_min(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * remove_recursive - Removes a node with a specific value from the BST
 * @root: Pointer to the root node of the BST
 * @node: Current node being evaluated in the BST
 * @value: Value to be removed from the BST
 *
 * Return: Pointer to the root node of the BST after removal
 *			of the specified value,
 */
bst_t *remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (remove_recursive(root, node->left, value));
		return (remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node with a specific value from the BST
 * @root: Pointer to the root node of the BST
 * @value: Value to be removed from the BST
 *
 * Return: Pointer to the root node of the BST after removal of
 *			the specified value,
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recursive(root, root, value));
}
