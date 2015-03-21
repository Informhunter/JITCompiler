#ifndef _COMPILER_H_INCLUDED
#define _COMPILER_H_INCLUDED

#include "tree/tree.h"
#include "bytearray/bytearray.h"

typedef float (*Func)(float);

typdef struct
{
    Func run;
    ByteArray* code;
    float* stack;
} CompiledFunc;

CompiledFunc compileTree(Tree* tree);
void freeCompiledFunc(CompiledFunc f);


#endif