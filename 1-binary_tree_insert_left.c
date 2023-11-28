#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the parent node
 * @value: The value of the node
 *
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL)
		return (NULL);

	node->parent = parent;
	if (parent->left != NULL)
	{
		temp = parent->left;
		temp->parent = node;
		node->left = temp;
	}
	else
	{
		node->left = NULL;
		node->right = NULL;
	}
	parent->left = node;
	node->n = value;

	return (node);
}
