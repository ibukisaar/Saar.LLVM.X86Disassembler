#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <llvm-c\Target.h>
#include <llvm\MC\MCInst.h>
#include <llvm\MC\MCDisassembler\MCDisassembler.h>
#include <llvm\MC\MCSubtargetInfo.h>
#include <llvm\MC\MCContext.h>
#include <llvm\MC\MCAsmInfo.h>
#include <llvm\MC\MCInstrInfo.h>
#include <llvm\MC\MCInstPrinter.h>
#include <llvm\CodeGen\TargetSubtargetInfo.h>
#include <llvm\Support\TargetRegistry.h>

struct X86DisAsm {
	const llvm::Target *TheTarget;
	std::unique_ptr<const llvm::MCRegisterInfo> MRI;
	std::unique_ptr<const llvm::MCAsmInfo> MAI;
	std::unique_ptr<const llvm::MCInstrInfo> MII;
	std::unique_ptr<const llvm::MCSubtargetInfo> MSI;
	std::unique_ptr<const llvm::MCContext> ctx;
	std::unique_ptr<const llvm::MCDisassembler> disasm;
	std::unique_ptr<llvm::MCInstPrinter> printer;
	
	X86DisAsm(bool is64Bit, LLVMOpInfoCallback opInfoCallback, LLVMSymbolLookupCallback symbolLookupCallback);
};