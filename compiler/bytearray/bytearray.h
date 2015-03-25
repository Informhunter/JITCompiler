#ifndef _BYTEARRAY_H_INCLUDED
#define _BYTEARRAY_H_INCLUDED

typedef struct
{
	int size;
	int dataSize;
	char* data;
} ByteArray;

ByteArray* byteArrayCreate(int initialSize);
void byteArrayFree(ByteArray* array);
void byteArrayAppend(ByteArray* array, const char* data, int dataSize);


#endif