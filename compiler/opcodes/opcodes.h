#ifndef _OPCODES_H_INCLUDED
#define _OPCODES_H_INCLUDED

#include "compiller/bytearray/bytearray.h"

void genFLD_m32pf(ByteArray* code, void* srcAddress);
void genFSTP(ByteArray* code, void* dstAddress);
void genFADD_m32fp(ByteArray* code,  void* srcAddress);
void genFSUB_m32fp(ByteArray* code,  void* srcAddress);
void genFMUL_m32fp(ByteArray* code,  void* srcAddress);
void genFDIV_m32fp(ByteArray* code,  void* srcAddress);
void genFCHS(ByteArray* code);
void genRET(ByteArray* code);
void genMOV_m32_imm32(ByteArray* code, void* dstAddress, int32_t value);
void genMOV_EAX_m32(ByteArray* code, void* srcAddress);
void genMOV_m32_EAX(ByteArray* code, void* dstAddress);

#endif