using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	unsafe public class Disassembler : Disposable {
		private Native.Disassembler* pointer;
		private readonly OpInfoCallback opInfoCallback;
		private readonly SymbolLookupCallback symbolLookupCallback;

		public Disassembler(bool is64Bit = true, OpInfoCallback opInfoCallback = null, SymbolLookupCallback symbolLookupCallback = null) {
			this.opInfoCallback = opInfoCallback;
			this.symbolLookupCallback = symbolLookupCallback;
			pointer = Native.CreateDisassembler(is64Bit, this.opInfoCallback, this.symbolLookupCallback);
		}

		protected override void Dispose(bool disposing) {
			if (pointer != null) {
				Native.DisposeDisassembler(pointer);
				pointer = null;
			}
			base.Dispose(disposing);
		}

		public void SetUseMarkup(bool value) {
			Native.SetDisassemblerUseMarkup(pointer, value);
		}

		public int GetInstruction(Instruction outInstruction, ReadOnlySpan<byte> opcodes, void* pc = null) {
			fixed (byte* p = opcodes) {
				int size = Native.GetInstruction(pointer, outInstruction.pointer, p, opcodes.Length, (long)pc);
				outInstruction.OpcodeByteCount = size;
				return size;
			}
		}

		public Instruction GetInstruction(ReadOnlySpan<byte> opcodes, void* pc = null) {
			var result = new Instruction();
			GetInstruction(result, opcodes, pc);
			return result;
		}

		public int GetInstruction(Instruction outInstruction, void* pc) {
			return GetInstruction(outInstruction, new ReadOnlySpan<byte>(pc, 32), pc);
		}

		public Instruction GetInstruction(void* pc) {
			return GetInstruction(new ReadOnlySpan<byte>(pc, 32), pc);
		}

		public string GetInstructionString(Instruction instruction) {
			byte* buffer = stackalloc byte[1000];
			int length = Native.GetInstructionString(pointer, instruction.pointer, buffer, 1000);
			return Marshal.PtrToStringAnsi((IntPtr)buffer, length).Trim();
		}
	}
}
