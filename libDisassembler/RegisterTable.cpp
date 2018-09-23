#include <llvm\MC\MCRegisterInfo.h>

using namespace llvm;

namespace X86 {
	enum {
		NoRegister,
		AH = 1,
		AL = 2,
		AX = 3,
		BH = 4,
		BL = 5,
		BP = 6,
		BPH = 7,
		BPL = 8,
		BX = 9,
		CH = 10,
		CL = 11,
		CS = 12,
		CX = 13,
		DF = 14,
		DH = 15,
		DI = 16,
		DIH = 17,
		DIL = 18,
		DL = 19,
		DS = 20,
		DX = 21,
		EAX = 22,
		EBP = 23,
		EBX = 24,
		ECX = 25,
		EDI = 26,
		EDX = 27,
		EFLAGS = 28,
		EIP = 29,
		EIZ = 30,
		ES = 31,
		ESI = 32,
		ESP = 33,
		FPSW = 34,
		FS = 35,
		GS = 36,
		HAX = 37,
		HBP = 38,
		HBX = 39,
		HCX = 40,
		HDI = 41,
		HDX = 42,
		HIP = 43,
		HSI = 44,
		HSP = 45,
		IP = 46,
		RAX = 47,
		RBP = 48,
		RBX = 49,
		RCX = 50,
		RDI = 51,
		RDX = 52,
		RIP = 53,
		RIZ = 54,
		RSI = 55,
		RSP = 56,
		SI = 57,
		SIH = 58,
		SIL = 59,
		SP = 60,
		SPH = 61,
		SPL = 62,
		SS = 63,
		SSP = 64,
		BND0 = 65,
		BND1 = 66,
		BND2 = 67,
		BND3 = 68,
		CR0 = 69,
		CR1 = 70,
		CR2 = 71,
		CR3 = 72,
		CR4 = 73,
		CR5 = 74,
		CR6 = 75,
		CR7 = 76,
		CR8 = 77,
		CR9 = 78,
		CR10 = 79,
		CR11 = 80,
		CR12 = 81,
		CR13 = 82,
		CR14 = 83,
		CR15 = 84,
		DR0 = 85,
		DR1 = 86,
		DR2 = 87,
		DR3 = 88,
		DR4 = 89,
		DR5 = 90,
		DR6 = 91,
		DR7 = 92,
		DR8 = 93,
		DR9 = 94,
		DR10 = 95,
		DR11 = 96,
		DR12 = 97,
		DR13 = 98,
		DR14 = 99,
		DR15 = 100,
		FP0 = 101,
		FP1 = 102,
		FP2 = 103,
		FP3 = 104,
		FP4 = 105,
		FP5 = 106,
		FP6 = 107,
		FP7 = 108,
		K0 = 109,
		K1 = 110,
		K2 = 111,
		K3 = 112,
		K4 = 113,
		K5 = 114,
		K6 = 115,
		K7 = 116,
		MM0 = 117,
		MM1 = 118,
		MM2 = 119,
		MM3 = 120,
		MM4 = 121,
		MM5 = 122,
		MM6 = 123,
		MM7 = 124,
		R8 = 125,
		R9 = 126,
		R10 = 127,
		R11 = 128,
		R12 = 129,
		R13 = 130,
		R14 = 131,
		R15 = 132,
		ST0 = 133,
		ST1 = 134,
		ST2 = 135,
		ST3 = 136,
		ST4 = 137,
		ST5 = 138,
		ST6 = 139,
		ST7 = 140,
		XMM0 = 141,
		XMM1 = 142,
		XMM2 = 143,
		XMM3 = 144,
		XMM4 = 145,
		XMM5 = 146,
		XMM6 = 147,
		XMM7 = 148,
		XMM8 = 149,
		XMM9 = 150,
		XMM10 = 151,
		XMM11 = 152,
		XMM12 = 153,
		XMM13 = 154,
		XMM14 = 155,
		XMM15 = 156,
		XMM16 = 157,
		XMM17 = 158,
		XMM18 = 159,
		XMM19 = 160,
		XMM20 = 161,
		XMM21 = 162,
		XMM22 = 163,
		XMM23 = 164,
		XMM24 = 165,
		XMM25 = 166,
		XMM26 = 167,
		XMM27 = 168,
		XMM28 = 169,
		XMM29 = 170,
		XMM30 = 171,
		XMM31 = 172,
		YMM0 = 173,
		YMM1 = 174,
		YMM2 = 175,
		YMM3 = 176,
		YMM4 = 177,
		YMM5 = 178,
		YMM6 = 179,
		YMM7 = 180,
		YMM8 = 181,
		YMM9 = 182,
		YMM10 = 183,
		YMM11 = 184,
		YMM12 = 185,
		YMM13 = 186,
		YMM14 = 187,
		YMM15 = 188,
		YMM16 = 189,
		YMM17 = 190,
		YMM18 = 191,
		YMM19 = 192,
		YMM20 = 193,
		YMM21 = 194,
		YMM22 = 195,
		YMM23 = 196,
		YMM24 = 197,
		YMM25 = 198,
		YMM26 = 199,
		YMM27 = 200,
		YMM28 = 201,
		YMM29 = 202,
		YMM30 = 203,
		YMM31 = 204,
		ZMM0 = 205,
		ZMM1 = 206,
		ZMM2 = 207,
		ZMM3 = 208,
		ZMM4 = 209,
		ZMM5 = 210,
		ZMM6 = 211,
		ZMM7 = 212,
		ZMM8 = 213,
		ZMM9 = 214,
		ZMM10 = 215,
		ZMM11 = 216,
		ZMM12 = 217,
		ZMM13 = 218,
		ZMM14 = 219,
		ZMM15 = 220,
		ZMM16 = 221,
		ZMM17 = 222,
		ZMM18 = 223,
		ZMM19 = 224,
		ZMM20 = 225,
		ZMM21 = 226,
		ZMM22 = 227,
		ZMM23 = 228,
		ZMM24 = 229,
		ZMM25 = 230,
		ZMM26 = 231,
		ZMM27 = 232,
		ZMM28 = 233,
		ZMM29 = 234,
		ZMM30 = 235,
		ZMM31 = 236,
		R8B = 237,
		R9B = 238,
		R10B = 239,
		R11B = 240,
		R12B = 241,
		R13B = 242,
		R14B = 243,
		R15B = 244,
		R8BH = 245,
		R9BH = 246,
		R10BH = 247,
		R11BH = 248,
		R12BH = 249,
		R13BH = 250,
		R14BH = 251,
		R15BH = 252,
		R8D = 253,
		R9D = 254,
		R10D = 255,
		R11D = 256,
		R12D = 257,
		R13D = 258,
		R14D = 259,
		R15D = 260,
		R8W = 261,
		R9W = 262,
		R10W = 263,
		R11W = 264,
		R12W = 265,
		R13W = 266,
		R14W = 267,
		R15W = 268,
		R8WH = 269,
		R9WH = 270,
		R10WH = 271,
		R11WH = 272,
		R12WH = 273,
		R13WH = 274,
		R14WH = 275,
		R15WH = 276,
		NUM_TARGET_REGS 	// 277
	};

	enum {
		GR8RegClassID = 0,
		GRH8RegClassID = 1,
		GR8_NOREXRegClassID = 2,
		GR8_ABCD_HRegClassID = 3,
		GR8_ABCD_LRegClassID = 4,
		GRH16RegClassID = 5,
		GR16RegClassID = 6,
		GR16_NOREXRegClassID = 7,
		VK1RegClassID = 8,
		VK16RegClassID = 9,
		VK2RegClassID = 10,
		VK4RegClassID = 11,
		VK8RegClassID = 12,
		VK16WMRegClassID = 13,
		VK1WMRegClassID = 14,
		VK2WMRegClassID = 15,
		VK4WMRegClassID = 16,
		VK8WMRegClassID = 17,
		SEGMENT_REGRegClassID = 18,
		GR16_ABCDRegClassID = 19,
		FPCCRRegClassID = 20,
		FR32XRegClassID = 21,
		LOW32_ADDR_ACCESS_RBPRegClassID = 22,
		LOW32_ADDR_ACCESSRegClassID = 23,
		LOW32_ADDR_ACCESS_RBP_with_sub_8bitRegClassID = 24,
		DEBUG_REGRegClassID = 25,
		FR32RegClassID = 26,
		GR32RegClassID = 27,
		GR32_NOSPRegClassID = 28,
		LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREXRegClassID = 29,
		GR32_NOREXRegClassID = 30,
		VK32RegClassID = 31,
		GR32_NOREX_NOSPRegClassID = 32,
		RFP32RegClassID = 33,
		VK32WMRegClassID = 34,
		GR32_ABCDRegClassID = 35,
		GR32_TCRegClassID = 36,
		GR32_ADRegClassID = 37,
		LOW32_ADDR_ACCESS_RBP_with_sub_32bitRegClassID = 38,
		CCRRegClassID = 39,
		DFCCRRegClassID = 40,
		LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bitRegClassID = 41,
		LOW32_ADDR_ACCESS_with_sub_32bitRegClassID = 42,
		RFP64RegClassID = 43,
		FR64XRegClassID = 44,
		GR64RegClassID = 45,
		CONTROL_REGRegClassID = 46,
		FR64RegClassID = 47,
		GR64_with_sub_8bitRegClassID = 48,
		GR64_NOSPRegClassID = 49,
		GR64_NOREXRegClassID = 50,
		GR64_TCRegClassID = 51,
		GR64_NOSP_and_GR64_TCRegClassID = 52,
		GR64_TCW64RegClassID = 53,
		GR64_with_sub_16bit_in_GR16_NOREXRegClassID = 54,
		VK64RegClassID = 55,
		VR64RegClassID = 56,
		GR64_NOREX_NOSPRegClassID = 57,
		GR64_NOSP_and_GR64_TCW64RegClassID = 58,
		GR64_TC_and_GR64_TCW64RegClassID = 59,
		VK64WMRegClassID = 60,
		GR64_NOREX_and_GR64_TCRegClassID = 61,
		GR64_TC_and_GR64_NOSP_and_GR64_TCW64RegClassID = 62,
		GR64_NOREX_NOSP_and_GR64_TCRegClassID = 63,
		GR64_ABCDRegClassID = 64,
		GR64_NOREX_and_GR64_TCW64RegClassID = 65,
		GR64_with_sub_32bit_in_GR32_TCRegClassID = 66,
		GR64_ADRegClassID = 67,
		GR64_and_LOW32_ADDR_ACCESS_RBPRegClassID = 68,
		GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBPRegClassID = 69,
		GR64_and_LOW32_ADDR_ACCESSRegClassID = 70,
		RSTRegClassID = 71,
		RFP80RegClassID = 72,
		VR128XRegClassID = 73,
		VR128RegClassID = 74,
		VR128HRegClassID = 75,
		VR128LRegClassID = 76,
		BNDRRegClassID = 77,
		VR256XRegClassID = 78,
		VR256RegClassID = 79,
		VR256HRegClassID = 80,
		VR256LRegClassID = 81,
		VR512RegClassID = 82,
		VR512_with_sub_xmm_in_FR32RegClassID = 83,
		VR512_with_sub_xmm_in_VR128HRegClassID = 84,
		VR512_with_sub_xmm_in_VR128LRegClassID = 85,

	};
}

extern const char X86RegStrings[] = {
	/* 0 */ 'X', 'M', 'M', '1', '0', 0,
	/* 6 */ 'Y', 'M', 'M', '1', '0', 0,
	/* 12 */ 'Z', 'M', 'M', '1', '0', 0,
	/* 18 */ 'C', 'R', '1', '0', 0,
	/* 23 */ 'D', 'R', '1', '0', 0,
	/* 28 */ 'X', 'M', 'M', '2', '0', 0,
	/* 34 */ 'Y', 'M', 'M', '2', '0', 0,
	/* 40 */ 'Z', 'M', 'M', '2', '0', 0,
	/* 46 */ 'X', 'M', 'M', '3', '0', 0,
	/* 52 */ 'Y', 'M', 'M', '3', '0', 0,
	/* 58 */ 'Z', 'M', 'M', '3', '0', 0,
	/* 64 */ 'B', 'N', 'D', '0', 0,
	/* 69 */ 'K', '0', 0,
	/* 72 */ 'X', 'M', 'M', '0', 0,
	/* 77 */ 'Y', 'M', 'M', '0', 0,
	/* 82 */ 'Z', 'M', 'M', '0', 0,
	/* 87 */ 'F', 'P', '0', 0,
	/* 91 */ 'C', 'R', '0', 0,
	/* 95 */ 'D', 'R', '0', 0,
	/* 99 */ 'S', 'T', '0', 0,
	/* 103 */ 'X', 'M', 'M', '1', '1', 0,
	/* 109 */ 'Y', 'M', 'M', '1', '1', 0,
	/* 115 */ 'Z', 'M', 'M', '1', '1', 0,
	/* 121 */ 'C', 'R', '1', '1', 0,
	/* 126 */ 'D', 'R', '1', '1', 0,
	/* 131 */ 'X', 'M', 'M', '2', '1', 0,
	/* 137 */ 'Y', 'M', 'M', '2', '1', 0,
	/* 143 */ 'Z', 'M', 'M', '2', '1', 0,
	/* 149 */ 'X', 'M', 'M', '3', '1', 0,
	/* 155 */ 'Y', 'M', 'M', '3', '1', 0,
	/* 161 */ 'Z', 'M', 'M', '3', '1', 0,
	/* 167 */ 'B', 'N', 'D', '1', 0,
	/* 172 */ 'K', '1', 0,
	/* 175 */ 'X', 'M', 'M', '1', 0,
	/* 180 */ 'Y', 'M', 'M', '1', 0,
	/* 185 */ 'Z', 'M', 'M', '1', 0,
	/* 190 */ 'F', 'P', '1', 0,
	/* 194 */ 'C', 'R', '1', 0,
	/* 198 */ 'D', 'R', '1', 0,
	/* 202 */ 'S', 'T', '1', 0,
	/* 206 */ 'X', 'M', 'M', '1', '2', 0,
	/* 212 */ 'Y', 'M', 'M', '1', '2', 0,
	/* 218 */ 'Z', 'M', 'M', '1', '2', 0,
	/* 224 */ 'C', 'R', '1', '2', 0,
	/* 229 */ 'D', 'R', '1', '2', 0,
	/* 234 */ 'X', 'M', 'M', '2', '2', 0,
	/* 240 */ 'Y', 'M', 'M', '2', '2', 0,
	/* 246 */ 'Z', 'M', 'M', '2', '2', 0,
	/* 252 */ 'B', 'N', 'D', '2', 0,
	/* 257 */ 'K', '2', 0,
	/* 260 */ 'X', 'M', 'M', '2', 0,
	/* 265 */ 'Y', 'M', 'M', '2', 0,
	/* 270 */ 'Z', 'M', 'M', '2', 0,
	/* 275 */ 'F', 'P', '2', 0,
	/* 279 */ 'C', 'R', '2', 0,
	/* 283 */ 'D', 'R', '2', 0,
	/* 287 */ 'S', 'T', '2', 0,
	/* 291 */ 'X', 'M', 'M', '1', '3', 0,
	/* 297 */ 'Y', 'M', 'M', '1', '3', 0,
	/* 303 */ 'Z', 'M', 'M', '1', '3', 0,
	/* 309 */ 'C', 'R', '1', '3', 0,
	/* 314 */ 'D', 'R', '1', '3', 0,
	/* 319 */ 'X', 'M', 'M', '2', '3', 0,
	/* 325 */ 'Y', 'M', 'M', '2', '3', 0,
	/* 331 */ 'Z', 'M', 'M', '2', '3', 0,
	/* 337 */ 'B', 'N', 'D', '3', 0,
	/* 342 */ 'K', '3', 0,
	/* 345 */ 'X', 'M', 'M', '3', 0,
	/* 350 */ 'Y', 'M', 'M', '3', 0,
	/* 355 */ 'Z', 'M', 'M', '3', 0,
	/* 360 */ 'F', 'P', '3', 0,
	/* 364 */ 'C', 'R', '3', 0,
	/* 368 */ 'D', 'R', '3', 0,
	/* 372 */ 'S', 'T', '3', 0,
	/* 376 */ 'X', 'M', 'M', '1', '4', 0,
	/* 382 */ 'Y', 'M', 'M', '1', '4', 0,
	/* 388 */ 'Z', 'M', 'M', '1', '4', 0,
	/* 394 */ 'C', 'R', '1', '4', 0,
	/* 399 */ 'D', 'R', '1', '4', 0,
	/* 404 */ 'X', 'M', 'M', '2', '4', 0,
	/* 410 */ 'Y', 'M', 'M', '2', '4', 0,
	/* 416 */ 'Z', 'M', 'M', '2', '4', 0,
	/* 422 */ 'K', '4', 0,
	/* 425 */ 'X', 'M', 'M', '4', 0,
	/* 430 */ 'Y', 'M', 'M', '4', 0,
	/* 435 */ 'Z', 'M', 'M', '4', 0,
	/* 440 */ 'F', 'P', '4', 0,
	/* 444 */ 'C', 'R', '4', 0,
	/* 448 */ 'D', 'R', '4', 0,
	/* 452 */ 'S', 'T', '4', 0,
	/* 456 */ 'X', 'M', 'M', '1', '5', 0,
	/* 462 */ 'Y', 'M', 'M', '1', '5', 0,
	/* 468 */ 'Z', 'M', 'M', '1', '5', 0,
	/* 474 */ 'C', 'R', '1', '5', 0,
	/* 479 */ 'D', 'R', '1', '5', 0,
	/* 484 */ 'X', 'M', 'M', '2', '5', 0,
	/* 490 */ 'Y', 'M', 'M', '2', '5', 0,
	/* 496 */ 'Z', 'M', 'M', '2', '5', 0,
	/* 502 */ 'K', '5', 0,
	/* 505 */ 'X', 'M', 'M', '5', 0,
	/* 510 */ 'Y', 'M', 'M', '5', 0,
	/* 515 */ 'Z', 'M', 'M', '5', 0,
	/* 520 */ 'F', 'P', '5', 0,
	/* 524 */ 'C', 'R', '5', 0,
	/* 528 */ 'D', 'R', '5', 0,
	/* 532 */ 'S', 'T', '5', 0,
	/* 536 */ 'X', 'M', 'M', '1', '6', 0,
	/* 542 */ 'Y', 'M', 'M', '1', '6', 0,
	/* 548 */ 'Z', 'M', 'M', '1', '6', 0,
	/* 554 */ 'X', 'M', 'M', '2', '6', 0,
	/* 560 */ 'Y', 'M', 'M', '2', '6', 0,
	/* 566 */ 'Z', 'M', 'M', '2', '6', 0,
	/* 572 */ 'K', '6', 0,
	/* 575 */ 'X', 'M', 'M', '6', 0,
	/* 580 */ 'Y', 'M', 'M', '6', 0,
	/* 585 */ 'Z', 'M', 'M', '6', 0,
	/* 590 */ 'F', 'P', '6', 0,
	/* 594 */ 'C', 'R', '6', 0,
	/* 598 */ 'D', 'R', '6', 0,
	/* 602 */ 'S', 'T', '6', 0,
	/* 606 */ 'X', 'M', 'M', '1', '7', 0,
	/* 612 */ 'Y', 'M', 'M', '1', '7', 0,
	/* 618 */ 'Z', 'M', 'M', '1', '7', 0,
	/* 624 */ 'X', 'M', 'M', '2', '7', 0,
	/* 630 */ 'Y', 'M', 'M', '2', '7', 0,
	/* 636 */ 'Z', 'M', 'M', '2', '7', 0,
	/* 642 */ 'K', '7', 0,
	/* 645 */ 'X', 'M', 'M', '7', 0,
	/* 650 */ 'Y', 'M', 'M', '7', 0,
	/* 655 */ 'Z', 'M', 'M', '7', 0,
	/* 660 */ 'F', 'P', '7', 0,
	/* 664 */ 'C', 'R', '7', 0,
	/* 668 */ 'D', 'R', '7', 0,
	/* 672 */ 'S', 'T', '7', 0,
	/* 676 */ 'X', 'M', 'M', '1', '8', 0,
	/* 682 */ 'Y', 'M', 'M', '1', '8', 0,
	/* 688 */ 'Z', 'M', 'M', '1', '8', 0,
	/* 694 */ 'X', 'M', 'M', '2', '8', 0,
	/* 700 */ 'Y', 'M', 'M', '2', '8', 0,
	/* 706 */ 'Z', 'M', 'M', '2', '8', 0,
	/* 712 */ 'X', 'M', 'M', '8', 0,
	/* 717 */ 'Y', 'M', 'M', '8', 0,
	/* 722 */ 'Z', 'M', 'M', '8', 0,
	/* 727 */ 'C', 'R', '8', 0,
	/* 731 */ 'D', 'R', '8', 0,
	/* 735 */ 'X', 'M', 'M', '1', '9', 0,
	/* 741 */ 'Y', 'M', 'M', '1', '9', 0,
	/* 747 */ 'Z', 'M', 'M', '1', '9', 0,
	/* 753 */ 'X', 'M', 'M', '2', '9', 0,
	/* 759 */ 'Y', 'M', 'M', '2', '9', 0,
	/* 765 */ 'Z', 'M', 'M', '2', '9', 0,
	/* 771 */ 'X', 'M', 'M', '9', 0,
	/* 776 */ 'Y', 'M', 'M', '9', 0,
	/* 781 */ 'Z', 'M', 'M', '9', 0,
	/* 786 */ 'C', 'R', '9', 0,
	/* 790 */ 'D', 'R', '9', 0,
	/* 794 */ 'R', '1', '0', 'B', 0,
	/* 799 */ 'R', '1', '1', 'B', 0,
	/* 804 */ 'R', '1', '2', 'B', 0,
	/* 809 */ 'R', '1', '3', 'B', 0,
	/* 814 */ 'R', '1', '4', 'B', 0,
	/* 819 */ 'R', '1', '5', 'B', 0,
	/* 824 */ 'R', '8', 'B', 0,
	/* 828 */ 'R', '9', 'B', 0,
	/* 832 */ 'R', '1', '0', 'D', 0,
	/* 837 */ 'R', '1', '1', 'D', 0,
	/* 842 */ 'R', '1', '2', 'D', 0,
	/* 847 */ 'R', '1', '3', 'D', 0,
	/* 852 */ 'R', '1', '4', 'D', 0,
	/* 857 */ 'R', '1', '5', 'D', 0,
	/* 862 */ 'R', '8', 'D', 0,
	/* 866 */ 'R', '9', 'D', 0,
	/* 870 */ 'D', 'F', 0,
	/* 873 */ 'A', 'H', 0,
	/* 876 */ 'R', '1', '0', 'B', 'H', 0,
	/* 882 */ 'R', '1', '1', 'B', 'H', 0,
	/* 888 */ 'R', '1', '2', 'B', 'H', 0,
	/* 894 */ 'R', '1', '3', 'B', 'H', 0,
	/* 900 */ 'R', '1', '4', 'B', 'H', 0,
	/* 906 */ 'R', '1', '5', 'B', 'H', 0,
	/* 912 */ 'R', '8', 'B', 'H', 0,
	/* 917 */ 'R', '9', 'B', 'H', 0,
	/* 922 */ 'C', 'H', 0,
	/* 925 */ 'D', 'H', 0,
	/* 928 */ 'D', 'I', 'H', 0,
	/* 932 */ 'S', 'I', 'H', 0,
	/* 936 */ 'B', 'P', 'H', 0,
	/* 940 */ 'S', 'P', 'H', 0,
	/* 944 */ 'R', '1', '0', 'W', 'H', 0,
	/* 950 */ 'R', '1', '1', 'W', 'H', 0,
	/* 956 */ 'R', '1', '2', 'W', 'H', 0,
	/* 962 */ 'R', '1', '3', 'W', 'H', 0,
	/* 968 */ 'R', '1', '4', 'W', 'H', 0,
	/* 974 */ 'R', '1', '5', 'W', 'H', 0,
	/* 980 */ 'R', '8', 'W', 'H', 0,
	/* 985 */ 'R', '9', 'W', 'H', 0,
	/* 990 */ 'E', 'D', 'I', 0,
	/* 994 */ 'H', 'D', 'I', 0,
	/* 998 */ 'R', 'D', 'I', 0,
	/* 1002 */ 'E', 'S', 'I', 0,
	/* 1006 */ 'H', 'S', 'I', 0,
	/* 1010 */ 'R', 'S', 'I', 0,
	/* 1014 */ 'A', 'L', 0,
	/* 1017 */ 'B', 'L', 0,
	/* 1020 */ 'C', 'L', 0,
	/* 1023 */ 'D', 'L', 0,
	/* 1026 */ 'D', 'I', 'L', 0,
	/* 1030 */ 'S', 'I', 'L', 0,
	/* 1034 */ 'B', 'P', 'L', 0,
	/* 1038 */ 'S', 'P', 'L', 0,
	/* 1042 */ 'E', 'B', 'P', 0,
	/* 1046 */ 'H', 'B', 'P', 0,
	/* 1050 */ 'R', 'B', 'P', 0,
	/* 1054 */ 'E', 'I', 'P', 0,
	/* 1058 */ 'H', 'I', 'P', 0,
	/* 1062 */ 'R', 'I', 'P', 0,
	/* 1066 */ 'E', 'S', 'P', 0,
	/* 1070 */ 'H', 'S', 'P', 0,
	/* 1074 */ 'R', 'S', 'P', 0,
	/* 1078 */ 'S', 'S', 'P', 0,
	/* 1082 */ 'C', 'S', 0,
	/* 1085 */ 'D', 'S', 0,
	/* 1088 */ 'E', 'S', 0,
	/* 1091 */ 'F', 'S', 0,
	/* 1094 */ 'E', 'F', 'L', 'A', 'G', 'S', 0,
	/* 1101 */ 'S', 'S', 0,
	/* 1104 */ 'R', '1', '0', 'W', 0,
	/* 1109 */ 'R', '1', '1', 'W', 0,
	/* 1114 */ 'R', '1', '2', 'W', 0,
	/* 1119 */ 'R', '1', '3', 'W', 0,
	/* 1124 */ 'R', '1', '4', 'W', 0,
	/* 1129 */ 'R', '1', '5', 'W', 0,
	/* 1134 */ 'R', '8', 'W', 0,
	/* 1138 */ 'R', '9', 'W', 0,
	/* 1142 */ 'F', 'P', 'S', 'W', 0,
	/* 1147 */ 'E', 'A', 'X', 0,
	/* 1151 */ 'H', 'A', 'X', 0,
	/* 1155 */ 'R', 'A', 'X', 0,
	/* 1159 */ 'E', 'B', 'X', 0,
	/* 1163 */ 'H', 'B', 'X', 0,
	/* 1167 */ 'R', 'B', 'X', 0,
	/* 1171 */ 'E', 'C', 'X', 0,
	/* 1175 */ 'H', 'C', 'X', 0,
	/* 1179 */ 'R', 'C', 'X', 0,
	/* 1183 */ 'E', 'D', 'X', 0,
	/* 1187 */ 'H', 'D', 'X', 0,
	/* 1191 */ 'R', 'D', 'X', 0,
	/* 1195 */ 'E', 'I', 'Z', 0,
	/* 1199 */ 'R', 'I', 'Z', 0,
};

extern const MCRegisterDesc X86RegDesc[] = { // Descriptors
  { 5, 0, 0, 0, 0, 0 },
  { 873, 2, 184, 2, 4641, 0 },
  { 1014, 2, 180, 2, 4641, 0 },
  { 1148, 298, 181, 0, 0, 2 },
  { 879, 2, 168, 2, 4593, 0 },
  { 1017, 2, 164, 2, 4593, 0 },
  { 1043, 289, 173, 3, 352, 5 },
  { 936, 2, 176, 2, 768, 0 },
  { 1034, 2, 172, 2, 736, 0 },
  { 1160, 292, 165, 0, 304, 2 },
  { 922, 2, 160, 2, 4497, 0 },
  { 1020, 2, 156, 2, 4497, 0 },
  { 1082, 2, 2, 2, 4497, 0 },
  { 1172, 295, 157, 0, 400, 2 },
  { 870, 2, 2, 2, 4449, 0 },
  { 925, 2, 144, 2, 4449, 0 },
  { 991, 289, 149, 3, 448, 5 },
  { 928, 2, 152, 2, 1296, 0 },
  { 1026, 2, 148, 2, 4130, 0 },
  { 1023, 2, 140, 2, 4417, 0 },
  { 1085, 2, 2, 2, 4417, 0 },
  { 1184, 280, 141, 0, 688, 2 },
  { 1147, 221, 142, 7, 1524, 8 },
  { 1042, 206, 142, 13, 1236, 12 },
  { 1159, 215, 142, 7, 1460, 8 },
  { 1171, 200, 142, 7, 1172, 8 },
  { 990, 135, 142, 13, 869, 12 },
  { 1183, 194, 142, 7, 928, 8 },
  { 1094, 2, 2, 2, 1584, 0 },
  { 1054, 284, 126, 19, 496, 16 },
  { 1195, 2, 2, 2, 4417, 0 },
  { 1088, 2, 2, 2, 4417, 0 },
  { 1002, 269, 105, 13, 243, 12 },
  { 1066, 263, 105, 13, 243, 12 },
  { 1142, 2, 2, 2, 4593, 0 },
  { 1091, 2, 2, 2, 4593, 0 },
  { 1098, 2, 2, 2, 4593, 0 },
  { 1151, 2, 188, 2, 4161, 0 },
  { 1046, 2, 188, 2, 4161, 0 },
  { 1163, 2, 188, 2, 4161, 0 },
  { 1175, 2, 188, 2, 4161, 0 },
  { 994, 2, 188, 2, 4161, 0 },
  { 1187, 2, 188, 2, 4161, 0 },
  { 1058, 2, 131, 2, 3923, 0 },
  { 1006, 2, 119, 2, 3955, 0 },
  { 1070, 2, 119, 2, 3955, 0 },
  { 1055, 2, 128, 2, 1616, 0 },
  { 1155, 220, 2, 6, 1396, 8 },
  { 1050, 205, 2, 12, 1108, 12 },
  { 1167, 214, 2, 6, 1332, 8 },
  { 1179, 199, 2, 6, 1044, 8 },
  { 998, 134, 2, 12, 805, 12 },
  { 1191, 193, 2, 6, 928, 8 },
  { 1062, 283, 2, 18, 496, 16 },
  { 1199, 2, 2, 2, 3488, 0 },
  { 1010, 268, 2, 12, 179, 12 },
  { 1074, 262, 2, 12, 179, 12 },
  { 1003, 289, 112, 3, 544, 5 },
  { 932, 2, 115, 2, 3152, 0 },
  { 1030, 2, 111, 2, 3056, 0 },
  { 1067, 289, 104, 3, 592, 5 },
  { 940, 2, 107, 2, 3248, 0 },
  { 1038, 2, 103, 2, 3719, 0 },
  { 1101, 2, 2, 2, 4097, 0 },
  { 1078, 2, 2, 2, 4097, 0 },
  { 64, 2, 2, 2, 4097, 0 },
  { 167, 2, 2, 2, 4097, 0 },
  { 252, 2, 2, 2, 4097, 0 },
  { 337, 2, 2, 2, 4097, 0 },
  { 91, 2, 2, 2, 4097, 0 },
  { 194, 2, 2, 2, 4097, 0 },
  { 279, 2, 2, 2, 4097, 0 },
  { 364, 2, 2, 2, 4097, 0 },
  { 444, 2, 2, 2, 4097, 0 },
  { 524, 2, 2, 2, 4097, 0 },
  { 594, 2, 2, 2, 4097, 0 },
  { 664, 2, 2, 2, 4097, 0 },
  { 727, 2, 2, 2, 4097, 0 },
  { 786, 2, 2, 2, 4097, 0 },
  { 18, 2, 2, 2, 4097, 0 },
  { 121, 2, 2, 2, 4097, 0 },
  { 224, 2, 2, 2, 4097, 0 },
  { 309, 2, 2, 2, 4097, 0 },
  { 394, 2, 2, 2, 4097, 0 },
  { 474, 2, 2, 2, 4097, 0 },
  { 95, 2, 2, 2, 4097, 0 },
  { 198, 2, 2, 2, 4097, 0 },
  { 283, 2, 2, 2, 4097, 0 },
  { 368, 2, 2, 2, 4097, 0 },
  { 448, 2, 2, 2, 4097, 0 },
  { 528, 2, 2, 2, 4097, 0 },
  { 598, 2, 2, 2, 4097, 0 },
  { 668, 2, 2, 2, 4097, 0 },
  { 731, 2, 2, 2, 4097, 0 },
  { 790, 2, 2, 2, 4097, 0 },
  { 23, 2, 2, 2, 4097, 0 },
  { 126, 2, 2, 2, 4097, 0 },
  { 229, 2, 2, 2, 4097, 0 },
  { 314, 2, 2, 2, 4097, 0 },
  { 399, 2, 2, 2, 4097, 0 },
  { 479, 2, 2, 2, 4097, 0 },
  { 87, 2, 2, 2, 4097, 0 },
  { 190, 2, 2, 2, 4097, 0 },
  { 275, 2, 2, 2, 4097, 0 },
  { 360, 2, 2, 2, 4097, 0 },
  { 440, 2, 2, 2, 4097, 0 },
  { 520, 2, 2, 2, 4097, 0 },
  { 590, 2, 2, 2, 4097, 0 },
  { 660, 2, 2, 2, 4097, 0 },
  { 69, 2, 2, 2, 4097, 0 },
  { 172, 2, 2, 2, 4097, 0 },
  { 257, 2, 2, 2, 4097, 0 },
  { 342, 2, 2, 2, 4097, 0 },
  { 422, 2, 2, 2, 4097, 0 },
  { 502, 2, 2, 2, 4097, 0 },
  { 572, 2, 2, 2, 4097, 0 },
  { 642, 2, 2, 2, 4097, 0 },
  { 73, 2, 2, 2, 4097, 0 },
  { 176, 2, 2, 2, 4097, 0 },
  { 261, 2, 2, 2, 4097, 0 },
  { 346, 2, 2, 2, 4097, 0 },
  { 426, 2, 2, 2, 4097, 0 },
  { 506, 2, 2, 2, 4097, 0 },
  { 576, 2, 2, 2, 4097, 0 },
  { 646, 2, 2, 2, 4097, 0 },
  { 728, 122, 2, 12, 115, 12 },
  { 787, 122, 2, 12, 115, 12 },
  { 19, 122, 2, 12, 115, 12 },
  { 122, 122, 2, 12, 115, 12 },
  { 225, 122, 2, 12, 115, 12 },
  { 310, 122, 2, 12, 115, 12 },
  { 395, 122, 2, 12, 115, 12 },
  { 475, 122, 2, 12, 115, 12 },
  { 99, 2, 2, 2, 4385, 0 },
  { 202, 2, 2, 2, 4385, 0 },
  { 287, 2, 2, 2, 4385, 0 },
  { 372, 2, 2, 2, 4385, 0 },
  { 452, 2, 2, 2, 4385, 0 },
  { 532, 2, 2, 2, 4385, 0 },
  { 602, 2, 2, 2, 4385, 0 },
  { 672, 2, 2, 2, 4385, 0 },
  { 72, 2, 211, 2, 4385, 0 },
  { 175, 2, 211, 2, 4385, 0 },
  { 260, 2, 211, 2, 4385, 0 },
  { 345, 2, 211, 2, 4385, 0 },
  { 425, 2, 211, 2, 4385, 0 },
  { 505, 2, 211, 2, 4385, 0 },
  { 575, 2, 211, 2, 4385, 0 },
  { 645, 2, 211, 2, 4385, 0 },
  { 712, 2, 211, 2, 4385, 0 },
  { 771, 2, 211, 2, 4385, 0 },
  { 0, 2, 211, 2, 4385, 0 },
  { 103, 2, 211, 2, 4385, 0 },
  { 206, 2, 211, 2, 4385, 0 },
  { 291, 2, 211, 2, 4385, 0 },
  { 376, 2, 211, 2, 4385, 0 },
  { 456, 2, 211, 2, 4385, 0 },
  { 536, 2, 211, 2, 4385, 0 },
  { 606, 2, 211, 2, 4385, 0 },
  { 676, 2, 211, 2, 4385, 0 },
  { 735, 2, 211, 2, 4385, 0 },
  { 28, 2, 211, 2, 4385, 0 },
  { 131, 2, 211, 2, 4385, 0 },
  { 234, 2, 211, 2, 4385, 0 },
  { 319, 2, 211, 2, 4385, 0 },
  { 404, 2, 211, 2, 4385, 0 },
  { 484, 2, 211, 2, 4385, 0 },
  { 554, 2, 211, 2, 4385, 0 },
  { 624, 2, 211, 2, 4385, 0 },
  { 694, 2, 211, 2, 4385, 0 },
  { 753, 2, 211, 2, 4385, 0 },
  { 46, 2, 211, 2, 4385, 0 },
  { 149, 2, 211, 2, 4385, 0 },
  { 77, 254, 212, 23, 4017, 19 },
  { 180, 254, 212, 23, 4017, 19 },
  { 265, 254, 212, 23, 4017, 19 },
  { 350, 254, 212, 23, 4017, 19 },
  { 430, 254, 212, 23, 4017, 19 },
  { 510, 254, 212, 23, 4017, 19 },
  { 580, 254, 212, 23, 4017, 19 },
  { 650, 254, 212, 23, 4017, 19 },
  { 717, 254, 212, 23, 4017, 19 },
  { 776, 254, 212, 23, 4017, 19 },
  { 6, 254, 212, 23, 4017, 19 },
  { 109, 254, 212, 23, 4017, 19 },
  { 212, 254, 212, 23, 4017, 19 },
  { 297, 254, 212, 23, 4017, 19 },
  { 382, 254, 212, 23, 4017, 19 },
  { 462, 254, 212, 23, 4017, 19 },
  { 542, 254, 212, 23, 4017, 19 },
  { 612, 254, 212, 23, 4017, 19 },
  { 682, 254, 212, 23, 4017, 19 },
  { 741, 254, 212, 23, 4017, 19 },
  { 34, 254, 212, 23, 4017, 19 },
  { 137, 254, 212, 23, 4017, 19 },
  { 240, 254, 212, 23, 4017, 19 },
  { 325, 254, 212, 23, 4017, 19 },
  { 410, 254, 212, 23, 4017, 19 },
  { 490, 254, 212, 23, 4017, 19 },
  { 560, 254, 212, 23, 4017, 19 },
  { 630, 254, 212, 23, 4017, 19 },
  { 700, 254, 212, 23, 4017, 19 },
  { 759, 254, 212, 23, 4017, 19 },
  { 52, 254, 212, 23, 4017, 19 },
  { 155, 254, 212, 23, 4017, 19 },
  { 82, 253, 2, 22, 3985, 19 },
  { 185, 253, 2, 22, 3985, 19 },
  { 270, 253, 2, 22, 3985, 19 },
  { 355, 253, 2, 22, 3985, 19 },
  { 435, 253, 2, 22, 3985, 19 },
  { 515, 253, 2, 22, 3985, 19 },
  { 585, 253, 2, 22, 3985, 19 },
  { 655, 253, 2, 22, 3985, 19 },
  { 722, 253, 2, 22, 3985, 19 },
  { 781, 253, 2, 22, 3985, 19 },
  { 12, 253, 2, 22, 3985, 19 },
  { 115, 253, 2, 22, 3985, 19 },
  { 218, 253, 2, 22, 3985, 19 },
  { 303, 253, 2, 22, 3985, 19 },
  { 388, 253, 2, 22, 3985, 19 },
  { 468, 253, 2, 22, 3985, 19 },
  { 548, 253, 2, 22, 3985, 19 },
  { 618, 253, 2, 22, 3985, 19 },
  { 688, 253, 2, 22, 3985, 19 },
  { 747, 253, 2, 22, 3985, 19 },
  { 40, 253, 2, 22, 3985, 19 },
  { 143, 253, 2, 22, 3985, 19 },
  { 246, 253, 2, 22, 3985, 19 },
  { 331, 253, 2, 22, 3985, 19 },
  { 416, 253, 2, 22, 3985, 19 },
  { 496, 253, 2, 22, 3985, 19 },
  { 566, 253, 2, 22, 3985, 19 },
  { 636, 253, 2, 22, 3985, 19 },
  { 706, 253, 2, 22, 3985, 19 },
  { 765, 253, 2, 22, 3985, 19 },
  { 58, 253, 2, 22, 3985, 19 },
  { 161, 253, 2, 22, 3985, 19 },
  { 824, 2, 241, 2, 3683, 0 },
  { 828, 2, 241, 2, 3683, 0 },
  { 794, 2, 241, 2, 3683, 0 },
  { 799, 2, 241, 2, 3683, 0 },
  { 804, 2, 241, 2, 3683, 0 },
  { 809, 2, 241, 2, 3683, 0 },
  { 814, 2, 241, 2, 3683, 0 },
  { 819, 2, 241, 2, 3683, 0 },
  { 912, 2, 237, 2, 3651, 0 },
  { 917, 2, 237, 2, 3651, 0 },
  { 876, 2, 237, 2, 3651, 0 },
  { 882, 2, 237, 2, 3651, 0 },
  { 888, 2, 237, 2, 3651, 0 },
  { 894, 2, 237, 2, 3651, 0 },
  { 900, 2, 237, 2, 3651, 0 },
  { 906, 2, 237, 2, 3651, 0 },
  { 862, 123, 235, 13, 51, 12 },
  { 866, 123, 235, 13, 51, 12 },
  { 832, 123, 235, 13, 51, 12 },
  { 837, 123, 235, 13, 51, 12 },
  { 842, 123, 235, 13, 51, 12 },
  { 847, 123, 235, 13, 51, 12 },
  { 852, 123, 235, 13, 51, 12 },
  { 857, 123, 235, 13, 51, 12 },
  { 1134, 62, 238, 3, 643, 5 },
  { 1138, 62, 238, 3, 643, 5 },
  { 1104, 62, 238, 3, 643, 5 },
  { 1109, 62, 238, 3, 643, 5 },
  { 1114, 62, 238, 3, 643, 5 },
  { 1119, 62, 238, 3, 643, 5 },
  { 1124, 62, 238, 3, 643, 5 },
  { 1129, 62, 238, 3, 643, 5 },
  { 980, 2, 234, 2, 3619, 0 },
  { 985, 2, 234, 2, 3619, 0 },
  { 944, 2, 234, 2, 3619, 0 },
  { 950, 2, 234, 2, 3619, 0 },
  { 956, 2, 234, 2, 3619, 0 },
  { 962, 2, 234, 2, 3619, 0 },
  { 968, 2, 234, 2, 3619, 0 },
  { 974, 2, 234, 2, 3619, 0 },
};

// GR8 Register Class...
const MCPhysReg GR8[] = {
  X86::AL, X86::CL, X86::DL, X86::AH, X86::CH, X86::DH, X86::BL, X86::BH, X86::SIL, X86::DIL, X86::BPL, X86::SPL, X86::R8B, X86::R9B, X86::R10B, X86::R11B, X86::R14B, X86::R15B, X86::R12B, X86::R13B,
};

// GR8 Bit set.
const uint8_t GR8Bits[] = {
  0x36, 0x8d, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GRH8 Register Class...
const MCPhysReg GRH8[] = {
  X86::SIH, X86::DIH, X86::BPH, X86::SPH, X86::R8BH, X86::R9BH, X86::R10BH, X86::R11BH, X86::R12BH, X86::R13BH, X86::R14BH, X86::R15BH,
};

// GRH8 Bit set.
const uint8_t GRH8Bits[] = {
  0x80, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR8_NOREX Register Class...
const MCPhysReg GR8_NOREX[] = {
  X86::AL, X86::CL, X86::DL, X86::AH, X86::CH, X86::DH, X86::BL, X86::BH,
};

// GR8_NOREX Bit set.
const uint8_t GR8_NOREXBits[] = {
  0x36, 0x8c, 0x08,
};

// GR8_ABCD_H Register Class...
const MCPhysReg GR8_ABCD_H[] = {
  X86::AH, X86::CH, X86::DH, X86::BH,
};

// GR8_ABCD_H Bit set.
const uint8_t GR8_ABCD_HBits[] = {
  0x12, 0x84,
};

// GR8_ABCD_L Register Class...
const MCPhysReg GR8_ABCD_L[] = {
  X86::AL, X86::CL, X86::DL, X86::BL,
};

// GR8_ABCD_L Bit set.
const uint8_t GR8_ABCD_LBits[] = {
  0x24, 0x08, 0x08,
};

// GRH16 Register Class...
const MCPhysReg GRH16[] = {
  X86::HAX, X86::HCX, X86::HDX, X86::HSI, X86::HDI, X86::HBX, X86::HBP, X86::HSP, X86::HIP, X86::R8WH, X86::R9WH, X86::R10WH, X86::R11WH, X86::R12WH, X86::R13WH, X86::R14WH, X86::R15WH,
};

// GRH16 Bit set.
const uint8_t GRH16Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR16 Register Class...
const MCPhysReg GR16[] = {
  X86::AX, X86::CX, X86::DX, X86::SI, X86::DI, X86::BX, X86::BP, X86::SP, X86::R8W, X86::R9W, X86::R10W, X86::R11W, X86::R14W, X86::R15W, X86::R12W, X86::R13W,
};

// GR16 Bit set.
const uint8_t GR16Bits[] = {
  0x48, 0x22, 0x21, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR16_NOREX Register Class...
const MCPhysReg GR16_NOREX[] = {
  X86::AX, X86::CX, X86::DX, X86::SI, X86::DI, X86::BX, X86::BP, X86::SP,
};

// GR16_NOREX Bit set.
const uint8_t GR16_NOREXBits[] = {
  0x48, 0x22, 0x21, 0x00, 0x00, 0x00, 0x00, 0x12,
};

// VK1 Register Class...
const MCPhysReg VK1[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK1 Bit set.
const uint8_t VK1Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VK16 Register Class...
const MCPhysReg VK16[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK16 Bit set.
const uint8_t VK16Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VK2 Register Class...
const MCPhysReg VK2[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK2 Bit set.
const uint8_t VK2Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VK4 Register Class...
const MCPhysReg VK4[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK4 Bit set.
const uint8_t VK4Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VK8 Register Class...
const MCPhysReg VK8[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK8 Bit set.
const uint8_t VK8Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VK16WM Register Class...
const MCPhysReg VK16WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK16WM Bit set.
const uint8_t VK16WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// VK1WM Register Class...
const MCPhysReg VK1WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK1WM Bit set.
const uint8_t VK1WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// VK2WM Register Class...
const MCPhysReg VK2WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK2WM Bit set.
const uint8_t VK2WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// VK4WM Register Class...
const MCPhysReg VK4WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK4WM Bit set.
const uint8_t VK4WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// VK8WM Register Class...
const MCPhysReg VK8WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK8WM Bit set.
const uint8_t VK8WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// SEGMENT_REG Register Class...
const MCPhysReg SEGMENT_REG[] = {
  X86::CS, X86::DS, X86::SS, X86::ES, X86::FS, X86::GS,
};

// SEGMENT_REG Bit set.
const uint8_t SEGMENT_REGBits[] = {
  0x00, 0x10, 0x10, 0x80, 0x18, 0x00, 0x00, 0x80,
};

// GR16_ABCD Register Class...
const MCPhysReg GR16_ABCD[] = {
  X86::AX, X86::CX, X86::DX, X86::BX,
};

// GR16_ABCD Bit set.
const uint8_t GR16_ABCDBits[] = {
  0x08, 0x22, 0x20,
};

// FPCCR Register Class...
const MCPhysReg FPCCR[] = {
  X86::FPSW,
};

// FPCCR Bit set.
const uint8_t FPCCRBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x04,
};

// FR32X Register Class...
const MCPhysReg FR32X[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, X86::XMM16, X86::XMM17, X86::XMM18, X86::XMM19, X86::XMM20, X86::XMM21, X86::XMM22, X86::XMM23, X86::XMM24, X86::XMM25, X86::XMM26, X86::XMM27, X86::XMM28, X86::XMM29, X86::XMM30, X86::XMM31,
};

// FR32X Bit set.
const uint8_t FR32XBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x1f,
};

// LOW32_ADDR_ACCESS_RBP Register Class...
const MCPhysReg LOW32_ADDR_ACCESS_RBP[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, X86::RIP, X86::RBP,
};

// LOW32_ADDR_ACCESS_RBP Bit set.
const uint8_t LOW32_ADDR_ACCESS_RBPBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x03, 0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// LOW32_ADDR_ACCESS Register Class...
const MCPhysReg LOW32_ADDR_ACCESS[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, X86::RIP,
};

// LOW32_ADDR_ACCESS Bit set.
const uint8_t LOW32_ADDR_ACCESSBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x03, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_8bit Register Class...
const MCPhysReg LOW32_ADDR_ACCESS_RBP_with_sub_8bit[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D, X86::RBP,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_8bit Bit set.
const uint8_t LOW32_ADDR_ACCESS_RBP_with_sub_8bitBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// DEBUG_REG Register Class...
const MCPhysReg DEBUG_REG[] = {
  X86::DR0, X86::DR1, X86::DR2, X86::DR3, X86::DR4, X86::DR5, X86::DR6, X86::DR7, X86::DR8, X86::DR9, X86::DR10, X86::DR11, X86::DR12, X86::DR13, X86::DR14, X86::DR15,
};

// DEBUG_REG Bit set.
const uint8_t DEBUG_REGBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// FR32 Register Class...
const MCPhysReg FR32[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15,
};

// FR32 Bit set.
const uint8_t FR32Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// GR32 Register Class...
const MCPhysReg GR32[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D,
};

// GR32 Bit set.
const uint8_t GR32Bits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR32_NOSP Register Class...
const MCPhysReg GR32_NOSP[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::R8D, X86::R9D, X86::R10D, X86::R11D, X86::R14D, X86::R15D, X86::R12D, X86::R13D,
};

// GR32_NOSP Bit set.
const uint8_t GR32_NOSPBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREX Register Class...
const MCPhysReg LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREX[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP, X86::RBP,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREX Bit set.
const uint8_t LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREXBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x03, 0x00, 0x01,
};

// GR32_NOREX Register Class...
const MCPhysReg GR32_NOREX[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP, X86::ESP,
};

// GR32_NOREX Bit set.
const uint8_t GR32_NOREXBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x03,
};

// VK32 Register Class...
const MCPhysReg VK32[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK32 Bit set.
const uint8_t VK32Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR32_NOREX_NOSP Register Class...
const MCPhysReg GR32_NOREX_NOSP[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::ESI, X86::EDI, X86::EBX, X86::EBP,
};

// GR32_NOREX_NOSP Bit set.
const uint8_t GR32_NOREX_NOSPBits[] = {
  0x00, 0x00, 0xc0, 0x0f, 0x01,
};

// RFP32 Register Class...
const MCPhysReg RFP32[] = {
  X86::FP0, X86::FP1, X86::FP2, X86::FP3, X86::FP4, X86::FP5, X86::FP6,
};

// RFP32 Bit set.
const uint8_t RFP32Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f,
};

// VK32WM Register Class...
const MCPhysReg VK32WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK32WM Bit set.
const uint8_t VK32WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// GR32_ABCD Register Class...
const MCPhysReg GR32_ABCD[] = {
  X86::EAX, X86::ECX, X86::EDX, X86::EBX,
};

// GR32_ABCD Bit set.
const uint8_t GR32_ABCDBits[] = {
  0x00, 0x00, 0x40, 0x0b,
};

// GR32_TC Register Class...
const MCPhysReg GR32_TC[] = {
  X86::EAX, X86::ECX, X86::EDX,
};

// GR32_TC Bit set.
const uint8_t GR32_TCBits[] = {
  0x00, 0x00, 0x40, 0x0a,
};

// GR32_AD Register Class...
const MCPhysReg GR32_AD[] = {
  X86::EAX, X86::EDX,
};

// GR32_AD Bit set.
const uint8_t GR32_ADBits[] = {
  0x00, 0x00, 0x40, 0x08,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_32bit Register Class...
const MCPhysReg LOW32_ADDR_ACCESS_RBP_with_sub_32bit[] = {
  X86::RIP, X86::RBP,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_32bit Bit set.
const uint8_t LOW32_ADDR_ACCESS_RBP_with_sub_32bitBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,
};

// CCR Register Class...
const MCPhysReg CCR[] = {
  X86::EFLAGS,
};

// CCR Bit set.
const uint8_t CCRBits[] = {
  0x00, 0x00, 0x00, 0x10,
};

// DFCCR Register Class...
const MCPhysReg DFCCR[] = {
  X86::DF,
};

// DFCCR Bit set.
const uint8_t DFCCRBits[] = {
  0x00, 0x40,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bit Register Class...
const MCPhysReg LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bit[] = {
  X86::RBP,
};

// LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bit Bit set.
const uint8_t LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bitBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
};

// LOW32_ADDR_ACCESS_with_sub_32bit Register Class...
const MCPhysReg LOW32_ADDR_ACCESS_with_sub_32bit[] = {
  X86::RIP,
};

// LOW32_ADDR_ACCESS_with_sub_32bit Bit set.
const uint8_t LOW32_ADDR_ACCESS_with_sub_32bitBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
};

// RFP64 Register Class...
const MCPhysReg RFP64[] = {
  X86::FP0, X86::FP1, X86::FP2, X86::FP3, X86::FP4, X86::FP5, X86::FP6,
};

// RFP64 Bit set.
const uint8_t RFP64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f,
};

// FR64X Register Class...
const MCPhysReg FR64X[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, X86::XMM16, X86::XMM17, X86::XMM18, X86::XMM19, X86::XMM20, X86::XMM21, X86::XMM22, X86::XMM23, X86::XMM24, X86::XMM25, X86::XMM26, X86::XMM27, X86::XMM28, X86::XMM29, X86::XMM30, X86::XMM31,
};

// FR64X Bit set.
const uint8_t FR64XBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x1f,
};

// GR64 Register Class...
const MCPhysReg GR64[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, X86::RSP, X86::RIP,
};

// GR64 Bit set.
const uint8_t GR64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// CONTROL_REG Register Class...
const MCPhysReg CONTROL_REG[] = {
  X86::CR0, X86::CR1, X86::CR2, X86::CR3, X86::CR4, X86::CR5, X86::CR6, X86::CR7, X86::CR8, X86::CR9, X86::CR10, X86::CR11, X86::CR12, X86::CR13, X86::CR14, X86::CR15,
};

// CONTROL_REG Bit set.
const uint8_t CONTROL_REGBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// FR64 Register Class...
const MCPhysReg FR64[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15,
};

// FR64 Bit set.
const uint8_t FR64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// GR64_with_sub_8bit Register Class...
const MCPhysReg GR64_with_sub_8bit[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP, X86::RSP,
};

// GR64_with_sub_8bit Bit set.
const uint8_t GR64_with_sub_8bitBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x9f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR64_NOSP Register Class...
const MCPhysReg GR64_NOSP[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R10, X86::R11, X86::RBX, X86::R14, X86::R15, X86::R12, X86::R13, X86::RBP,
};

// GR64_NOSP Bit set.
const uint8_t GR64_NOSPBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR64_NOREX Register Class...
const MCPhysReg GR64_NOREX[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, X86::RSP, X86::RIP,
};

// GR64_NOREX Bit set.
const uint8_t GR64_NOREXBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x01,
};

// GR64_TC Register Class...
const MCPhysReg GR64_TC[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R11, X86::RIP,
};

// GR64_TC Bit set.
const uint8_t GR64_TCBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01,
};

// GR64_NOSP_and_GR64_TC Register Class...
const MCPhysReg GR64_NOSP_and_GR64_TC[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::R8, X86::R9, X86::R11,
};

// GR64_NOSP_and_GR64_TC Bit set.
const uint8_t GR64_NOSP_and_GR64_TCBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01,
};

// GR64_TCW64 Register Class...
const MCPhysReg GR64_TCW64[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::R8, X86::R9, X86::R10, X86::R11, X86::RIP,
};

// GR64_TCW64 Bit set.
const uint8_t GR64_TCW64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x01,
};

// GR64_with_sub_16bit_in_GR16_NOREX Register Class...
const MCPhysReg GR64_with_sub_16bit_in_GR16_NOREX[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP, X86::RSP,
};

// GR64_with_sub_16bit_in_GR16_NOREX Bit set.
const uint8_t GR64_with_sub_16bit_in_GR16_NOREXBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x9f, 0x01,
};

// VK64 Register Class...
const MCPhysReg VK64[] = {
  X86::K0, X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK64 Bit set.
const uint8_t VK64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VR64 Register Class...
const MCPhysReg VR64[] = {
  X86::MM0, X86::MM1, X86::MM2, X86::MM3, X86::MM4, X86::MM5, X86::MM6, X86::MM7,
};

// VR64 Bit set.
const uint8_t VR64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// GR64_NOREX_NOSP Register Class...
const MCPhysReg GR64_NOREX_NOSP[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RBX, X86::RBP,
};

// GR64_NOREX_NOSP Bit set.
const uint8_t GR64_NOREX_NOSPBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x9f,
};

// GR64_NOSP_and_GR64_TCW64 Register Class...
const MCPhysReg GR64_NOSP_and_GR64_TCW64[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::R8, X86::R9, X86::R10, X86::R11,
};

// GR64_NOSP_and_GR64_TCW64 Bit set.
const uint8_t GR64_NOSP_and_GR64_TCW64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x01,
};

// GR64_TC_and_GR64_TCW64 Register Class...
const MCPhysReg GR64_TC_and_GR64_TCW64[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::R8, X86::R9, X86::R11, X86::RIP,
};

// GR64_TC_and_GR64_TCW64 Bit set.
const uint8_t GR64_TC_and_GR64_TCW64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01,
};

// VK64WM Register Class...
const MCPhysReg VK64WM[] = {
  X86::K1, X86::K2, X86::K3, X86::K4, X86::K5, X86::K6, X86::K7,
};

// VK64WM Bit set.
const uint8_t VK64WMBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f,
};

// GR64_NOREX_and_GR64_TC Register Class...
const MCPhysReg GR64_NOREX_and_GR64_TC[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI, X86::RIP,
};

// GR64_NOREX_and_GR64_TC Bit set.
const uint8_t GR64_NOREX_and_GR64_TCBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbc,
};

// GR64_TC_and_GR64_NOSP_and_GR64_TCW64 Register Class...
const MCPhysReg GR64_TC_and_GR64_NOSP_and_GR64_TCW64[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::R8, X86::R9, X86::R11,
};

// GR64_TC_and_GR64_NOSP_and_GR64_TCW64 Bit set.
const uint8_t GR64_TC_and_GR64_NOSP_and_GR64_TCW64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x01,
};

// GR64_NOREX_NOSP_and_GR64_TC Register Class...
const MCPhysReg GR64_NOREX_NOSP_and_GR64_TC[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RSI, X86::RDI,
};

// GR64_NOREX_NOSP_and_GR64_TC Bit set.
const uint8_t GR64_NOREX_NOSP_and_GR64_TCBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x9c,
};

// GR64_ABCD Register Class...
const MCPhysReg GR64_ABCD[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RBX,
};

// GR64_ABCD Bit set.
const uint8_t GR64_ABCDBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x16,
};

// GR64_NOREX_and_GR64_TCW64 Register Class...
const MCPhysReg GR64_NOREX_and_GR64_TCW64[] = {
  X86::RAX, X86::RCX, X86::RDX, X86::RIP,
};

// GR64_NOREX_and_GR64_TCW64 Bit set.
const uint8_t GR64_NOREX_and_GR64_TCW64Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x34,
};

// GR64_with_sub_32bit_in_GR32_TC Register Class...
const MCPhysReg GR64_with_sub_32bit_in_GR32_TC[] = {
  X86::RAX, X86::RCX, X86::RDX,
};

// GR64_with_sub_32bit_in_GR32_TC Bit set.
const uint8_t GR64_with_sub_32bit_in_GR32_TCBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x14,
};

// GR64_AD Register Class...
const MCPhysReg GR64_AD[] = {
  X86::RAX, X86::RDX,
};

// GR64_AD Bit set.
const uint8_t GR64_ADBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x10,
};

// GR64_and_LOW32_ADDR_ACCESS_RBP Register Class...
const MCPhysReg GR64_and_LOW32_ADDR_ACCESS_RBP[] = {
  X86::RBP, X86::RIP,
};

// GR64_and_LOW32_ADDR_ACCESS_RBP Bit set.
const uint8_t GR64_and_LOW32_ADDR_ACCESS_RBPBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,
};

// GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBP Register Class...
const MCPhysReg GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBP[] = {
  X86::RBP,
};

// GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBP Bit set.
const uint8_t GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBPBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
};

// GR64_and_LOW32_ADDR_ACCESS Register Class...
const MCPhysReg GR64_and_LOW32_ADDR_ACCESS[] = {
  X86::RIP,
};

// GR64_and_LOW32_ADDR_ACCESS Bit set.
const uint8_t GR64_and_LOW32_ADDR_ACCESSBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
};

// RST Register Class...
const MCPhysReg RST[] = {
  X86::ST0, X86::ST1, X86::ST2, X86::ST3, X86::ST4, X86::ST5, X86::ST6, X86::ST7,
};

// RST Bit set.
const uint8_t RSTBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// RFP80 Register Class...
const MCPhysReg RFP80[] = {
  X86::FP0, X86::FP1, X86::FP2, X86::FP3, X86::FP4, X86::FP5, X86::FP6,
};

// RFP80 Bit set.
const uint8_t RFP80Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f,
};

// VR128X Register Class...
const MCPhysReg VR128X[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15, X86::XMM16, X86::XMM17, X86::XMM18, X86::XMM19, X86::XMM20, X86::XMM21, X86::XMM22, X86::XMM23, X86::XMM24, X86::XMM25, X86::XMM26, X86::XMM27, X86::XMM28, X86::XMM29, X86::XMM30, X86::XMM31,
};

// VR128X Bit set.
const uint8_t VR128XBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x1f,
};

// VR128 Register Class...
const MCPhysReg VR128[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7, X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15,
};

// VR128 Bit set.
const uint8_t VR128Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// VR128H Register Class...
const MCPhysReg VR128H[] = {
  X86::XMM8, X86::XMM9, X86::XMM10, X86::XMM11, X86::XMM12, X86::XMM13, X86::XMM14, X86::XMM15,
};

// VR128H Bit set.
const uint8_t VR128HBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VR128L Register Class...
const MCPhysReg VR128L[] = {
  X86::XMM0, X86::XMM1, X86::XMM2, X86::XMM3, X86::XMM4, X86::XMM5, X86::XMM6, X86::XMM7,
};

// VR128L Bit set.
const uint8_t VR128LBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// BNDR Register Class...
const MCPhysReg BNDR[] = {
  X86::BND0, X86::BND1, X86::BND2, X86::BND3,
};

// BNDR Bit set.
const uint8_t BNDRBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e,
};

// VR256X Register Class...
const MCPhysReg VR256X[] = {
  X86::YMM0, X86::YMM1, X86::YMM2, X86::YMM3, X86::YMM4, X86::YMM5, X86::YMM6, X86::YMM7, X86::YMM8, X86::YMM9, X86::YMM10, X86::YMM11, X86::YMM12, X86::YMM13, X86::YMM14, X86::YMM15, X86::YMM16, X86::YMM17, X86::YMM18, X86::YMM19, X86::YMM20, X86::YMM21, X86::YMM22, X86::YMM23, X86::YMM24, X86::YMM25, X86::YMM26, X86::YMM27, X86::YMM28, X86::YMM29, X86::YMM30, X86::YMM31,
};

// VR256X Bit set.
const uint8_t VR256XBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x1f,
};

// VR256 Register Class...
const MCPhysReg VR256[] = {
  X86::YMM0, X86::YMM1, X86::YMM2, X86::YMM3, X86::YMM4, X86::YMM5, X86::YMM6, X86::YMM7, X86::YMM8, X86::YMM9, X86::YMM10, X86::YMM11, X86::YMM12, X86::YMM13, X86::YMM14, X86::YMM15,
};

// VR256 Bit set.
const uint8_t VR256Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// VR256H Register Class...
const MCPhysReg VR256H[] = {
  X86::YMM8, X86::YMM9, X86::YMM10, X86::YMM11, X86::YMM12, X86::YMM13, X86::YMM14, X86::YMM15,
};

// VR256H Bit set.
const uint8_t VR256HBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VR256L Register Class...
const MCPhysReg VR256L[] = {
  X86::YMM0, X86::YMM1, X86::YMM2, X86::YMM3, X86::YMM4, X86::YMM5, X86::YMM6, X86::YMM7,
};

// VR256L Bit set.
const uint8_t VR256LBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VR512 Register Class...
const MCPhysReg VR512[] = {
  X86::ZMM0, X86::ZMM1, X86::ZMM2, X86::ZMM3, X86::ZMM4, X86::ZMM5, X86::ZMM6, X86::ZMM7, X86::ZMM8, X86::ZMM9, X86::ZMM10, X86::ZMM11, X86::ZMM12, X86::ZMM13, X86::ZMM14, X86::ZMM15, X86::ZMM16, X86::ZMM17, X86::ZMM18, X86::ZMM19, X86::ZMM20, X86::ZMM21, X86::ZMM22, X86::ZMM23, X86::ZMM24, X86::ZMM25, X86::ZMM26, X86::ZMM27, X86::ZMM28, X86::ZMM29, X86::ZMM30, X86::ZMM31,
};

// VR512 Bit set.
const uint8_t VR512Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0x1f,
};

// VR512_with_sub_xmm_in_FR32 Register Class...
const MCPhysReg VR512_with_sub_xmm_in_FR32[] = {
  X86::ZMM0, X86::ZMM1, X86::ZMM2, X86::ZMM3, X86::ZMM4, X86::ZMM5, X86::ZMM6, X86::ZMM7, X86::ZMM8, X86::ZMM9, X86::ZMM10, X86::ZMM11, X86::ZMM12, X86::ZMM13, X86::ZMM14, X86::ZMM15,
};

// VR512_with_sub_xmm_in_FR32 Bit set.
const uint8_t VR512_with_sub_xmm_in_FR32Bits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x1f,
};

// VR512_with_sub_xmm_in_VR128H Register Class...
const MCPhysReg VR512_with_sub_xmm_in_VR128H[] = {
  X86::ZMM8, X86::ZMM9, X86::ZMM10, X86::ZMM11, X86::ZMM12, X86::ZMM13, X86::ZMM14, X86::ZMM15,
};

// VR512_with_sub_xmm_in_VR128H Bit set.
const uint8_t VR512_with_sub_xmm_in_VR128HBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

// VR512_with_sub_xmm_in_VR128L Register Class...
const MCPhysReg VR512_with_sub_xmm_in_VR128L[] = {
  X86::ZMM0, X86::ZMM1, X86::ZMM2, X86::ZMM3, X86::ZMM4, X86::ZMM5, X86::ZMM6, X86::ZMM7,
};

// VR512_with_sub_xmm_in_VR128L Bit set.
const uint8_t VR512_with_sub_xmm_in_VR128LBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f,
};

extern const MCRegisterClass X86MCRegisterClasses[] = {
  { GR8, GR8Bits, 216, 20, sizeof(GR8Bits), X86::GR8RegClassID, 1, 1, true },
  { GRH8, GRH8Bits, 207, 12, sizeof(GRH8Bits), X86::GRH8RegClassID, 1, 1, false },
  { GR8_NOREX, GR8_NOREXBits, 849, 8, sizeof(GR8_NOREXBits), X86::GR8_NOREXRegClassID, 1, 1, true },
  { GR8_ABCD_H, GR8_ABCD_HBits, 440, 4, sizeof(GR8_ABCD_HBits), X86::GR8_ABCD_HRegClassID, 1, 1, true },
  { GR8_ABCD_L, GR8_ABCD_LBits, 487, 4, sizeof(GR8_ABCD_LBits), X86::GR8_ABCD_LRegClassID, 1, 1, true },
  { GRH16, GRH16Bits, 179, 17, sizeof(GRH16Bits), X86::GRH16RegClassID, 2, 1, false },
  { GR16, GR16Bits, 190, 16, sizeof(GR16Bits), X86::GR16RegClassID, 2, 1, true },
  { GR16_NOREX, GR16_NOREXBits, 787, 8, sizeof(GR16_NOREXBits), X86::GR16_NOREXRegClassID, 2, 1, true },
  { VK1, VK1Bits, 6, 8, sizeof(VK1Bits), X86::VK1RegClassID, 2, 1, true },
  { VK16, VK16Bits, 185, 8, sizeof(VK16Bits), X86::VK16RegClassID, 2, 1, true },
  { VK2, VK2Bits, 59, 8, sizeof(VK2Bits), X86::VK2RegClassID, 2, 1, true },
  { VK4, VK4Bits, 175, 8, sizeof(VK4Bits), X86::VK4RegClassID, 2, 1, true },
  { VK8, VK8Bits, 212, 8, sizeof(VK8Bits), X86::VK8RegClassID, 2, 1, true },
  { VK16WM, VK16WMBits, 530, 7, sizeof(VK16WMBits), X86::VK16WMRegClassID, 2, 1, true },
  { VK1WM, VK1WMBits, 498, 7, sizeof(VK1WMBits), X86::VK1WMRegClassID, 2, 1, true },
  { VK2WM, VK2WMBits, 511, 7, sizeof(VK2WMBits), X86::VK2WMRegClassID, 2, 1, true },
  { VK4WM, VK4WMBits, 524, 7, sizeof(VK4WMBits), X86::VK4WMRegClassID, 2, 1, true },
  { VK8WM, VK8WMBits, 537, 7, sizeof(VK8WMBits), X86::VK8WMRegClassID, 2, 1, true },
  { SEGMENT_REG, SEGMENT_REGBits, 392, 6, sizeof(SEGMENT_REGBits), X86::SEGMENT_REGRegClassID, 2, 1, true },
  { GR16_ABCD, GR16_ABCDBits, 360, 4, sizeof(GR16_ABCDBits), X86::GR16_ABCDRegClassID, 2, 1, true },
  { FPCCR, FPCCRBits, 674, 1, sizeof(FPCCRBits), X86::FPCCRRegClassID, 2, -1, false },
  { FR32X, FR32XBits, 716, 32, sizeof(FR32XBits), X86::FR32XRegClassID, 4, 1, true },
  { LOW32_ADDR_ACCESS_RBP, LOW32_ADDR_ACCESS_RBPBits, 552, 18, sizeof(LOW32_ADDR_ACCESS_RBPBits), X86::LOW32_ADDR_ACCESS_RBPRegClassID, 4, 1, true },
  { LOW32_ADDR_ACCESS, LOW32_ADDR_ACCESSBits, 694, 17, sizeof(LOW32_ADDR_ACCESSBits), X86::LOW32_ADDR_ACCESSRegClassID, 4, 1, true },
  { LOW32_ADDR_ACCESS_RBP_with_sub_8bit, LOW32_ADDR_ACCESS_RBP_with_sub_8bitBits, 999, 17, sizeof(LOW32_ADDR_ACCESS_RBP_with_sub_8bitBits), X86::LOW32_ADDR_ACCESS_RBP_with_sub_8bitRegClassID, 4, 1, true },
  { DEBUG_REG, DEBUG_REGBits, 370, 16, sizeof(DEBUG_REGBits), X86::DEBUG_REGRegClassID, 4, 1, true },
  { FR32, FR32Bits, 49, 16, sizeof(FR32Bits), X86::FR32RegClassID, 4, 1, true },
  { GR32, GR32Bits, 54, 16, sizeof(GR32Bits), X86::GR32RegClassID, 4, 1, true },
  { GR32_NOSP, GR32_NOSPBits, 616, 15, sizeof(GR32_NOSPBits), X86::GR32_NOSPRegClassID, 4, 1, true },
  { LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREX, LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREXBits, 798, 9, sizeof(LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREXBits), X86::LOW32_ADDR_ACCESS_RBP_with_sub_16bit_in_GR16_NOREXRegClassID, 4, 1, true },
  { GR32_NOREX, GR32_NOREXBits, 742, 8, sizeof(GR32_NOREXBits), X86::GR32_NOREXRegClassID, 4, 1, true },
  { VK32, VK32Bits, 16, 8, sizeof(VK32Bits), X86::VK32RegClassID, 4, 1, true },
  { GR32_NOREX_NOSP, GR32_NOREX_NOSPBits, 636, 7, sizeof(GR32_NOREX_NOSPBits), X86::GR32_NOREX_NOSPRegClassID, 4, 1, true },
  { RFP32, RFP32Bits, 21, 7, sizeof(RFP32Bits), X86::RFP32RegClassID, 4, 1, true },
  { VK32WM, VK32WMBits, 504, 7, sizeof(VK32WMBits), X86::VK32WMRegClassID, 4, 1, true },
  { GR32_ABCD, GR32_ABCDBits, 340, 4, sizeof(GR32_ABCDBits), X86::GR32_ABCDRegClassID, 4, 1, true },
  { GR32_TC, GR32_TCBits, 243, 3, sizeof(GR32_TCBits), X86::GR32_TCRegClassID, 4, 1, true },
  { GR32_AD, GR32_ADBits, 324, 2, sizeof(GR32_ADBits), X86::GR32_ADRegClassID, 4, 1, true },
  { LOW32_ADDR_ACCESS_RBP_with_sub_32bit, LOW32_ADDR_ACCESS_RBP_with_sub_32bitBits, 859, 2, sizeof(LOW32_ADDR_ACCESS_RBP_with_sub_32bitBits), X86::LOW32_ADDR_ACCESS_RBP_with_sub_32bitRegClassID, 4, 1, true },
  { CCR, CCRBits, 670, 1, sizeof(CCRBits), X86::CCRRegClassID, 4, -1, false },
  { DFCCR, DFCCRBits, 668, 1, sizeof(DFCCRBits), X86::DFCCRRegClassID, 4, -1, false },
  { LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bit, LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bitBits, 929, 1, sizeof(LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bitBits), X86::LOW32_ADDR_ACCESS_RBP_with_sub_8bit_with_sub_32bitRegClassID, 4, 1, true },
  { LOW32_ADDR_ACCESS_with_sub_32bit, LOW32_ADDR_ACCESS_with_sub_32bitBits, 896, 1, sizeof(LOW32_ADDR_ACCESS_with_sub_32bitBits), X86::LOW32_ADDR_ACCESS_with_sub_32bitRegClassID, 4, 1, true },
  { RFP64, RFP64Bits, 68, 7, sizeof(RFP64Bits), X86::RFP64RegClassID, 8, 1, true },
  { FR64X, FR64XBits, 722, 32, sizeof(FR64XBits), X86::FR64XRegClassID, 8, 1, true },
  { GR64, GR64Bits, 79, 17, sizeof(GR64Bits), X86::GR64RegClassID, 8, 1, true },
  { CONTROL_REG, CONTROL_REGBits, 380, 16, sizeof(CONTROL_REGBits), X86::CONTROL_REGRegClassID, 8, 1, true },
  { FR64, FR64Bits, 74, 16, sizeof(FR64Bits), X86::FR64RegClassID, 8, 1, true },
  { GR64_with_sub_8bit, GR64_with_sub_8bitBits, 980, 16, sizeof(GR64_with_sub_8bitBits), X86::GR64_with_sub_8bitRegClassID, 8, 1, true },
  { GR64_NOSP, GR64_NOSPBits, 626, 15, sizeof(GR64_NOSPBits), X86::GR64_NOSPRegClassID, 8, 1, true },
  { GR64_NOREX, GR64_NOREXBits, 753, 9, sizeof(GR64_NOREXBits), X86::GR64_NOREXRegClassID, 8, 1, true },
  { GR64_TC, GR64_TCBits, 265, 9, sizeof(GR64_TCBits), X86::GR64_TCRegClassID, 8, 1, true },
  { GR64_NOSP_and_GR64_TC, GR64_NOSP_and_GR64_TCBits, 251, 8, sizeof(GR64_NOSP_and_GR64_TCBits), X86::GR64_NOSP_and_GR64_TCRegClassID, 8, 1, true },
  { GR64_TCW64, GR64_TCW64Bits, 101, 8, sizeof(GR64_TCW64Bits), X86::GR64_TCW64RegClassID, 8, 1, true },
  { GR64_with_sub_16bit_in_GR16_NOREX, GR64_with_sub_16bit_in_GR16_NOREXBits, 764, 8, sizeof(GR64_with_sub_16bit_in_GR16_NOREXBits), X86::GR64_with_sub_16bit_in_GR16_NOREXRegClassID, 8, 1, true },
  { VK64, VK64Bits, 63, 8, sizeof(VK64Bits), X86::VK64RegClassID, 8, 1, true },
  { VR64, VR64Bits, 84, 8, sizeof(VR64Bits), X86::VR64RegClassID, 8, 1, true },
  { GR64_NOREX_NOSP, GR64_NOREX_NOSPBits, 652, 7, sizeof(GR64_NOREX_NOSPBits), X86::GR64_NOREX_NOSPRegClassID, 8, 1, true },
  { GR64_NOSP_and_GR64_TCW64, GR64_NOSP_and_GR64_TCW64Bits, 124, 7, sizeof(GR64_NOSP_and_GR64_TCW64Bits), X86::GR64_NOSP_and_GR64_TCW64RegClassID, 8, 1, true },
  { GR64_TC_and_GR64_TCW64, GR64_TC_and_GR64_TCW64Bits, 89, 7, sizeof(GR64_TC_and_GR64_TCW64Bits), X86::GR64_TC_and_GR64_TCW64RegClassID, 8, 1, true },
  { VK64WM, VK64WMBits, 517, 7, sizeof(VK64WMBits), X86::VK64WMRegClassID, 8, 1, true },
  { GR64_NOREX_and_GR64_TC, GR64_NOREX_and_GR64_TCBits, 301, 6, sizeof(GR64_NOREX_and_GR64_TCBits), X86::GR64_NOREX_and_GR64_TCRegClassID, 8, 1, true },
  { GR64_TC_and_GR64_NOSP_and_GR64_TCW64, GR64_TC_and_GR64_NOSP_and_GR64_TCW64Bits, 112, 6, sizeof(GR64_TC_and_GR64_NOSP_and_GR64_TCW64Bits), X86::GR64_TC_and_GR64_NOSP_and_GR64_TCW64RegClassID, 8, 1, true },
  { GR64_NOREX_NOSP_and_GR64_TC, GR64_NOREX_NOSP_and_GR64_TCBits, 273, 5, sizeof(GR64_NOREX_NOSP_and_GR64_TCBits), X86::GR64_NOREX_NOSP_and_GR64_TCRegClassID, 8, 1, true },
  { GR64_ABCD, GR64_ABCDBits, 350, 4, sizeof(GR64_ABCDBits), X86::GR64_ABCDRegClassID, 8, 1, true },
  { GR64_NOREX_and_GR64_TCW64, GR64_NOREX_and_GR64_TCW64Bits, 149, 4, sizeof(GR64_NOREX_and_GR64_TCW64Bits), X86::GR64_NOREX_and_GR64_TCW64RegClassID, 8, 1, true },
  { GR64_with_sub_32bit_in_GR32_TC, GR64_with_sub_32bit_in_GR32_TCBits, 220, 3, sizeof(GR64_with_sub_32bit_in_GR32_TCBits), X86::GR64_with_sub_32bit_in_GR32_TCRegClassID, 8, 1, true },
  { GR64_AD, GR64_ADBits, 332, 2, sizeof(GR64_ADBits), X86::GR64_ADRegClassID, 8, 1, true },
  { GR64_and_LOW32_ADDR_ACCESS_RBP, GR64_and_LOW32_ADDR_ACCESS_RBPBits, 543, 2, sizeof(GR64_and_LOW32_ADDR_ACCESS_RBPBits), X86::GR64_and_LOW32_ADDR_ACCESS_RBPRegClassID, 8, 1, true },
  { GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBP, GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBPBits, 574, 1, sizeof(GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBPBits), X86::GR64_NOREX_NOSP_and_LOW32_ADDR_ACCESS_RBPRegClassID, 8, 1, true },
  { GR64_and_LOW32_ADDR_ACCESS, GR64_and_LOW32_ADDR_ACCESSBits, 685, 1, sizeof(GR64_and_LOW32_ADDR_ACCESSBits), X86::GR64_and_LOW32_ADDR_ACCESSRegClassID, 8, 1, true },
  { RST, RSTBits, 712, 8, sizeof(RSTBits), X86::RSTRegClassID, 10, 1, false },
  { RFP80, RFP80Bits, 0, 7, sizeof(RFP80Bits), X86::RFP80RegClassID, 10, 1, true },
  { VR128X, VR128XBits, 735, 32, sizeof(VR128XBits), X86::VR128XRegClassID, 16, 1, true },
  { VR128, VR128Bits, 201, 16, sizeof(VR128Bits), X86::VR128RegClassID, 16, 1, true },
  { VR128H, VR128HBits, 433, 8, sizeof(VR128HBits), X86::VR128HRegClassID, 16, 1, true },
  { VR128L, VR128LBits, 480, 8, sizeof(VR128LBits), X86::VR128LRegClassID, 16, 1, true },
  { BNDR, BNDRBits, 680, 4, sizeof(BNDRBits), X86::BNDRRegClassID, 16, 1, true },
  { VR256X, VR256XBits, 728, 32, sizeof(VR256XBits), X86::VR256XRegClassID, 32, 1, true },
  { VR256, VR256Bits, 195, 16, sizeof(VR256Bits), X86::VR256RegClassID, 32, 1, true },
  { VR256H, VR256HBits, 404, 8, sizeof(VR256HBits), X86::VR256HRegClassID, 32, 1, true },
  { VR256L, VR256LBits, 451, 8, sizeof(VR256LBits), X86::VR256LRegClassID, 32, 1, true },
  { VR512, VR512Bits, 10, 32, sizeof(VR512Bits), X86::VR512RegClassID, 64, 1, true },
  { VR512_with_sub_xmm_in_FR32, VR512_with_sub_xmm_in_FR32Bits, 27, 16, sizeof(VR512_with_sub_xmm_in_FR32Bits), X86::VR512_with_sub_xmm_in_FR32RegClassID, 64, 1, true },
  { VR512_with_sub_xmm_in_VR128H, VR512_with_sub_xmm_in_VR128HBits, 411, 8, sizeof(VR512_with_sub_xmm_in_VR128HBits), X86::VR512_with_sub_xmm_in_VR128HRegClassID, 64, 1, true },
  { VR512_with_sub_xmm_in_VR128L, VR512_with_sub_xmm_in_VR128LBits, 458, 8, sizeof(VR512_with_sub_xmm_in_VR128LBits), X86::VR512_with_sub_xmm_in_VR128LRegClassID, 64, 1, true },
};