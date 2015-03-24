#include <malloc.h>
#include <string.h>
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

void byteArrayAppend(ByteArray* array, const char* data, int dataSize)
{
	if(array->size - array->dataSize < dataSize)
	{
        while(array->size - array->dataSize < dataSize)
            array->size *= 2;
		array->data = realloc(array->data, array->size);
	}
	memcpy(array->data + array->dataSize, data, dataSize);
    array->dataSize += dataSize;
}