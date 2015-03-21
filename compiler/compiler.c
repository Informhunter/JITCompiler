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

static void generateCode(Tree* tree, double* stack, ByteArray* resultCode)
{
	ByteArray* rc = resultCode;
	//Some stack allocation stuff + argument parsing
	
	//Calculating
	generateCodeR(tree->root, rc);
	//Return value stuff
}

CompiledFunc compileTree(Tree* tree);
{
	CompiledFunc result;
	DWORD oldP;
	ByteArray* code;
	double* stack;

	code = byteArrayCreate(2);
	stack = (double *)malloc(sizeof(double) * (tree->height + 1));

	generateCode(tree, stack, code);

	VirtualProtect(code->data, code->dataSize, PAGE_EXECUTE_READ_WRITE, &oldP);

	result.code = code;
	result.run = (Func)result.code->data;
	result.stack = stack;
	
	return result;
}

void compiledFuncFree(CompiledFunc f)
{
	ByteArrayFree(f.code);
	free(f.stack);
}