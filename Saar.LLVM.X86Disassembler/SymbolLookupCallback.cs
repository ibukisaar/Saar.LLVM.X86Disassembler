using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	unsafe public delegate string SymbolLookupCallback(IntPtr DisInfo, ulong ReferenceValue, ulong* ReferenceType, ulong ReferencePC, IntPtr* ReferenceName);
}
