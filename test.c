#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "parser/parser.h"
#include "compiler/compiler.h"

double measureTimeJIT(Tree* tree, int iters)
{
    int i;
    double result;
    clock_t start, end;
    CompiledFunc f;

    start = clock();
    f = compileTree(tree);
    for (i = 0; i < iters; i++)
    {
        f.run((float) (i % 1000));
    }
    end = clock();

    result = (end - start) / (double)CLOCKS_PER_SEC;

    compiledFuncFree(f);

    return result;
}

double measureTimeNormal(Tree* tree, int iters)
{
    int i;
    clock_t start, end;
    double result;

    start = clock();
    for (i = 0; i < iters; i++)
    {
        calcTree(tree, (float) (i % 1000));
    }
    end = clock();

    result = (end - start) / (double)CLOCKS_PER_SEC;

    return result;
}



int main(int argc, char** argv)
{
    int i;
	char* expr;
	int iters;
    int maxSize;
	Tree* tree;
    FILE* fileJIT;
    FILE* fileNormal;

    if(argc < 3)
    {
        printf("\nUsage: %s {iters} {max input size}\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d", &iters);
    sscanf(argv[2], "%d", &maxSize);

    maxSize = maxSize / 4;

    fileJIT = fopen("jitTime.txt", "w");
    fileNormal = fopen("normalTime.txt", "w");

    expr = calloc(maxSize * 5 + 1, sizeof(char));
    expr[0] = 'x';

    for(i = 0; i < maxSize; i++)
    {
        expr[i*4+1] = '+';
        expr[i*4+2] = 'x';
        expr[i*4+3] = '*';
        expr[i*4+4] = '5';
        expr[i*4+5] = '\0';
        tree = buildTreeForExpression(expr);
        fprintf(fileJIT, "%d %lf\n", 5 + 4 * i, measureTimeJIT(tree, iters));
        fprintf(fileNormal, "%d %lf\n", 5 + 4 * i, measureTimeNormal(tree, iters));
        treeFree(tree);
        if(i % (maxSize / 10) == 0)
        {
            printf("%lf%% done\n", (double) i / maxSize * 100);
        }
    }

    fclose(fileJIT);
    fclose(fileNormal);

	return 0;
}