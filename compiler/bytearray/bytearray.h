#ifndef _BYTEARRAY_H_INCLUDED
#define _BYTEARRAY_H_INCLUDED

typedef struct
{
	int size;
	int dataSize;
	char* array;
} ByteArray;

ByteArray* byteArrayCreate(int initialSize);
void byteArrayFree(ByteArray* array);

void byteArrayAppend(ByteArray* array, char* data, int dataSize);
void byteArrayAppendArray(ByteArray* array, const ByteArray* dataArray)
ByteArray* byteArrayCat(const ByateArray* array1, const ByteArray* array2);


#endif