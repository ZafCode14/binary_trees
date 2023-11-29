#include "binary_trees.h"

/**
 * heapify_up - Maintains the heap property by moving a node up
 * @node: Pointer to the node to heapify up
 *
 * Return: Pointer to the new position of the node after heapify up
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *parent;
	int tmp;

	while (node->parent && (node->n > node->parent->n))
	{
		parent = node->parent;
		tmp = node->n;
		node->n = parent->n;
		parent->n = tmp;
		node = parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a binary heap
 * @root: Pointer to the root node of the heap
 * @value: Value to insert into the heap
 *
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level;

	if (root == NULL)
		return (NULL);
	if ((*root) == NULL)
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = heapify_up(new);

	return (flip);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}
