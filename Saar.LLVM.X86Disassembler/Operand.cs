using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	[StructLayout(LayoutKind.Explicit)]
	public struct Operand {
		[field: FieldOffset(0)]
		public OperandType Type { get; }
		[field: FieldOffset(sizeof(Register))]
		public Register Register { get; }
		[field: FieldOffset(8)]
		public long Immediate { get; }
		[field: FieldOffset(8)]
		public double FloatingPointImmediate { get; }

		unsafe internal Operand(Native.Operand* operand) {
			this = default;
			if (Native.OperandIsReg(operand)) {
				Type = OperandType.Register;
				Register = Native.OperandGetReg(operand);
			} else if (Native.OperandIsImm(operand)) {
				Type = OperandType.Immediate;
				Immediate = Native.OperandGetImm(operand);
			} else if (Native.OperandIsFPImm(operand)) {
				Type = OperandType.FloatingPointImmediate;
				FloatingPointImmediate = Native.OperandGetFPImm(operand);
			} else {
				throw new ArgumentException(nameof(operand));
			}
		}

		public override string ToString() {
			switch (Type) {
				case OperandType.Register:
					return "reg:" + Register.GetName();
				case OperandType.Immediate:
					return "imm:" + Immediate;
				case OperandType.FloatingPointImmediate:
					return "fpimm:" + FloatingPointImmediate;
				default: throw new InvalidOperationException();
			}
		}
	}
}
