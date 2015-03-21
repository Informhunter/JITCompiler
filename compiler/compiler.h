#ifndef _COMPILER_H_INCLUDED
#define _COMPILER_H_INCLUDED

#include "tree/tree.h"
#include "bytearray/bytearray.h"

typedef double (*Func)(double);

typdef struct
{
    Func run;
    ByteArray* code;
    double* stack;
} CompiledFunc;

CompiledFunc compileTree(Tree* tree);
void freeCompiledFunc(CompiledFunc f);


#endif