#include "binary_trees.h"

/**
 * recurse - measures the height of the entire binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of a binary tree.
 */
size_t recurse(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	left_height = recurse(tree->left) + 1;
	right_height = recurse(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of a binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (depth);
	for (; tree && tree->parent; tree = tree->parent, depth++)
		;
	return (recurse(tree) - 1 - depth);
}
