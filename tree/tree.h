#ifndef _TREE_H_INCLUDED
#define _TREE_H_INCLUDED


typedef enum
{
    OperatorPlus,
    OperatorMinus,
    OperatorMul,
    OperatorDiv,
    OperandConst,
    OperandVar,
    OperandNegVar,
} TreeNodeType;

typedef struct TreeNode TreeNode;
struct TreeNode
{
    TreeNodeType type;
    TreeNode* left;
    TreeNode* right;
    float value;
};

typedef struct
{
    TreeNode* root;
    int height;
} Tree;

TreeNode* treeNodeCreate(TreeNodeType type);
void treeNodeFree(TreeNode* node);

Tree* treeCreate(TreeNode* root);
void treeFree(Tree* tree);

float calcTree(Tree* tree, float x);

int treeHeightFromRoot(TreeNode* root, int currentHeight);
void treeDataFree(TreeNode* root);
TreeNode* treeDataCopy(TreeNode* root);



#endif