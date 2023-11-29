#include "binary_trees.h"

/**
 * tree_max_height - Calculates the maximum height of the tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Maximum height of the tree
 */
size_t tree_max_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = 1 + tree_max_height(tree->left);

	if (tree->right)
		height_right = 1 + tree_max_height(tree->right);

	return ((height_left > height_right) ?
			height_left : height_right);
}

/**
 * tree_size - Calculates the size of the tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t size_left = 0;
	size_t size_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		size_left = 1 + tree_size(tree->left);

	if (tree->right)
		size_right = 1 + tree_size(tree->right);

	return (size_left + size_right);
}

/**
 * preorder_traversal - Performs a preorder traversal to find a
 *					node at a certain height
 * @tree: Pointer to the root node of the tree
 * @node: Pointer to a pointer to the found node
 * @height: Height to search for the node
 *
 * Return: None
 */
void preorder_traversal(heap_t *tree, heap_t **node, size_t height)
{
	if (tree == NULL)
		return;

	if (!height)
		*node = tree;
	height--;

	preorder_traversal(tree->left, node, height);
	preorder_traversal(tree->right, node, height);
}

/**
 * heapify_down - Reorganizes the heap after replacing the root node
 * @root: Pointer to the root node of the heap
 *
 * Return: None
 */
void heapify_down(heap_t *root)
{
	int value;
	heap_t *current, *child;

	if (root == NULL)
		return;

	current = root;

	while (1)
	{
		if (!current->left)
			break;
		if (!current->right)
			child = current->left;
		else
		{
			if (current->left->n > current->right->n)
				child = current->left;
			else
				child = current->right;
		}
		if (current->n > child->n)
			break;
		value = current->n;
		current->n = child->n;
		child->n = value;
		current = child;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_root, *node;

	if (root == NULL || (*root) == NULL)
		return (0);
	heap_root = *root;
	value = heap_root->n;
	if (!heap_root->left && !heap_root->right)
	{
		*root = NULL;
		free(heap_root);
		return (value);
	}

	preorder_traversal(heap_root, &node,
			tree_max_height(heap_root));

	heap_root->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify_down(heap_root);
	*root = heap_root;
	return (value);
}
