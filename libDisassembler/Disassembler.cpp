#include "Disassembler.h"

using namespace llvm;

struct InitDisAsm {
	InitDisAsm() {
		LLVMInitializeX86Target();
		LLVMInitializeX86TargetInfo();
		LLVMInitializeX86TargetMC();
		LLVMInitializeX86Disassembler();
	}
};

X86DisAsm::X86DisAsm(bool is64Bit, LLVMOpInfoCallback opInfoCallback, LLVMSymbolLookupCallback symbolLookupCallback) {
	static InitDisAsm init;
	const char*const TargetName = is64Bit ? "x86_64" : "x86";

	std::string Error;
	TheTarget = TargetRegistry::lookupTarget(TargetName, Error);
	MCRegisterInfo *MRI = TheTarget->createMCRegInfo(TargetName);
	MCAsmInfo *MAI = TheTarget->createMCAsmInfo(*MRI, TargetName);
	MCInstrInfo *MII = TheTarget->createMCInstrInfo();
	MCSubtargetInfo *MSI = TheTarget->createMCSubtargetInfo(TargetName, "", "");
	MCContext *ctx = new MCContext(MAI, MRI, nullptr);
	MCDisassembler *disasm = TheTarget->createMCDisassembler(*MSI, *ctx);

	std::unique_ptr<MCRelocationInfo> relInfo(TheTarget->createMCRelocationInfo(TargetName, *ctx));
	std::unique_ptr<MCSymbolizer> symbolizer(TheTarget->createMCSymbolizer(TargetName, opInfoCallback, symbolLookupCallback, nullptr, ctx, std::move(relInfo)));
	disasm->setSymbolizer(std::move(symbolizer));

	int asmPrinterVar = MAI->getAssemblerDialect();
	MCInstPrinter *printer = TheTarget->createMCInstPrinter(Triple(TargetName), asmPrinterVar, *MAI, *MII, *MRI);

	this->MAI.reset(MAI);
	this->MRI.reset(MRI);
	this->MII.reset(MII);
	this->MSI.reset(MSI);
	this->ctx.reset(ctx);
	this->disasm.reset(disasm);
	this->printer.reset(printer);
}
