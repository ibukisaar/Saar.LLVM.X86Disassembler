using System;
using System.Collections.Generic;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	[System.Diagnostics.DebuggerDisplay("{" + nameof(Opcode) + "}")]
	unsafe public class Instruction : Disposable {
		internal Native.Inst* pointer;

		public int OpcodeByteCount { get; internal set; }

		public Opcode Opcode => Native.GetOpcode(pointer);

		public int OperandCount => Native.GetOperandCount(pointer);

		public Operand[] GetOperands() {
			int count = Native.GetOperandCount(pointer);
			if (count == 0) return Array.Empty<Operand>();
			var result = new Operand[count];
			for (int i = 0; i < result.Length; i++) {
				result[i] = GetOperand(i);
			}
			return result;
		}

		public Operand GetOperand(int index)
			=> new Operand(Native.GetOperand(pointer, index));

		public Instruction() {
			pointer = Native.CreateInst();
		}

		protected override void Dispose(bool disposing) {
			if (pointer != null) {
				Native.DisposeInst(pointer);
				pointer = null;
			}
			base.Dispose(disposing);
		}
	}
}
