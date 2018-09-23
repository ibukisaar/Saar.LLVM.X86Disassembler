using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	[SuppressUnmanagedCodeSecurity]
	unsafe internal static class Native {
		public struct Disassembler { }
		public struct Inst { }
		public struct Operand { }


		const string DllName = "libDisassembler";

		[DllImport(DllName)]
		public extern static Disassembler* CreateDisassembler(bool is64Bit, OpInfoCallback opInfoCallback, SymbolLookupCallback symbolLookupCallback);
		[DllImport(DllName)]
		public extern static void DisposeDisassembler(Disassembler* disasm);
		[DllImport(DllName)]
		public extern static Inst* CreateInst();
		[DllImport(DllName)]
		public extern static void DisposeInst(Inst* inst);
		[DllImport(DllName)]
		public extern static void SetDisassemblerUseMarkup(Disassembler* disasm, bool value);
		[DllImport(DllName)]
		public extern static int GetInstruction(Disassembler* disasm, Inst* inst, byte* opcodeBytes, int opcodeByteCount, long PC);
		[DllImport(DllName)]
		public extern static int GetInstructionString(Disassembler* disasm, Inst* inst, byte* buffer, int bufferLength);
		[DllImport(DllName)]
		public extern static byte* GetOpcodeName(Opcode opcode);
		[DllImport(DllName)]
		public extern static byte* GetRegisterName(Register register);
		[DllImport(DllName)]
		public extern static Operand* GetOperand(Inst* inst, int index);
		[DllImport(DllName)]
		public extern static Opcode GetOpcode(Inst* inst);
		[DllImport(DllName)]
		public extern static int GetOperandCount(Inst* inst);
		[DllImport(DllName)]
		public extern static bool OperandIsValid(Operand* operand);
		[DllImport(DllName)]
		public extern static bool OperandIsReg(Operand* operand);
		[DllImport(DllName)]
		public extern static bool OperandIsImm(Operand* operand);
		[DllImport(DllName)]
		public extern static bool OperandIsFPImm(Operand* operand);
		[DllImport(DllName)]
		public extern static Register OperandGetReg(Operand* operand);
		[DllImport(DllName)]
		public extern static long OperandGetImm(Operand* operand);
		[DllImport(DllName)]
		public extern static double OperandGetFPImm(Operand* operand);
	}
}
