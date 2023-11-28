#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 *						of another node.
 * @parent: pointer to the parent node
 * @value: Value of the node
 *
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		temp = parent->right;
		node->right = temp;
		temp->parent = node;
	}
	else
	{
		node->right = NULL;
		node->left = NULL;
	}
	node->parent = parent;
	parent->right = node;
	node->n = value;

	return (node);
}
