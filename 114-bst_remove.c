#include "binary_trees.h"

/**
 * find_successor - Finds the minimum value node in a BST.
 * @root: Pointer to the root node of the BST.
 *
 * Return: Pointer to the node containing the minimum value.
 */
bst_t *find_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from the BST.
 * @node: Node to be deleted from the BST.
 *
 * Return: void
 */
void bst_delete(bst_t *node)
{
	bst_t *parent = node->parent, *successor;

	if (!node->right)
	{
		if (parent)
		{
			if (parent->left == node)
				parent->left = node->left;
			else
				parent->right = node->left;
		}

		if (node->left)
			node->left->parent = parent;

		free(node);
	}
	else
	{
		successor = find_successor(node->right);
		node->n = successor->n;
		bst_delete(successor);
	}
}
/**
 * search - Searches for a node with a specific value in the BST.
 * @tree: Pointer to the root node of the BST.
 * @value: Value to search for.
 *
 * Return: Pointer to the node containing the value or NULL if not found.
 */
bst_t *search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (search(tree->left, value));
	else
		return (search(tree->right, value));
}

/**
 * bst_remove - Removes a node with a specific value from the BST.
 * @root: Pointer to the root node of the BST.
 * @value: Value to be removed from the BST.
 *
 * Return: Pointer to the root node of the BST after removal of
 *			the specified value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = search(root, value);
	bst_delete(node);

	return (root);
}
