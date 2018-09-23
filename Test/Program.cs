using Saar.LLVM.X86Disassembler;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Test {
	unsafe class Program {
		[DllImport("kernel32")]
		extern static byte* GetProcAddress(IntPtr hModule, [MarshalAs(UnmanagedType.LPStr)] string function);
		[DllImport("kernel32", EntryPoint = "GetModuleHandleW")]
		extern static IntPtr GetModuleHandle([MarshalAs(UnmanagedType.LPWStr)] string moduleName = null);

		static void Main(string[] args) {
			var hModule = GetModuleHandle("user32");
			byte* pc = GetProcAddress(hModule, "MessageBoxA");
			if (pc == null) return;

			var disassembler = new Disassembler();
			var inst = new Instruction();
			while (true) {
				disassembler.GetInstruction(inst, pc);
				var instStr = disassembler.GetInstructionString(inst);
				Console.WriteLine(instStr);
				pc += inst.OpcodeByteCount;
				switch (inst.Opcode) {
					case Opcode.RET:
					case Opcode.RETQ:
					case Opcode.RETIQ:
						goto Exit;
				}
			}
			Exit:;
		}
	}
}
