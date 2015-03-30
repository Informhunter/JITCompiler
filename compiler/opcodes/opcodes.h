#ifndef _OPCODES_H_INCLUDED
#define _OPCODES_H_INCLUDED

#include <stdint.h>
#include "compiler/bytearray/bytearray.h"

void genADD_ECX_4(ByteArray* code);
void genADD_ESP_4(ByteArray* code);
void genFADD_DWORD_PTR_ESP(ByteArray* code);
void genFCHS(ByteArray* code);
void genFDIV_DWORD_PTR_ESP(ByteArray* code);
void genFLD_DWORD_PTR_ESP(ByteArray* code);
void genFMUL_DWORD_PTR_ESP(ByteArray* code);
void genFSTP(ByteArray* code, void* dstAddress);
void genFSTP_DWORD_PTR_ESP(ByteArray* code);
void genFSUB_DWORD_PTR_ESP(ByteArray* code);
void genMOV_EAX_ESP_4(ByteArray* code);
void genMOV_ECX_DWORD_PTR(ByteArray* code, void* srcAddress);
void genPUSH_DWORD_PTR_ECX(ByteArray* code);
void genPUSH_EAX(ByteArray* code);
void genRET(ByteArray* code);

#endif