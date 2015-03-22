#ifndef _OPCODES_H_INCLUDED
#define _OPCODES_H_INCLUDED

#include <stdint.h>
#include "compiler/bytearray/bytearray.h"

void genFLD_m32fp(ByteArray* code, void* srcAddress);
void genFSTP(ByteArray* code, void* dstAddress);
void genFADD_m32fp(ByteArray* code,  void* srcAddress);
void genFSUB_m32fp(ByteArray* code,  void* srcAddress);
void genFMUL_m32fp(ByteArray* code,  void* srcAddress);
void genFDIV_m32fp(ByteArray* code,  void* srcAddress);
void genFCHS(ByteArray* code);
void genRET(ByteArray* code);
void genMOV_m32_imm32(ByteArray* code, void* dstAddress, int32_t* pValue);
void genMOV_EAX_ESP_4(ByteArray* code);
void genMOV_m32_EAX(ByteArray* code, void* dstAddress);
void genMOV_EDX_imm32(ByteArray* code, int32_t* pValue);
void genADD_EDX_4(ByteArray* code);
void genSUB_EDX_4(ByteArray* code);
void genFSTP_DWORD_PTR_EDX(ByteArray* code);
void genFLD_DWORD_PTR_EDX(ByteArray* code);
void genMOV_DWORD_PTR_EDX_imm32(ByteArray* code, int32_t* pValue);
void genMOV_DWORD_PTR_EDX_EAX(ByteArray* code);
void genADD_DWORD_PTR_EDX(ByteArray* code);
void genSUB_DWORD_PTR_EDX(ByteArray* code);
void genMUL_DWORD_PTR_EDX(ByteArray* code);
void genDIV_DWORD_PTR_EDX(ByteArray* code);
void genMOV_ECX_imm32(ByteArray* code, int32_t* pValue);
void genFLD_DWORD_PTR_ECX(ByteArray* code);
void genADD_ECX_4(ByteArray* code);
void genMOV_EDX_DWORD_PTR(ByteArray* code, void* srcAddress);
void genMOV_ECX_DWORD_PTR(ByteArray* code, void* srcAddress);

#endif