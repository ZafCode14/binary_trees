#include "binary_trees.h"

/**
 * balance_avl - Balance the AVL tree
 * @tree: Pointer to the root of the AVL tree
 *
 * Return: void
 */
void balance_avl(avl_t **tree)
{
	int balance;

	if (tree == NULL || *tree == NULL)
		return;

	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	balance = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Find the successor node value
 * @node: Pointer to the node in the tree
 *
 * Return: The value of the successor node
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);

	left = find_successor(node->left);
	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * remove_node - Remove the node from the BST
 * @root: Pointer to the root node of the BST
 *
 * Return: 0 if successful, else successor value
 */
int remove_node(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = find_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Remove a node with a specific value from the BST
 * @root: Pointer to the root node of the BST
 * @value: Value to be removed from the BST
 *
 * Return: Pointer to the root node of the BST after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node with a specific value from the AVL Tree
 * @root: Pointer to the root node of the AVL Tree
 * @value: Value to be removed from the AVL Tree
 *
 * Return: Pointer to the root node of the AVL Tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_a == NULL)
		return (NULL);

	balance_avl(&root_a);
	return (root_a);
}
