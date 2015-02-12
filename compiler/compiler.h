#ifndef _COMPILER_H_INCLUDED
#define _COMPILER_H_INCLUDED

#include "tree/tree.h"

typedef double (*Func)(double);

Func compileTree(Tree* tree);


#endif