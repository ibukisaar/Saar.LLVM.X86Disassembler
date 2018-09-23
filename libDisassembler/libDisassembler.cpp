#include "Disassembler.h"
#include <llvm\MC\MCRegisterInfo.h>

using namespace llvm;

extern const char X86InstrNameData[];
extern const unsigned X86InstrNameIndices[];

extern const MCRegisterDesc X86RegDesc[];
extern const char X86RegStrings[];



X86DisAsm *CreateDisassembler(bool is64Bit, LLVMOpInfoCallback opInfoCallback, LLVMSymbolLookupCallback symbolLookupCallback) {
	return new X86DisAsm(is64Bit, opInfoCallback, symbolLookupCallback);
}

void DisposeDisassembler(X86DisAsm *disasm) {
	delete disasm;
}

MCInst *CreateInst() {
	return new MCInst;
}

void DisposeInst(MCInst *inst) {
	delete inst;
}

void SetDisassemblerUseMarkup(X86DisAsm *disasm, bool value) {
	disasm->printer->setUseMarkup(value);
}

int GetInstruction(X86DisAsm *disasm, MCInst *inst, uint8_t *data, int bytes, uint64_t PC = 0) {
	uint64_t size;
	MCDisassembler::DecodeStatus s = disasm->disasm->getInstruction(*inst, size, ArrayRef<uint8_t>(data, bytes), PC, nulls(), nulls());
	if (s == MCDisassembler::Success) {
		return size;
	}
	return 0;
}

int GetInstructionString(X86DisAsm *disasm, MCInst *inst, char *buffer, int bufferSize) {
	if (bufferSize <= 0) return 0;

	SmallVector<char, 64> tempStr;
	raw_svector_ostream os(tempStr);
	formatted_raw_ostream formattedOS(os);
	disasm->printer->printInst(inst, formattedOS, StringRef(), *disasm->MSI);
	size_t outSize = std::min((size_t)(bufferSize), tempStr.size());
	if (buffer) {
		std::memcpy(buffer, tempStr.data(), outSize);
	}
	return outSize;
}

const char *GetOpcodeName(unsigned int opcode) {
	return X86InstrNameData + X86InstrNameIndices[opcode];
}

const char *GetRegisterName(unsigned int reg) {
	return X86RegStrings + X86RegDesc[reg].Name;
}

unsigned int GetOpcode(MCInst *inst) { return inst->getOpcode(); }
unsigned int GetOperandCount(MCInst *inst) { return inst->getNumOperands(); }
MCOperand *GetOperand(MCInst *inst, unsigned index) { return &inst->getOperand(index); }
int OperandIsValid(MCOperand *operand) { return operand->isValid(); }
int OperandIsReg(MCOperand *operand) { return operand->isReg(); }
int OperandIsImm(MCOperand *operand) { return operand->isImm(); }
int OperandIsFPImm(MCOperand *operand) { return operand->isFPImm(); }
unsigned int OperandGetReg(MCOperand *operand) { return operand->getReg(); }
int64_t OperandGetImm(MCOperand *operand) { return operand->getImm(); }
double OperandGetFPImm(MCOperand *operand) { return operand->getFPImm(); }