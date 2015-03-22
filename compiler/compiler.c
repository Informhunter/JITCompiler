#include "compiler.h"
#include "opcodes/opcodes.h"
#include "bytearray/bytearray.h"
#include <Windows.h>

static void generateCodeR(TreeNode* root, ByteArray* resultCode)
{
    ByteArray* code = resultCode;
    if(root->left && root->right)
    {
        generateCodeR(root->right, code); //Generating in this order, because we need 
        genADD_EDX_4(code);
        generateCodeR(root->left, code);  //left operand to be on top of the stack
    }

    if(root->type == OperandVar)
    {
        genMOV_DWORD_PTR_EDX_EAX(code);
    }
    else if(root->type == OperandNegVar)
    {
        genMOV_DWORD_PTR_EDX_EAX(code);
        genFLD_DWORD_PTR_EDX(code);
        genFCHS(code);
        genFSTP_DWORD_PTR_EDX(code);
    }
    else if(root->type == OperandConst)
    {
        genFLD_DWORD_PTR_ECX(code);
        genFSTP_DWORD_PTR_EDX(code);
        genADD_ECX_4(code);
    }
    else
    {
        genFLD_DWORD_PTR_EDX(code);
        genSUB_EDX_4(code);

        switch(root->type)
        {
            case OperatorPlus:
                genADD_DWORD_PTR_EDX(code);
                break;

            case OperatorMinus:
                genSUB_DWORD_PTR_EDX(code);
                break;

            case OperatorMul:
                genMUL_DWORD_PTR_EDX(code);
                break;

            case OperatorDiv:
                genDIV_DWORD_PTR_EDX(code);
                break;
        }

        genFSTP_DWORD_PTR_EDX(code);
    }
}

static void generateCode(Tree* tree, void** stack, void** consts, ByteArray* resultCode)
{
    ByteArray* code = resultCode;
    //Argument parsing
    genMOV_EAX_ESP_4(code);
    genMOV_EDX_DWORD_PTR(code, (int32_t*)stack);
    genMOV_ECX_DWORD_PTR(code, (int32_t*)consts);
    //Calculating
    generateCodeR(tree->root, code);
    //Return value stuff
    genFLD_DWORD_PTR_EDX(code);
    genRET(code);
}

static void collectConstsR(TreeNode* root, ByteArray* consts)
{
    float* pConst;
    if(root)
    {
        if(root->type == OperandConst)
        {
            pConst = &root->value;
            byteArrayAppend(consts, (char*)pConst, 4);
        }
        else if(root->type < OperandConst)
        {
            collectConstsR(root->right, consts);
            collectConstsR(root->left, consts);
        }
    }
}


CompiledFunc compileTree(Tree* tree)
{
    CompiledFunc result;
    DWORD oldP;
    ByteArray* consts;

    ByteArray* code;
    ByteArray* stack;


    code = byteArrayCreate(2);
    consts = byteArrayCreate(2);
    stack = byteArrayCreate(sizeof(float) * (tree->height + 1));



    collectConstsR(tree->root, consts);

    result.stackP = malloc(sizeof(void*));
    result.constsP = malloc(sizeof(void*));

    *result.stackP = stack->data;
    *result.constsP = consts->data;

    generateCode(tree, result.stackP, result.constsP, code);

    VirtualProtect(code->data, code->dataSize, PAGE_EXECUTE_READWRITE, &oldP);

    result.code = code;
    result.run = (Func)result.code->data;
    result.stack = stack;
    result.consts = consts;

    return result;
}

void compiledFuncFree(CompiledFunc f)
{
    byteArrayFree(f.code);
    byteArrayFree(f.stack);
    byteArrayFree(f.consts);
    free(f.stackP);
    free(f.constsP);
}