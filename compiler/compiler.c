#include "compiler.h"
#include "bytearray/bytearray.h"
#include <Windows.h>

static void generateCodeR(TreeNode* root, ByteArray* resultCode)
{
	ByteArray* rc = resultCode;
	generateCodeR(root->left, rc);
	generateCodeR(root->right, rc);
	switch(root->type)
	{
		case OperatorPlus:

		case OperatorMinus:

		case OperatorMul:

		case OperatorDiv:

		case OperandVar:

		case OperandNegVar:

		case OperandConst:
			
	}
}

static void generateCode(Tree* tree, ByteArray* resultCode)
{
	ByteArray* rc = resultCode;
	//Some stack allocation stuff + argument parsing
	
	//Calculating
	generateCodeR(tree->root, rc);
	//Return value stuff
}

Func compileTree(Tree* tree);
{
	DWORD oldP;
	char* resultCode;
	ByteArray* code;
	code = byteArrayCreate(2);
	generateCode(tree, code);
	resultCode = malloc(code->dataSize);
	memcpy(resultCode, code->data, code->dataSize);
	VirtualProtect(resultCode, code->dataSize, PAGE_EXECUTE_READ_WRITE, &oldP);
	ByteArrayFree(code);
	return (Func) resultCode;
}