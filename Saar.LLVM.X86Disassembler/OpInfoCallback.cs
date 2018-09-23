using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	unsafe public delegate int OpInfoCallback(IntPtr DisInfo, ulong PC, ulong Offset, ulong Size, int TagType, IntPtr TagBuf);
}
