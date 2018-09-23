using System;
using System.Collections.Generic;
using System.Text;

namespace Saar.LLVM.X86Disassembler {
	public abstract class Disposable : IDisposable {
		public bool IsDisposed { get; private set; } = false;

		protected virtual void Dispose(bool disposing) {
			if (!IsDisposed) {
				if (disposing) {
					GC.SuppressFinalize(this);
				}

				IsDisposed = true;
			}
		}

		~Disposable() {
			Dispose(false);
		}

		public void Dispose() {
			Dispose(true);
		}
	}
}
