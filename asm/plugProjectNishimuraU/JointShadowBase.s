.include "macros.inc"
.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_8051D170, local
	.float 0.5
.endobj lbl_8051D170
.obj lbl_8051D174, local
	.float 0.0
.endobj lbl_8051D174
.obj lbl_8051D178, local
	.float 1.0
.endobj lbl_8051D178
.obj lbl_8051D17C, local
	.float 100.0
.endobj lbl_8051D17C

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn "makeShadowSRT__Q24Game19TubeShadowTransNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>", global
/* 802F2040 002EEF80  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 802F2044 002EEF84  7C 08 02 A6 */	mflr r0
/* 802F2048 002EEF88  90 01 00 84 */	stw r0, 0x84(r1)
/* 802F204C 002EEF8C  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 802F2050 002EEF90  F3 E1 00 78 */	psq_st f31, 120(r1), 0, qr0
/* 802F2054 002EEF94  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 802F2058 002EEF98  F3 C1 00 68 */	psq_st f30, 104(r1), 0, qr0
/* 802F205C 002EEF9C  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 802F2060 002EEFA0  F3 A1 00 58 */	psq_st f29, 88(r1), 0, qr0
/* 802F2064 002EEFA4  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 802F2068 002EEFA8  F3 81 00 48 */	psq_st f28, 72(r1), 0, qr0
/* 802F206C 002EEFAC  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 802F2070 002EEFB0  F3 61 00 38 */	psq_st f27, 56(r1), 0, qr0
/* 802F2074 002EEFB4  DB 41 00 20 */	stfd f26, 0x20(r1)
/* 802F2078 002EEFB8  F3 41 00 28 */	psq_st f26, 40(r1), 0, qr0
/* 802F207C 002EEFBC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802F2080 002EEFC0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802F2084 002EEFC4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802F2088 002EEFC8  93 81 00 10 */	stw r28, 0x10(r1)
/* 802F208C 002EEFCC  7C 7C 1B 78 */	mr r28, r3
/* 802F2090 002EEFD0  7C 9D 23 78 */	mr r29, r4
/* 802F2094 002EEFD4  80 63 00 24 */	lwz r3, 0x24(r3)
/* 802F2098 002EEFD8  7C BE 2B 78 */	mr r30, r5
/* 802F209C 002EEFDC  7C DF 33 78 */	mr r31, r6
/* 802F20A0 002EEFE0  48 13 78 01 */	bl getWorldMatrix__Q28SysShape5JointFv
/* 802F20A4 002EEFE4  C0 63 00 00 */	lfs f3, 0(r3)
/* 802F20A8 002EEFE8  C0 A3 00 10 */	lfs f5, 0x10(r3)
/* 802F20AC 002EEFEC  C0 C3 00 20 */	lfs f6, 0x20(r3)
/* 802F20B0 002EEFF0  C0 43 00 04 */	lfs f2, 4(r3)
/* 802F20B4 002EEFF4  C0 E3 00 14 */	lfs f7, 0x14(r3)
/* 802F20B8 002EEFF8  C1 03 00 24 */	lfs f8, 0x24(r3)
/* 802F20BC 002EEFFC  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 802F20C0 002EF000  C0 82 EE 10 */	lfs f4, lbl_8051D170@sda21(r2)
/* 802F20C4 002EF004  D0 1E 00 00 */	stfs f0, 0(r30)
/* 802F20C8 002EF008  C3 A2 EE 14 */	lfs f29, lbl_8051D174@sda21(r2)
/* 802F20CC 002EF00C  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 802F20D0 002EF010  D0 1E 00 04 */	stfs f0, 4(r30)
/* 802F20D4 002EF014  C0 03 00 2C */	lfs f0, 0x2c(r3)
/* 802F20D8 002EF018  D0 1E 00 08 */	stfs f0, 8(r30)
/* 802F20DC 002EF01C  C0 1D 00 1C */	lfs f0, 0x1c(r29)
/* 802F20E0 002EF020  C0 3D 00 18 */	lfs f1, 0x18(r29)
/* 802F20E4 002EF024  EC 02 00 32 */	fmuls f0, f2, f0
/* 802F20E8 002EF028  C0 5E 00 00 */	lfs f2, 0(r30)
/* 802F20EC 002EF02C  EC 03 00 7A */	fmadds f0, f3, f1, f0
/* 802F20F0 002EF030  EC 02 00 2A */	fadds f0, f2, f0
/* 802F20F4 002EF034  D0 1F 00 00 */	stfs f0, 0(r31)
/* 802F20F8 002EF038  C0 1D 00 1C */	lfs f0, 0x1c(r29)
/* 802F20FC 002EF03C  C0 3D 00 18 */	lfs f1, 0x18(r29)
/* 802F2100 002EF040  EC 07 00 32 */	fmuls f0, f7, f0
/* 802F2104 002EF044  C0 5E 00 04 */	lfs f2, 4(r30)
/* 802F2108 002EF048  EC 05 00 7A */	fmadds f0, f5, f1, f0
/* 802F210C 002EF04C  EC 02 00 2A */	fadds f0, f2, f0
/* 802F2110 002EF050  D0 1F 00 04 */	stfs f0, 4(r31)
/* 802F2114 002EF054  C0 1D 00 1C */	lfs f0, 0x1c(r29)
/* 802F2118 002EF058  C0 3D 00 18 */	lfs f1, 0x18(r29)
/* 802F211C 002EF05C  EC 08 00 32 */	fmuls f0, f8, f0
/* 802F2120 002EF060  C0 5E 00 08 */	lfs f2, 8(r30)
/* 802F2124 002EF064  EC 06 00 7A */	fmadds f0, f6, f1, f0
/* 802F2128 002EF068  EC 02 00 2A */	fadds f0, f2, f0
/* 802F212C 002EF06C  D0 1F 00 08 */	stfs f0, 8(r31)
/* 802F2130 002EF070  C1 5F 00 00 */	lfs f10, 0(r31)
/* 802F2134 002EF074  C1 3E 00 00 */	lfs f9, 0(r30)
/* 802F2138 002EF078  C1 9F 00 04 */	lfs f12, 4(r31)
/* 802F213C 002EF07C  EC 0A 48 28 */	fsubs f0, f10, f9
/* 802F2140 002EF080  C1 7E 00 04 */	lfs f11, 4(r30)
/* 802F2144 002EF084  C3 FF 00 08 */	lfs f31, 8(r31)
/* 802F2148 002EF088  C1 BE 00 08 */	lfs f13, 8(r30)
/* 802F214C 002EF08C  EC 2C 58 28 */	fsubs f1, f12, f11
/* 802F2150 002EF090  EC 04 00 32 */	fmuls f0, f4, f0
/* 802F2154 002EF094  EC 5F 68 28 */	fsubs f2, f31, f13
/* 802F2158 002EF098  C1 1D 00 14 */	lfs f8, 0x14(r29)
/* 802F215C 002EF09C  EC 24 00 72 */	fmuls f1, f4, f1
/* 802F2160 002EF0A0  C0 DD 00 0C */	lfs f6, 0xc(r29)
/* 802F2164 002EF0A4  EC 60 02 32 */	fmuls f3, f0, f8
/* 802F2168 002EF0A8  EC 44 00 B2 */	fmuls f2, f4, f2
/* 802F216C 002EF0AC  C0 FD 00 10 */	lfs f7, 0x10(r29)
/* 802F2170 002EF0B0  EC A1 01 B2 */	fmuls f5, f1, f6
/* 802F2174 002EF0B4  EC 82 19 B8 */	fmsubs f4, f2, f6, f3
/* 802F2178 002EF0B8  EC 62 01 F2 */	fmuls f3, f2, f7
/* 802F217C 002EF0BC  EC A0 29 F8 */	fmsubs f5, f0, f7, f5
/* 802F2180 002EF0C0  EF 84 01 32 */	fmuls f28, f4, f4
/* 802F2184 002EF0C4  EC 61 1A 38 */	fmsubs f3, f1, f8, f3
/* 802F2188 002EF0C8  EF 65 01 72 */	fmuls f27, f5, f5
/* 802F218C 002EF0CC  EF C3 E0 FA */	fmadds f30, f3, f3, f28
/* 802F2190 002EF0D0  EF DB F0 2A */	fadds f30, f27, f30
/* 802F2194 002EF0D4  FC 1E E8 40 */	fcmpo cr0, f30, f29
/* 802F2198 002EF0D8  40 81 00 14 */	ble .L_802F21AC
/* 802F219C 002EF0DC  40 81 00 14 */	ble .L_802F21B0
/* 802F21A0 002EF0E0  FF A0 F0 34 */	frsqrte f29, f30
/* 802F21A4 002EF0E4  EF DD 07 B2 */	fmuls f30, f29, f30
/* 802F21A8 002EF0E8  48 00 00 08 */	b .L_802F21B0
.L_802F21AC:
/* 802F21AC 002EF0EC  FF C0 E8 90 */	fmr f30, f29
.L_802F21B0:
/* 802F21B0 002EF0F0  C3 A2 EE 14 */	lfs f29, lbl_8051D174@sda21(r2)
/* 802F21B4 002EF0F4  FC 1E E8 40 */	fcmpo cr0, f30, f29
/* 802F21B8 002EF0F8  40 81 00 18 */	ble .L_802F21D0
/* 802F21BC 002EF0FC  C3 A2 EE 18 */	lfs f29, lbl_8051D178@sda21(r2)
/* 802F21C0 002EF100  EF BD F0 24 */	fdivs f29, f29, f30
/* 802F21C4 002EF104  EC 63 07 72 */	fmuls f3, f3, f29
/* 802F21C8 002EF108  EC 84 07 72 */	fmuls f4, f4, f29
/* 802F21CC 002EF10C  EC A5 07 72 */	fmuls f5, f5, f29
.L_802F21D0:
/* 802F21D0 002EF110  C3 5D 00 24 */	lfs f26, 0x24(r29)
/* 802F21D4 002EF114  ED 6C 58 2A */	fadds f11, f12, f11
/* 802F21D8 002EF118  C3 7D 00 20 */	lfs f27, 0x20(r29)
/* 802F21DC 002EF11C  EF CA 48 2A */	fadds f30, f10, f9
/* 802F21E0 002EF120  ED 47 06 B2 */	fmuls f10, f7, f26
/* 802F21E4 002EF124  C3 A2 EE 10 */	lfs f29, lbl_8051D170@sda21(r2)
/* 802F21E8 002EF128  ED 86 06 B2 */	fmuls f12, f6, f26
/* 802F21EC 002EF12C  C1 3D 00 04 */	lfs f9, 4(r29)
/* 802F21F0 002EF130  EC 63 06 F2 */	fmuls f3, f3, f27
/* 802F21F4 002EF134  EF 9D 52 FA */	fmadds f28, f29, f11, f10
/* 802F21F8 002EF138  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F21FC 002EF13C  EC 84 06 F2 */	fmuls f4, f4, f27
/* 802F2200 002EF140  C1 62 EE 1C */	lfs f11, lbl_8051D17C@sda21(r2)
/* 802F2204 002EF144  EC A5 06 F2 */	fmuls f5, f5, f27
/* 802F2208 002EF148  ED 5C 48 28 */	fsubs f10, f28, f9
/* 802F220C 002EF14C  D0 03 00 00 */	stfs f0, 0(r3)
/* 802F2210 002EF150  ED 9D 67 BA */	fmadds f12, f29, f30, f12
/* 802F2214 002EF154  ED 3F 68 2A */	fadds f9, f31, f13
/* 802F2218 002EF158  ED 4B 50 2A */	fadds f10, f11, f10
/* 802F221C 002EF15C  D0 23 00 10 */	stfs f1, 0x10(r3)
/* 802F2220 002EF160  EC 08 06 B2 */	fmuls f0, f8, f26
/* 802F2224 002EF164  D0 43 00 20 */	stfs f2, 0x20(r3)
/* 802F2228 002EF168  EC C6 02 B2 */	fmuls f6, f6, f10
/* 802F222C 002EF16C  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F2230 002EF170  EC 47 02 B2 */	fmuls f2, f7, f10
/* 802F2234 002EF174  EC 28 02 B2 */	fmuls f1, f8, f10
/* 802F2238 002EF178  D0 C3 00 04 */	stfs f6, 4(r3)
/* 802F223C 002EF17C  EC 1D 02 7A */	fmadds f0, f29, f9, f0
/* 802F2240 002EF180  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 802F2244 002EF184  D0 23 00 24 */	stfs f1, 0x24(r3)
/* 802F2248 002EF188  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F224C 002EF18C  D0 63 00 08 */	stfs f3, 8(r3)
/* 802F2250 002EF190  D0 83 00 18 */	stfs f4, 0x18(r3)
/* 802F2254 002EF194  D0 A3 00 28 */	stfs f5, 0x28(r3)
/* 802F2258 002EF198  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F225C 002EF19C  D1 83 00 0C */	stfs f12, 0xc(r3)
/* 802F2260 002EF1A0  D3 83 00 1C */	stfs f28, 0x1c(r3)
/* 802F2264 002EF1A4  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 802F2268 002EF1A8  E3 E1 00 78 */	psq_l f31, 120(r1), 0, qr0
/* 802F226C 002EF1AC  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 802F2270 002EF1B0  E3 C1 00 68 */	psq_l f30, 104(r1), 0, qr0
/* 802F2274 002EF1B4  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 802F2278 002EF1B8  E3 A1 00 58 */	psq_l f29, 88(r1), 0, qr0
/* 802F227C 002EF1BC  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 802F2280 002EF1C0  E3 81 00 48 */	psq_l f28, 72(r1), 0, qr0
/* 802F2284 002EF1C4  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 802F2288 002EF1C8  E3 61 00 38 */	psq_l f27, 56(r1), 0, qr0
/* 802F228C 002EF1CC  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 802F2290 002EF1D0  E3 41 00 28 */	psq_l f26, 40(r1), 0, qr0
/* 802F2294 002EF1D4  CB 41 00 20 */	lfd f26, 0x20(r1)
/* 802F2298 002EF1D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802F229C 002EF1DC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802F22A0 002EF1E0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802F22A4 002EF1E4  80 01 00 84 */	lwz r0, 0x84(r1)
/* 802F22A8 002EF1E8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 802F22AC 002EF1EC  7C 08 03 A6 */	mtlr r0
/* 802F22B0 002EF1F0  38 21 00 80 */	addi r1, r1, 0x80
/* 802F22B4 002EF1F4  4E 80 00 20 */	blr 
.endfn "makeShadowSRT__Q24Game19TubeShadowTransNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"

.fn "makeShadowSRT__Q24Game17TubeShadowSetNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>", global
/* 802F22B8 002EF1F8  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 802F22BC 002EF1FC  7C 08 02 A6 */	mflr r0
/* 802F22C0 002EF200  90 01 00 84 */	stw r0, 0x84(r1)
/* 802F22C4 002EF204  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 802F22C8 002EF208  F3 E1 00 78 */	psq_st f31, 120(r1), 0, qr0
/* 802F22CC 002EF20C  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 802F22D0 002EF210  F3 C1 00 68 */	psq_st f30, 104(r1), 0, qr0
/* 802F22D4 002EF214  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 802F22D8 002EF218  F3 A1 00 58 */	psq_st f29, 88(r1), 0, qr0
/* 802F22DC 002EF21C  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 802F22E0 002EF220  F3 81 00 48 */	psq_st f28, 72(r1), 0, qr0
/* 802F22E4 002EF224  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 802F22E8 002EF228  F3 61 00 38 */	psq_st f27, 56(r1), 0, qr0
/* 802F22EC 002EF22C  DB 41 00 20 */	stfd f26, 0x20(r1)
/* 802F22F0 002EF230  F3 41 00 28 */	psq_st f26, 40(r1), 0, qr0
/* 802F22F4 002EF234  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802F22F8 002EF238  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802F22FC 002EF23C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802F2300 002EF240  93 81 00 10 */	stw r28, 0x10(r1)
/* 802F2304 002EF244  7C 7C 1B 78 */	mr r28, r3
/* 802F2308 002EF248  7C 9D 23 78 */	mr r29, r4
/* 802F230C 002EF24C  80 63 00 24 */	lwz r3, 0x24(r3)
/* 802F2310 002EF250  7C BE 2B 78 */	mr r30, r5
/* 802F2314 002EF254  7C DF 33 78 */	mr r31, r6
/* 802F2318 002EF258  48 13 75 89 */	bl getWorldMatrix__Q28SysShape5JointFv
/* 802F231C 002EF25C  C0 63 00 00 */	lfs f3, 0(r3)
/* 802F2320 002EF260  C0 A3 00 10 */	lfs f5, 0x10(r3)
/* 802F2324 002EF264  C0 C3 00 20 */	lfs f6, 0x20(r3)
/* 802F2328 002EF268  C0 43 00 04 */	lfs f2, 4(r3)
/* 802F232C 002EF26C  C0 E3 00 14 */	lfs f7, 0x14(r3)
/* 802F2330 002EF270  C1 03 00 24 */	lfs f8, 0x24(r3)
/* 802F2334 002EF274  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 802F2338 002EF278  C0 82 EE 10 */	lfs f4, lbl_8051D170@sda21(r2)
/* 802F233C 002EF27C  D0 1F 00 00 */	stfs f0, 0(r31)
/* 802F2340 002EF280  C3 A2 EE 14 */	lfs f29, lbl_8051D174@sda21(r2)
/* 802F2344 002EF284  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 802F2348 002EF288  D0 1F 00 04 */	stfs f0, 4(r31)
/* 802F234C 002EF28C  C0 03 00 2C */	lfs f0, 0x2c(r3)
/* 802F2350 002EF290  D0 1F 00 08 */	stfs f0, 8(r31)
/* 802F2354 002EF294  C0 1D 00 1C */	lfs f0, 0x1c(r29)
/* 802F2358 002EF298  C0 3D 00 18 */	lfs f1, 0x18(r29)
/* 802F235C 002EF29C  EC 02 00 32 */	fmuls f0, f2, f0
/* 802F2360 002EF2A0  C0 5F 00 00 */	lfs f2, 0(r31)
/* 802F2364 002EF2A4  EC 03 00 7A */	fmadds f0, f3, f1, f0
/* 802F2368 002EF2A8  EC 02 00 2A */	fadds f0, f2, f0
/* 802F236C 002EF2AC  D0 1F 00 00 */	stfs f0, 0(r31)
/* 802F2370 002EF2B0  C0 1D 00 1C */	lfs f0, 0x1c(r29)
/* 802F2374 002EF2B4  C0 3D 00 18 */	lfs f1, 0x18(r29)
/* 802F2378 002EF2B8  EC 07 00 32 */	fmuls f0, f7, f0
/* 802F237C 002EF2BC  C0 5F 00 04 */	lfs f2, 4(r31)
/* 802F2380 002EF2C0  EC 05 00 7A */	fmadds f0, f5, f1, f0
/* 802F2384 002EF2C4  EC 02 00 2A */	fadds f0, f2, f0
/* 802F2388 002EF2C8  D0 1F 00 04 */	stfs f0, 4(r31)
/* 802F238C 002EF2CC  C0 1D 00 1C */	lfs f0, 0x1c(r29)
/* 802F2390 002EF2D0  C0 3D 00 18 */	lfs f1, 0x18(r29)
/* 802F2394 002EF2D4  EC 08 00 32 */	fmuls f0, f8, f0
/* 802F2398 002EF2D8  C0 5F 00 08 */	lfs f2, 8(r31)
/* 802F239C 002EF2DC  EC 06 00 7A */	fmadds f0, f6, f1, f0
/* 802F23A0 002EF2E0  EC 02 00 2A */	fadds f0, f2, f0
/* 802F23A4 002EF2E4  D0 1F 00 08 */	stfs f0, 8(r31)
/* 802F23A8 002EF2E8  C1 5F 00 00 */	lfs f10, 0(r31)
/* 802F23AC 002EF2EC  C1 3E 00 00 */	lfs f9, 0(r30)
/* 802F23B0 002EF2F0  C1 9F 00 04 */	lfs f12, 4(r31)
/* 802F23B4 002EF2F4  EC 0A 48 28 */	fsubs f0, f10, f9
/* 802F23B8 002EF2F8  C1 7E 00 04 */	lfs f11, 4(r30)
/* 802F23BC 002EF2FC  C3 FF 00 08 */	lfs f31, 8(r31)
/* 802F23C0 002EF300  C1 BE 00 08 */	lfs f13, 8(r30)
/* 802F23C4 002EF304  EC 2C 58 28 */	fsubs f1, f12, f11
/* 802F23C8 002EF308  EC 04 00 32 */	fmuls f0, f4, f0
/* 802F23CC 002EF30C  EC 5F 68 28 */	fsubs f2, f31, f13
/* 802F23D0 002EF310  C1 1D 00 14 */	lfs f8, 0x14(r29)
/* 802F23D4 002EF314  EC 24 00 72 */	fmuls f1, f4, f1
/* 802F23D8 002EF318  C0 DD 00 0C */	lfs f6, 0xc(r29)
/* 802F23DC 002EF31C  EC 60 02 32 */	fmuls f3, f0, f8
/* 802F23E0 002EF320  EC 44 00 B2 */	fmuls f2, f4, f2
/* 802F23E4 002EF324  C0 FD 00 10 */	lfs f7, 0x10(r29)
/* 802F23E8 002EF328  EC A1 01 B2 */	fmuls f5, f1, f6
/* 802F23EC 002EF32C  EC 82 19 B8 */	fmsubs f4, f2, f6, f3
/* 802F23F0 002EF330  EC 62 01 F2 */	fmuls f3, f2, f7
/* 802F23F4 002EF334  EC A0 29 F8 */	fmsubs f5, f0, f7, f5
/* 802F23F8 002EF338  EF 84 01 32 */	fmuls f28, f4, f4
/* 802F23FC 002EF33C  EC 61 1A 38 */	fmsubs f3, f1, f8, f3
/* 802F2400 002EF340  EF 65 01 72 */	fmuls f27, f5, f5
/* 802F2404 002EF344  EF C3 E0 FA */	fmadds f30, f3, f3, f28
/* 802F2408 002EF348  EF DB F0 2A */	fadds f30, f27, f30
/* 802F240C 002EF34C  FC 1E E8 40 */	fcmpo cr0, f30, f29
/* 802F2410 002EF350  40 81 00 14 */	ble .L_802F2424
/* 802F2414 002EF354  40 81 00 14 */	ble .L_802F2428
/* 802F2418 002EF358  FF A0 F0 34 */	frsqrte f29, f30
/* 802F241C 002EF35C  EF DD 07 B2 */	fmuls f30, f29, f30
/* 802F2420 002EF360  48 00 00 08 */	b .L_802F2428
.L_802F2424:
/* 802F2424 002EF364  FF C0 E8 90 */	fmr f30, f29
.L_802F2428:
/* 802F2428 002EF368  C3 A2 EE 14 */	lfs f29, lbl_8051D174@sda21(r2)
/* 802F242C 002EF36C  FC 1E E8 40 */	fcmpo cr0, f30, f29
/* 802F2430 002EF370  40 81 00 18 */	ble .L_802F2448
/* 802F2434 002EF374  C3 A2 EE 18 */	lfs f29, lbl_8051D178@sda21(r2)
/* 802F2438 002EF378  EF BD F0 24 */	fdivs f29, f29, f30
/* 802F243C 002EF37C  EC 63 07 72 */	fmuls f3, f3, f29
/* 802F2440 002EF380  EC 84 07 72 */	fmuls f4, f4, f29
/* 802F2444 002EF384  EC A5 07 72 */	fmuls f5, f5, f29
.L_802F2448:
/* 802F2448 002EF388  C3 5D 00 24 */	lfs f26, 0x24(r29)
/* 802F244C 002EF38C  ED 6C 58 2A */	fadds f11, f12, f11
/* 802F2450 002EF390  C3 7D 00 20 */	lfs f27, 0x20(r29)
/* 802F2454 002EF394  EF CA 48 2A */	fadds f30, f10, f9
/* 802F2458 002EF398  ED 47 06 B2 */	fmuls f10, f7, f26
/* 802F245C 002EF39C  C3 A2 EE 10 */	lfs f29, lbl_8051D170@sda21(r2)
/* 802F2460 002EF3A0  ED 86 06 B2 */	fmuls f12, f6, f26
/* 802F2464 002EF3A4  C1 3D 00 04 */	lfs f9, 4(r29)
/* 802F2468 002EF3A8  EC 63 06 F2 */	fmuls f3, f3, f27
/* 802F246C 002EF3AC  EF 9D 52 FA */	fmadds f28, f29, f11, f10
/* 802F2470 002EF3B0  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F2474 002EF3B4  EC 84 06 F2 */	fmuls f4, f4, f27
/* 802F2478 002EF3B8  C1 62 EE 1C */	lfs f11, lbl_8051D17C@sda21(r2)
/* 802F247C 002EF3BC  EC A5 06 F2 */	fmuls f5, f5, f27
/* 802F2480 002EF3C0  ED 5C 48 28 */	fsubs f10, f28, f9
/* 802F2484 002EF3C4  D0 03 00 00 */	stfs f0, 0(r3)
/* 802F2488 002EF3C8  ED 9D 67 BA */	fmadds f12, f29, f30, f12
/* 802F248C 002EF3CC  ED 3F 68 2A */	fadds f9, f31, f13
/* 802F2490 002EF3D0  ED 4B 50 2A */	fadds f10, f11, f10
/* 802F2494 002EF3D4  D0 23 00 10 */	stfs f1, 0x10(r3)
/* 802F2498 002EF3D8  EC 08 06 B2 */	fmuls f0, f8, f26
/* 802F249C 002EF3DC  D0 43 00 20 */	stfs f2, 0x20(r3)
/* 802F24A0 002EF3E0  EC C6 02 B2 */	fmuls f6, f6, f10
/* 802F24A4 002EF3E4  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F24A8 002EF3E8  EC 47 02 B2 */	fmuls f2, f7, f10
/* 802F24AC 002EF3EC  EC 28 02 B2 */	fmuls f1, f8, f10
/* 802F24B0 002EF3F0  D0 C3 00 04 */	stfs f6, 4(r3)
/* 802F24B4 002EF3F4  EC 1D 02 7A */	fmadds f0, f29, f9, f0
/* 802F24B8 002EF3F8  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 802F24BC 002EF3FC  D0 23 00 24 */	stfs f1, 0x24(r3)
/* 802F24C0 002EF400  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F24C4 002EF404  D0 63 00 08 */	stfs f3, 8(r3)
/* 802F24C8 002EF408  D0 83 00 18 */	stfs f4, 0x18(r3)
/* 802F24CC 002EF40C  D0 A3 00 28 */	stfs f5, 0x28(r3)
/* 802F24D0 002EF410  80 7C 00 1C */	lwz r3, 0x1c(r28)
/* 802F24D4 002EF414  D1 83 00 0C */	stfs f12, 0xc(r3)
/* 802F24D8 002EF418  D3 83 00 1C */	stfs f28, 0x1c(r3)
/* 802F24DC 002EF41C  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 802F24E0 002EF420  E3 E1 00 78 */	psq_l f31, 120(r1), 0, qr0
/* 802F24E4 002EF424  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 802F24E8 002EF428  E3 C1 00 68 */	psq_l f30, 104(r1), 0, qr0
/* 802F24EC 002EF42C  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 802F24F0 002EF430  E3 A1 00 58 */	psq_l f29, 88(r1), 0, qr0
/* 802F24F4 002EF434  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 802F24F8 002EF438  E3 81 00 48 */	psq_l f28, 72(r1), 0, qr0
/* 802F24FC 002EF43C  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 802F2500 002EF440  E3 61 00 38 */	psq_l f27, 56(r1), 0, qr0
/* 802F2504 002EF444  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 802F2508 002EF448  E3 41 00 28 */	psq_l f26, 40(r1), 0, qr0
/* 802F250C 002EF44C  CB 41 00 20 */	lfd f26, 0x20(r1)
/* 802F2510 002EF450  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802F2514 002EF454  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802F2518 002EF458  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802F251C 002EF45C  80 01 00 84 */	lwz r0, 0x84(r1)
/* 802F2520 002EF460  83 81 00 10 */	lwz r28, 0x10(r1)
/* 802F2524 002EF464  7C 08 03 A6 */	mtlr r0
/* 802F2528 002EF468  38 21 00 80 */	addi r1, r1, 0x80
/* 802F252C 002EF46C  4E 80 00 20 */	blr 
.endfn "makeShadowSRT__Q24Game17TubeShadowSetNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"

.fn "makeShadowSRT__Q24Game17TubeShadowPosNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>", global
/* 802F2530 002EF470  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 802F2534 002EF474  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 802F2538 002EF478  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 802F253C 002EF47C  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 802F2540 002EF480  F3 C1 00 58 */	psq_st f30, 88(r1), 0, qr0
/* 802F2544 002EF484  DB A1 00 40 */	stfd f29, 0x40(r1)
/* 802F2548 002EF488  F3 A1 00 48 */	psq_st f29, 72(r1), 0, qr0
/* 802F254C 002EF48C  DB 81 00 30 */	stfd f28, 0x30(r1)
/* 802F2550 002EF490  F3 81 00 38 */	psq_st f28, 56(r1), 0, qr0
/* 802F2554 002EF494  DB 61 00 20 */	stfd f27, 0x20(r1)
/* 802F2558 002EF498  F3 61 00 28 */	psq_st f27, 40(r1), 0, qr0
/* 802F255C 002EF49C  DB 41 00 10 */	stfd f26, 0x10(r1)
/* 802F2560 002EF4A0  F3 41 00 18 */	psq_st f26, 24(r1), 0, qr0
/* 802F2564 002EF4A4  C1 46 00 00 */	lfs f10, 0(r6)
/* 802F2568 002EF4A8  C1 25 00 00 */	lfs f9, 0(r5)
/* 802F256C 002EF4AC  C0 62 EE 10 */	lfs f3, lbl_8051D170@sda21(r2)
/* 802F2570 002EF4B0  EC 0A 48 28 */	fsubs f0, f10, f9
/* 802F2574 002EF4B4  C1 86 00 04 */	lfs f12, 4(r6)
/* 802F2578 002EF4B8  C1 65 00 04 */	lfs f11, 4(r5)
/* 802F257C 002EF4BC  C3 E6 00 08 */	lfs f31, 8(r6)
/* 802F2580 002EF4C0  C1 A5 00 08 */	lfs f13, 8(r5)
/* 802F2584 002EF4C4  EC 2C 58 28 */	fsubs f1, f12, f11
/* 802F2588 002EF4C8  EC 03 00 32 */	fmuls f0, f3, f0
/* 802F258C 002EF4CC  C1 04 00 14 */	lfs f8, 0x14(r4)
/* 802F2590 002EF4D0  EC 5F 68 28 */	fsubs f2, f31, f13
/* 802F2594 002EF4D4  C0 E4 00 10 */	lfs f7, 0x10(r4)
/* 802F2598 002EF4D8  EC 23 00 72 */	fmuls f1, f3, f1
/* 802F259C 002EF4DC  C0 C4 00 0C */	lfs f6, 0xc(r4)
/* 802F25A0 002EF4E0  EC 43 00 B2 */	fmuls f2, f3, f2
/* 802F25A4 002EF4E4  C3 A2 EE 14 */	lfs f29, lbl_8051D174@sda21(r2)
/* 802F25A8 002EF4E8  EC 80 02 32 */	fmuls f4, f0, f8
/* 802F25AC 002EF4EC  EC A1 01 B2 */	fmuls f5, f1, f6
/* 802F25B0 002EF4F0  EC 62 01 F2 */	fmuls f3, f2, f7
/* 802F25B4 002EF4F4  EC 82 21 B8 */	fmsubs f4, f2, f6, f4
/* 802F25B8 002EF4F8  EC A0 29 F8 */	fmsubs f5, f0, f7, f5
/* 802F25BC 002EF4FC  EC 61 1A 38 */	fmsubs f3, f1, f8, f3
/* 802F25C0 002EF500  EF 84 01 32 */	fmuls f28, f4, f4
/* 802F25C4 002EF504  EF 65 01 72 */	fmuls f27, f5, f5
/* 802F25C8 002EF508  EF C3 E0 FA */	fmadds f30, f3, f3, f28
/* 802F25CC 002EF50C  EF DB F0 2A */	fadds f30, f27, f30
/* 802F25D0 002EF510  FC 1E E8 40 */	fcmpo cr0, f30, f29
/* 802F25D4 002EF514  40 81 00 14 */	ble .L_802F25E8
/* 802F25D8 002EF518  40 81 00 14 */	ble .L_802F25EC
/* 802F25DC 002EF51C  FF A0 F0 34 */	frsqrte f29, f30
/* 802F25E0 002EF520  EF DD 07 B2 */	fmuls f30, f29, f30
/* 802F25E4 002EF524  48 00 00 08 */	b .L_802F25EC
.L_802F25E8:
/* 802F25E8 002EF528  FF C0 E8 90 */	fmr f30, f29
.L_802F25EC:
/* 802F25EC 002EF52C  C3 A2 EE 14 */	lfs f29, lbl_8051D174@sda21(r2)
/* 802F25F0 002EF530  FC 1E E8 40 */	fcmpo cr0, f30, f29
/* 802F25F4 002EF534  40 81 00 18 */	ble .L_802F260C
/* 802F25F8 002EF538  C3 A2 EE 18 */	lfs f29, lbl_8051D178@sda21(r2)
/* 802F25FC 002EF53C  EF BD F0 24 */	fdivs f29, f29, f30
/* 802F2600 002EF540  EC 63 07 72 */	fmuls f3, f3, f29
/* 802F2604 002EF544  EC 84 07 72 */	fmuls f4, f4, f29
/* 802F2608 002EF548  EC A5 07 72 */	fmuls f5, f5, f29
.L_802F260C:
/* 802F260C 002EF54C  C3 44 00 24 */	lfs f26, 0x24(r4)
/* 802F2610 002EF550  ED 6C 58 2A */	fadds f11, f12, f11
/* 802F2614 002EF554  C3 64 00 20 */	lfs f27, 0x20(r4)
/* 802F2618 002EF558  EF CA 48 2A */	fadds f30, f10, f9
/* 802F261C 002EF55C  ED 47 06 B2 */	fmuls f10, f7, f26
/* 802F2620 002EF560  C3 A2 EE 10 */	lfs f29, lbl_8051D170@sda21(r2)
/* 802F2624 002EF564  ED 86 06 B2 */	fmuls f12, f6, f26
/* 802F2628 002EF568  C1 24 00 04 */	lfs f9, 4(r4)
/* 802F262C 002EF56C  EC 63 06 F2 */	fmuls f3, f3, f27
/* 802F2630 002EF570  EF 9D 52 FA */	fmadds f28, f29, f11, f10
/* 802F2634 002EF574  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 802F2638 002EF578  EC 84 06 F2 */	fmuls f4, f4, f27
/* 802F263C 002EF57C  C1 62 EE 1C */	lfs f11, lbl_8051D17C@sda21(r2)
/* 802F2640 002EF580  EC A5 06 F2 */	fmuls f5, f5, f27
/* 802F2644 002EF584  ED 5C 48 28 */	fsubs f10, f28, f9
/* 802F2648 002EF588  D0 04 00 00 */	stfs f0, 0(r4)
/* 802F264C 002EF58C  ED 9D 67 BA */	fmadds f12, f29, f30, f12
/* 802F2650 002EF590  ED 3F 68 2A */	fadds f9, f31, f13
/* 802F2654 002EF594  ED 4B 50 2A */	fadds f10, f11, f10
/* 802F2658 002EF598  D0 24 00 10 */	stfs f1, 0x10(r4)
/* 802F265C 002EF59C  EC 08 06 B2 */	fmuls f0, f8, f26
/* 802F2660 002EF5A0  D0 44 00 20 */	stfs f2, 0x20(r4)
/* 802F2664 002EF5A4  EC C6 02 B2 */	fmuls f6, f6, f10
/* 802F2668 002EF5A8  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 802F266C 002EF5AC  EC 47 02 B2 */	fmuls f2, f7, f10
/* 802F2670 002EF5B0  EC 28 02 B2 */	fmuls f1, f8, f10
/* 802F2674 002EF5B4  D0 C4 00 04 */	stfs f6, 4(r4)
/* 802F2678 002EF5B8  EC 1D 02 7A */	fmadds f0, f29, f9, f0
/* 802F267C 002EF5BC  D0 44 00 14 */	stfs f2, 0x14(r4)
/* 802F2680 002EF5C0  D0 24 00 24 */	stfs f1, 0x24(r4)
/* 802F2684 002EF5C4  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 802F2688 002EF5C8  D0 64 00 08 */	stfs f3, 8(r4)
/* 802F268C 002EF5CC  D0 84 00 18 */	stfs f4, 0x18(r4)
/* 802F2690 002EF5D0  D0 A4 00 28 */	stfs f5, 0x28(r4)
/* 802F2694 002EF5D4  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 802F2698 002EF5D8  D1 83 00 0C */	stfs f12, 0xc(r3)
/* 802F269C 002EF5DC  D3 83 00 1C */	stfs f28, 0x1c(r3)
/* 802F26A0 002EF5E0  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 802F26A4 002EF5E4  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 802F26A8 002EF5E8  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 802F26AC 002EF5EC  E3 C1 00 58 */	psq_l f30, 88(r1), 0, qr0
/* 802F26B0 002EF5F0  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 802F26B4 002EF5F4  E3 A1 00 48 */	psq_l f29, 72(r1), 0, qr0
/* 802F26B8 002EF5F8  CB A1 00 40 */	lfd f29, 0x40(r1)
/* 802F26BC 002EF5FC  E3 81 00 38 */	psq_l f28, 56(r1), 0, qr0
/* 802F26C0 002EF600  CB 81 00 30 */	lfd f28, 0x30(r1)
/* 802F26C4 002EF604  E3 61 00 28 */	psq_l f27, 40(r1), 0, qr0
/* 802F26C8 002EF608  CB 61 00 20 */	lfd f27, 0x20(r1)
/* 802F26CC 002EF60C  E3 41 00 18 */	psq_l f26, 24(r1), 0, qr0
/* 802F26D0 002EF610  CB 41 00 10 */	lfd f26, 0x10(r1)
/* 802F26D4 002EF614  38 21 00 70 */	addi r1, r1, 0x70
/* 802F26D8 002EF618  4E 80 00 20 */	blr 
.endfn "makeShadowSRT__Q24Game17TubeShadowPosNodeFRQ24Game15JointShadowParmR10Vector3<f>R10Vector3<f>"

.fn "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>", global
/* 802F26DC 002EF61C  C0 22 EE 14 */	lfs f1, lbl_8051D174@sda21(r2)
/* 802F26E0 002EF620  C1 64 00 0C */	lfs f11, 0xc(r4)
/* 802F26E4 002EF624  C1 24 00 10 */	lfs f9, 0x10(r4)
/* 802F26E8 002EF628  EC 41 02 F2 */	fmuls f2, f1, f11
/* 802F26EC 002EF62C  C1 04 00 20 */	lfs f8, 0x20(r4)
/* 802F26F0 002EF630  C1 44 00 14 */	lfs f10, 0x14(r4)
/* 802F26F4 002EF634  EC 01 02 72 */	fmuls f0, f1, f9
/* 802F26F8 002EF638  EC 88 12 BC */	fnmsubs f4, f8, f10, f2
/* 802F26FC 002EF63C  EC A8 12 78 */	fmsubs f5, f8, f9, f2
/* 802F2700 002EF640  EC 61 02 B8 */	fmsubs f3, f1, f10, f0
/* 802F2704 002EF644  EC 04 01 32 */	fmuls f0, f4, f4
/* 802F2708 002EF648  EC 45 01 72 */	fmuls f2, f5, f5
/* 802F270C 002EF64C  EC 03 00 FA */	fmadds f0, f3, f3, f0
/* 802F2710 002EF650  EC 42 00 2A */	fadds f2, f2, f0
/* 802F2714 002EF654  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 802F2718 002EF658  40 81 00 14 */	ble .L_802F272C
/* 802F271C 002EF65C  40 81 00 14 */	ble .L_802F2730
/* 802F2720 002EF660  FC 00 10 34 */	frsqrte f0, f2
/* 802F2724 002EF664  EC 40 00 B2 */	fmuls f2, f0, f2
/* 802F2728 002EF668  48 00 00 08 */	b .L_802F2730
.L_802F272C:
/* 802F272C 002EF66C  FC 40 08 90 */	fmr f2, f1
.L_802F2730:
/* 802F2730 002EF670  C0 02 EE 14 */	lfs f0, lbl_8051D174@sda21(r2)
/* 802F2734 002EF674  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 802F2738 002EF678  40 81 00 18 */	ble .L_802F2750
/* 802F273C 002EF67C  C0 02 EE 18 */	lfs f0, lbl_8051D178@sda21(r2)
/* 802F2740 002EF680  EC 00 10 24 */	fdivs f0, f0, f2
/* 802F2744 002EF684  EC 63 00 32 */	fmuls f3, f3, f0
/* 802F2748 002EF688  EC 84 00 32 */	fmuls f4, f4, f0
/* 802F274C 002EF68C  EC A5 00 32 */	fmuls f5, f5, f0
.L_802F2750:
/* 802F2750 002EF690  C0 E5 00 04 */	lfs f7, 4(r5)
/* 802F2754 002EF694  EC 63 02 32 */	fmuls f3, f3, f8
/* 802F2758 002EF698  C0 04 00 04 */	lfs f0, 4(r4)
/* 802F275C 002EF69C  EC 84 02 32 */	fmuls f4, f4, f8
/* 802F2760 002EF6A0  C1 84 00 24 */	lfs f12, 0x24(r4)
/* 802F2764 002EF6A4  EC A5 02 32 */	fmuls f5, f5, f8
/* 802F2768 002EF6A8  C0 25 00 00 */	lfs f1, 0(r5)
/* 802F276C 002EF6AC  C0 45 00 08 */	lfs f2, 8(r5)
/* 802F2770 002EF6B0  EC 07 00 28 */	fsubs f0, f7, f0
/* 802F2774 002EF6B4  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 802F2778 002EF6B8  EC CB 0B 3A */	fmadds f6, f11, f12, f1
/* 802F277C 002EF6BC  C0 22 EE 1C */	lfs f1, lbl_8051D17C@sda21(r2)
/* 802F2780 002EF6C0  EC E9 3B 3A */	fmadds f7, f9, f12, f7
/* 802F2784 002EF6C4  D1 04 00 00 */	stfs f8, 0(r4)
/* 802F2788 002EF6C8  ED A1 00 2A */	fadds f13, f1, f0
/* 802F278C 002EF6CC  C0 02 EE 14 */	lfs f0, lbl_8051D174@sda21(r2)
/* 802F2790 002EF6D0  ED 0A 13 3A */	fmadds f8, f10, f12, f2
/* 802F2794 002EF6D4  D0 04 00 10 */	stfs f0, 0x10(r4)
/* 802F2798 002EF6D8  EC 4B 03 72 */	fmuls f2, f11, f13
/* 802F279C 002EF6DC  D0 04 00 20 */	stfs f0, 0x20(r4)
/* 802F27A0 002EF6E0  EC 29 03 72 */	fmuls f1, f9, f13
/* 802F27A4 002EF6E4  EC 0A 03 72 */	fmuls f0, f10, f13
/* 802F27A8 002EF6E8  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 802F27AC 002EF6EC  D0 44 00 04 */	stfs f2, 4(r4)
/* 802F27B0 002EF6F0  D0 24 00 14 */	stfs f1, 0x14(r4)
/* 802F27B4 002EF6F4  D0 04 00 24 */	stfs f0, 0x24(r4)
/* 802F27B8 002EF6F8  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 802F27BC 002EF6FC  D0 64 00 08 */	stfs f3, 8(r4)
/* 802F27C0 002EF700  D0 84 00 18 */	stfs f4, 0x18(r4)
/* 802F27C4 002EF704  D0 A4 00 28 */	stfs f5, 0x28(r4)
/* 802F27C8 002EF708  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 802F27CC 002EF70C  D0 C3 00 0C */	stfs f6, 0xc(r3)
/* 802F27D0 002EF710  D0 E3 00 1C */	stfs f7, 0x1c(r3)
/* 802F27D4 002EF714  D1 03 00 2C */	stfs f8, 0x2c(r3)
/* 802F27D8 002EF718  4E 80 00 20 */	blr 
.endfn "makeShadowSRT__Q24Game16SphereShadowNodeFRQ24Game15JointShadowParmR10Vector3<f>"
