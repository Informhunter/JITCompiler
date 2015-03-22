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

void genMOV_EDX_imm32(ByteArray* code, int32_t* pValue)
{
    byteArrayAppend(code, "\xBA", 1);
    byteArrayAppend(code, (char *)pValue, 4);
}

void genADD_EDX_4(ByteArray* code)
{
    byteArrayAppend(code, "\x83\xC2\x04", 3);
}

void genSUB_EDX_4(ByteArray* code)
{
    byteArrayAppend(code, "\x83\xEA\x04", 3);
}

void genFSTP_DWORD_PTR_EDX(ByteArray* code)
{
    byteArrayAppend(code, "\xD9\x1A", 2);
}

void genFLD_DWORD_PTR_EDX(ByteArray* code)
{
    byteArrayAppend(code, "\xD9\x02", 2);
}

void genMOV_DWORD_PTR_EDX_imm32(ByteArray* code, int32_t* pValue)
{
    byteArrayAppend(code, "\xC7\x02", 2);
    byteArrayAppend(code, (char *)pValue, 4);
}

void genMOV_DWORD_PTR_EDX_EAX(ByteArray* code)
{
    byteArrayAppend(code, "\x89\x02", 2);
}

void genADD_DWORD_PTR_EDX(ByteArray* code)
{
    byteArrayAppend(code, "\xD8\x02", 2);
}

void genSUB_DWORD_PTR_EDX(ByteArray* code)
{
    byteArrayAppend(code, "\xD8\x22", 2);
}

void genMUL_DWORD_PTR_EDX(ByteArray* code)
{
    byteArrayAppend(code, "\xD8\x0A", 2);
}

void genDIV_DWORD_PTR_EDX(ByteArray* code)
{
    byteArrayAppend(code, "\xD8\x32", 2);
}

void genMOV_ECX_imm32(ByteArray* code, int32_t* pValue)
{
    byteArrayAppend(code, "\xB9", 1);
    byteArrayAppend(code, (char *)pValue, 4);
}

void genFLD_DWORD_PTR_ECX(ByteArray* code)
{
    byteArrayAppend(code, "\xD9\x01", 2);
}

void genADD_ECX_4(ByteArray* code)
{
    byteArrayAppend(code, "\x83\xC1\x04", 3);
}

void genMOV_EDX_DWORD_PTR(ByteArray* code, void* srcAddress)
{
    byteArrayAppend(code, "\x8B\x15", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}

void genMOV_ECX_DWORD_PTR(ByteArray* code, void* srcAddress)
{
    byteArrayAppend(code, "\x8B\x0D", 2);
    byteArrayAppend(code, (char *)&srcAddress, 4);
}