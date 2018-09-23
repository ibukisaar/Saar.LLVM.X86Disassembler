using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	unsafe public static class Ex {
		public static string GetName(this Register register)
			=> Marshal.PtrToStringAnsi((IntPtr)Native.GetRegisterName(register));

		public static string GetName(this Opcode opcode)
			=> Marshal.PtrToStringAnsi((IntPtr)Native.GetOpcodeName(opcode));
	}
}
