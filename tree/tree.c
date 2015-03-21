#include <malloc.h>
#include <string.h>
#include <math.h>
#include "tree.h"

TreeNode* treeNodeCreate(TreeNodeType type)
{
    TreeNode* node = malloc(sizeof(TreeNode));
    node->type = type;
    node->left = 0;
    node->right = 0;
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
    return 1 + fmax(treeHeightFromRoot(root->left, currentHeight), treeHeightFromRoot(root->right, currentHeight));
}

void treeDataFree(TreeNode* root)
{
    if(root)
    {
        treeDataFree(root->left);
        treeDataFree(root->right);
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

static float calcTreeFromRoot(TreeNode* root, float x)
{
    
    if(root->type == OperandVar)
        return x;
    if(root->type == OperandNegVar)
        return -x;
    if(root->type == OperandConst)
        return root->value;
        
    switch(root->type)
    {
        case OperatorPlus:
            return calcTreeFromRoot(root->left, x) + calcTreeFromRoot(root->right, x);
        case OperatorMinus:
            return calcTreeFromRoot(root->left, x) - calcTreeFromRoot(root->right, x);
        case OperatorMul:
            return calcTreeFromRoot(root->left, x) * calcTreeFromRoot(root->right, x);
        case OperatorDiv:
            return calcTreeFromRoot(root->left, x) / calcTreeFromRoot(root->right, x);
    }
}

float calcTree(Tree* tree, float x)
{
    return calcTreeFromRoot(tree->root, x);
}