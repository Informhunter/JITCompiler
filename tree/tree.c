#include <malloc.h>
#include "tree.h"

TreeNode* treeNodeCreate(TreeNodeType type)
{
	TreeNode* node = malloc(sizeof(TreeNode));
	node->type = type;
	node->left = 0;
	node=>right = 0;
	node->value = 0;
	return node;
}

void treeNodeFree(TreeNode* node)
{
	free(node);
}

Tree* treeCreate(TreeNode* root)
{
	Tree* tree = malloc(sizeof(Tree));
	tree->root = treeDataCopy(root);
	tree->height = treeHeightFromRoot(root, 0);
	return tree;
}

void treeFree(Tree* tree)
{
	treeDataFree(tree->root);
	free(tree);
}

int treeHeightFromRoot(TreeNode* root, int currentHeight)
{
	if(!root) return 0;
	return 1 + treeHeight(root->left) + treeHeight(root->right);
}

void treeDataFree(TreeNode* root)
{
	if(root)
	{
		treeFreeData(root->left);
		treeFreeData(root->right);
		treeNodeFree(root);
	}
}

TreeNode* treeDataCopy(TreeNode* root)
{
	TreeNode* node;
	if(!root) return 0;
	node = malloc(sizeof(TreeNode));
	memcpy(node, root, sizeof(TreeNode));
	node->left = treeDataCopy(root->left);
	node->right = treeDataCopy(root->right);
	return node;
}