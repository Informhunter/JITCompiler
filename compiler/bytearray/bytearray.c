#include "bytearray.h"

ByteArray* byteArrayCreate(int initialSize)
{
	ByteArray* array = malloc(sizeof(ByteArray));
	array->size = initialSize;
	array->data = malloc(sizeof(char) * initialSize);
	array->dataSize = 0;
	return array;
}

void byteArrayFree(ByteArray* array)
{
	free(array->data);
	free(array);
}

void byteArrayAppendData(ByteArray* array, const char* data, int dataSize)
{
	if(array->size - array->dataSize < dataSize)
	{
		array->size *= 2;
		array->data = realloc(array->data, array->size);
	}
	memcpy(array->data + array->dataSize, data, dataSize);
}

void byteArrayAppendArray(ByteArray* array, const ByteArray* dataArray)
{
	byteArrayAppendData(array, dataArray->data, dataArray->dataSize);
}

ByteArray* byteArrayCat(const ByteArray* array1, const ByteArray* array2)
{
	ByteArray* array;
	array = byteArrayCreate(array1->dataSize + array2->dataSize);
	byteArrayAppend(array, array1->data);
	byteArrayAppend(array, array2->data);
	return array;
}