#include <string.h>
#include <stdio.h>
#include "tree/tree.h"
#include "parser.h"

static TreeNodeType getOperatorType(char c)
{
    switch(c)
    {
        case '+':
            return OperatorPlus;
        case '-':
            return OperatorMinus;
        case '*':
            return OperatorMul;
        case '/':
            return OperatorDiv;
    }
}

static TreeNodeType getOperandType(char* expression, int start, int end)
{
    if(expression[start] == '-')
    {
        if(expression[start + 1] == 'x')
            return OperandNegVar;
        return OperandConst;
    }
    else
    {
        if(expression[start] == 'x')
            return OperandVar;
        return OperandConst;
    }
}

float extractConstValue(char* expression, int start, int end)
{
    float result;
    sscanf(expression + start, "%f", &result);
    return result;
}

static int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

static OperatorPriority getOperatorPriority(char c)
{
    switch(c)
    {
        case '+':
        case '-':
            return PriorityPlusMinus;
            break;
        case '*':
        case '/':
            return PriorityMulDiv;
            break;
        default:
            return BadPriority;
    }
}


static int getDivisionIndex(char* expression, int start, int end)
{
    int i;
    int bracketNestingLevel = 0;
    int minPriorityMetIndex = -1;
    OperatorPriority minPriorityMet = MaxPriority;
    OperatorPriority currentPriority;
    
    if(expression[start] == '-') start++;
    
    for(i = start; i <= end; i++)
    {
        if(expression[i] == '(')
        {
            bracketNestingLevel++;
        }
        else if(expression[i] == ')')
        {
            bracketNestingLevel--;
        }
        else if(isOperator(expression[i]) && bracketNestingLevel == 0)
        {
            currentPriority = getOperatorPriority(expression[i]);
            if(currentPriority <= minPriorityMet)
            {
                minPriorityMet = currentPriority;
                minPriorityMetIndex = i;
            }
        }
    }
    return minPriorityMetIndex;
}


static int hasOuterBrackets(char* expr, int start, int end)
{
    int i;
    int count = 0;
    if(expr[start] == '(' && expr[end] == ')')
    {
        for(i = start+1; i <= end - 1; i++)
        {
            if(expr[i] == '(') count++;
            if(expr[i] == ')') count--;
            if(count < 0)
                return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

static TreeNode* buildTreeForExpressionR(char* expression, int start, int end)
{
    TreeNode* root;
    int divIndex;
    while(hasOuterBrackets(expression, start, end))
    {
        start++;
        end--;
    }
    divIndex = getDivisionIndex(expression, start, end);
    if(divIndex > 0)
    {
        root = treeNodeCreate(getOperatorType(expression[divIndex]));
        root->left = buildTreeForExpressionR(expression, start, divIndex - 1);
        root->right = buildTreeForExpressionR(expression, divIndex + 1, end);
    }
    else
    {
        root = treeNodeCreate(getOperandType(expression, start, end));
        if(root->type == OperandConst)
        {
            root->value = extractConstValue(expression, start, end);
        }
    }
    return root;
}

Tree* buildTreeForExpression(char* expression)
{
    Tree* tree;
    TreeNode* root;
    root = buildTreeForExpressionR(expression, 0, strlen(expression) - 1);
    tree = treeCreate(root);
    treeDataFree(root);
    return tree;
}