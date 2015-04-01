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
        generateCodeR(root->left, code);  //left operand to be on top of the stack
    }

    if(root->type == OperandVar)
    {
        genPUSH_EAX(code);
    }
    else if(root->type == OperandNegVar)
    {
        genPUSH_EAX(code);
        genFLD_DWORD_PTR_ESP(code);
        genFCHS(code);
        genFSTP_DWORD_PTR_ESP(code);
    }
    else if(root->type == OperandConst)
    {
        genPUSH_imm32(code, (int32_t*)&root->value);
    }
    else
    {
        genFLD_DWORD_PTR_ESP(code);
        genADD_ESP_4(code);
        switch(root->type)
        {
            case OperatorPlus:
                genFADD_DWORD_PTR_ESP(code);
                break;

            case OperatorMinus:
                genFSUB_DWORD_PTR_ESP(code);
                break;

            case OperatorMul:
                genFMUL_DWORD_PTR_ESP(code);
                break;

            case OperatorDiv:
                genFDIV_DWORD_PTR_ESP(code);
                break;
        }

        genFSTP_DWORD_PTR_ESP(code);
    }
}

static void generateCode(Tree* tree, ByteArray* resultCode)
{
    ByteArray* code = resultCode;
    //X value -> EAX
    genMOV_EAX_ESP_4(code);
    //Generating math code
    generateCodeR(tree->root, code);
    //Return value stuff
    genADD_ESP_4(code);
    genRET(code);
}


CompiledFunc compileTree(Tree* tree)
{
    CompiledFunc result;
    DWORD oldP;
    ByteArray* code;

    code = byteArrayCreate(2);

    generateCode(tree, code);

    VirtualProtect(code->data, code->dataSize, PAGE_EXECUTE_READWRITE, &oldP);

    result.code = code;
    result.run = (Func)result.code->data;
    return result;
}

void compiledFuncFree(CompiledFunc f)
{
    byteArrayFree(f.code);
}