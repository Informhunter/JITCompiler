#ifndef _COMPILER_H_INCLUDED
#define _COMPILER_H_INCLUDED

#include "tree/tree.h"
#include "bytearray/bytearray.h"

typedef double (*Func)(double);

typedef struct
{
	ByteArray* data;
	Func function;
} CompiledFunc;

CompiledFunc compileTree(Tree* tree);


#endif