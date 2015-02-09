#include "bytearray.h"

ByteArray* byteArrayCreate(int initialSize)
{
	ByteArray* array = malloc(sizeof(ByteArray));
	array->size = initialSize;
	array->data = malloc(sizeof(char) * initialSize);
	array->end = 0;
	return array;
}

void byteArrayFree(ByteArray* array)
{
	free(array->data);
	free(array);
}

void byteArrayAppend(ByteArray* array, const char* data, int dataSize)
{
	if(array->size - array->end < dataSize)
	{
		array->size *= 2;
		array->data = realloc(array->data, array->size);
	}
	memcpy(array->data + array->end, data, dataSize);
}

ByteArray* byteArrayCat(ByateArray* array1, ByteArray* array2)
{
	ByteArray* array;
	array = byteArrayCreate(array1->size + array2->size);
	byteArrayAppend(array, array1->data);
	byteArrayAppend(array, array2->data);
	return array;
}