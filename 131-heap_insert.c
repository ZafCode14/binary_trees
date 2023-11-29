#include "binary_trees.h"

/**
 * heapify_up - Ensures the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * binary_tree_size - Computes the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}

/**
 * find_parent - Finds the parent node for the next insertion in the Heap
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *parent = root;

	while (parent->left && parent->right)
	{
		if (!parent->left || !parent->right)
			break;

		parent = (binary_tree_size(parent->left) <=
				binary_tree_size(parent->right))
			? parent->left : parent->right;
	}
	return (parent);
}

/**
 * insert_to_heap - Helper function to insert a value into a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 * @value: The value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *insert_to_heap(heap_t *root, int value)
{
	heap_t *new_node, *parent;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	parent = find_parent(root);
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	heapify_up(new_node);

	return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 * @value: The value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	return (insert_to_heap(*root, value));
}
