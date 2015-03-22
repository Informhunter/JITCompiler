#include "opcodes.h"
#include "compiler/bytearray/bytearray.h"

void genFLD_m32fp(ByteArray* code, void* srcAddress)
{
    byteArrayAppend(code, "\xD9\x05", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}

void genFSTP(ByteArray* code, void* dstAddress)
{
    byteArrayAppend(code, "\xD9\x15", 2);
    byteArrayAppend(code, (char *)&dstAddress, 4);
}

void genFADD_m32fp(ByteArray* code,  void* srcAddress)
{
    byteArrayAppend(code, "\xD8\x05", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}

void genFSUB_m32fp(ByteArray* code,  void* srcAddress)
{
    byteArrayAppend(code, "\xD8\x25", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}

void genFMUL_m32fp(ByteArray* code,  void* srcAddress)
{
    byteArrayAppend(code, "\xD8\x0D", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}

void genFDIV_m32fp(ByteArray* code,  void* srcAddress)
{
    byteArrayAppend(code, "\xD8\x35", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}

void genFCHS(ByteArray* code)
{
    byteArrayAppend(code, "\xD0\xE0", 2);
}

void genRET(ByteArray* code)
{
    byteArrayAppend(code, "\xC3", 1);
}

void genMOV_m32_imm32(ByteArray* code, void* dstAddress, int32_t* pValue)
{
    byteArrayAppend(code, "\xC7\x05", 2);
    byteArrayAppend(code, (char *)&dstAddress, 4);
    byteArrayAppend(code, (char *)pValue, 4);
}

void genMOV_m32_EAX(ByteArray* code, void* dstAddress)
{
    byteArrayAppend(code, "\x89\x05", 2);
    byteArrayAppend(code, (char *)&dstAddress, 4);
}

void genMOV_EAX_ESP_4(ByteArray* code)
{
    byteArrayAppend(code, "\x8B\x44\x24\x04", 4);
}