#ifndef _TREE_H_INCLUDED
#defien _TREE_H_INCLUDED


typedef enum
{
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	OperandConst,
	OperandVar,
} TreeNodeType;

typedef struct TreeNode TreeNode;
struct TreeNode
{
	TreeNodeType type;
	TreeNode* left;
	TreeNode* right;
	double value;
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

int treeHeightFromRoot(TreeNode* root, int currentHeight);
void treeDataFree(TreeNode* root);
TreeItem* treeDataCopy(TreeNode* root);



#endif