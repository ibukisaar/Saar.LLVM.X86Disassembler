using System;
using System.Collections.Generic;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	public enum OperandType : byte {
		Register, Immediate, FloatingPointImmediate
	}
}
