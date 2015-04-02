#include <stdio.h>
#include <time.h>
#include "parser/parser.h"
#include "compiler/compiler.h"


int main()
{
    int i;
    Tree* tree;
    char expr[100];
    CompiledFunc f;

    scanf("%s", expr);

    tree = buildTreeForExpression(expr);

    f = compileTree(tree);
    for(i = 0; i < 100; i++)
    {
        printf("%f\n", f.run((float)i));
    }

    getchar();
    getchar();
    return 0;
}