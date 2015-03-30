#ifndef _COMPILER_H_INCLUDED
#define _COMPILER_H_INCLUDED

#include "tree/tree.h"
#include "bytearray/bytearray.h"

typedef float _cdecl (*Func)(float);

typedef struct
{
    Func run;
    ByteArray* code;
    ByteArray* consts;
    void** constsP;
} CompiledFunc;

CompiledFunc compileTree(Tree* tree);
void freeCompiledFunc(CompiledFunc f);

#endif