#ifndef _PARSER_H_INCLUDED
#define _PARSER_H_INCLUDED

typedef enum
{
	MinPriority,
	PriorityPlusMinus,
	PriorityMulDiv,
	MaxPriority,
	BadPriority,
} OperatorPriority;

Tree* buildTreeForExpression(char* expression);

#endif