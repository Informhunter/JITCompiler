#include "compiler.h"
#include "opcodes/opcodes.h"
#include "bytearray/bytearray.h"
#include <Windows.h>

static void generateCodeR(TreeNode* root, ByteArray* resultCode, float* currentSP)
{
    ByteArray* rc = resultCode;
    generateCodeR(root->right, rc, currentSP); //Generating in this order, because we need 
    generateCodeR(root->left, rc, currentSP);  //left operand to be on top of the stack
    currentSP += sizeof(float); //Now it points to the top of the stack (left operand)
    switch(root->type)
    {
        case OperatorPlus:
        	genFLD_m32fp(code, currentSP);
        	currentSP -= sizeof(float);
        	genFADD_m32fp(code, currentSP);
        	genFSTP(code, currentSP);
        	break;

        case OperatorMinus:
        	genFLD_m32fp(code, currentSP);
        	currentSP -= sizeof(float);
        	genFSUB_m32fp(code, currentSP);
        	genFSTP(code, currentSP);
        	break;

        case OperatorMul:
        	genFLD_m32fp(code, currentSP);
        	currentSP -= sizeof(float);
        	genFMUL_m32fp(code, currentSP);
        	genFSTP(code, currentSP);
        	break;

        case OperatorDiv:
        	genFLD_m32fp(code, currentSP);
        	currentSP -= sizeof(float);
        	genFDIV_m32fp(code, currentSP);
        	genFSTP(code, currentSP);
        	break;

        case OperandVar:
        	currentSP += sizeof(float);
        	genMOV_m32_EAX(code, currentSP);
        	break;

        case OperandNegVar:
        	currentSP += sizeof(float);
        	genMOV_m32_EAX(code, currentSP);
        	genFCHS(code);
        	break;

        case OperandConst:
            currentSP += sizeof(float);
            genMOV_m32_imm32(code, currentSP, (int32_t) root->value);
            break;
    }
}

static void generateCode(Tree* tree, float* stack, ByteArray* resultCode)
{
    ByteArray* rc = resultCode;
    //Some stack allocation stuff + argument parsing
    gen
    
    //Calculating
    generateCodeR(tree->root, rc);
    //Return value stuff
}

CompiledFunc compileTree(Tree* tree);
{
    CompiledFunc result;
    DWORD oldP;
    ByteArray* code;
    float* stack;

    code = byteArrayCreate(2);
    stack = (float *)malloc(sizeof(float) * (tree->height + 1));

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