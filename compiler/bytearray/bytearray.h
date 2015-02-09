#ifndef _BYTEARRAY_H_INCLUDED
#define _BYTEARRAY_H_INCLUDED

typedef struct
{
	int size;
	int end;
	char* array;
} ByteArray;

ByteArray* byteArrayCreate(int initialSize);
void byteArrayFree(ByteArray* array);

void byteArrayAppend(ByteArray* array, char* data, int dataSize);
ByteArray* byteArrayCat(ByateArray* array1, ByteArray* array2);


#endif