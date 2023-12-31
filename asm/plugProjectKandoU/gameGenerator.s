.include "macros.inc"
.section .ctors, "wa"  # 0x80472F00 - 0x804732C0
lbl_constructor:
.4byte __sinit_gameGenerator_cpp

.section .rodata  # 0x804732E0 - 0x8049E220
.balign 8
.obj lbl_8047F668, local
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_8047F668
.balign 4
.obj lbl_8047F674, local
	.asciz "generator"
.endobj lbl_8047F674
.balign 4
.obj lbl_8047F680, local
	.asciz "gen base"
.endobj lbl_8047F680
.balign 4
.obj lbl_8047F68C, local
	.asciz "gameGenerator.cpp"
.endobj lbl_8047F68C
.balign 4
.obj lbl_8047F6A0, local # "Generator" typo
	.asciz "Generaotr::saveCreature creature is 0\n"
.endobj lbl_8047F6A0
.balign 4
.obj lbl_8047F6C8, local
	.asciz "Creature"
.endobj lbl_8047F6C8
.balign 4
.obj lbl_8047F6D4, local
	.asciz "\t# version\r\n"
.endobj lbl_8047F6D4
.balign 4
.obj lbl_8047F6E4, local
	.asciz "\t# reserved\r\n"
.endobj lbl_8047F6E4
.balign 4
.obj lbl_8047F6F4, local # Shift-JIS
	.4byte 0x09232095
	.4byte 0x9C8A8893
	.4byte 0xFA90940D
	.2byte 0x0A00
.endobj lbl_8047F6F4
.balign 4
.obj lbl_8047F704, local
	.asciz "\t# <%s>\r\n"
.endobj lbl_8047F704
.balign 4
.obj lbl_8047F710, local
	.asciz "\t# pos\r\n"
.endobj lbl_8047F710
.balign 4
.obj lbl_8047F71C, local
	.asciz "\t# offset\r\n"
.endobj lbl_8047F71C
.balign 4
.obj lbl_8047F728, local
	.asciz "GeneratorMgr"
.endobj lbl_8047F728
.balign 4
.obj lbl_8047F738, local
	.asciz "# generatorMgr <%s>\r\n"
.endobj lbl_8047F738
.balign 4
.obj lbl_8047F750, local
	.asciz "\t# startPos\r\n"
.endobj lbl_8047F750
.balign 4
.obj lbl_8047F760, local
	.asciz "\t# startDir\r\n"
.endobj lbl_8047F760
.balign 4
.obj lbl_8047F770, local
	.asciz "\t# %d generators\r\n"
.endobj lbl_8047F770

.section .data, "wa"  # 0x8049E220 - 0x804EFC20
.balign 8
.obj govNAN___Q24Game5P2JST, local
	.float 0.0
	.float 0.0
	.float 0.0
.endobj govNAN___Q24Game5P2JST
.obj __vt__Q24Game12GeneratorMgr, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q24Game12GeneratorMgrFv
	.4byte getChildCount__5CNodeFv
	.4byte doAnimation__Q24Game12GeneratorMgrFv
	.4byte doEntry__Q24Game12GeneratorMgrFv
	.4byte doSetView__Q24Game12GeneratorMgrFi
	.4byte doViewCalc__Q24Game12GeneratorMgrFv
.endobj __vt__Q24Game12GeneratorMgr
.obj __vt__Q24Game9Generator, global
	.4byte 0
	.4byte 0
	.4byte __dt__Q24Game9GeneratorFv
	.4byte getChildCount__5CNodeFv
	.4byte doAnimation__Q24Game9GeneratorFv
	.4byte doEntry__Q24Game9GeneratorFv
	.4byte doSetView__Q24Game9GeneratorFi
	.4byte doViewCalc__Q24Game9GeneratorFv
.endobj __vt__Q24Game9Generator
.obj __vt__Q24Game9GenObject, global
	.4byte 0
	.4byte 0
	.4byte doWrite__Q24Game7GenBaseFR6Stream
	.4byte ramSaveParameters__Q24Game7GenBaseFR6Stream
	.4byte ramLoadParameters__Q24Game7GenBaseFR6Stream
	.4byte doEvent__Q24Game7GenBaseFUl
	.4byte doRead__Q24Game7GenBaseFR6Stream
	.4byte update__Q24Game9GenObjectFPQ24Game9Generator
	.4byte render__Q24Game9GenObjectFR8GraphicsPQ24Game9Generator
	.4byte getLatestVersion__Q24Game9GenObjectFv
	.4byte getShape__Q24Game7GenBaseFv
	.4byte updateUseList__Q24Game9GenObjectFPQ24Game9Generatori
	.4byte generate__Q24Game9GenObjectFPQ24Game9Generator
	.4byte 0
	.4byte "generatorMakeMatrix__Q24Game9GenObjectFR7MatrixfR10Vector3<f>"
	.4byte getDebugInfo__Q24Game9GenObjectFPc
.endobj __vt__Q24Game9GenObject
.obj __vt__Q24Game7GenBase, global
	.4byte 0
	.4byte 0
	.4byte doWrite__Q24Game7GenBaseFR6Stream
	.4byte ramSaveParameters__Q24Game7GenBaseFR6Stream
	.4byte ramLoadParameters__Q24Game7GenBaseFR6Stream
	.4byte doEvent__Q24Game7GenBaseFUl
	.4byte doRead__Q24Game7GenBaseFR6Stream
	.4byte update__Q24Game7GenBaseFPQ24Game9Generator
	.4byte render__Q24Game7GenBaseFR8GraphicsPQ24Game9Generator
	.4byte getLatestVersion__Q24Game7GenBaseFv
	.4byte getShape__Q24Game7GenBaseFv
.endobj __vt__Q24Game7GenBase

.section .sdata, "wa"  # 0x80514680 - 0x80514D80
.balign 8
.obj GeneratorCurrentVersion, global
	.ascii "v0.3"
.endobj GeneratorCurrentVersion

.section .sbss # 0x80514D80 - 0x80516360
.balign 8
.obj gu32NAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gu32NAN___Q24Game5P2JST
.obj gfNAN___Q24Game5P2JST, local
	.skip 0x4
.endobj gfNAN___Q24Game5P2JST
.obj factory__Q24Game16GenObjectFactory, global
	.skip 0x4
.endobj factory__Q24Game16GenObjectFactory
.obj ramMode__Q24Game9Generator, global
	.skip 0x1
.endobj ramMode__Q24Game9Generator
.balign 4
.obj generatorMgr__4Game, global
	.skip 0x4
.endobj generatorMgr__4Game
.obj onceGeneratorMgr__4Game, global
	.skip 0x4
.endobj onceGeneratorMgr__4Game
.obj limitGeneratorMgr__4Game, global
	.skip 0x4
.endobj limitGeneratorMgr__4Game
.obj plantsGeneratorMgr__4Game, global
	.skip 0x4
.endobj plantsGeneratorMgr__4Game
.obj dayGeneratorMgr__4Game, global
	.skip 0x4
.endobj dayGeneratorMgr__4Game
.obj cursorCallback__Q24Game12GeneratorMgr, global
	.skip 0x4
.endobj cursorCallback__Q24Game12GeneratorMgr

.section .sdata2, "a"     # 0x80516360 - 0x80520E40
.balign 8
.obj lbl_80519258, local
	.float 0.0
.endobj lbl_80519258
.balign 4
.obj lbl_8051925C, local
	.asciz "unset"
.endobj lbl_8051925C
.balign 8
.obj lbl_80519268, local
	.8byte 0x4330000080000000
.endobj lbl_80519268
.balign 4
.obj lbl_80519270, local
	.asciz "genMgr"
.endobj lbl_80519270

.section .text, "ax"  # 0x800056C0 - 0x80472F00
.fn __ct__Q24Game7GenBaseFUlPcPc, global
/* 801AA6E4 001A7624  7C 80 07 35 */	extsh. r0, r4
/* 801AA6E8 001A7628  41 82 00 0C */	beq .L_801AA6F4
/* 801AA6EC 001A762C  38 03 00 24 */	addi r0, r3, 0x24
/* 801AA6F0 001A7630  90 03 00 00 */	stw r0, 0(r3)
.L_801AA6F4:
/* 801AA6F4 001A7634  39 20 00 00 */	li r9, 0
/* 801AA6F8 001A7638  3C 80 80 48 */	lis r4, lbl_8047F680@ha
/* 801AA6FC 001A763C  91 23 00 04 */	stw r9, 4(r3)
/* 801AA700 001A7640  38 04 F6 80 */	addi r0, r4, lbl_8047F680@l
/* 801AA704 001A7644  3D 00 80 4B */	lis r8, __vt__Q24Game7GenBase@ha
/* 801AA708 001A7648  3C 80 5F 5F */	lis r4, 0x5F5F5F5F@ha
/* 801AA70C 001A764C  90 03 00 08 */	stw r0, 8(r3)
/* 801AA710 001A7650  39 08 56 7C */	addi r8, r8, __vt__Q24Game7GenBase@l
/* 801AA714 001A7654  38 04 5F 5F */	addi r0, r4, 0x5F5F5F5F@l
/* 801AA718 001A7658  91 03 00 0C */	stw r8, 0xc(r3)
/* 801AA71C 001A765C  90 A3 00 10 */	stw r5, 0x10(r3)
/* 801AA720 001A7660  90 C3 00 18 */	stw r6, 0x18(r3)
/* 801AA724 001A7664  90 E3 00 1C */	stw r7, 0x1c(r3)
/* 801AA728 001A7668  90 03 00 14 */	stw r0, 0x14(r3)
/* 801AA72C 001A766C  91 23 00 20 */	stw r9, 0x20(r3)
/* 801AA730 001A7670  4E 80 00 20 */	blr 
.endfn __ct__Q24Game7GenBaseFUlPcPc

.fn getLatestVersion__Q24Game7GenBaseFv, weak
/* 801AA734 001A7674  3C 60 75 64 */	lis r3, 0x75646566@ha
/* 801AA738 001A7678  38 63 65 66 */	addi r3, r3, 0x75646566@l
/* 801AA73C 001A767C  4E 80 00 20 */	blr 
.endfn getLatestVersion__Q24Game7GenBaseFv

.fn doWrite__Q24Game7GenBaseFR6Stream, weak
/* 801AA740 001A7680  4E 80 00 20 */	blr 
.endfn doWrite__Q24Game7GenBaseFR6Stream

.fn ramSaveParameters__Q24Game7GenBaseFR6Stream, global
/* 801AA744 001A7684  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AA748 001A7688  7C 08 02 A6 */	mflr r0
/* 801AA74C 001A768C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AA750 001A7690  48 26 8F B5 */	bl write__10ParametersFR6Stream
/* 801AA754 001A7694  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AA758 001A7698  7C 08 03 A6 */	mtlr r0
/* 801AA75C 001A769C  38 21 00 10 */	addi r1, r1, 0x10
/* 801AA760 001A76A0  4E 80 00 20 */	blr 
.endfn ramSaveParameters__Q24Game7GenBaseFR6Stream

.fn ramLoadParameters__Q24Game7GenBaseFR6Stream, global
/* 801AA764 001A76A4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AA768 001A76A8  7C 08 02 A6 */	mflr r0
/* 801AA76C 001A76AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AA770 001A76B0  48 26 90 85 */	bl read__10ParametersFR6Stream
/* 801AA774 001A76B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AA778 001A76B8  7C 08 03 A6 */	mtlr r0
/* 801AA77C 001A76BC  38 21 00 10 */	addi r1, r1, 0x10
/* 801AA780 001A76C0  4E 80 00 20 */	blr 
.endfn ramLoadParameters__Q24Game7GenBaseFR6Stream

.fn doRead__Q24Game7GenBaseFR6Stream, weak
/* 801AA784 001A76C4  4E 80 00 20 */	blr 
.endfn doRead__Q24Game7GenBaseFR6Stream

.fn getLatestVersion__Q24Game9GenObjectFv, global
/* 801AA788 001A76C8  80 ED 93 A0 */	lwz r7, factory__Q24Game16GenObjectFactory@sda21(r13)
/* 801AA78C 001A76CC  38 80 00 00 */	li r4, 0
/* 801AA790 001A76D0  7C 85 23 78 */	mr r5, r4
/* 801AA794 001A76D4  80 63 00 10 */	lwz r3, 0x10(r3)
/* 801AA798 001A76D8  80 07 00 00 */	lwz r0, 0(r7)
/* 801AA79C 001A76DC  7C 09 03 A6 */	mtctr r0
/* 801AA7A0 001A76E0  2C 00 00 00 */	cmpwi r0, 0
/* 801AA7A4 001A76E4  4C 81 00 20 */	blelr 
.L_801AA7A8:
/* 801AA7A8 001A76E8  80 C7 00 08 */	lwz r6, 8(r7)
/* 801AA7AC 001A76EC  7C 06 28 2E */	lwzx r0, r6, r5
/* 801AA7B0 001A76F0  7C 03 00 40 */	cmplw r3, r0
/* 801AA7B4 001A76F4  40 82 00 14 */	bne .L_801AA7C8
/* 801AA7B8 001A76F8  54 80 20 36 */	slwi r0, r4, 4
/* 801AA7BC 001A76FC  7C 66 02 14 */	add r3, r6, r0
/* 801AA7C0 001A7700  80 63 00 0C */	lwz r3, 0xc(r3)
/* 801AA7C4 001A7704  4E 80 00 20 */	blr 
.L_801AA7C8:
/* 801AA7C8 001A7708  38 A5 00 10 */	addi r5, r5, 0x10
/* 801AA7CC 001A770C  38 84 00 01 */	addi r4, r4, 1
/* 801AA7D0 001A7710  42 00 FF D8 */	bdnz .L_801AA7A8
/* 801AA7D4 001A7714  4E 80 00 20 */	blr 
.endfn getLatestVersion__Q24Game9GenObjectFv

.fn initialiseSystem__Q24Game9GeneratorFv, global
/* 801AA7D8 001A7718  38 00 00 00 */	li r0, 0
/* 801AA7DC 001A771C  90 0D 93 A0 */	stw r0, factory__Q24Game16GenObjectFactory@sda21(r13)
/* 801AA7E0 001A7720  4E 80 00 20 */	blr 
.endfn initialiseSystem__Q24Game9GeneratorFv

.fn __ct__Q24Game9GeneratorFv, global
/* 801AA7E4 001A7724  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AA7E8 001A7728  7C 08 02 A6 */	mflr r0
/* 801AA7EC 001A772C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AA7F0 001A7730  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AA7F4 001A7734  7C 7F 1B 78 */	mr r31, r3
/* 801AA7F8 001A7738  48 26 6B 99 */	bl __ct__5CNodeFv
/* 801AA7FC 001A773C  3C 80 80 4B */	lis r4, __vt__Q24Game9Generator@ha
/* 801AA800 001A7740  38 7F 00 40 */	addi r3, r31, 0x40
/* 801AA804 001A7744  38 04 56 1C */	addi r0, r4, __vt__Q24Game9Generator@l
/* 801AA808 001A7748  90 1F 00 00 */	stw r0, 0(r31)
/* 801AA80C 001A774C  48 26 8A 65 */	bl __ct__4ID32Fv
/* 801AA810 001A7750  38 7F 00 4C */	addi r3, r31, 0x4c
/* 801AA814 001A7754  48 26 8A 5D */	bl __ct__4ID32Fv
/* 801AA818 001A7758  C0 02 AE F8 */	lfs f0, lbl_80519258@sda21(r2)
/* 801AA81C 001A775C  3C 60 5F 5F */	lis r3, 0x5F5F5F5F@ha
/* 801AA820 001A7760  3C 80 20 20 */	lis r4, 0x20202020@ha
/* 801AA824 001A7764  38 A0 00 00 */	li r5, 0
/* 801AA828 001A7768  D0 1F 00 94 */	stfs f0, 0x94(r31)
/* 801AA82C 001A776C  38 03 5F 5F */	addi r0, r3, 0x5F5F5F5F@l
/* 801AA830 001A7770  38 7F 00 40 */	addi r3, r31, 0x40
/* 801AA834 001A7774  38 84 20 20 */	addi r4, r4, 0x20202020@l
/* 801AA838 001A7778  D0 1F 00 98 */	stfs f0, 0x98(r31)
/* 801AA83C 001A777C  D0 1F 00 9C */	stfs f0, 0x9c(r31)
/* 801AA840 001A7780  90 BF 00 18 */	stw r5, 0x18(r31)
/* 801AA844 001A7784  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 801AA848 001A7788  B0 BF 00 5C */	sth r5, 0x5c(r31)
/* 801AA84C 001A778C  48 26 8A 8D */	bl setID__4ID32FUl
/* 801AA850 001A7790  80 8D 84 38 */	lwz r4, GeneratorCurrentVersion@sda21(r13)
/* 801AA854 001A7794  38 7F 00 4C */	addi r3, r31, 0x4c
/* 801AA858 001A7798  48 26 8A 81 */	bl setID__4ID32FUl
/* 801AA85C 001A779C  38 7F 00 20 */	addi r3, r31, 0x20
/* 801AA860 001A77A0  38 82 AE FC */	addi r4, r2, lbl_8051925C@sda21
/* 801AA864 001A77A4  4B F1 FF F5 */	bl strcpy
/* 801AA868 001A77A8  38 A0 00 00 */	li r5, 0
/* 801AA86C 001A77AC  38 80 00 01 */	li r4, 1
/* 801AA870 001A77B0  90 BF 00 64 */	stw r5, 0x64(r31)
/* 801AA874 001A77B4  38 00 FF FF */	li r0, -1
/* 801AA878 001A77B8  7F E3 FB 78 */	mr r3, r31
/* 801AA87C 001A77BC  90 BF 00 60 */	stw r5, 0x60(r31)
/* 801AA880 001A77C0  90 BF 00 6C */	stw r5, 0x6c(r31)
/* 801AA884 001A77C4  90 BF 00 7C */	stw r5, 0x7c(r31)
/* 801AA888 001A77C8  90 BF 00 10 */	stw r5, 0x10(r31)
/* 801AA88C 001A77CC  90 BF 00 0C */	stw r5, 0xc(r31)
/* 801AA890 001A77D0  90 BF 00 08 */	stw r5, 8(r31)
/* 801AA894 001A77D4  90 BF 00 04 */	stw r5, 4(r31)
/* 801AA898 001A77D8  98 9F 00 AC */	stb r4, 0xac(r31)
/* 801AA89C 001A77DC  90 1F 00 84 */	stw r0, 0x84(r31)
/* 801AA8A0 001A77E0  90 BF 00 74 */	stw r5, 0x74(r31)
/* 801AA8A4 001A77E4  90 BF 00 78 */	stw r5, 0x78(r31)
/* 801AA8A8 001A77E8  90 BF 00 70 */	stw r5, 0x70(r31)
/* 801AA8AC 001A77EC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AA8B0 001A77F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AA8B4 001A77F4  7C 08 03 A6 */	mtlr r0
/* 801AA8B8 001A77F8  38 21 00 10 */	addi r1, r1, 0x10
/* 801AA8BC 001A77FC  4E 80 00 20 */	blr 
.endfn __ct__Q24Game9GeneratorFv

.fn __dt__Q24Game9GeneratorFv, global
/* 801AA8C0 001A7800  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AA8C4 001A7804  7C 08 02 A6 */	mflr r0
/* 801AA8C8 001A7808  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AA8CC 001A780C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AA8D0 001A7810  7C 9F 23 78 */	mr r31, r4
/* 801AA8D4 001A7814  93 C1 00 08 */	stw r30, 8(r1)
/* 801AA8D8 001A7818  7C 7E 1B 79 */	or. r30, r3, r3
/* 801AA8DC 001A781C  41 82 00 30 */	beq .L_801AA90C
/* 801AA8E0 001A7820  3C 80 80 4B */	lis r4, __vt__Q24Game9Generator@ha
/* 801AA8E4 001A7824  38 00 00 00 */	li r0, 0
/* 801AA8E8 001A7828  38 A4 56 1C */	addi r5, r4, __vt__Q24Game9Generator@l
/* 801AA8EC 001A782C  38 80 00 00 */	li r4, 0
/* 801AA8F0 001A7830  90 BE 00 00 */	stw r5, 0(r30)
/* 801AA8F4 001A7834  90 1E 00 64 */	stw r0, 0x64(r30)
/* 801AA8F8 001A7838  48 26 6C 91 */	bl __dt__5CNodeFv
/* 801AA8FC 001A783C  7F E0 07 35 */	extsh. r0, r31
/* 801AA900 001A7840  40 81 00 0C */	ble .L_801AA90C
/* 801AA904 001A7844  7F C3 F3 78 */	mr r3, r30
/* 801AA908 001A7848  4B E7 97 AD */	bl __dl__FPv
.L_801AA90C:
/* 801AA90C 001A784C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AA910 001A7850  7F C3 F3 78 */	mr r3, r30
/* 801AA914 001A7854  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AA918 001A7858  83 C1 00 08 */	lwz r30, 8(r1)
/* 801AA91C 001A785C  7C 08 03 A6 */	mtlr r0
/* 801AA920 001A7860  38 21 00 10 */	addi r1, r1, 0x10
/* 801AA924 001A7864  4E 80 00 20 */	blr 
.endfn __dt__Q24Game9GeneratorFv

.fn updateUseList__Q24Game9GeneratorFv, global
/* 801AA928 001A7868  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AA92C 001A786C  7C 08 02 A6 */	mflr r0
/* 801AA930 001A7870  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AA934 001A7874  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AA938 001A7878  7C 7F 1B 78 */	mr r31, r3
/* 801AA93C 001A787C  48 00 00 49 */	bl isExpired__Q24Game9GeneratorFv
/* 801AA940 001A7880  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801AA944 001A7884  40 82 00 28 */	bne .L_801AA96C
/* 801AA948 001A7888  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AA94C 001A788C  28 03 00 00 */	cmplwi r3, 0
/* 801AA950 001A7890  41 82 00 1C */	beq .L_801AA96C
/* 801AA954 001A7894  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801AA958 001A7898  7F E4 FB 78 */	mr r4, r31
/* 801AA95C 001A789C  38 A0 00 01 */	li r5, 1
/* 801AA960 001A78A0  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 801AA964 001A78A4  7D 89 03 A6 */	mtctr r12
/* 801AA968 001A78A8  4E 80 04 21 */	bctrl 
.L_801AA96C:
/* 801AA96C 001A78AC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AA970 001A78B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AA974 001A78B4  7C 08 03 A6 */	mtlr r0
/* 801AA978 001A78B8  38 21 00 10 */	addi r1, r1, 0x10
/* 801AA97C 001A78BC  4E 80 00 20 */	blr 
.endfn updateUseList__Q24Game9GeneratorFv

.fn updateUseList__Q24Game9GenObjectFPQ24Game9Generatori, weak
/* 801AA980 001A78C0  4E 80 00 20 */	blr 
.endfn updateUseList__Q24Game9GenObjectFPQ24Game9Generatori

.fn isExpired__Q24Game9GeneratorFv, global
/* 801AA984 001A78C4  80 03 00 84 */	lwz r0, 0x84(r3)
/* 801AA988 001A78C8  2C 00 FF FF */	cmpwi r0, -1
/* 801AA98C 001A78CC  40 82 00 0C */	bne .L_801AA998
/* 801AA990 001A78D0  38 60 00 00 */	li r3, 0
/* 801AA994 001A78D4  4E 80 00 20 */	blr 
.L_801AA998:
/* 801AA998 001A78D8  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 801AA99C 001A78DC  80 63 00 40 */	lwz r3, 0x40(r3)
/* 801AA9A0 001A78E0  80 63 02 18 */	lwz r3, 0x218(r3)
/* 801AA9A4 001A78E4  7C 60 02 78 */	xor r0, r3, r0
/* 801AA9A8 001A78E8  7C 00 00 34 */	cntlzw r0, r0
/* 801AA9AC 001A78EC  7C 60 00 30 */	slw r0, r3, r0
/* 801AA9B0 001A78F0  54 03 0F FE */	srwi r3, r0, 0x1f
/* 801AA9B4 001A78F4  4E 80 00 20 */	blr 
.endfn isExpired__Q24Game9GeneratorFv

.fn loadCreature__Q24Game9GeneratorFR6Stream, global
/* 801AA9B8 001A78F8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AA9BC 001A78FC  7C 08 02 A6 */	mflr r0
/* 801AA9C0 001A7900  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AA9C4 001A7904  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AA9C8 001A7908  7C 9F 23 78 */	mr r31, r4
/* 801AA9CC 001A790C  93 C1 00 08 */	stw r30, 8(r1)
/* 801AA9D0 001A7910  7C 7E 1B 78 */	mr r30, r3
/* 801AA9D4 001A7914  80 63 00 18 */	lwz r3, 0x18(r3)
/* 801AA9D8 001A7918  28 03 00 00 */	cmplwi r3, 0
/* 801AA9DC 001A791C  41 82 00 38 */	beq .L_801AAA14
/* 801AA9E0 001A7920  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801AA9E4 001A7924  7F C4 F3 78 */	mr r4, r30
/* 801AA9E8 001A7928  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 801AA9EC 001A792C  7D 89 03 A6 */	mtctr r12
/* 801AA9F0 001A7930  4E 80 04 21 */	bctrl 
/* 801AA9F4 001A7934  90 7E 00 6C */	stw r3, 0x6c(r30)
/* 801AA9F8 001A7938  80 7E 00 6C */	lwz r3, 0x6c(r30)
/* 801AA9FC 001A793C  28 03 00 00 */	cmplwi r3, 0
/* 801AAA00 001A7940  41 82 00 14 */	beq .L_801AAA14
/* 801AAA04 001A7944  81 83 00 00 */	lwz r12, 0(r3)
/* 801AAA08 001A7948  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 801AAA0C 001A794C  7D 89 03 A6 */	mtctr r12
/* 801AAA10 001A7950  4E 80 04 21 */	bctrl 
.L_801AAA14:
/* 801AAA14 001A7954  80 7E 00 6C */	lwz r3, 0x6c(r30)
/* 801AAA18 001A7958  28 03 00 00 */	cmplwi r3, 0
/* 801AAA1C 001A795C  41 82 00 30 */	beq .L_801AAA4C
/* 801AAA20 001A7960  93 C3 00 C4 */	stw r30, 0xc4(r3)
/* 801AAA24 001A7964  38 A0 00 00 */	li r5, 0
/* 801AAA28 001A7968  A0 1E 00 5C */	lhz r0, 0x5c(r30)
/* 801AAA2C 001A796C  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 801AAA30 001A7970  41 82 00 0C */	beq .L_801AAA3C
/* 801AAA34 001A7974  60 A0 00 01 */	ori r0, r5, 1
/* 801AAA38 001A7978  54 05 06 3E */	clrlwi r5, r0, 0x18
.L_801AAA3C:
/* 801AAA3C 001A797C  80 7E 00 6C */	lwz r3, 0x6c(r30)
/* 801AAA40 001A7980  7F E4 FB 78 */	mr r4, r31
/* 801AAA44 001A7984  4B F9 0B C1 */	bl load__Q24Game8CreatureFR6StreamUc
/* 801AAA48 001A7988  48 00 00 0C */	b .L_801AAA54
.L_801AAA4C:
/* 801AAA4C 001A798C  38 60 00 00 */	li r3, 0
/* 801AAA50 001A7990  48 00 00 08 */	b .L_801AAA58
.L_801AAA54:
/* 801AAA54 001A7994  38 60 00 01 */	li r3, 1
.L_801AAA58:
/* 801AAA58 001A7998  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AAA5C 001A799C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AAA60 001A79A0  83 C1 00 08 */	lwz r30, 8(r1)
/* 801AAA64 001A79A4  7C 08 03 A6 */	mtlr r0
/* 801AAA68 001A79A8  38 21 00 10 */	addi r1, r1, 0x10
/* 801AAA6C 001A79AC  4E 80 00 20 */	blr 
.endfn loadCreature__Q24Game9GeneratorFR6Stream

.fn generate__Q24Game9GenObjectFPQ24Game9Generator, weak
/* 801AAA70 001A79B0  38 60 00 00 */	li r3, 0
/* 801AAA74 001A79B4  4E 80 00 20 */	blr 
.endfn generate__Q24Game9GenObjectFPQ24Game9Generator

.fn need_saveCreature__Q24Game9GeneratorFv, global
/* 801AAA78 001A79B8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AAA7C 001A79BC  7C 08 02 A6 */	mflr r0
/* 801AAA80 001A79C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AAA84 001A79C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AAA88 001A79C8  7C 7F 1B 78 */	mr r31, r3
/* 801AAA8C 001A79CC  80 63 00 6C */	lwz r3, 0x6c(r3)
/* 801AAA90 001A79D0  28 03 00 00 */	cmplwi r3, 0
/* 801AAA94 001A79D4  40 82 00 0C */	bne .L_801AAAA0
/* 801AAA98 001A79D8  38 60 00 01 */	li r3, 1
/* 801AAA9C 001A79DC  48 00 00 44 */	b .L_801AAAE0
.L_801AAAA0:
/* 801AAAA0 001A79E0  81 83 00 00 */	lwz r12, 0(r3)
/* 801AAAA4 001A79E4  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 801AAAA8 001A79E8  7D 89 03 A6 */	mtctr r12
/* 801AAAAC 001A79EC  4E 80 04 21 */	bctrl 
/* 801AAAB0 001A79F0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801AAAB4 001A79F4  40 82 00 28 */	bne .L_801AAADC
/* 801AAAB8 001A79F8  80 7F 00 6C */	lwz r3, 0x6c(r31)
/* 801AAABC 001A79FC  81 83 00 00 */	lwz r12, 0(r3)
/* 801AAAC0 001A7A00  81 8C 00 80 */	lwz r12, 0x80(r12)
/* 801AAAC4 001A7A04  7D 89 03 A6 */	mtctr r12
/* 801AAAC8 001A7A08  4E 80 04 21 */	bctrl 
/* 801AAACC 001A7A0C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801AAAD0 001A7A10  41 82 00 0C */	beq .L_801AAADC
/* 801AAAD4 001A7A14  38 60 00 00 */	li r3, 0
/* 801AAAD8 001A7A18  48 00 00 08 */	b .L_801AAAE0
.L_801AAADC:
/* 801AAADC 001A7A1C  38 60 00 01 */	li r3, 1
.L_801AAAE0:
/* 801AAAE0 001A7A20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AAAE4 001A7A24  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AAAE8 001A7A28  7C 08 03 A6 */	mtlr r0
/* 801AAAEC 001A7A2C  38 21 00 10 */	addi r1, r1, 0x10
/* 801AAAF0 001A7A30  4E 80 00 20 */	blr 
.endfn need_saveCreature__Q24Game9GeneratorFv

.fn saveCreature__Q24Game9GeneratorFR6Stream, global
/* 801AAAF4 001A7A34  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801AAAF8 001A7A38  7C 08 02 A6 */	mflr r0
/* 801AAAFC 001A7A3C  90 01 00 24 */	stw r0, 0x24(r1)
/* 801AAB00 001A7A40  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801AAB04 001A7A44  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801AAB08 001A7A48  7C 9E 23 78 */	mr r30, r4
/* 801AAB0C 001A7A4C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801AAB10 001A7A50  7C 7D 1B 78 */	mr r29, r3
/* 801AAB14 001A7A54  80 63 00 6C */	lwz r3, 0x6c(r3)
/* 801AAB18 001A7A58  28 03 00 00 */	cmplwi r3, 0
/* 801AAB1C 001A7A5C  41 82 00 68 */	beq .L_801AAB84
/* 801AAB20 001A7A60  A0 1D 00 5C */	lhz r0, 0x5c(r29)
/* 801AAB24 001A7A64  3B E0 00 00 */	li r31, 0
/* 801AAB28 001A7A68  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 801AAB2C 001A7A6C  41 82 00 0C */	beq .L_801AAB38
/* 801AAB30 001A7A70  63 E0 00 01 */	ori r0, r31, 1
/* 801AAB34 001A7A74  54 1F 06 3E */	clrlwi r31, r0, 0x18
.L_801AAB38:
/* 801AAB38 001A7A78  81 83 00 00 */	lwz r12, 0(r3)
/* 801AAB3C 001A7A7C  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 801AAB40 001A7A80  7D 89 03 A6 */	mtctr r12
/* 801AAB44 001A7A84  4E 80 04 21 */	bctrl 
/* 801AAB48 001A7A88  80 7D 00 6C */	lwz r3, 0x6c(r29)
/* 801AAB4C 001A7A8C  81 83 00 00 */	lwz r12, 0(r3)
/* 801AAB50 001A7A90  81 8C 01 A8 */	lwz r12, 0x1a8(r12)
/* 801AAB54 001A7A94  7D 89 03 A6 */	mtctr r12
/* 801AAB58 001A7A98  4E 80 04 21 */	bctrl 
/* 801AAB5C 001A7A9C  80 7D 00 6C */	lwz r3, 0x6c(r29)
/* 801AAB60 001A7AA0  81 83 00 00 */	lwz r12, 0(r3)
/* 801AAB64 001A7AA4  81 8C 01 AC */	lwz r12, 0x1ac(r12)
/* 801AAB68 001A7AA8  7D 89 03 A6 */	mtctr r12
/* 801AAB6C 001A7AAC  4E 80 04 21 */	bctrl 
/* 801AAB70 001A7AB0  80 7D 00 6C */	lwz r3, 0x6c(r29)
/* 801AAB74 001A7AB4  7F C4 F3 78 */	mr r4, r30
/* 801AAB78 001A7AB8  7F E5 FB 78 */	mr r5, r31
/* 801AAB7C 001A7ABC  4B F9 09 F9 */	bl save__Q24Game8CreatureFR6StreamUc
/* 801AAB80 001A7AC0  48 00 00 20 */	b .L_801AABA0
.L_801AAB84:
/* 801AAB84 001A7AC4  3C 60 80 48 */	lis r3, lbl_8047F68C@ha
/* 801AAB88 001A7AC8  3C A0 80 48 */	lis r5, lbl_8047F6A0@ha
/* 801AAB8C 001A7ACC  38 63 F6 8C */	addi r3, r3, lbl_8047F68C@l
/* 801AAB90 001A7AD0  38 80 01 C0 */	li r4, 0x1c0
/* 801AAB94 001A7AD4  38 A5 F6 A0 */	addi r5, r5, lbl_8047F6A0@l
/* 801AAB98 001A7AD8  4C C6 31 82 */	crclr 6
/* 801AAB9C 001A7ADC  4B E7 FA A5 */	bl panic_f__12JUTExceptionFPCciPCce
.L_801AABA0:
/* 801AABA0 001A7AE0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801AABA4 001A7AE4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801AABA8 001A7AE8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801AABAC 001A7AEC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801AABB0 001A7AF0  7C 08 03 A6 */	mtlr r0
/* 801AABB4 001A7AF4  38 21 00 20 */	addi r1, r1, 0x20
/* 801AABB8 001A7AF8  4E 80 00 20 */	blr 
.endfn saveCreature__Q24Game9GeneratorFR6Stream

.fn generate__Q24Game9GeneratorFv, global
/* 801AABBC 001A7AFC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AABC0 001A7B00  7C 08 02 A6 */	mflr r0
/* 801AABC4 001A7B04  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AABC8 001A7B08  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AABCC 001A7B0C  7C 7F 1B 78 */	mr r31, r3
/* 801AABD0 001A7B10  80 83 00 84 */	lwz r4, 0x84(r3)
/* 801AABD4 001A7B14  2C 04 FF FF */	cmpwi r4, -1
/* 801AABD8 001A7B18  40 82 00 0C */	bne .L_801AABE4
/* 801AABDC 001A7B1C  38 00 00 00 */	li r0, 0
/* 801AABE0 001A7B20  48 00 00 24 */	b .L_801AAC04
.L_801AABE4:
/* 801AABE4 001A7B24  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 801AABE8 001A7B28  80 63 00 40 */	lwz r3, 0x40(r3)
/* 801AABEC 001A7B2C  80 03 02 18 */	lwz r0, 0x218(r3)
/* 801AABF0 001A7B30  7C 04 00 40 */	cmplw r4, r0
/* 801AABF4 001A7B34  40 80 00 0C */	bge .L_801AAC00
/* 801AABF8 001A7B38  38 00 00 01 */	li r0, 1
/* 801AABFC 001A7B3C  48 00 00 08 */	b .L_801AAC04
.L_801AAC00:
/* 801AAC00 001A7B40  38 00 00 00 */	li r0, 0
.L_801AAC04:
/* 801AAC04 001A7B44  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 801AAC08 001A7B48  41 82 00 14 */	beq .L_801AAC1C
/* 801AAC0C 001A7B4C  38 00 00 00 */	li r0, 0
/* 801AAC10 001A7B50  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 801AAC14 001A7B54  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 801AAC18 001A7B58  48 00 00 C8 */	b .L_801AACE0
.L_801AAC1C:
/* 801AAC1C 001A7B5C  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AAC20 001A7B60  28 00 00 00 */	cmplwi r0, 0
/* 801AAC24 001A7B64  40 82 00 24 */	bne .L_801AAC48
/* 801AAC28 001A7B68  38 00 00 00 */	li r0, 0
/* 801AAC2C 001A7B6C  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 801AAC30 001A7B70  90 1F 00 74 */	stw r0, 0x74(r31)
/* 801AAC34 001A7B74  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 801AAC38 001A7B78  80 63 00 40 */	lwz r3, 0x40(r3)
/* 801AAC3C 001A7B7C  80 03 02 18 */	lwz r0, 0x218(r3)
/* 801AAC40 001A7B80  90 1F 00 78 */	stw r0, 0x78(r31)
/* 801AAC44 001A7B84  48 00 00 1C */	b .L_801AAC60
.L_801AAC48:
/* 801AAC48 001A7B88  A0 1F 00 5C */	lhz r0, 0x5c(r31)
/* 801AAC4C 001A7B8C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 801AAC50 001A7B90  40 82 00 10 */	bne .L_801AAC60
/* 801AAC54 001A7B94  38 00 00 00 */	li r0, 0
/* 801AAC58 001A7B98  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 801AAC5C 001A7B9C  48 00 00 84 */	b .L_801AACE0
.L_801AAC60:
/* 801AAC60 001A7BA0  38 A0 00 00 */	li r5, 0
/* 801AAC64 001A7BA4  90 BF 00 6C */	stw r5, 0x6c(r31)
/* 801AAC68 001A7BA8  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 801AAC6C 001A7BAC  28 00 00 00 */	cmplwi r0, 0
/* 801AAC70 001A7BB0  41 82 00 70 */	beq .L_801AACE0
/* 801AAC74 001A7BB4  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AAC78 001A7BB8  28 00 00 00 */	cmplwi r0, 0
/* 801AAC7C 001A7BBC  41 82 00 38 */	beq .L_801AACB4
/* 801AAC80 001A7BC0  A0 1F 00 5C */	lhz r0, 0x5c(r31)
/* 801AAC84 001A7BC4  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 801AAC88 001A7BC8  41 82 00 2C */	beq .L_801AACB4
/* 801AAC8C 001A7BCC  80 8D 93 E8 */	lwz r4, gameSystem__4Game@sda21(r13)
/* 801AAC90 001A7BD0  80 7F 00 78 */	lwz r3, 0x78(r31)
/* 801AAC94 001A7BD4  80 84 00 40 */	lwz r4, 0x40(r4)
/* 801AAC98 001A7BD8  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 801AAC9C 001A7BDC  80 84 02 18 */	lwz r4, 0x218(r4)
/* 801AACA0 001A7BE0  7C 03 02 14 */	add r0, r3, r0
/* 801AACA4 001A7BE4  7C 04 00 00 */	cmpw r4, r0
/* 801AACA8 001A7BE8  41 80 00 0C */	blt .L_801AACB4
/* 801AACAC 001A7BEC  90 9F 00 78 */	stw r4, 0x78(r31)
/* 801AACB0 001A7BF0  90 BF 00 74 */	stw r5, 0x74(r31)
.L_801AACB4:
/* 801AACB4 001A7BF4  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AACB8 001A7BF8  7F E4 FB 78 */	mr r4, r31
/* 801AACBC 001A7BFC  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801AACC0 001A7C00  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 801AACC4 001A7C04  7D 89 03 A6 */	mtctr r12
/* 801AACC8 001A7C08  4E 80 04 21 */	bctrl 
/* 801AACCC 001A7C0C  90 7F 00 6C */	stw r3, 0x6c(r31)
/* 801AACD0 001A7C10  80 7F 00 6C */	lwz r3, 0x6c(r31)
/* 801AACD4 001A7C14  28 03 00 00 */	cmplwi r3, 0
/* 801AACD8 001A7C18  41 82 00 08 */	beq .L_801AACE0
/* 801AACDC 001A7C1C  93 E3 00 C4 */	stw r31, 0xc4(r3)
.L_801AACE0:
/* 801AACE0 001A7C20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AACE4 001A7C24  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AACE8 001A7C28  7C 08 03 A6 */	mtlr r0
/* 801AACEC 001A7C2C  38 21 00 10 */	addi r1, r1, 0x10
/* 801AACF0 001A7C30  4E 80 00 20 */	blr 
.endfn generate__Q24Game9GeneratorFv

.fn informDeath__Q24Game9GeneratorFPQ24Game8Creature, global
/* 801AACF4 001A7C34  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 801AACF8 001A7C38  7C 04 00 40 */	cmplw r4, r0
/* 801AACFC 001A7C3C  40 82 00 0C */	bne .L_801AAD08
/* 801AAD00 001A7C40  38 00 00 00 */	li r0, 0
/* 801AAD04 001A7C44  90 03 00 6C */	stw r0, 0x6c(r3)
.L_801AAD08:
/* 801AAD08 001A7C48  80 83 00 74 */	lwz r4, 0x74(r3)
/* 801AAD0C 001A7C4C  38 04 00 01 */	addi r0, r4, 1
/* 801AAD10 001A7C50  90 03 00 74 */	stw r0, 0x74(r3)
/* 801AAD14 001A7C54  4E 80 00 20 */	blr 
.endfn informDeath__Q24Game9GeneratorFPQ24Game8Creature

.fn read__Q24Game9GeneratorFR6Stream, global
/* 801AAD18 001A7C58  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 801AAD1C 001A7C5C  7C 08 02 A6 */	mflr r0
/* 801AAD20 001A7C60  90 01 00 54 */	stw r0, 0x54(r1)
/* 801AAD24 001A7C64  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 801AAD28 001A7C68  7C 9F 23 78 */	mr r31, r4
/* 801AAD2C 001A7C6C  93 C1 00 48 */	stw r30, 0x48(r1)
/* 801AAD30 001A7C70  7C 7E 1B 78 */	mr r30, r3
/* 801AAD34 001A7C74  38 7E 00 4C */	addi r3, r30, 0x4c
/* 801AAD38 001A7C78  93 A1 00 44 */	stw r29, 0x44(r1)
/* 801AAD3C 001A7C7C  93 81 00 40 */	stw r28, 0x40(r1)
/* 801AAD40 001A7C80  48 26 87 B1 */	bl read__4ID32FR6Stream
/* 801AAD44 001A7C84  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 801AAD48 001A7C88  80 9E 00 54 */	lwz r4, 0x54(r30)
/* 801AAD4C 001A7C8C  38 03 2E 30 */	addi r0, r3, 0x76302E30@l
/* 801AAD50 001A7C90  7C 04 00 40 */	cmplw r4, r0
/* 801AAD54 001A7C94  41 80 00 14 */	blt .L_801AAD68
/* 801AAD58 001A7C98  7F E3 FB 78 */	mr r3, r31
/* 801AAD5C 001A7C9C  48 26 9A 09 */	bl readShort__6StreamFv
/* 801AAD60 001A7CA0  B0 7E 00 5C */	sth r3, 0x5c(r30)
/* 801AAD64 001A7CA4  48 00 00 10 */	b .L_801AAD74
.L_801AAD68:
/* 801AAD68 001A7CA8  7F E3 FB 78 */	mr r3, r31
/* 801AAD6C 001A7CAC  48 26 9D 25 */	bl readInt__6StreamFv
/* 801AAD70 001A7CB0  B0 7E 00 5C */	sth r3, 0x5c(r30)
.L_801AAD74:
/* 801AAD74 001A7CB4  3C 60 76 30 */	lis r3, 0x76302E33@ha
/* 801AAD78 001A7CB8  80 9E 00 54 */	lwz r4, 0x54(r30)
/* 801AAD7C 001A7CBC  38 03 2E 33 */	addi r0, r3, 0x76302E33@l
/* 801AAD80 001A7CC0  7C 04 00 40 */	cmplw r4, r0
/* 801AAD84 001A7CC4  41 80 00 18 */	blt .L_801AAD9C
/* 801AAD88 001A7CC8  7F E3 FB 78 */	mr r3, r31
/* 801AAD8C 001A7CCC  48 26 99 D9 */	bl readShort__6StreamFv
/* 801AAD90 001A7CD0  7C 60 07 34 */	extsh r0, r3
/* 801AAD94 001A7CD4  90 1E 00 70 */	stw r0, 0x70(r30)
/* 801AAD98 001A7CD8  48 00 00 28 */	b .L_801AADC0
.L_801AAD9C:
/* 801AAD9C 001A7CDC  38 03 2E 31 */	addi r0, r3, 0x2e31
/* 801AADA0 001A7CE0  7C 04 00 40 */	cmplw r4, r0
/* 801AADA4 001A7CE4  41 80 00 14 */	blt .L_801AADB8
/* 801AADA8 001A7CE8  7F E3 FB 78 */	mr r3, r31
/* 801AADAC 001A7CEC  48 26 9C E5 */	bl readInt__6StreamFv
/* 801AADB0 001A7CF0  90 7E 00 70 */	stw r3, 0x70(r30)
/* 801AADB4 001A7CF4  48 00 00 0C */	b .L_801AADC0
.L_801AADB8:
/* 801AADB8 001A7CF8  38 00 00 00 */	li r0, 0
/* 801AADBC 001A7CFC  90 1E 00 70 */	stw r0, 0x70(r30)
.L_801AADC0:
/* 801AADC0 001A7D00  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AADC4 001A7D04  28 00 00 00 */	cmplwi r0, 0
/* 801AADC8 001A7D08  40 82 00 28 */	bne .L_801AADF0
/* 801AADCC 001A7D0C  3B A0 00 00 */	li r29, 0
.L_801AADD0:
/* 801AADD0 001A7D10  7F E3 FB 78 */	mr r3, r31
/* 801AADD4 001A7D14  48 26 96 C9 */	bl readByte__6StreamFv
/* 801AADD8 001A7D18  38 1D 00 20 */	addi r0, r29, 0x20
/* 801AADDC 001A7D1C  3B BD 00 01 */	addi r29, r29, 1
/* 801AADE0 001A7D20  2C 1D 00 20 */	cmpwi r29, 0x20
/* 801AADE4 001A7D24  7C 7E 01 AE */	stbx r3, r30, r0
/* 801AADE8 001A7D28  41 80 FF E8 */	blt .L_801AADD0
/* 801AADEC 001A7D2C  48 00 00 90 */	b .L_801AAE7C
.L_801AADF0:
/* 801AADF0 001A7D30  3C 60 76 30 */	lis r3, 0x76302E32@ha
/* 801AADF4 001A7D34  80 9E 00 54 */	lwz r4, 0x54(r30)
/* 801AADF8 001A7D38  38 03 2E 32 */	addi r0, r3, 0x76302E32@l
/* 801AADFC 001A7D3C  7C 04 00 40 */	cmplw r4, r0
/* 801AAE00 001A7D40  41 80 00 44 */	blt .L_801AAE44
/* 801AAE04 001A7D44  7F E3 FB 78 */	mr r3, r31
/* 801AAE08 001A7D48  48 26 96 95 */	bl readByte__6StreamFv
/* 801AAE0C 001A7D4C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801AAE10 001A7D50  41 82 00 28 */	beq .L_801AAE38
/* 801AAE14 001A7D54  3B A0 00 00 */	li r29, 0
.L_801AAE18:
/* 801AAE18 001A7D58  7F E3 FB 78 */	mr r3, r31
/* 801AAE1C 001A7D5C  48 26 96 81 */	bl readByte__6StreamFv
/* 801AAE20 001A7D60  38 1D 00 20 */	addi r0, r29, 0x20
/* 801AAE24 001A7D64  3B BD 00 01 */	addi r29, r29, 1
/* 801AAE28 001A7D68  2C 1D 00 20 */	cmpwi r29, 0x20
/* 801AAE2C 001A7D6C  7C 7E 01 AE */	stbx r3, r30, r0
/* 801AAE30 001A7D70  41 80 FF E8 */	blt .L_801AAE18
/* 801AAE34 001A7D74  48 00 00 18 */	b .L_801AAE4C
.L_801AAE38:
/* 801AAE38 001A7D78  38 00 00 00 */	li r0, 0
/* 801AAE3C 001A7D7C  98 1E 00 20 */	stb r0, 0x20(r30)
/* 801AAE40 001A7D80  48 00 00 0C */	b .L_801AAE4C
.L_801AAE44:
/* 801AAE44 001A7D84  38 00 00 00 */	li r0, 0
/* 801AAE48 001A7D88  98 1E 00 20 */	stb r0, 0x20(r30)
.L_801AAE4C:
/* 801AAE4C 001A7D8C  7F E3 FB 78 */	mr r3, r31
/* 801AAE50 001A7D90  48 26 99 15 */	bl readShort__6StreamFv
/* 801AAE54 001A7D94  7C 60 07 34 */	extsh r0, r3
/* 801AAE58 001A7D98  7F E3 FB 78 */	mr r3, r31
/* 801AAE5C 001A7D9C  90 1E 00 74 */	stw r0, 0x74(r30)
/* 801AAE60 001A7DA0  48 26 99 05 */	bl readShort__6StreamFv
/* 801AAE64 001A7DA4  7C 60 07 34 */	extsh r0, r3
/* 801AAE68 001A7DA8  7F E3 FB 78 */	mr r3, r31
/* 801AAE6C 001A7DAC  90 1E 00 78 */	stw r0, 0x78(r30)
/* 801AAE70 001A7DB0  48 26 98 F5 */	bl readShort__6StreamFv
/* 801AAE74 001A7DB4  7C 60 07 34 */	extsh r0, r3
/* 801AAE78 001A7DB8  90 1E 00 84 */	stw r0, 0x84(r30)
.L_801AAE7C:
/* 801AAE7C 001A7DBC  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AAE80 001A7DC0  28 00 00 00 */	cmplwi r0, 0
/* 801AAE84 001A7DC4  41 82 00 8C */	beq .L_801AAF10
/* 801AAE88 001A7DC8  7F E3 FB 78 */	mr r3, r31
/* 801AAE8C 001A7DCC  48 26 98 D9 */	bl readShort__6StreamFv
/* 801AAE90 001A7DD0  7C 63 07 34 */	extsh r3, r3
/* 801AAE94 001A7DD4  3C 00 43 30 */	lis r0, 0x4330
/* 801AAE98 001A7DD8  6C 64 80 00 */	xoris r4, r3, 0x8000
/* 801AAE9C 001A7DDC  90 01 00 20 */	stw r0, 0x20(r1)
/* 801AAEA0 001A7DE0  C8 22 AF 08 */	lfd f1, lbl_80519268@sda21(r2)
/* 801AAEA4 001A7DE4  7F E3 FB 78 */	mr r3, r31
/* 801AAEA8 001A7DE8  90 81 00 24 */	stw r4, 0x24(r1)
/* 801AAEAC 001A7DEC  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 801AAEB0 001A7DF0  EC 00 08 28 */	fsubs f0, f0, f1
/* 801AAEB4 001A7DF4  D0 1E 00 94 */	stfs f0, 0x94(r30)
/* 801AAEB8 001A7DF8  48 26 98 AD */	bl readShort__6StreamFv
/* 801AAEBC 001A7DFC  7C 63 07 34 */	extsh r3, r3
/* 801AAEC0 001A7E00  3C 00 43 30 */	lis r0, 0x4330
/* 801AAEC4 001A7E04  6C 64 80 00 */	xoris r4, r3, 0x8000
/* 801AAEC8 001A7E08  90 01 00 28 */	stw r0, 0x28(r1)
/* 801AAECC 001A7E0C  C8 22 AF 08 */	lfd f1, lbl_80519268@sda21(r2)
/* 801AAED0 001A7E10  7F E3 FB 78 */	mr r3, r31
/* 801AAED4 001A7E14  90 81 00 2C */	stw r4, 0x2c(r1)
/* 801AAED8 001A7E18  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 801AAEDC 001A7E1C  EC 00 08 28 */	fsubs f0, f0, f1
/* 801AAEE0 001A7E20  D0 1E 00 98 */	stfs f0, 0x98(r30)
/* 801AAEE4 001A7E24  48 26 98 81 */	bl readShort__6StreamFv
/* 801AAEE8 001A7E28  7C 63 07 34 */	extsh r3, r3
/* 801AAEEC 001A7E2C  3C 00 43 30 */	lis r0, 0x4330
/* 801AAEF0 001A7E30  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 801AAEF4 001A7E34  90 01 00 30 */	stw r0, 0x30(r1)
/* 801AAEF8 001A7E38  C8 22 AF 08 */	lfd f1, lbl_80519268@sda21(r2)
/* 801AAEFC 001A7E3C  90 61 00 34 */	stw r3, 0x34(r1)
/* 801AAF00 001A7E40  C8 01 00 30 */	lfd f0, 0x30(r1)
/* 801AAF04 001A7E44  EC 00 08 28 */	fsubs f0, f0, f1
/* 801AAF08 001A7E48  D0 1E 00 9C */	stfs f0, 0x9c(r30)
/* 801AAF0C 001A7E4C  48 00 00 28 */	b .L_801AAF34
.L_801AAF10:
/* 801AAF10 001A7E50  7F E3 FB 78 */	mr r3, r31
/* 801AAF14 001A7E54  48 26 9E 99 */	bl readFloat__6StreamFv
/* 801AAF18 001A7E58  D0 3E 00 94 */	stfs f1, 0x94(r30)
/* 801AAF1C 001A7E5C  7F E3 FB 78 */	mr r3, r31
/* 801AAF20 001A7E60  48 26 9E 8D */	bl readFloat__6StreamFv
/* 801AAF24 001A7E64  D0 3E 00 98 */	stfs f1, 0x98(r30)
/* 801AAF28 001A7E68  7F E3 FB 78 */	mr r3, r31
/* 801AAF2C 001A7E6C  48 26 9E 81 */	bl readFloat__6StreamFv
/* 801AAF30 001A7E70  D0 3E 00 9C */	stfs f1, 0x9c(r30)
.L_801AAF34:
/* 801AAF34 001A7E74  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AAF38 001A7E78  28 00 00 00 */	cmplwi r0, 0
/* 801AAF3C 001A7E7C  41 82 00 18 */	beq .L_801AAF54
/* 801AAF40 001A7E80  C0 02 AE F8 */	lfs f0, lbl_80519258@sda21(r2)
/* 801AAF44 001A7E84  D0 1E 00 A0 */	stfs f0, 0xa0(r30)
/* 801AAF48 001A7E88  D0 1E 00 A4 */	stfs f0, 0xa4(r30)
/* 801AAF4C 001A7E8C  D0 1E 00 A8 */	stfs f0, 0xa8(r30)
/* 801AAF50 001A7E90  48 00 00 28 */	b .L_801AAF78
.L_801AAF54:
/* 801AAF54 001A7E94  7F E3 FB 78 */	mr r3, r31
/* 801AAF58 001A7E98  48 26 9E 55 */	bl readFloat__6StreamFv
/* 801AAF5C 001A7E9C  D0 3E 00 A0 */	stfs f1, 0xa0(r30)
/* 801AAF60 001A7EA0  7F E3 FB 78 */	mr r3, r31
/* 801AAF64 001A7EA4  48 26 9E 49 */	bl readFloat__6StreamFv
/* 801AAF68 001A7EA8  D0 3E 00 A4 */	stfs f1, 0xa4(r30)
/* 801AAF6C 001A7EAC  7F E3 FB 78 */	mr r3, r31
/* 801AAF70 001A7EB0  48 26 9E 3D */	bl readFloat__6StreamFv
/* 801AAF74 001A7EB4  D0 3E 00 A8 */	stfs f1, 0xa8(r30)
.L_801AAF78:
/* 801AAF78 001A7EB8  38 00 00 00 */	li r0, 0
/* 801AAF7C 001A7EBC  38 61 00 14 */	addi r3, r1, 0x14
/* 801AAF80 001A7EC0  90 1E 00 18 */	stw r0, 0x18(r30)
/* 801AAF84 001A7EC4  48 26 82 ED */	bl __ct__4ID32Fv
/* 801AAF88 001A7EC8  7F E4 FB 78 */	mr r4, r31
/* 801AAF8C 001A7ECC  38 61 00 14 */	addi r3, r1, 0x14
/* 801AAF90 001A7ED0  48 26 85 61 */	bl read__4ID32FR6Stream
/* 801AAF94 001A7ED4  80 CD 93 A0 */	lwz r6, factory__Q24Game16GenObjectFactory@sda21(r13)
/* 801AAF98 001A7ED8  38 60 00 00 */	li r3, 0
/* 801AAF9C 001A7EDC  7C 64 1B 78 */	mr r4, r3
/* 801AAFA0 001A7EE0  83 81 00 1C */	lwz r28, 0x1c(r1)
/* 801AAFA4 001A7EE4  80 06 00 00 */	lwz r0, 0(r6)
/* 801AAFA8 001A7EE8  7C 09 03 A6 */	mtctr r0
/* 801AAFAC 001A7EEC  2C 00 00 00 */	cmpwi r0, 0
/* 801AAFB0 001A7EF0  40 81 00 38 */	ble .L_801AAFE8
.L_801AAFB4:
/* 801AAFB4 001A7EF4  80 A6 00 08 */	lwz r5, 8(r6)
/* 801AAFB8 001A7EF8  7C 05 20 2E */	lwzx r0, r5, r4
/* 801AAFBC 001A7EFC  7C 1C 00 40 */	cmplw r28, r0
/* 801AAFC0 001A7F00  40 82 00 1C */	bne .L_801AAFDC
/* 801AAFC4 001A7F04  54 60 20 36 */	slwi r0, r3, 4
/* 801AAFC8 001A7F08  7C 65 02 14 */	add r3, r5, r0
/* 801AAFCC 001A7F0C  81 83 00 04 */	lwz r12, 4(r3)
/* 801AAFD0 001A7F10  7D 89 03 A6 */	mtctr r12
/* 801AAFD4 001A7F14  4E 80 04 21 */	bctrl 
/* 801AAFD8 001A7F18  48 00 00 14 */	b .L_801AAFEC
.L_801AAFDC:
/* 801AAFDC 001A7F1C  38 84 00 10 */	addi r4, r4, 0x10
/* 801AAFE0 001A7F20  38 63 00 01 */	addi r3, r3, 1
/* 801AAFE4 001A7F24  42 00 FF D0 */	bdnz .L_801AAFB4
.L_801AAFE8:
/* 801AAFE8 001A7F28  38 60 00 00 */	li r3, 0
.L_801AAFEC:
/* 801AAFEC 001A7F2C  90 7E 00 18 */	stw r3, 0x18(r30)
/* 801AAFF0 001A7F30  83 BE 00 18 */	lwz r29, 0x18(r30)
/* 801AAFF4 001A7F34  28 1D 00 00 */	cmplwi r29, 0
/* 801AAFF8 001A7F38  41 82 00 9C */	beq .L_801AB094
/* 801AAFFC 001A7F3C  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB000 001A7F40  28 00 00 00 */	cmplwi r0, 0
/* 801AB004 001A7F44  40 82 00 24 */	bne .L_801AB028
/* 801AB008 001A7F48  38 61 00 08 */	addi r3, r1, 8
/* 801AB00C 001A7F4C  48 26 82 65 */	bl __ct__4ID32Fv
/* 801AB010 001A7F50  7F E4 FB 78 */	mr r4, r31
/* 801AB014 001A7F54  38 61 00 08 */	addi r3, r1, 8
/* 801AB018 001A7F58  48 26 84 D9 */	bl read__4ID32FR6Stream
/* 801AB01C 001A7F5C  80 01 00 10 */	lwz r0, 0x10(r1)
/* 801AB020 001A7F60  90 1D 00 14 */	stw r0, 0x14(r29)
/* 801AB024 001A7F64  48 00 00 1C */	b .L_801AB040
.L_801AB028:
/* 801AB028 001A7F68  7F A3 EB 78 */	mr r3, r29
/* 801AB02C 001A7F6C  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 801AB030 001A7F70  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 801AB034 001A7F74  7D 89 03 A6 */	mtctr r12
/* 801AB038 001A7F78  4E 80 04 21 */	bctrl 
/* 801AB03C 001A7F7C  90 7D 00 14 */	stw r3, 0x14(r29)
.L_801AB040:
/* 801AB040 001A7F80  7F A3 EB 78 */	mr r3, r29
/* 801AB044 001A7F84  7F E4 FB 78 */	mr r4, r31
/* 801AB048 001A7F88  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 801AB04C 001A7F8C  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 801AB050 001A7F90  7D 89 03 A6 */	mtctr r12
/* 801AB054 001A7F94  4E 80 04 21 */	bctrl 
/* 801AB058 001A7F98  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB05C 001A7F9C  28 00 00 00 */	cmplwi r0, 0
/* 801AB060 001A7FA0  41 82 00 20 */	beq .L_801AB080
/* 801AB064 001A7FA4  7F A3 EB 78 */	mr r3, r29
/* 801AB068 001A7FA8  7F E4 FB 78 */	mr r4, r31
/* 801AB06C 001A7FAC  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 801AB070 001A7FB0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801AB074 001A7FB4  7D 89 03 A6 */	mtctr r12
/* 801AB078 001A7FB8  4E 80 04 21 */	bctrl 
/* 801AB07C 001A7FBC  48 00 00 10 */	b .L_801AB08C
.L_801AB080:
/* 801AB080 001A7FC0  7F A3 EB 78 */	mr r3, r29
/* 801AB084 001A7FC4  7F E4 FB 78 */	mr r4, r31
/* 801AB088 001A7FC8  48 26 87 6D */	bl read__10ParametersFR6Stream
.L_801AB08C:
/* 801AB08C 001A7FCC  93 9E 00 1C */	stw r28, 0x1c(r30)
/* 801AB090 001A7FD0  48 00 00 0C */	b .L_801AB09C
.L_801AB094:
/* 801AB094 001A7FD4  38 61 00 14 */	addi r3, r1, 0x14
/* 801AB098 001A7FD8  48 26 85 45 */	bl print__4ID32Fv
.L_801AB09C:
/* 801AB09C 001A7FDC  80 01 00 54 */	lwz r0, 0x54(r1)
/* 801AB0A0 001A7FE0  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 801AB0A4 001A7FE4  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 801AB0A8 001A7FE8  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 801AB0AC 001A7FEC  83 81 00 40 */	lwz r28, 0x40(r1)
/* 801AB0B0 001A7FF0  7C 08 03 A6 */	mtlr r0
/* 801AB0B4 001A7FF4  38 21 00 50 */	addi r1, r1, 0x50
/* 801AB0B8 001A7FF8  4E 80 00 20 */	blr 
.endfn read__Q24Game9GeneratorFR6Stream

.fn write__Q24Game9GeneratorFR6Stream, global
/* 801AB0BC 001A7FFC  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 801AB0C0 001A8000  7C 08 02 A6 */	mflr r0
/* 801AB0C4 001A8004  3C A0 80 48 */	lis r5, lbl_8047F668@ha
/* 801AB0C8 001A8008  90 01 00 94 */	stw r0, 0x94(r1)
/* 801AB0CC 001A800C  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 801AB0D0 001A8010  7C 9F 23 78 */	mr r31, r4
/* 801AB0D4 001A8014  93 C1 00 88 */	stw r30, 0x88(r1)
/* 801AB0D8 001A8018  7C 7E 1B 78 */	mr r30, r3
/* 801AB0DC 001A801C  7F E3 FB 78 */	mr r3, r31
/* 801AB0E0 001A8020  93 A1 00 84 */	stw r29, 0x84(r1)
/* 801AB0E4 001A8024  3B A5 F6 68 */	addi r29, r5, lbl_8047F668@l
/* 801AB0E8 001A8028  93 81 00 80 */	stw r28, 0x80(r1)
/* 801AB0EC 001A802C  80 84 04 14 */	lwz r4, 0x414(r4)
/* 801AB0F0 001A8030  48 26 93 45 */	bl textWriteTab__6StreamFi
/* 801AB0F4 001A8034  80 8D 84 38 */	lwz r4, GeneratorCurrentVersion@sda21(r13)
/* 801AB0F8 001A8038  38 61 00 20 */	addi r3, r1, 0x20
/* 801AB0FC 001A803C  48 26 81 AD */	bl __ct__4ID32FUl
/* 801AB100 001A8040  7F E4 FB 78 */	mr r4, r31
/* 801AB104 001A8044  38 61 00 20 */	addi r3, r1, 0x20
/* 801AB108 001A8048  48 26 83 59 */	bl write__4ID32FR6Stream
/* 801AB10C 001A804C  7F E3 FB 78 */	mr r3, r31
/* 801AB110 001A8050  38 9D 00 6C */	addi r4, r29, 0x6c
/* 801AB114 001A8054  4C C6 31 82 */	crclr 6
/* 801AB118 001A8058  48 26 90 C5 */	bl textWriteText__6StreamFPce
/* 801AB11C 001A805C  80 9F 04 14 */	lwz r4, 0x414(r31)
/* 801AB120 001A8060  7F E3 FB 78 */	mr r3, r31
/* 801AB124 001A8064  48 26 93 11 */	bl textWriteTab__6StreamFi
/* 801AB128 001A8068  A0 1E 00 5C */	lhz r0, 0x5c(r30)
/* 801AB12C 001A806C  7F E3 FB 78 */	mr r3, r31
/* 801AB130 001A8070  7C 04 07 34 */	extsh r4, r0
/* 801AB134 001A8074  48 26 A5 FD */	bl writeShort__6StreamFs
/* 801AB138 001A8078  7F E3 FB 78 */	mr r3, r31
/* 801AB13C 001A807C  38 9D 00 7C */	addi r4, r29, 0x7c
/* 801AB140 001A8080  4C C6 31 82 */	crclr 6
/* 801AB144 001A8084  48 26 90 99 */	bl textWriteText__6StreamFPce
/* 801AB148 001A8088  80 9F 04 14 */	lwz r4, 0x414(r31)
/* 801AB14C 001A808C  7F E3 FB 78 */	mr r3, r31
/* 801AB150 001A8090  48 26 92 E5 */	bl textWriteTab__6StreamFi
/* 801AB154 001A8094  80 1E 00 70 */	lwz r0, 0x70(r30)
/* 801AB158 001A8098  7F E3 FB 78 */	mr r3, r31
/* 801AB15C 001A809C  7C 04 07 34 */	extsh r4, r0
/* 801AB160 001A80A0  48 26 A5 D1 */	bl writeShort__6StreamFs
/* 801AB164 001A80A4  7F E3 FB 78 */	mr r3, r31
/* 801AB168 001A80A8  38 9D 00 8C */	addi r4, r29, 0x8c
/* 801AB16C 001A80AC  4C C6 31 82 */	crclr 6
/* 801AB170 001A80B0  48 26 90 6D */	bl textWriteText__6StreamFPce
/* 801AB174 001A80B4  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB178 001A80B8  28 00 00 00 */	cmplwi r0, 0
/* 801AB17C 001A80BC  40 82 00 48 */	bne .L_801AB1C4
/* 801AB180 001A80C0  80 9F 04 14 */	lwz r4, 0x414(r31)
/* 801AB184 001A80C4  7F E3 FB 78 */	mr r3, r31
/* 801AB188 001A80C8  48 26 92 AD */	bl textWriteTab__6StreamFi
/* 801AB18C 001A80CC  3B 80 00 00 */	li r28, 0
.L_801AB190:
/* 801AB190 001A80D0  38 1C 00 20 */	addi r0, r28, 0x20
/* 801AB194 001A80D4  7F E3 FB 78 */	mr r3, r31
/* 801AB198 001A80D8  7C 9E 00 AE */	lbzx r4, r30, r0
/* 801AB19C 001A80DC  48 26 A4 D5 */	bl writeByte__6StreamFUc
/* 801AB1A0 001A80E0  3B 9C 00 01 */	addi r28, r28, 1
/* 801AB1A4 001A80E4  2C 1C 00 20 */	cmpwi r28, 0x20
/* 801AB1A8 001A80E8  41 80 FF E8 */	blt .L_801AB190
/* 801AB1AC 001A80EC  7F E3 FB 78 */	mr r3, r31
/* 801AB1B0 001A80F0  38 9D 00 9C */	addi r4, r29, 0x9c
/* 801AB1B4 001A80F4  38 BE 00 20 */	addi r5, r30, 0x20
/* 801AB1B8 001A80F8  4C C6 31 82 */	crclr 6
/* 801AB1BC 001A80FC  48 26 90 21 */	bl textWriteText__6StreamFPce
/* 801AB1C0 001A8100  48 00 00 40 */	b .L_801AB200
.L_801AB1C4:
/* 801AB1C4 001A8104  7F E3 FB 78 */	mr r3, r31
/* 801AB1C8 001A8108  38 80 00 00 */	li r4, 0
/* 801AB1CC 001A810C  48 26 A4 A5 */	bl writeByte__6StreamFUc
/* 801AB1D0 001A8110  80 1E 00 74 */	lwz r0, 0x74(r30)
/* 801AB1D4 001A8114  7F E3 FB 78 */	mr r3, r31
/* 801AB1D8 001A8118  7C 04 07 34 */	extsh r4, r0
/* 801AB1DC 001A811C  48 26 A5 55 */	bl writeShort__6StreamFs
/* 801AB1E0 001A8120  80 1E 00 78 */	lwz r0, 0x78(r30)
/* 801AB1E4 001A8124  7F E3 FB 78 */	mr r3, r31
/* 801AB1E8 001A8128  7C 04 07 34 */	extsh r4, r0
/* 801AB1EC 001A812C  48 26 A5 45 */	bl writeShort__6StreamFs
/* 801AB1F0 001A8130  80 1E 00 84 */	lwz r0, 0x84(r30)
/* 801AB1F4 001A8134  7F E3 FB 78 */	mr r3, r31
/* 801AB1F8 001A8138  7C 04 07 34 */	extsh r4, r0
/* 801AB1FC 001A813C  48 26 A5 35 */	bl writeShort__6StreamFs
.L_801AB200:
/* 801AB200 001A8140  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB204 001A8144  28 00 00 00 */	cmplwi r0, 0
/* 801AB208 001A8148  41 82 00 EC */	beq .L_801AB2F4
/* 801AB20C 001A814C  C0 1E 00 94 */	lfs f0, 0x94(r30)
/* 801AB210 001A8150  3C 00 43 30 */	lis r0, 0x4330
/* 801AB214 001A8154  90 01 00 38 */	stw r0, 0x38(r1)
/* 801AB218 001A8158  7F E3 FB 78 */	mr r3, r31
/* 801AB21C 001A815C  FC 20 00 1E */	fctiwz f1, f0
/* 801AB220 001A8160  C8 42 AF 08 */	lfd f2, lbl_80519268@sda21(r2)
/* 801AB224 001A8164  C0 1E 00 A0 */	lfs f0, 0xa0(r30)
/* 801AB228 001A8168  D8 21 00 30 */	stfd f1, 0x30(r1)
/* 801AB22C 001A816C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801AB230 001A8170  7C 00 07 34 */	extsh r0, r0
/* 801AB234 001A8174  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801AB238 001A8178  90 01 00 3C */	stw r0, 0x3c(r1)
/* 801AB23C 001A817C  C8 21 00 38 */	lfd f1, 0x38(r1)
/* 801AB240 001A8180  EC 21 10 28 */	fsubs f1, f1, f2
/* 801AB244 001A8184  EC 01 00 2A */	fadds f0, f1, f0
/* 801AB248 001A8188  FC 00 00 1E */	fctiwz f0, f0
/* 801AB24C 001A818C  D8 01 00 40 */	stfd f0, 0x40(r1)
/* 801AB250 001A8190  80 81 00 44 */	lwz r4, 0x44(r1)
/* 801AB254 001A8194  48 26 A4 DD */	bl writeShort__6StreamFs
/* 801AB258 001A8198  C0 1E 00 98 */	lfs f0, 0x98(r30)
/* 801AB25C 001A819C  3C 00 43 30 */	lis r0, 0x4330
/* 801AB260 001A81A0  90 01 00 50 */	stw r0, 0x50(r1)
/* 801AB264 001A81A4  7F E3 FB 78 */	mr r3, r31
/* 801AB268 001A81A8  FC 20 00 1E */	fctiwz f1, f0
/* 801AB26C 001A81AC  C8 42 AF 08 */	lfd f2, lbl_80519268@sda21(r2)
/* 801AB270 001A81B0  C0 1E 00 A4 */	lfs f0, 0xa4(r30)
/* 801AB274 001A81B4  D8 21 00 48 */	stfd f1, 0x48(r1)
/* 801AB278 001A81B8  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 801AB27C 001A81BC  7C 00 07 34 */	extsh r0, r0
/* 801AB280 001A81C0  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801AB284 001A81C4  90 01 00 54 */	stw r0, 0x54(r1)
/* 801AB288 001A81C8  C8 21 00 50 */	lfd f1, 0x50(r1)
/* 801AB28C 001A81CC  EC 21 10 28 */	fsubs f1, f1, f2
/* 801AB290 001A81D0  EC 01 00 2A */	fadds f0, f1, f0
/* 801AB294 001A81D4  FC 00 00 1E */	fctiwz f0, f0
/* 801AB298 001A81D8  D8 01 00 58 */	stfd f0, 0x58(r1)
/* 801AB29C 001A81DC  80 81 00 5C */	lwz r4, 0x5c(r1)
/* 801AB2A0 001A81E0  48 26 A4 91 */	bl writeShort__6StreamFs
/* 801AB2A4 001A81E4  C0 1E 00 9C */	lfs f0, 0x9c(r30)
/* 801AB2A8 001A81E8  3C 00 43 30 */	lis r0, 0x4330
/* 801AB2AC 001A81EC  90 01 00 68 */	stw r0, 0x68(r1)
/* 801AB2B0 001A81F0  7F E3 FB 78 */	mr r3, r31
/* 801AB2B4 001A81F4  FC 20 00 1E */	fctiwz f1, f0
/* 801AB2B8 001A81F8  C8 42 AF 08 */	lfd f2, lbl_80519268@sda21(r2)
/* 801AB2BC 001A81FC  C0 1E 00 A8 */	lfs f0, 0xa8(r30)
/* 801AB2C0 001A8200  D8 21 00 60 */	stfd f1, 0x60(r1)
/* 801AB2C4 001A8204  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801AB2C8 001A8208  7C 00 07 34 */	extsh r0, r0
/* 801AB2CC 001A820C  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801AB2D0 001A8210  90 01 00 6C */	stw r0, 0x6c(r1)
/* 801AB2D4 001A8214  C8 21 00 68 */	lfd f1, 0x68(r1)
/* 801AB2D8 001A8218  EC 21 10 28 */	fsubs f1, f1, f2
/* 801AB2DC 001A821C  EC 01 00 2A */	fadds f0, f1, f0
/* 801AB2E0 001A8220  FC 00 00 1E */	fctiwz f0, f0
/* 801AB2E4 001A8224  D8 01 00 70 */	stfd f0, 0x70(r1)
/* 801AB2E8 001A8228  80 81 00 74 */	lwz r4, 0x74(r1)
/* 801AB2EC 001A822C  48 26 A4 45 */	bl writeShort__6StreamFs
/* 801AB2F0 001A8230  48 00 00 84 */	b .L_801AB374
.L_801AB2F4:
/* 801AB2F4 001A8234  80 9F 04 14 */	lwz r4, 0x414(r31)
/* 801AB2F8 001A8238  7F E3 FB 78 */	mr r3, r31
/* 801AB2FC 001A823C  48 26 91 39 */	bl textWriteTab__6StreamFi
/* 801AB300 001A8240  C0 3E 00 94 */	lfs f1, 0x94(r30)
/* 801AB304 001A8244  7F E3 FB 78 */	mr r3, r31
/* 801AB308 001A8248  48 26 A5 41 */	bl writeFloat__6StreamFf
/* 801AB30C 001A824C  C0 3E 00 98 */	lfs f1, 0x98(r30)
/* 801AB310 001A8250  7F E3 FB 78 */	mr r3, r31
/* 801AB314 001A8254  48 26 A5 35 */	bl writeFloat__6StreamFf
/* 801AB318 001A8258  C0 3E 00 9C */	lfs f1, 0x9c(r30)
/* 801AB31C 001A825C  7F E3 FB 78 */	mr r3, r31
/* 801AB320 001A8260  48 26 A5 29 */	bl writeFloat__6StreamFf
/* 801AB324 001A8264  7F E3 FB 78 */	mr r3, r31
/* 801AB328 001A8268  38 9D 00 A8 */	addi r4, r29, 0xa8
/* 801AB32C 001A826C  4C C6 31 82 */	crclr 6
/* 801AB330 001A8270  48 26 8E AD */	bl textWriteText__6StreamFPce
/* 801AB334 001A8274  80 9F 04 14 */	lwz r4, 0x414(r31)
/* 801AB338 001A8278  7F E3 FB 78 */	mr r3, r31
/* 801AB33C 001A827C  48 26 90 F9 */	bl textWriteTab__6StreamFi
/* 801AB340 001A8280  C0 3E 00 A0 */	lfs f1, 0xa0(r30)
/* 801AB344 001A8284  7F E3 FB 78 */	mr r3, r31
/* 801AB348 001A8288  48 26 A5 01 */	bl writeFloat__6StreamFf
/* 801AB34C 001A828C  C0 3E 00 A4 */	lfs f1, 0xa4(r30)
/* 801AB350 001A8290  7F E3 FB 78 */	mr r3, r31
/* 801AB354 001A8294  48 26 A4 F5 */	bl writeFloat__6StreamFf
/* 801AB358 001A8298  C0 3E 00 A8 */	lfs f1, 0xa8(r30)
/* 801AB35C 001A829C  7F E3 FB 78 */	mr r3, r31
/* 801AB360 001A82A0  48 26 A4 E9 */	bl writeFloat__6StreamFf
/* 801AB364 001A82A4  7F E3 FB 78 */	mr r3, r31
/* 801AB368 001A82A8  38 9D 00 B4 */	addi r4, r29, 0xb4
/* 801AB36C 001A82AC  4C C6 31 82 */	crclr 6
/* 801AB370 001A82B0  48 26 8E 6D */	bl textWriteText__6StreamFPce
.L_801AB374:
/* 801AB374 001A82B4  83 BE 00 18 */	lwz r29, 0x18(r30)
/* 801AB378 001A82B8  28 1D 00 00 */	cmplwi r29, 0
/* 801AB37C 001A82BC  41 82 00 B0 */	beq .L_801AB42C
/* 801AB380 001A82C0  80 9D 00 10 */	lwz r4, 0x10(r29)
/* 801AB384 001A82C4  38 61 00 14 */	addi r3, r1, 0x14
/* 801AB388 001A82C8  48 26 7F 21 */	bl __ct__4ID32FUl
/* 801AB38C 001A82CC  80 9F 04 14 */	lwz r4, 0x414(r31)
/* 801AB390 001A82D0  7F E3 FB 78 */	mr r3, r31
/* 801AB394 001A82D4  48 26 90 A1 */	bl textWriteTab__6StreamFi
/* 801AB398 001A82D8  7F E4 FB 78 */	mr r4, r31
/* 801AB39C 001A82DC  38 61 00 14 */	addi r3, r1, 0x14
/* 801AB3A0 001A82E0  48 26 80 C1 */	bl write__4ID32FR6Stream
/* 801AB3A4 001A82E4  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB3A8 001A82E8  28 00 00 00 */	cmplwi r0, 0
/* 801AB3AC 001A82EC  40 82 00 30 */	bne .L_801AB3DC
/* 801AB3B0 001A82F0  7F A3 EB 78 */	mr r3, r29
/* 801AB3B4 001A82F4  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 801AB3B8 001A82F8  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 801AB3BC 001A82FC  7D 89 03 A6 */	mtctr r12
/* 801AB3C0 001A8300  4E 80 04 21 */	bctrl 
/* 801AB3C4 001A8304  7C 64 1B 78 */	mr r4, r3
/* 801AB3C8 001A8308  38 61 00 08 */	addi r3, r1, 8
/* 801AB3CC 001A830C  48 26 7E DD */	bl __ct__4ID32FUl
/* 801AB3D0 001A8310  7F E4 FB 78 */	mr r4, r31
/* 801AB3D4 001A8314  38 61 00 08 */	addi r3, r1, 8
/* 801AB3D8 001A8318  48 26 80 89 */	bl write__4ID32FR6Stream
.L_801AB3DC:
/* 801AB3DC 001A831C  7F A3 EB 78 */	mr r3, r29
/* 801AB3E0 001A8320  7F E4 FB 78 */	mr r4, r31
/* 801AB3E4 001A8324  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 801AB3E8 001A8328  81 8C 00 08 */	lwz r12, 8(r12)
/* 801AB3EC 001A832C  7D 89 03 A6 */	mtctr r12
/* 801AB3F0 001A8330  4E 80 04 21 */	bctrl 
/* 801AB3F4 001A8334  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB3F8 001A8338  28 00 00 00 */	cmplwi r0, 0
/* 801AB3FC 001A833C  41 82 00 20 */	beq .L_801AB41C
/* 801AB400 001A8340  7F A3 EB 78 */	mr r3, r29
/* 801AB404 001A8344  7F E4 FB 78 */	mr r4, r31
/* 801AB408 001A8348  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 801AB40C 001A834C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801AB410 001A8350  7D 89 03 A6 */	mtctr r12
/* 801AB414 001A8354  4E 80 04 21 */	bctrl 
/* 801AB418 001A8358  48 00 00 20 */	b .L_801AB438
.L_801AB41C:
/* 801AB41C 001A835C  7F A3 EB 78 */	mr r3, r29
/* 801AB420 001A8360  7F E4 FB 78 */	mr r4, r31
/* 801AB424 001A8364  48 26 82 E1 */	bl write__10ParametersFR6Stream
/* 801AB428 001A8368  48 00 00 10 */	b .L_801AB438
.L_801AB42C:
/* 801AB42C 001A836C  7F E3 FB 78 */	mr r3, r31
/* 801AB430 001A8370  38 80 00 00 */	li r4, 0
/* 801AB434 001A8374  48 26 A3 8D */	bl writeInt__6StreamFi
.L_801AB438:
/* 801AB438 001A8378  80 01 00 94 */	lwz r0, 0x94(r1)
/* 801AB43C 001A837C  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 801AB440 001A8380  83 C1 00 88 */	lwz r30, 0x88(r1)
/* 801AB444 001A8384  83 A1 00 84 */	lwz r29, 0x84(r1)
/* 801AB448 001A8388  83 81 00 80 */	lwz r28, 0x80(r1)
/* 801AB44C 001A838C  7C 08 03 A6 */	mtlr r0
/* 801AB450 001A8390  38 21 00 90 */	addi r1, r1, 0x90
/* 801AB454 001A8394  4E 80 00 20 */	blr 
.endfn write__Q24Game9GeneratorFR6Stream

.fn __ct__Q24Game12GeneratorMgrFv, global
/* 801AB458 001A8398  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AB45C 001A839C  7C 08 02 A6 */	mflr r0
/* 801AB460 001A83A0  3C 80 80 4F */	lis r4, __vt__5CNode@ha
/* 801AB464 001A83A4  38 A0 00 00 */	li r5, 0
/* 801AB468 001A83A8  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AB46C 001A83AC  38 04 B5 28 */	addi r0, r4, __vt__5CNode@l
/* 801AB470 001A83B0  38 82 AF 10 */	addi r4, r2, lbl_80519270@sda21
/* 801AB474 001A83B4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AB478 001A83B8  93 C1 00 08 */	stw r30, 8(r1)
/* 801AB47C 001A83BC  7C 7E 1B 78 */	mr r30, r3
/* 801AB480 001A83C0  3C 60 80 4B */	lis r3, __vt__Q24Game12GeneratorMgr@ha
/* 801AB484 001A83C4  90 1E 00 00 */	stw r0, 0(r30)
/* 801AB488 001A83C8  38 03 55 FC */	addi r0, r3, __vt__Q24Game12GeneratorMgr@l
/* 801AB48C 001A83CC  38 7E 00 34 */	addi r3, r30, 0x34
/* 801AB490 001A83D0  90 BE 00 10 */	stw r5, 0x10(r30)
/* 801AB494 001A83D4  90 BE 00 0C */	stw r5, 0xc(r30)
/* 801AB498 001A83D8  90 BE 00 08 */	stw r5, 8(r30)
/* 801AB49C 001A83DC  90 BE 00 04 */	stw r5, 4(r30)
/* 801AB4A0 001A83E0  90 9E 00 14 */	stw r4, 0x14(r30)
/* 801AB4A4 001A83E4  90 1E 00 00 */	stw r0, 0(r30)
/* 801AB4A8 001A83E8  48 26 7D C9 */	bl __ct__4ID32Fv
/* 801AB4AC 001A83EC  38 7E 00 40 */	addi r3, r30, 0x40
/* 801AB4B0 001A83F0  48 26 7D C1 */	bl __ct__4ID32Fv
/* 801AB4B4 001A83F4  38 7E 00 50 */	addi r3, r30, 0x50
/* 801AB4B8 001A83F8  48 26 7D B9 */	bl __ct__4ID32Fv
/* 801AB4BC 001A83FC  38 00 00 00 */	li r0, 0
/* 801AB4C0 001A8400  3C 80 76 30 */	lis r4, 0x76302E31@ha
/* 801AB4C4 001A8404  90 1E 00 20 */	stw r0, 0x20(r30)
/* 801AB4C8 001A8408  38 7E 00 34 */	addi r3, r30, 0x34
/* 801AB4CC 001A840C  C0 02 AE F8 */	lfs f0, lbl_80519258@sda21(r2)
/* 801AB4D0 001A8410  38 84 2E 31 */	addi r4, r4, 0x76302E31@l
/* 801AB4D4 001A8414  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 801AB4D8 001A8418  90 1E 00 18 */	stw r0, 0x18(r30)
/* 801AB4DC 001A841C  98 1E 00 6D */	stb r0, 0x6d(r30)
/* 801AB4E0 001A8420  D0 1E 00 5C */	stfs f0, 0x5c(r30)
/* 801AB4E4 001A8424  D0 1E 00 60 */	stfs f0, 0x60(r30)
/* 801AB4E8 001A8428  D0 1E 00 64 */	stfs f0, 0x64(r30)
/* 801AB4EC 001A842C  D0 1E 00 68 */	stfs f0, 0x68(r30)
/* 801AB4F0 001A8430  90 1E 00 4C */	stw r0, 0x4c(r30)
/* 801AB4F4 001A8434  90 1E 00 30 */	stw r0, 0x30(r30)
/* 801AB4F8 001A8438  48 26 7D E1 */	bl setID__4ID32FUl
/* 801AB4FC 001A843C  3C 80 76 30 */	lis r4, 0x76302E30@ha
/* 801AB500 001A8440  38 7E 00 40 */	addi r3, r30, 0x40
/* 801AB504 001A8444  38 84 2E 30 */	addi r4, r4, 0x76302E30@l
/* 801AB508 001A8448  48 26 7D D1 */	bl setID__4ID32FUl
/* 801AB50C 001A844C  80 0D 93 A0 */	lwz r0, factory__Q24Game16GenObjectFactory@sda21(r13)
/* 801AB510 001A8450  28 00 00 00 */	cmplwi r0, 0
/* 801AB514 001A8454  40 82 00 34 */	bne .L_801AB548
/* 801AB518 001A8458  38 60 00 10 */	li r3, 0x10
/* 801AB51C 001A845C  4B E7 89 89 */	bl __nw__FUl
/* 801AB520 001A8460  7C 7F 1B 79 */	or. r31, r3, r3
/* 801AB524 001A8464  41 82 00 20 */	beq .L_801AB544
/* 801AB528 001A8468  38 60 00 C0 */	li r3, 0xc0
/* 801AB52C 001A846C  4B E7 8A 81 */	bl __nwa__FUl
/* 801AB530 001A8470  90 7F 00 08 */	stw r3, 8(r31)
/* 801AB534 001A8474  38 60 00 0C */	li r3, 0xc
/* 801AB538 001A8478  38 00 00 00 */	li r0, 0
/* 801AB53C 001A847C  90 7F 00 04 */	stw r3, 4(r31)
/* 801AB540 001A8480  90 1F 00 00 */	stw r0, 0(r31)
.L_801AB544:
/* 801AB544 001A8484  93 ED 93 A0 */	stw r31, factory__Q24Game16GenObjectFactory@sda21(r13)
.L_801AB548:
/* 801AB548 001A8488  38 00 00 00 */	li r0, 0
/* 801AB54C 001A848C  3C 60 80 48 */	lis r3, lbl_8047F728@ha
/* 801AB550 001A8490  98 1E 00 6C */	stb r0, 0x6c(r30)
/* 801AB554 001A8494  38 03 F7 28 */	addi r0, r3, lbl_8047F728@l
/* 801AB558 001A8498  7F C3 F3 78 */	mr r3, r30
/* 801AB55C 001A849C  90 1E 00 14 */	stw r0, 0x14(r30)
/* 801AB560 001A84A0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AB564 001A84A4  83 C1 00 08 */	lwz r30, 8(r1)
/* 801AB568 001A84A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AB56C 001A84AC  7C 08 03 A6 */	mtlr r0
/* 801AB570 001A84B0  38 21 00 10 */	addi r1, r1, 0x10
/* 801AB574 001A84B4  4E 80 00 20 */	blr 
.endfn __ct__Q24Game12GeneratorMgrFv

.fn addMgr__Q24Game12GeneratorMgrFPQ24Game12GeneratorMgr, global
/* 801AB578 001A84B8  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 801AB57C 001A84BC  28 00 00 00 */	cmplwi r0, 0
/* 801AB580 001A84C0  40 82 00 10 */	bne .L_801AB590
/* 801AB584 001A84C4  90 83 00 1C */	stw r4, 0x1c(r3)
/* 801AB588 001A84C8  90 64 00 20 */	stw r3, 0x20(r4)
/* 801AB58C 001A84CC  4E 80 00 20 */	blr 
.L_801AB590:
/* 801AB590 001A84D0  7C 05 03 78 */	mr r5, r0
/* 801AB594 001A84D4  48 00 00 08 */	b .L_801AB59C
.L_801AB598:
/* 801AB598 001A84D8  7C 05 03 78 */	mr r5, r0
.L_801AB59C:
/* 801AB59C 001A84DC  80 05 00 18 */	lwz r0, 0x18(r5)
/* 801AB5A0 001A84E0  28 00 00 00 */	cmplwi r0, 0
/* 801AB5A4 001A84E4  40 82 FF F4 */	bne .L_801AB598
/* 801AB5A8 001A84E8  90 85 00 18 */	stw r4, 0x18(r5)
/* 801AB5AC 001A84EC  90 64 00 20 */	stw r3, 0x20(r4)
/* 801AB5B0 001A84F0  4E 80 00 20 */	blr 
.endfn addMgr__Q24Game12GeneratorMgrFPQ24Game12GeneratorMgr

.fn generate__Q24Game12GeneratorMgrFv, global
/* 801AB5B4 001A84F4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AB5B8 001A84F8  7C 08 02 A6 */	mflr r0
/* 801AB5BC 001A84FC  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AB5C0 001A8500  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AB5C4 001A8504  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 801AB5C8 001A8508  48 00 01 18 */	b .L_801AB6E0
.L_801AB5CC:
/* 801AB5CC 001A850C  80 9F 00 84 */	lwz r4, 0x84(r31)
/* 801AB5D0 001A8510  2C 04 FF FF */	cmpwi r4, -1
/* 801AB5D4 001A8514  40 82 00 0C */	bne .L_801AB5E0
/* 801AB5D8 001A8518  38 00 00 00 */	li r0, 0
/* 801AB5DC 001A851C  48 00 00 24 */	b .L_801AB600
.L_801AB5E0:
/* 801AB5E0 001A8520  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 801AB5E4 001A8524  80 63 00 40 */	lwz r3, 0x40(r3)
/* 801AB5E8 001A8528  80 03 02 18 */	lwz r0, 0x218(r3)
/* 801AB5EC 001A852C  7C 04 00 40 */	cmplw r4, r0
/* 801AB5F0 001A8530  40 80 00 0C */	bge .L_801AB5FC
/* 801AB5F4 001A8534  38 00 00 01 */	li r0, 1
/* 801AB5F8 001A8538  48 00 00 08 */	b .L_801AB600
.L_801AB5FC:
/* 801AB5FC 001A853C  38 00 00 00 */	li r0, 0
.L_801AB600:
/* 801AB600 001A8540  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 801AB604 001A8544  41 82 00 14 */	beq .L_801AB618
/* 801AB608 001A8548  38 00 00 00 */	li r0, 0
/* 801AB60C 001A854C  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 801AB610 001A8550  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 801AB614 001A8554  48 00 00 C8 */	b .L_801AB6DC
.L_801AB618:
/* 801AB618 001A8558  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB61C 001A855C  28 00 00 00 */	cmplwi r0, 0
/* 801AB620 001A8560  40 82 00 24 */	bne .L_801AB644
/* 801AB624 001A8564  38 00 00 00 */	li r0, 0
/* 801AB628 001A8568  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 801AB62C 001A856C  90 1F 00 74 */	stw r0, 0x74(r31)
/* 801AB630 001A8570  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 801AB634 001A8574  80 63 00 40 */	lwz r3, 0x40(r3)
/* 801AB638 001A8578  80 03 02 18 */	lwz r0, 0x218(r3)
/* 801AB63C 001A857C  90 1F 00 78 */	stw r0, 0x78(r31)
/* 801AB640 001A8580  48 00 00 1C */	b .L_801AB65C
.L_801AB644:
/* 801AB644 001A8584  A0 1F 00 5C */	lhz r0, 0x5c(r31)
/* 801AB648 001A8588  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 801AB64C 001A858C  40 82 00 10 */	bne .L_801AB65C
/* 801AB650 001A8590  38 00 00 00 */	li r0, 0
/* 801AB654 001A8594  90 1F 00 7C */	stw r0, 0x7c(r31)
/* 801AB658 001A8598  48 00 00 84 */	b .L_801AB6DC
.L_801AB65C:
/* 801AB65C 001A859C  38 A0 00 00 */	li r5, 0
/* 801AB660 001A85A0  90 BF 00 6C */	stw r5, 0x6c(r31)
/* 801AB664 001A85A4  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 801AB668 001A85A8  28 00 00 00 */	cmplwi r0, 0
/* 801AB66C 001A85AC  41 82 00 70 */	beq .L_801AB6DC
/* 801AB670 001A85B0  88 0D 93 A4 */	lbz r0, ramMode__Q24Game9Generator@sda21(r13)
/* 801AB674 001A85B4  28 00 00 00 */	cmplwi r0, 0
/* 801AB678 001A85B8  41 82 00 38 */	beq .L_801AB6B0
/* 801AB67C 001A85BC  A0 1F 00 5C */	lhz r0, 0x5c(r31)
/* 801AB680 001A85C0  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 801AB684 001A85C4  41 82 00 2C */	beq .L_801AB6B0
/* 801AB688 001A85C8  80 8D 93 E8 */	lwz r4, gameSystem__4Game@sda21(r13)
/* 801AB68C 001A85CC  80 7F 00 78 */	lwz r3, 0x78(r31)
/* 801AB690 001A85D0  80 84 00 40 */	lwz r4, 0x40(r4)
/* 801AB694 001A85D4  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 801AB698 001A85D8  80 84 02 18 */	lwz r4, 0x218(r4)
/* 801AB69C 001A85DC  7C 03 02 14 */	add r0, r3, r0
/* 801AB6A0 001A85E0  7C 04 00 00 */	cmpw r4, r0
/* 801AB6A4 001A85E4  41 80 00 0C */	blt .L_801AB6B0
/* 801AB6A8 001A85E8  90 9F 00 78 */	stw r4, 0x78(r31)
/* 801AB6AC 001A85EC  90 BF 00 74 */	stw r5, 0x74(r31)
.L_801AB6B0:
/* 801AB6B0 001A85F0  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AB6B4 001A85F4  7F E4 FB 78 */	mr r4, r31
/* 801AB6B8 001A85F8  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801AB6BC 001A85FC  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 801AB6C0 001A8600  7D 89 03 A6 */	mtctr r12
/* 801AB6C4 001A8604  4E 80 04 21 */	bctrl 
/* 801AB6C8 001A8608  90 7F 00 6C */	stw r3, 0x6c(r31)
/* 801AB6CC 001A860C  80 7F 00 6C */	lwz r3, 0x6c(r31)
/* 801AB6D0 001A8610  28 03 00 00 */	cmplwi r3, 0
/* 801AB6D4 001A8614  41 82 00 08 */	beq .L_801AB6DC
/* 801AB6D8 001A8618  93 E3 00 C4 */	stw r31, 0xc4(r3)
.L_801AB6DC:
/* 801AB6DC 001A861C  83 FF 00 64 */	lwz r31, 0x64(r31)
.L_801AB6E0:
/* 801AB6E0 001A8620  28 1F 00 00 */	cmplwi r31, 0
/* 801AB6E4 001A8624  40 82 FE E8 */	bne .L_801AB5CC
/* 801AB6E8 001A8628  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AB6EC 001A862C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AB6F0 001A8630  7C 08 03 A6 */	mtlr r0
/* 801AB6F4 001A8634  38 21 00 10 */	addi r1, r1, 0x10
/* 801AB6F8 001A8638  4E 80 00 20 */	blr 
.endfn generate__Q24Game12GeneratorMgrFv

.fn setDayLimit__Q24Game12GeneratorMgrFi, global
/* 801AB6FC 001A863C  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801AB700 001A8640  48 00 00 0C */	b .L_801AB70C
.L_801AB704:
/* 801AB704 001A8644  90 83 00 84 */	stw r4, 0x84(r3)
/* 801AB708 001A8648  80 63 00 64 */	lwz r3, 0x64(r3)
.L_801AB70C:
/* 801AB70C 001A864C  28 03 00 00 */	cmplwi r3, 0
/* 801AB710 001A8650  40 82 FF F4 */	bne .L_801AB704
/* 801AB714 001A8654  4E 80 00 20 */	blr 
.endfn setDayLimit__Q24Game12GeneratorMgrFi

.fn updateUseList__Q24Game12GeneratorMgrFv, global
/* 801AB718 001A8658  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AB71C 001A865C  7C 08 02 A6 */	mflr r0
/* 801AB720 001A8660  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AB724 001A8664  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AB728 001A8668  83 E3 00 30 */	lwz r31, 0x30(r3)
/* 801AB72C 001A866C  48 00 00 68 */	b .L_801AB794
.L_801AB730:
/* 801AB730 001A8670  80 9F 00 84 */	lwz r4, 0x84(r31)
/* 801AB734 001A8674  2C 04 FF FF */	cmpwi r4, -1
/* 801AB738 001A8678  40 82 00 0C */	bne .L_801AB744
/* 801AB73C 001A867C  38 00 00 00 */	li r0, 0
/* 801AB740 001A8680  48 00 00 24 */	b .L_801AB764
.L_801AB744:
/* 801AB744 001A8684  80 6D 93 E8 */	lwz r3, gameSystem__4Game@sda21(r13)
/* 801AB748 001A8688  80 63 00 40 */	lwz r3, 0x40(r3)
/* 801AB74C 001A868C  80 03 02 18 */	lwz r0, 0x218(r3)
/* 801AB750 001A8690  7C 04 00 40 */	cmplw r4, r0
/* 801AB754 001A8694  40 80 00 0C */	bge .L_801AB760
/* 801AB758 001A8698  38 00 00 01 */	li r0, 1
/* 801AB75C 001A869C  48 00 00 08 */	b .L_801AB764
.L_801AB760:
/* 801AB760 001A86A0  38 00 00 00 */	li r0, 0
.L_801AB764:
/* 801AB764 001A86A4  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 801AB768 001A86A8  40 82 00 28 */	bne .L_801AB790
/* 801AB76C 001A86AC  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AB770 001A86B0  28 03 00 00 */	cmplwi r3, 0
/* 801AB774 001A86B4  41 82 00 1C */	beq .L_801AB790
/* 801AB778 001A86B8  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801AB77C 001A86BC  7F E4 FB 78 */	mr r4, r31
/* 801AB780 001A86C0  38 A0 00 01 */	li r5, 1
/* 801AB784 001A86C4  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 801AB788 001A86C8  7D 89 03 A6 */	mtctr r12
/* 801AB78C 001A86CC  4E 80 04 21 */	bctrl 
.L_801AB790:
/* 801AB790 001A86D0  83 FF 00 64 */	lwz r31, 0x64(r31)
.L_801AB794:
/* 801AB794 001A86D4  28 1F 00 00 */	cmplwi r31, 0
/* 801AB798 001A86D8  40 82 FF 98 */	bne .L_801AB730
/* 801AB79C 001A86DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AB7A0 001A86E0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AB7A4 001A86E4  7C 08 03 A6 */	mtlr r0
/* 801AB7A8 001A86E8  38 21 00 10 */	addi r1, r1, 0x10
/* 801AB7AC 001A86EC  4E 80 00 20 */	blr 
.endfn updateUseList__Q24Game12GeneratorMgrFv

.fn getNext__Q24Game12GeneratorMgrFv, weak
/* 801AB7B0 001A86F0  80 63 00 18 */	lwz r3, 0x18(r3)
/* 801AB7B4 001A86F4  4E 80 00 20 */	blr 
.endfn getNext__Q24Game12GeneratorMgrFv

.fn getChild__Q24Game12GeneratorMgrFv, weak
/* 801AB7B8 001A86F8  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 801AB7BC 001A86FC  4E 80 00 20 */	blr 
.endfn getChild__Q24Game12GeneratorMgrFv

.fn "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>", global
/* 801AB7C0 001A8700  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801AB7C4 001A8704  7C 08 02 A6 */	mflr r0
/* 801AB7C8 001A8708  90 01 00 24 */	stw r0, 0x24(r1)
/* 801AB7CC 001A870C  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 801AB7D0 001A8710  7C 9F 23 78 */	mr r31, r4
/* 801AB7D4 001A8714  7C 7B 1B 78 */	mr r27, r3
/* 801AB7D8 001A8718  C0 04 00 00 */	lfs f0, 0(r4)
/* 801AB7DC 001A871C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801AB7E0 001A8720  C0 04 00 04 */	lfs f0, 4(r4)
/* 801AB7E4 001A8724  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 801AB7E8 001A8728  C0 04 00 08 */	lfs f0, 8(r4)
/* 801AB7EC 001A872C  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 801AB7F0 001A8730  83 A3 00 1C */	lwz r29, 0x1c(r3)
/* 801AB7F4 001A8734  28 1D 00 00 */	cmplwi r29, 0
/* 801AB7F8 001A8738  41 82 01 F4 */	beq .L_801AB9EC
/* 801AB7FC 001A873C  C0 1F 00 00 */	lfs f0, 0(r31)
/* 801AB800 001A8740  D0 1D 00 24 */	stfs f0, 0x24(r29)
/* 801AB804 001A8744  C0 1F 00 04 */	lfs f0, 4(r31)
/* 801AB808 001A8748  D0 1D 00 28 */	stfs f0, 0x28(r29)
/* 801AB80C 001A874C  C0 1F 00 08 */	lfs f0, 8(r31)
/* 801AB810 001A8750  D0 1D 00 2C */	stfs f0, 0x2c(r29)
/* 801AB814 001A8754  83 9D 00 1C */	lwz r28, 0x1c(r29)
/* 801AB818 001A8758  28 1C 00 00 */	cmplwi r28, 0
/* 801AB81C 001A875C  41 82 00 E4 */	beq .L_801AB900
/* 801AB820 001A8760  C0 1F 00 00 */	lfs f0, 0(r31)
/* 801AB824 001A8764  D0 1C 00 24 */	stfs f0, 0x24(r28)
/* 801AB828 001A8768  C0 1F 00 04 */	lfs f0, 4(r31)
/* 801AB82C 001A876C  D0 1C 00 28 */	stfs f0, 0x28(r28)
/* 801AB830 001A8770  C0 1F 00 08 */	lfs f0, 8(r31)
/* 801AB834 001A8774  D0 1C 00 2C */	stfs f0, 0x2c(r28)
/* 801AB838 001A8778  80 1C 00 1C */	lwz r0, 0x1c(r28)
/* 801AB83C 001A877C  28 00 00 00 */	cmplwi r0, 0
/* 801AB840 001A8780  41 82 00 5C */	beq .L_801AB89C
/* 801AB844 001A8784  7F 83 E3 78 */	mr r3, r28
/* 801AB848 001A8788  4B FF FF 71 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB84C 001A878C  7C 7E 1B 78 */	mr r30, r3
/* 801AB850 001A8790  7F E4 FB 78 */	mr r4, r31
/* 801AB854 001A8794  38 7E 00 24 */	addi r3, r30, 0x24
/* 801AB858 001A8798  48 00 03 A5 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801AB85C 001A879C  7F C3 F3 78 */	mr r3, r30
/* 801AB860 001A87A0  4B FF FF 59 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB864 001A87A4  28 03 00 00 */	cmplwi r3, 0
/* 801AB868 001A87A8  41 82 00 14 */	beq .L_801AB87C
/* 801AB86C 001A87AC  7F C3 F3 78 */	mr r3, r30
/* 801AB870 001A87B0  4B FF FF 49 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB874 001A87B4  7F E4 FB 78 */	mr r4, r31
/* 801AB878 001A87B8  4B FF FF 49 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB87C:
/* 801AB87C 001A87BC  7F C3 F3 78 */	mr r3, r30
/* 801AB880 001A87C0  4B FF FF 31 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB884 001A87C4  28 03 00 00 */	cmplwi r3, 0
/* 801AB888 001A87C8  41 82 00 14 */	beq .L_801AB89C
/* 801AB88C 001A87CC  7F C3 F3 78 */	mr r3, r30
/* 801AB890 001A87D0  4B FF FF 21 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB894 001A87D4  7F E4 FB 78 */	mr r4, r31
/* 801AB898 001A87D8  4B FF FF 29 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB89C:
/* 801AB89C 001A87DC  80 1C 00 18 */	lwz r0, 0x18(r28)
/* 801AB8A0 001A87E0  28 00 00 00 */	cmplwi r0, 0
/* 801AB8A4 001A87E4  41 82 00 5C */	beq .L_801AB900
/* 801AB8A8 001A87E8  7F 83 E3 78 */	mr r3, r28
/* 801AB8AC 001A87EC  4B FF FF 05 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB8B0 001A87F0  7C 7E 1B 78 */	mr r30, r3
/* 801AB8B4 001A87F4  7F E4 FB 78 */	mr r4, r31
/* 801AB8B8 001A87F8  38 7E 00 24 */	addi r3, r30, 0x24
/* 801AB8BC 001A87FC  48 00 03 41 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801AB8C0 001A8800  7F C3 F3 78 */	mr r3, r30
/* 801AB8C4 001A8804  4B FF FE F5 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB8C8 001A8808  28 03 00 00 */	cmplwi r3, 0
/* 801AB8CC 001A880C  41 82 00 14 */	beq .L_801AB8E0
/* 801AB8D0 001A8810  7F C3 F3 78 */	mr r3, r30
/* 801AB8D4 001A8814  4B FF FE E5 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB8D8 001A8818  7F E4 FB 78 */	mr r4, r31
/* 801AB8DC 001A881C  4B FF FE E5 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB8E0:
/* 801AB8E0 001A8820  7F C3 F3 78 */	mr r3, r30
/* 801AB8E4 001A8824  4B FF FE CD */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB8E8 001A8828  28 03 00 00 */	cmplwi r3, 0
/* 801AB8EC 001A882C  41 82 00 14 */	beq .L_801AB900
/* 801AB8F0 001A8830  7F C3 F3 78 */	mr r3, r30
/* 801AB8F4 001A8834  4B FF FE BD */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB8F8 001A8838  7F E4 FB 78 */	mr r4, r31
/* 801AB8FC 001A883C  4B FF FE C5 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB900:
/* 801AB900 001A8840  83 9D 00 18 */	lwz r28, 0x18(r29)
/* 801AB904 001A8844  28 1C 00 00 */	cmplwi r28, 0
/* 801AB908 001A8848  41 82 00 E4 */	beq .L_801AB9EC
/* 801AB90C 001A884C  C0 1F 00 00 */	lfs f0, 0(r31)
/* 801AB910 001A8850  D0 1C 00 24 */	stfs f0, 0x24(r28)
/* 801AB914 001A8854  C0 1F 00 04 */	lfs f0, 4(r31)
/* 801AB918 001A8858  D0 1C 00 28 */	stfs f0, 0x28(r28)
/* 801AB91C 001A885C  C0 1F 00 08 */	lfs f0, 8(r31)
/* 801AB920 001A8860  D0 1C 00 2C */	stfs f0, 0x2c(r28)
/* 801AB924 001A8864  80 1C 00 1C */	lwz r0, 0x1c(r28)
/* 801AB928 001A8868  28 00 00 00 */	cmplwi r0, 0
/* 801AB92C 001A886C  41 82 00 5C */	beq .L_801AB988
/* 801AB930 001A8870  7F 83 E3 78 */	mr r3, r28
/* 801AB934 001A8874  4B FF FE 85 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB938 001A8878  7C 7E 1B 78 */	mr r30, r3
/* 801AB93C 001A887C  7F E4 FB 78 */	mr r4, r31
/* 801AB940 001A8880  38 7E 00 24 */	addi r3, r30, 0x24
/* 801AB944 001A8884  48 00 02 B9 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801AB948 001A8888  7F C3 F3 78 */	mr r3, r30
/* 801AB94C 001A888C  4B FF FE 6D */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB950 001A8890  28 03 00 00 */	cmplwi r3, 0
/* 801AB954 001A8894  41 82 00 14 */	beq .L_801AB968
/* 801AB958 001A8898  7F C3 F3 78 */	mr r3, r30
/* 801AB95C 001A889C  4B FF FE 5D */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB960 001A88A0  7F E4 FB 78 */	mr r4, r31
/* 801AB964 001A88A4  4B FF FE 5D */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB968:
/* 801AB968 001A88A8  7F C3 F3 78 */	mr r3, r30
/* 801AB96C 001A88AC  4B FF FE 45 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB970 001A88B0  28 03 00 00 */	cmplwi r3, 0
/* 801AB974 001A88B4  41 82 00 14 */	beq .L_801AB988
/* 801AB978 001A88B8  7F C3 F3 78 */	mr r3, r30
/* 801AB97C 001A88BC  4B FF FE 35 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB980 001A88C0  7F E4 FB 78 */	mr r4, r31
/* 801AB984 001A88C4  4B FF FE 3D */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB988:
/* 801AB988 001A88C8  80 1C 00 18 */	lwz r0, 0x18(r28)
/* 801AB98C 001A88CC  28 00 00 00 */	cmplwi r0, 0
/* 801AB990 001A88D0  41 82 00 5C */	beq .L_801AB9EC
/* 801AB994 001A88D4  7F 83 E3 78 */	mr r3, r28
/* 801AB998 001A88D8  4B FF FE 19 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB99C 001A88DC  7C 7E 1B 78 */	mr r30, r3
/* 801AB9A0 001A88E0  7F E4 FB 78 */	mr r4, r31
/* 801AB9A4 001A88E4  38 7E 00 24 */	addi r3, r30, 0x24
/* 801AB9A8 001A88E8  48 00 02 55 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801AB9AC 001A88EC  7F C3 F3 78 */	mr r3, r30
/* 801AB9B0 001A88F0  4B FF FE 09 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB9B4 001A88F4  28 03 00 00 */	cmplwi r3, 0
/* 801AB9B8 001A88F8  41 82 00 14 */	beq .L_801AB9CC
/* 801AB9BC 001A88FC  7F C3 F3 78 */	mr r3, r30
/* 801AB9C0 001A8900  4B FF FD F9 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801AB9C4 001A8904  7F E4 FB 78 */	mr r4, r31
/* 801AB9C8 001A8908  4B FF FD F9 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB9CC:
/* 801AB9CC 001A890C  7F C3 F3 78 */	mr r3, r30
/* 801AB9D0 001A8910  4B FF FD E1 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB9D4 001A8914  28 03 00 00 */	cmplwi r3, 0
/* 801AB9D8 001A8918  41 82 00 14 */	beq .L_801AB9EC
/* 801AB9DC 001A891C  7F C3 F3 78 */	mr r3, r30
/* 801AB9E0 001A8920  4B FF FD D1 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801AB9E4 001A8924  7F E4 FB 78 */	mr r4, r31
/* 801AB9E8 001A8928  4B FF FD D9 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801AB9EC:
/* 801AB9EC 001A892C  83 9B 00 18 */	lwz r28, 0x18(r27)
/* 801AB9F0 001A8930  28 1C 00 00 */	cmplwi r28, 0
/* 801AB9F4 001A8934  41 82 01 F4 */	beq .L_801ABBE8
/* 801AB9F8 001A8938  C0 1F 00 00 */	lfs f0, 0(r31)
/* 801AB9FC 001A893C  D0 1C 00 24 */	stfs f0, 0x24(r28)
/* 801ABA00 001A8940  C0 1F 00 04 */	lfs f0, 4(r31)
/* 801ABA04 001A8944  D0 1C 00 28 */	stfs f0, 0x28(r28)
/* 801ABA08 001A8948  C0 1F 00 08 */	lfs f0, 8(r31)
/* 801ABA0C 001A894C  D0 1C 00 2C */	stfs f0, 0x2c(r28)
/* 801ABA10 001A8950  83 BC 00 1C */	lwz r29, 0x1c(r28)
/* 801ABA14 001A8954  28 1D 00 00 */	cmplwi r29, 0
/* 801ABA18 001A8958  41 82 00 E4 */	beq .L_801ABAFC
/* 801ABA1C 001A895C  C0 1F 00 00 */	lfs f0, 0(r31)
/* 801ABA20 001A8960  D0 1D 00 24 */	stfs f0, 0x24(r29)
/* 801ABA24 001A8964  C0 1F 00 04 */	lfs f0, 4(r31)
/* 801ABA28 001A8968  D0 1D 00 28 */	stfs f0, 0x28(r29)
/* 801ABA2C 001A896C  C0 1F 00 08 */	lfs f0, 8(r31)
/* 801ABA30 001A8970  D0 1D 00 2C */	stfs f0, 0x2c(r29)
/* 801ABA34 001A8974  80 1D 00 1C */	lwz r0, 0x1c(r29)
/* 801ABA38 001A8978  28 00 00 00 */	cmplwi r0, 0
/* 801ABA3C 001A897C  41 82 00 5C */	beq .L_801ABA98
/* 801ABA40 001A8980  7F A3 EB 78 */	mr r3, r29
/* 801ABA44 001A8984  4B FF FD 75 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABA48 001A8988  7C 7E 1B 78 */	mr r30, r3
/* 801ABA4C 001A898C  7F E4 FB 78 */	mr r4, r31
/* 801ABA50 001A8990  38 7E 00 24 */	addi r3, r30, 0x24
/* 801ABA54 001A8994  48 00 01 A9 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801ABA58 001A8998  7F C3 F3 78 */	mr r3, r30
/* 801ABA5C 001A899C  4B FF FD 5D */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABA60 001A89A0  28 03 00 00 */	cmplwi r3, 0
/* 801ABA64 001A89A4  41 82 00 14 */	beq .L_801ABA78
/* 801ABA68 001A89A8  7F C3 F3 78 */	mr r3, r30
/* 801ABA6C 001A89AC  4B FF FD 4D */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABA70 001A89B0  7F E4 FB 78 */	mr r4, r31
/* 801ABA74 001A89B4  4B FF FD 4D */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABA78:
/* 801ABA78 001A89B8  7F C3 F3 78 */	mr r3, r30
/* 801ABA7C 001A89BC  4B FF FD 35 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABA80 001A89C0  28 03 00 00 */	cmplwi r3, 0
/* 801ABA84 001A89C4  41 82 00 14 */	beq .L_801ABA98
/* 801ABA88 001A89C8  7F C3 F3 78 */	mr r3, r30
/* 801ABA8C 001A89CC  4B FF FD 25 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABA90 001A89D0  7F E4 FB 78 */	mr r4, r31
/* 801ABA94 001A89D4  4B FF FD 2D */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABA98:
/* 801ABA98 001A89D8  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 801ABA9C 001A89DC  28 00 00 00 */	cmplwi r0, 0
/* 801ABAA0 001A89E0  41 82 00 5C */	beq .L_801ABAFC
/* 801ABAA4 001A89E4  7F A3 EB 78 */	mr r3, r29
/* 801ABAA8 001A89E8  4B FF FD 09 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABAAC 001A89EC  7C 7E 1B 78 */	mr r30, r3
/* 801ABAB0 001A89F0  7F E4 FB 78 */	mr r4, r31
/* 801ABAB4 001A89F4  38 7E 00 24 */	addi r3, r30, 0x24
/* 801ABAB8 001A89F8  48 00 01 45 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801ABABC 001A89FC  7F C3 F3 78 */	mr r3, r30
/* 801ABAC0 001A8A00  4B FF FC F9 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABAC4 001A8A04  28 03 00 00 */	cmplwi r3, 0
/* 801ABAC8 001A8A08  41 82 00 14 */	beq .L_801ABADC
/* 801ABACC 001A8A0C  7F C3 F3 78 */	mr r3, r30
/* 801ABAD0 001A8A10  4B FF FC E9 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABAD4 001A8A14  7F E4 FB 78 */	mr r4, r31
/* 801ABAD8 001A8A18  4B FF FC E9 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABADC:
/* 801ABADC 001A8A1C  7F C3 F3 78 */	mr r3, r30
/* 801ABAE0 001A8A20  4B FF FC D1 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABAE4 001A8A24  28 03 00 00 */	cmplwi r3, 0
/* 801ABAE8 001A8A28  41 82 00 14 */	beq .L_801ABAFC
/* 801ABAEC 001A8A2C  7F C3 F3 78 */	mr r3, r30
/* 801ABAF0 001A8A30  4B FF FC C1 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABAF4 001A8A34  7F E4 FB 78 */	mr r4, r31
/* 801ABAF8 001A8A38  4B FF FC C9 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABAFC:
/* 801ABAFC 001A8A3C  83 9C 00 18 */	lwz r28, 0x18(r28)
/* 801ABB00 001A8A40  28 1C 00 00 */	cmplwi r28, 0
/* 801ABB04 001A8A44  41 82 00 E4 */	beq .L_801ABBE8
/* 801ABB08 001A8A48  C0 1F 00 00 */	lfs f0, 0(r31)
/* 801ABB0C 001A8A4C  D0 1C 00 24 */	stfs f0, 0x24(r28)
/* 801ABB10 001A8A50  C0 1F 00 04 */	lfs f0, 4(r31)
/* 801ABB14 001A8A54  D0 1C 00 28 */	stfs f0, 0x28(r28)
/* 801ABB18 001A8A58  C0 1F 00 08 */	lfs f0, 8(r31)
/* 801ABB1C 001A8A5C  D0 1C 00 2C */	stfs f0, 0x2c(r28)
/* 801ABB20 001A8A60  80 1C 00 1C */	lwz r0, 0x1c(r28)
/* 801ABB24 001A8A64  28 00 00 00 */	cmplwi r0, 0
/* 801ABB28 001A8A68  41 82 00 5C */	beq .L_801ABB84
/* 801ABB2C 001A8A6C  7F 83 E3 78 */	mr r3, r28
/* 801ABB30 001A8A70  4B FF FC 89 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABB34 001A8A74  7C 7E 1B 78 */	mr r30, r3
/* 801ABB38 001A8A78  7F E4 FB 78 */	mr r4, r31
/* 801ABB3C 001A8A7C  38 7E 00 24 */	addi r3, r30, 0x24
/* 801ABB40 001A8A80  48 00 00 BD */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801ABB44 001A8A84  7F C3 F3 78 */	mr r3, r30
/* 801ABB48 001A8A88  4B FF FC 71 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABB4C 001A8A8C  28 03 00 00 */	cmplwi r3, 0
/* 801ABB50 001A8A90  41 82 00 14 */	beq .L_801ABB64
/* 801ABB54 001A8A94  7F C3 F3 78 */	mr r3, r30
/* 801ABB58 001A8A98  4B FF FC 61 */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABB5C 001A8A9C  7F E4 FB 78 */	mr r4, r31
/* 801ABB60 001A8AA0  4B FF FC 61 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABB64:
/* 801ABB64 001A8AA4  7F C3 F3 78 */	mr r3, r30
/* 801ABB68 001A8AA8  4B FF FC 49 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABB6C 001A8AAC  28 03 00 00 */	cmplwi r3, 0
/* 801ABB70 001A8AB0  41 82 00 14 */	beq .L_801ABB84
/* 801ABB74 001A8AB4  7F C3 F3 78 */	mr r3, r30
/* 801ABB78 001A8AB8  4B FF FC 39 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABB7C 001A8ABC  7F E4 FB 78 */	mr r4, r31
/* 801ABB80 001A8AC0  4B FF FC 41 */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABB84:
/* 801ABB84 001A8AC4  80 1C 00 18 */	lwz r0, 0x18(r28)
/* 801ABB88 001A8AC8  28 00 00 00 */	cmplwi r0, 0
/* 801ABB8C 001A8ACC  41 82 00 5C */	beq .L_801ABBE8
/* 801ABB90 001A8AD0  7F 83 E3 78 */	mr r3, r28
/* 801ABB94 001A8AD4  4B FF FC 1D */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABB98 001A8AD8  7C 7E 1B 78 */	mr r30, r3
/* 801ABB9C 001A8ADC  7F E4 FB 78 */	mr r4, r31
/* 801ABBA0 001A8AE0  38 7E 00 24 */	addi r3, r30, 0x24
/* 801ABBA4 001A8AE4  48 00 00 59 */	bl "__as__10Vector3<f>FRC10Vector3<f>"
/* 801ABBA8 001A8AE8  7F C3 F3 78 */	mr r3, r30
/* 801ABBAC 001A8AEC  4B FF FC 0D */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABBB0 001A8AF0  28 03 00 00 */	cmplwi r3, 0
/* 801ABBB4 001A8AF4  41 82 00 14 */	beq .L_801ABBC8
/* 801ABBB8 001A8AF8  7F C3 F3 78 */	mr r3, r30
/* 801ABBBC 001A8AFC  4B FF FB FD */	bl getChild__Q24Game12GeneratorMgrFv
/* 801ABBC0 001A8B00  7F E4 FB 78 */	mr r4, r31
/* 801ABBC4 001A8B04  4B FF FB FD */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABBC8:
/* 801ABBC8 001A8B08  7F C3 F3 78 */	mr r3, r30
/* 801ABBCC 001A8B0C  4B FF FB E5 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABBD0 001A8B10  28 03 00 00 */	cmplwi r3, 0
/* 801ABBD4 001A8B14  41 82 00 14 */	beq .L_801ABBE8
/* 801ABBD8 001A8B18  7F C3 F3 78 */	mr r3, r30
/* 801ABBDC 001A8B1C  4B FF FB D5 */	bl getNext__Q24Game12GeneratorMgrFv
/* 801ABBE0 001A8B20  7F E4 FB 78 */	mr r4, r31
/* 801ABBE4 001A8B24  4B FF FB DD */	bl "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"
.L_801ABBE8:
/* 801ABBE8 001A8B28  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 801ABBEC 001A8B2C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801ABBF0 001A8B30  7C 08 03 A6 */	mtlr r0
/* 801ABBF4 001A8B34  38 21 00 20 */	addi r1, r1, 0x20
/* 801ABBF8 001A8B38  4E 80 00 20 */	blr 
.endfn "updateCursorPos__Q24Game12GeneratorMgrFR10Vector3<f>"

.fn "__as__10Vector3<f>FRC10Vector3<f>", weak
/* 801ABBFC 001A8B3C  C0 04 00 00 */	lfs f0, 0(r4)
/* 801ABC00 001A8B40  C0 24 00 04 */	lfs f1, 4(r4)
/* 801ABC04 001A8B44  D0 03 00 00 */	stfs f0, 0(r3)
/* 801ABC08 001A8B48  C0 04 00 08 */	lfs f0, 8(r4)
/* 801ABC0C 001A8B4C  D0 23 00 04 */	stfs f1, 4(r3)
/* 801ABC10 001A8B50  D0 03 00 08 */	stfs f0, 8(r3)
/* 801ABC14 001A8B54  4E 80 00 20 */	blr 
.endfn "__as__10Vector3<f>FRC10Vector3<f>"

.fn read__Q24Game12GeneratorMgrFR6Streamb, global
/* 801ABC18 001A8B58  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801ABC1C 001A8B5C  7C 08 02 A6 */	mflr r0
/* 801ABC20 001A8B60  90 01 00 24 */	stw r0, 0x24(r1)
/* 801ABC24 001A8B64  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801ABC28 001A8B68  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801ABC2C 001A8B6C  7C 9E 23 78 */	mr r30, r4
/* 801ABC30 001A8B70  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801ABC34 001A8B74  7C 7D 1B 78 */	mr r29, r3
/* 801ABC38 001A8B78  93 81 00 10 */	stw r28, 0x10(r1)
/* 801ABC3C 001A8B7C  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801ABC40 001A8B80  28 03 00 00 */	cmplwi r3, 0
/* 801ABC44 001A8B84  41 82 00 24 */	beq .L_801ABC68
/* 801ABC48 001A8B88  41 82 00 18 */	beq .L_801ABC60
/* 801ABC4C 001A8B8C  81 83 00 00 */	lwz r12, 0(r3)
/* 801ABC50 001A8B90  38 80 00 01 */	li r4, 1
/* 801ABC54 001A8B94  81 8C 00 08 */	lwz r12, 8(r12)
/* 801ABC58 001A8B98  7D 89 03 A6 */	mtctr r12
/* 801ABC5C 001A8B9C  4E 80 04 21 */	bctrl 
.L_801ABC60:
/* 801ABC60 001A8BA0  38 00 00 00 */	li r0, 0
/* 801ABC64 001A8BA4  90 1D 00 4C */	stw r0, 0x4c(r29)
.L_801ABC68:
/* 801ABC68 001A8BA8  7F C4 F3 78 */	mr r4, r30
/* 801ABC6C 001A8BAC  38 7D 00 40 */	addi r3, r29, 0x40
/* 801ABC70 001A8BB0  48 26 78 81 */	bl read__4ID32FR6Stream
/* 801ABC74 001A8BB4  3C 80 76 30 */	lis r4, 0x76302E30@ha
/* 801ABC78 001A8BB8  38 7D 00 40 */	addi r3, r29, 0x40
/* 801ABC7C 001A8BBC  38 84 2E 30 */	addi r4, r4, 0x76302E30@l
/* 801ABC80 001A8BC0  48 26 77 B5 */	bl __eq__4ID32FUl
/* 801ABC84 001A8BC4  7F C3 F3 78 */	mr r3, r30
/* 801ABC88 001A8BC8  48 26 91 25 */	bl readFloat__6StreamFv
/* 801ABC8C 001A8BCC  D0 3D 00 5C */	stfs f1, 0x5c(r29)
/* 801ABC90 001A8BD0  7F C3 F3 78 */	mr r3, r30
/* 801ABC94 001A8BD4  48 26 91 19 */	bl readFloat__6StreamFv
/* 801ABC98 001A8BD8  D0 3D 00 60 */	stfs f1, 0x60(r29)
/* 801ABC9C 001A8BDC  7F C3 F3 78 */	mr r3, r30
/* 801ABCA0 001A8BE0  48 26 91 0D */	bl readFloat__6StreamFv
/* 801ABCA4 001A8BE4  3C 80 76 30 */	lis r4, 0x76302E31@ha
/* 801ABCA8 001A8BE8  D0 3D 00 64 */	stfs f1, 0x64(r29)
/* 801ABCAC 001A8BEC  38 7D 00 40 */	addi r3, r29, 0x40
/* 801ABCB0 001A8BF0  38 84 2E 31 */	addi r4, r4, 0x76302E31@l
/* 801ABCB4 001A8BF4  48 26 77 81 */	bl __eq__4ID32FUl
/* 801ABCB8 001A8BF8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801ABCBC 001A8BFC  41 82 00 10 */	beq .L_801ABCCC
/* 801ABCC0 001A8C00  7F C3 F3 78 */	mr r3, r30
/* 801ABCC4 001A8C04  48 26 90 E9 */	bl readFloat__6StreamFv
/* 801ABCC8 001A8C08  D0 3D 00 68 */	stfs f1, 0x68(r29)
.L_801ABCCC:
/* 801ABCCC 001A8C0C  7F C3 F3 78 */	mr r3, r30
/* 801ABCD0 001A8C10  48 26 8D C1 */	bl readInt__6StreamFv
/* 801ABCD4 001A8C14  90 7D 00 4C */	stw r3, 0x4c(r29)
/* 801ABCD8 001A8C18  38 00 00 00 */	li r0, 0
/* 801ABCDC 001A8C1C  3B E0 00 00 */	li r31, 0
/* 801ABCE0 001A8C20  90 1D 00 30 */	stw r0, 0x30(r29)
/* 801ABCE4 001A8C24  48 00 01 F8 */	b .L_801ABEDC
.L_801ABCE8:
/* 801ABCE8 001A8C28  80 1D 00 30 */	lwz r0, 0x30(r29)
/* 801ABCEC 001A8C2C  28 00 00 00 */	cmplwi r0, 0
/* 801ABCF0 001A8C30  40 82 00 EC */	bne .L_801ABDDC
/* 801ABCF4 001A8C34  38 60 00 B4 */	li r3, 0xb4
/* 801ABCF8 001A8C38  4B E7 81 AD */	bl __nw__FUl
/* 801ABCFC 001A8C3C  7C 7C 1B 79 */	or. r28, r3, r3
/* 801ABD00 001A8C40  41 82 00 B4 */	beq .L_801ABDB4
/* 801ABD04 001A8C44  48 26 56 8D */	bl __ct__5CNodeFv
/* 801ABD08 001A8C48  3C 80 80 4B */	lis r4, __vt__Q24Game9Generator@ha
/* 801ABD0C 001A8C4C  38 7C 00 40 */	addi r3, r28, 0x40
/* 801ABD10 001A8C50  38 04 56 1C */	addi r0, r4, __vt__Q24Game9Generator@l
/* 801ABD14 001A8C54  90 1C 00 00 */	stw r0, 0(r28)
/* 801ABD18 001A8C58  48 26 75 59 */	bl __ct__4ID32Fv
/* 801ABD1C 001A8C5C  38 7C 00 4C */	addi r3, r28, 0x4c
/* 801ABD20 001A8C60  48 26 75 51 */	bl __ct__4ID32Fv
/* 801ABD24 001A8C64  C0 02 AE F8 */	lfs f0, lbl_80519258@sda21(r2)
/* 801ABD28 001A8C68  3C 60 5F 5F */	lis r3, 0x5F5F5F5F@ha
/* 801ABD2C 001A8C6C  3C 80 20 20 */	lis r4, 0x20202020@ha
/* 801ABD30 001A8C70  38 A0 00 00 */	li r5, 0
/* 801ABD34 001A8C74  D0 1C 00 94 */	stfs f0, 0x94(r28)
/* 801ABD38 001A8C78  38 03 5F 5F */	addi r0, r3, 0x5F5F5F5F@l
/* 801ABD3C 001A8C7C  38 7C 00 40 */	addi r3, r28, 0x40
/* 801ABD40 001A8C80  38 84 20 20 */	addi r4, r4, 0x20202020@l
/* 801ABD44 001A8C84  D0 1C 00 98 */	stfs f0, 0x98(r28)
/* 801ABD48 001A8C88  D0 1C 00 9C */	stfs f0, 0x9c(r28)
/* 801ABD4C 001A8C8C  90 BC 00 18 */	stw r5, 0x18(r28)
/* 801ABD50 001A8C90  90 1C 00 1C */	stw r0, 0x1c(r28)
/* 801ABD54 001A8C94  B0 BC 00 5C */	sth r5, 0x5c(r28)
/* 801ABD58 001A8C98  48 26 75 81 */	bl setID__4ID32FUl
/* 801ABD5C 001A8C9C  80 8D 84 38 */	lwz r4, GeneratorCurrentVersion@sda21(r13)
/* 801ABD60 001A8CA0  38 7C 00 4C */	addi r3, r28, 0x4c
/* 801ABD64 001A8CA4  48 26 75 75 */	bl setID__4ID32FUl
/* 801ABD68 001A8CA8  38 7C 00 20 */	addi r3, r28, 0x20
/* 801ABD6C 001A8CAC  38 82 AE FC */	addi r4, r2, lbl_8051925C@sda21
/* 801ABD70 001A8CB0  4B F1 EA E9 */	bl strcpy
/* 801ABD74 001A8CB4  38 80 00 00 */	li r4, 0
/* 801ABD78 001A8CB8  38 60 00 01 */	li r3, 1
/* 801ABD7C 001A8CBC  90 9C 00 64 */	stw r4, 0x64(r28)
/* 801ABD80 001A8CC0  38 00 FF FF */	li r0, -1
/* 801ABD84 001A8CC4  90 9C 00 60 */	stw r4, 0x60(r28)
/* 801ABD88 001A8CC8  90 9C 00 6C */	stw r4, 0x6c(r28)
/* 801ABD8C 001A8CCC  90 9C 00 7C */	stw r4, 0x7c(r28)
/* 801ABD90 001A8CD0  90 9C 00 10 */	stw r4, 0x10(r28)
/* 801ABD94 001A8CD4  90 9C 00 0C */	stw r4, 0xc(r28)
/* 801ABD98 001A8CD8  90 9C 00 08 */	stw r4, 8(r28)
/* 801ABD9C 001A8CDC  90 9C 00 04 */	stw r4, 4(r28)
/* 801ABDA0 001A8CE0  98 7C 00 AC */	stb r3, 0xac(r28)
/* 801ABDA4 001A8CE4  90 1C 00 84 */	stw r0, 0x84(r28)
/* 801ABDA8 001A8CE8  90 9C 00 74 */	stw r4, 0x74(r28)
/* 801ABDAC 001A8CEC  90 9C 00 78 */	stw r4, 0x78(r28)
/* 801ABDB0 001A8CF0  90 9C 00 70 */	stw r4, 0x70(r28)
.L_801ABDB4:
/* 801ABDB4 001A8CF4  93 9D 00 30 */	stw r28, 0x30(r29)
/* 801ABDB8 001A8CF8  7F C4 F3 78 */	mr r4, r30
/* 801ABDBC 001A8CFC  80 7D 00 30 */	lwz r3, 0x30(r29)
/* 801ABDC0 001A8D00  4B FF EF 59 */	bl read__Q24Game9GeneratorFR6Stream
/* 801ABDC4 001A8D04  80 7D 00 30 */	lwz r3, 0x30(r29)
/* 801ABDC8 001A8D08  93 A3 00 68 */	stw r29, 0x68(r3)
/* 801ABDCC 001A8D0C  80 6D 94 C0 */	lwz r3, generatorCache__4Game@sda21(r13)
/* 801ABDD0 001A8D10  80 9D 00 30 */	lwz r4, 0x30(r29)
/* 801ABDD4 001A8D14  48 04 5C CD */	bl addGenerator__Q24Game14GeneratorCacheFPQ24Game9Generator
/* 801ABDD8 001A8D18  48 00 01 00 */	b .L_801ABED8
.L_801ABDDC:
/* 801ABDDC 001A8D1C  38 60 00 B4 */	li r3, 0xb4
/* 801ABDE0 001A8D20  4B E7 80 C5 */	bl __nw__FUl
/* 801ABDE4 001A8D24  7C 7C 1B 79 */	or. r28, r3, r3
/* 801ABDE8 001A8D28  41 82 00 B4 */	beq .L_801ABE9C
/* 801ABDEC 001A8D2C  48 26 55 A5 */	bl __ct__5CNodeFv
/* 801ABDF0 001A8D30  3C 80 80 4B */	lis r4, __vt__Q24Game9Generator@ha
/* 801ABDF4 001A8D34  38 7C 00 40 */	addi r3, r28, 0x40
/* 801ABDF8 001A8D38  38 04 56 1C */	addi r0, r4, __vt__Q24Game9Generator@l
/* 801ABDFC 001A8D3C  90 1C 00 00 */	stw r0, 0(r28)
/* 801ABE00 001A8D40  48 26 74 71 */	bl __ct__4ID32Fv
/* 801ABE04 001A8D44  38 7C 00 4C */	addi r3, r28, 0x4c
/* 801ABE08 001A8D48  48 26 74 69 */	bl __ct__4ID32Fv
/* 801ABE0C 001A8D4C  C0 02 AE F8 */	lfs f0, lbl_80519258@sda21(r2)
/* 801ABE10 001A8D50  3C 60 5F 5F */	lis r3, 0x5F5F5F5F@ha
/* 801ABE14 001A8D54  3C 80 20 20 */	lis r4, 0x20202020@ha
/* 801ABE18 001A8D58  38 A0 00 00 */	li r5, 0
/* 801ABE1C 001A8D5C  D0 1C 00 94 */	stfs f0, 0x94(r28)
/* 801ABE20 001A8D60  38 03 5F 5F */	addi r0, r3, 0x5F5F5F5F@l
/* 801ABE24 001A8D64  38 7C 00 40 */	addi r3, r28, 0x40
/* 801ABE28 001A8D68  38 84 20 20 */	addi r4, r4, 0x20202020@l
/* 801ABE2C 001A8D6C  D0 1C 00 98 */	stfs f0, 0x98(r28)
/* 801ABE30 001A8D70  D0 1C 00 9C */	stfs f0, 0x9c(r28)
/* 801ABE34 001A8D74  90 BC 00 18 */	stw r5, 0x18(r28)
/* 801ABE38 001A8D78  90 1C 00 1C */	stw r0, 0x1c(r28)
/* 801ABE3C 001A8D7C  B0 BC 00 5C */	sth r5, 0x5c(r28)
/* 801ABE40 001A8D80  48 26 74 99 */	bl setID__4ID32FUl
/* 801ABE44 001A8D84  80 8D 84 38 */	lwz r4, GeneratorCurrentVersion@sda21(r13)
/* 801ABE48 001A8D88  38 7C 00 4C */	addi r3, r28, 0x4c
/* 801ABE4C 001A8D8C  48 26 74 8D */	bl setID__4ID32FUl
/* 801ABE50 001A8D90  38 7C 00 20 */	addi r3, r28, 0x20
/* 801ABE54 001A8D94  38 82 AE FC */	addi r4, r2, lbl_8051925C@sda21
/* 801ABE58 001A8D98  4B F1 EA 01 */	bl strcpy
/* 801ABE5C 001A8D9C  38 80 00 00 */	li r4, 0
/* 801ABE60 001A8DA0  38 60 00 01 */	li r3, 1
/* 801ABE64 001A8DA4  90 9C 00 64 */	stw r4, 0x64(r28)
/* 801ABE68 001A8DA8  38 00 FF FF */	li r0, -1
/* 801ABE6C 001A8DAC  90 9C 00 60 */	stw r4, 0x60(r28)
/* 801ABE70 001A8DB0  90 9C 00 6C */	stw r4, 0x6c(r28)
/* 801ABE74 001A8DB4  90 9C 00 7C */	stw r4, 0x7c(r28)
/* 801ABE78 001A8DB8  90 9C 00 10 */	stw r4, 0x10(r28)
/* 801ABE7C 001A8DBC  90 9C 00 0C */	stw r4, 0xc(r28)
/* 801ABE80 001A8DC0  90 9C 00 08 */	stw r4, 8(r28)
/* 801ABE84 001A8DC4  90 9C 00 04 */	stw r4, 4(r28)
/* 801ABE88 001A8DC8  98 7C 00 AC */	stb r3, 0xac(r28)
/* 801ABE8C 001A8DCC  90 1C 00 84 */	stw r0, 0x84(r28)
/* 801ABE90 001A8DD0  90 9C 00 74 */	stw r4, 0x74(r28)
/* 801ABE94 001A8DD4  90 9C 00 78 */	stw r4, 0x78(r28)
/* 801ABE98 001A8DD8  90 9C 00 70 */	stw r4, 0x70(r28)
.L_801ABE9C:
/* 801ABE9C 001A8DDC  93 BC 00 68 */	stw r29, 0x68(r28)
/* 801ABEA0 001A8DE0  7F 83 E3 78 */	mr r3, r28
/* 801ABEA4 001A8DE4  7F C4 F3 78 */	mr r4, r30
/* 801ABEA8 001A8DE8  4B FF EE 71 */	bl read__Q24Game9GeneratorFR6Stream
/* 801ABEAC 001A8DEC  80 7D 00 30 */	lwz r3, 0x30(r29)
/* 801ABEB0 001A8DF0  48 00 00 08 */	b .L_801ABEB8
.L_801ABEB4:
/* 801ABEB4 001A8DF4  7C 03 03 78 */	mr r3, r0
.L_801ABEB8:
/* 801ABEB8 001A8DF8  80 03 00 64 */	lwz r0, 0x64(r3)
/* 801ABEBC 001A8DFC  28 00 00 00 */	cmplwi r0, 0
/* 801ABEC0 001A8E00  40 82 FF F4 */	bne .L_801ABEB4
/* 801ABEC4 001A8E04  93 83 00 64 */	stw r28, 0x64(r3)
/* 801ABEC8 001A8E08  7F 84 E3 78 */	mr r4, r28
/* 801ABECC 001A8E0C  90 7C 00 60 */	stw r3, 0x60(r28)
/* 801ABED0 001A8E10  80 6D 94 C0 */	lwz r3, generatorCache__4Game@sda21(r13)
/* 801ABED4 001A8E14  48 04 5B CD */	bl addGenerator__Q24Game14GeneratorCacheFPQ24Game9Generator
.L_801ABED8:
/* 801ABED8 001A8E18  3B FF 00 01 */	addi r31, r31, 1
.L_801ABEDC:
/* 801ABEDC 001A8E1C  80 1D 00 4C */	lwz r0, 0x4c(r29)
/* 801ABEE0 001A8E20  7C 1F 00 00 */	cmpw r31, r0
/* 801ABEE4 001A8E24  41 80 FE 04 */	blt .L_801ABCE8
/* 801ABEE8 001A8E28  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801ABEEC 001A8E2C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801ABEF0 001A8E30  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801ABEF4 001A8E34  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801ABEF8 001A8E38  83 81 00 10 */	lwz r28, 0x10(r1)
/* 801ABEFC 001A8E3C  7C 08 03 A6 */	mtlr r0
/* 801ABF00 001A8E40  38 21 00 20 */	addi r1, r1, 0x20
/* 801ABF04 001A8E44  4E 80 00 20 */	blr 
.endfn read__Q24Game12GeneratorMgrFR6Streamb

.fn doAnimation__Q24Game9GeneratorFv, global
/* 801ABF08 001A8E48  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 801ABF0C 001A8E4C  7C 08 02 A6 */	mflr r0
/* 801ABF10 001A8E50  90 01 00 54 */	stw r0, 0x54(r1)
/* 801ABF14 001A8E54  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 801ABF18 001A8E58  7C 7F 1B 78 */	mr r31, r3
/* 801ABF1C 001A8E5C  80 63 00 18 */	lwz r3, 0x18(r3)
/* 801ABF20 001A8E60  28 03 00 00 */	cmplwi r3, 0
/* 801ABF24 001A8E64  41 82 00 8C */	beq .L_801ABFB0
/* 801ABF28 001A8E68  80 03 00 20 */	lwz r0, 0x20(r3)
/* 801ABF2C 001A8E6C  28 00 00 00 */	cmplwi r0, 0
/* 801ABF30 001A8E70  41 82 00 80 */	beq .L_801ABFB0
/* 801ABF34 001A8E74  C0 3F 00 9C */	lfs f1, 0x9c(r31)
/* 801ABF38 001A8E78  38 81 00 14 */	addi r4, r1, 0x14
/* 801ABF3C 001A8E7C  C0 1F 00 A8 */	lfs f0, 0xa8(r31)
/* 801ABF40 001A8E80  38 A1 00 08 */	addi r5, r1, 8
/* 801ABF44 001A8E84  C0 7F 00 98 */	lfs f3, 0x98(r31)
/* 801ABF48 001A8E88  EC 81 00 2A */	fadds f4, f1, f0
/* 801ABF4C 001A8E8C  C0 5F 00 A4 */	lfs f2, 0xa4(r31)
/* 801ABF50 001A8E90  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 801ABF54 001A8E94  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 801ABF58 001A8E98  EC 43 10 2A */	fadds f2, f3, f2
/* 801ABF5C 001A8E9C  EC 01 00 2A */	fadds f0, f1, f0
/* 801ABF60 001A8EA0  D0 81 00 10 */	stfs f4, 0x10(r1)
/* 801ABF64 001A8EA4  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 801ABF68 001A8EA8  D0 01 00 08 */	stfs f0, 8(r1)
/* 801ABF6C 001A8EAC  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801ABF70 001A8EB0  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 801ABF74 001A8EB4  7D 89 03 A6 */	mtctr r12
/* 801ABF78 001A8EB8  4E 80 04 21 */	bctrl 
/* 801ABF7C 001A8EBC  80 9F 00 18 */	lwz r4, 0x18(r31)
/* 801ABF80 001A8EC0  38 61 00 14 */	addi r3, r1, 0x14
/* 801ABF84 001A8EC4  80 84 00 20 */	lwz r4, 0x20(r4)
/* 801ABF88 001A8EC8  80 84 00 08 */	lwz r4, 8(r4)
/* 801ABF8C 001A8ECC  38 84 00 24 */	addi r4, r4, 0x24
/* 801ABF90 001A8ED0  4B F3 E3 3D */	bl PSMTXCopy
/* 801ABF94 001A8ED4  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801ABF98 001A8ED8  80 63 00 20 */	lwz r3, 0x20(r3)
/* 801ABF9C 001A8EDC  80 63 00 08 */	lwz r3, 8(r3)
/* 801ABFA0 001A8EE0  81 83 00 00 */	lwz r12, 0(r3)
/* 801ABFA4 001A8EE4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801ABFA8 001A8EE8  7D 89 03 A6 */	mtctr r12
/* 801ABFAC 001A8EEC  4E 80 04 21 */	bctrl 
.L_801ABFB0:
/* 801ABFB0 001A8EF0  80 7F 00 64 */	lwz r3, 0x64(r31)
/* 801ABFB4 001A8EF4  28 03 00 00 */	cmplwi r3, 0
/* 801ABFB8 001A8EF8  41 82 00 14 */	beq .L_801ABFCC
/* 801ABFBC 001A8EFC  81 83 00 00 */	lwz r12, 0(r3)
/* 801ABFC0 001A8F00  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801ABFC4 001A8F04  7D 89 03 A6 */	mtctr r12
/* 801ABFC8 001A8F08  4E 80 04 21 */	bctrl 
.L_801ABFCC:
/* 801ABFCC 001A8F0C  80 01 00 54 */	lwz r0, 0x54(r1)
/* 801ABFD0 001A8F10  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 801ABFD4 001A8F14  7C 08 03 A6 */	mtlr r0
/* 801ABFD8 001A8F18  38 21 00 50 */	addi r1, r1, 0x50
/* 801ABFDC 001A8F1C  4E 80 00 20 */	blr 
.endfn doAnimation__Q24Game9GeneratorFv

.fn doEntry__Q24Game9GeneratorFv, global
/* 801ABFE0 001A8F20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801ABFE4 001A8F24  7C 08 02 A6 */	mflr r0
/* 801ABFE8 001A8F28  90 01 00 14 */	stw r0, 0x14(r1)
/* 801ABFEC 001A8F2C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801ABFF0 001A8F30  7C 7F 1B 78 */	mr r31, r3
/* 801ABFF4 001A8F34  80 63 00 18 */	lwz r3, 0x18(r3)
/* 801ABFF8 001A8F38  28 03 00 00 */	cmplwi r3, 0
/* 801ABFFC 001A8F3C  41 82 00 24 */	beq .L_801AC020
/* 801AC000 001A8F40  80 63 00 20 */	lwz r3, 0x20(r3)
/* 801AC004 001A8F44  28 03 00 00 */	cmplwi r3, 0
/* 801AC008 001A8F48  41 82 00 18 */	beq .L_801AC020
/* 801AC00C 001A8F4C  80 63 00 08 */	lwz r3, 8(r3)
/* 801AC010 001A8F50  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC014 001A8F54  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801AC018 001A8F58  7D 89 03 A6 */	mtctr r12
/* 801AC01C 001A8F5C  4E 80 04 21 */	bctrl 
.L_801AC020:
/* 801AC020 001A8F60  80 7F 00 64 */	lwz r3, 0x64(r31)
/* 801AC024 001A8F64  28 03 00 00 */	cmplwi r3, 0
/* 801AC028 001A8F68  41 82 00 14 */	beq .L_801AC03C
/* 801AC02C 001A8F6C  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC030 001A8F70  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801AC034 001A8F74  7D 89 03 A6 */	mtctr r12
/* 801AC038 001A8F78  4E 80 04 21 */	bctrl 
.L_801AC03C:
/* 801AC03C 001A8F7C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC040 001A8F80  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC044 001A8F84  7C 08 03 A6 */	mtlr r0
/* 801AC048 001A8F88  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC04C 001A8F8C  4E 80 00 20 */	blr 
.endfn doEntry__Q24Game9GeneratorFv

.fn doSetView__Q24Game9GeneratorFi, global
/* 801AC050 001A8F90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC054 001A8F94  7C 08 02 A6 */	mflr r0
/* 801AC058 001A8F98  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC05C 001A8F9C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC060 001A8FA0  7C 9F 23 78 */	mr r31, r4
/* 801AC064 001A8FA4  93 C1 00 08 */	stw r30, 8(r1)
/* 801AC068 001A8FA8  7C 7E 1B 78 */	mr r30, r3
/* 801AC06C 001A8FAC  80 63 00 18 */	lwz r3, 0x18(r3)
/* 801AC070 001A8FB0  28 03 00 00 */	cmplwi r3, 0
/* 801AC074 001A8FB4  41 82 00 14 */	beq .L_801AC088
/* 801AC078 001A8FB8  80 63 00 20 */	lwz r3, 0x20(r3)
/* 801AC07C 001A8FBC  28 03 00 00 */	cmplwi r3, 0
/* 801AC080 001A8FC0  41 82 00 08 */	beq .L_801AC088
/* 801AC084 001A8FC4  48 29 30 3D */	bl setCurrentViewNo__Q28SysShape5ModelFUl
.L_801AC088:
/* 801AC088 001A8FC8  80 7E 00 64 */	lwz r3, 0x64(r30)
/* 801AC08C 001A8FCC  28 03 00 00 */	cmplwi r3, 0
/* 801AC090 001A8FD0  41 82 00 18 */	beq .L_801AC0A8
/* 801AC094 001A8FD4  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC098 001A8FD8  7F E4 FB 78 */	mr r4, r31
/* 801AC09C 001A8FDC  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 801AC0A0 001A8FE0  7D 89 03 A6 */	mtctr r12
/* 801AC0A4 001A8FE4  4E 80 04 21 */	bctrl 
.L_801AC0A8:
/* 801AC0A8 001A8FE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC0AC 001A8FEC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC0B0 001A8FF0  83 C1 00 08 */	lwz r30, 8(r1)
/* 801AC0B4 001A8FF4  7C 08 03 A6 */	mtlr r0
/* 801AC0B8 001A8FF8  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC0BC 001A8FFC  4E 80 00 20 */	blr 
.endfn doSetView__Q24Game9GeneratorFi

.fn doViewCalc__Q24Game9GeneratorFv, global
/* 801AC0C0 001A9000  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC0C4 001A9004  7C 08 02 A6 */	mflr r0
/* 801AC0C8 001A9008  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC0CC 001A900C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC0D0 001A9010  7C 7F 1B 78 */	mr r31, r3
/* 801AC0D4 001A9014  80 63 00 18 */	lwz r3, 0x18(r3)
/* 801AC0D8 001A9018  28 03 00 00 */	cmplwi r3, 0
/* 801AC0DC 001A901C  41 82 00 14 */	beq .L_801AC0F0
/* 801AC0E0 001A9020  80 63 00 20 */	lwz r3, 0x20(r3)
/* 801AC0E4 001A9024  28 03 00 00 */	cmplwi r3, 0
/* 801AC0E8 001A9028  41 82 00 08 */	beq .L_801AC0F0
/* 801AC0EC 001A902C  48 29 2F 6D */	bl viewCalc__Q28SysShape5ModelFv
.L_801AC0F0:
/* 801AC0F0 001A9030  80 7F 00 64 */	lwz r3, 0x64(r31)
/* 801AC0F4 001A9034  28 03 00 00 */	cmplwi r3, 0
/* 801AC0F8 001A9038  41 82 00 14 */	beq .L_801AC10C
/* 801AC0FC 001A903C  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC100 001A9040  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 801AC104 001A9044  7D 89 03 A6 */	mtctr r12
/* 801AC108 001A9048  4E 80 04 21 */	bctrl 
.L_801AC10C:
/* 801AC10C 001A904C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC110 001A9050  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC114 001A9054  7C 08 03 A6 */	mtlr r0
/* 801AC118 001A9058  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC11C 001A905C  4E 80 00 20 */	blr 
.endfn doViewCalc__Q24Game9GeneratorFv

.fn doAnimation__Q24Game12GeneratorMgrFv, global
/* 801AC120 001A9060  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC124 001A9064  7C 08 02 A6 */	mflr r0
/* 801AC128 001A9068  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC12C 001A906C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC130 001A9070  7C 7F 1B 78 */	mr r31, r3
/* 801AC134 001A9074  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801AC138 001A9078  28 03 00 00 */	cmplwi r3, 0
/* 801AC13C 001A907C  41 82 00 14 */	beq .L_801AC150
/* 801AC140 001A9080  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC144 001A9084  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801AC148 001A9088  7D 89 03 A6 */	mtctr r12
/* 801AC14C 001A908C  4E 80 04 21 */	bctrl 
.L_801AC150:
/* 801AC150 001A9090  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 801AC154 001A9094  28 03 00 00 */	cmplwi r3, 0
/* 801AC158 001A9098  41 82 00 14 */	beq .L_801AC16C
/* 801AC15C 001A909C  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC160 001A90A0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801AC164 001A90A4  7D 89 03 A6 */	mtctr r12
/* 801AC168 001A90A8  4E 80 04 21 */	bctrl 
.L_801AC16C:
/* 801AC16C 001A90AC  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AC170 001A90B0  28 03 00 00 */	cmplwi r3, 0
/* 801AC174 001A90B4  41 82 00 14 */	beq .L_801AC188
/* 801AC178 001A90B8  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC17C 001A90BC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801AC180 001A90C0  7D 89 03 A6 */	mtctr r12
/* 801AC184 001A90C4  4E 80 04 21 */	bctrl 
.L_801AC188:
/* 801AC188 001A90C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC18C 001A90CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC190 001A90D0  7C 08 03 A6 */	mtlr r0
/* 801AC194 001A90D4  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC198 001A90D8  4E 80 00 20 */	blr 
.endfn doAnimation__Q24Game12GeneratorMgrFv

.fn doEntry__Q24Game12GeneratorMgrFv, global
/* 801AC19C 001A90DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC1A0 001A90E0  7C 08 02 A6 */	mflr r0
/* 801AC1A4 001A90E4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC1A8 001A90E8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC1AC 001A90EC  7C 7F 1B 78 */	mr r31, r3
/* 801AC1B0 001A90F0  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801AC1B4 001A90F4  28 03 00 00 */	cmplwi r3, 0
/* 801AC1B8 001A90F8  41 82 00 14 */	beq .L_801AC1CC
/* 801AC1BC 001A90FC  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC1C0 001A9100  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801AC1C4 001A9104  7D 89 03 A6 */	mtctr r12
/* 801AC1C8 001A9108  4E 80 04 21 */	bctrl 
.L_801AC1CC:
/* 801AC1CC 001A910C  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 801AC1D0 001A9110  28 03 00 00 */	cmplwi r3, 0
/* 801AC1D4 001A9114  41 82 00 14 */	beq .L_801AC1E8
/* 801AC1D8 001A9118  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC1DC 001A911C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801AC1E0 001A9120  7D 89 03 A6 */	mtctr r12
/* 801AC1E4 001A9124  4E 80 04 21 */	bctrl 
.L_801AC1E8:
/* 801AC1E8 001A9128  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AC1EC 001A912C  28 03 00 00 */	cmplwi r3, 0
/* 801AC1F0 001A9130  41 82 00 14 */	beq .L_801AC204
/* 801AC1F4 001A9134  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC1F8 001A9138  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801AC1FC 001A913C  7D 89 03 A6 */	mtctr r12
/* 801AC200 001A9140  4E 80 04 21 */	bctrl 
.L_801AC204:
/* 801AC204 001A9144  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC208 001A9148  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC20C 001A914C  7C 08 03 A6 */	mtlr r0
/* 801AC210 001A9150  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC214 001A9154  4E 80 00 20 */	blr 
.endfn doEntry__Q24Game12GeneratorMgrFv

.fn doSetView__Q24Game12GeneratorMgrFi, global
/* 801AC218 001A9158  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC21C 001A915C  7C 08 02 A6 */	mflr r0
/* 801AC220 001A9160  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC224 001A9164  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC228 001A9168  7C 9F 23 78 */	mr r31, r4
/* 801AC22C 001A916C  93 C1 00 08 */	stw r30, 8(r1)
/* 801AC230 001A9170  7C 7E 1B 78 */	mr r30, r3
/* 801AC234 001A9174  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801AC238 001A9178  28 03 00 00 */	cmplwi r3, 0
/* 801AC23C 001A917C  41 82 00 14 */	beq .L_801AC250
/* 801AC240 001A9180  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC244 001A9184  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 801AC248 001A9188  7D 89 03 A6 */	mtctr r12
/* 801AC24C 001A918C  4E 80 04 21 */	bctrl 
.L_801AC250:
/* 801AC250 001A9190  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 801AC254 001A9194  28 03 00 00 */	cmplwi r3, 0
/* 801AC258 001A9198  41 82 00 18 */	beq .L_801AC270
/* 801AC25C 001A919C  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC260 001A91A0  7F E4 FB 78 */	mr r4, r31
/* 801AC264 001A91A4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 801AC268 001A91A8  7D 89 03 A6 */	mtctr r12
/* 801AC26C 001A91AC  4E 80 04 21 */	bctrl 
.L_801AC270:
/* 801AC270 001A91B0  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 801AC274 001A91B4  28 03 00 00 */	cmplwi r3, 0
/* 801AC278 001A91B8  41 82 00 18 */	beq .L_801AC290
/* 801AC27C 001A91BC  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC280 001A91C0  7F E4 FB 78 */	mr r4, r31
/* 801AC284 001A91C4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 801AC288 001A91C8  7D 89 03 A6 */	mtctr r12
/* 801AC28C 001A91CC  4E 80 04 21 */	bctrl 
.L_801AC290:
/* 801AC290 001A91D0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC294 001A91D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC298 001A91D8  83 C1 00 08 */	lwz r30, 8(r1)
/* 801AC29C 001A91DC  7C 08 03 A6 */	mtlr r0
/* 801AC2A0 001A91E0  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC2A4 001A91E4  4E 80 00 20 */	blr 
.endfn doSetView__Q24Game12GeneratorMgrFi

.fn doViewCalc__Q24Game12GeneratorMgrFv, global
/* 801AC2A8 001A91E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC2AC 001A91EC  7C 08 02 A6 */	mflr r0
/* 801AC2B0 001A91F0  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC2B4 001A91F4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC2B8 001A91F8  7C 7F 1B 78 */	mr r31, r3
/* 801AC2BC 001A91FC  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801AC2C0 001A9200  28 03 00 00 */	cmplwi r3, 0
/* 801AC2C4 001A9204  41 82 00 14 */	beq .L_801AC2D8
/* 801AC2C8 001A9208  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC2CC 001A920C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 801AC2D0 001A9210  7D 89 03 A6 */	mtctr r12
/* 801AC2D4 001A9214  4E 80 04 21 */	bctrl 
.L_801AC2D8:
/* 801AC2D8 001A9218  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 801AC2DC 001A921C  28 03 00 00 */	cmplwi r3, 0
/* 801AC2E0 001A9220  41 82 00 14 */	beq .L_801AC2F4
/* 801AC2E4 001A9224  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC2E8 001A9228  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 801AC2EC 001A922C  7D 89 03 A6 */	mtctr r12
/* 801AC2F0 001A9230  4E 80 04 21 */	bctrl 
.L_801AC2F4:
/* 801AC2F4 001A9234  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 801AC2F8 001A9238  28 03 00 00 */	cmplwi r3, 0
/* 801AC2FC 001A923C  41 82 00 14 */	beq .L_801AC310
/* 801AC300 001A9240  81 83 00 00 */	lwz r12, 0(r3)
/* 801AC304 001A9244  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 801AC308 001A9248  7D 89 03 A6 */	mtctr r12
/* 801AC30C 001A924C  4E 80 04 21 */	bctrl 
.L_801AC310:
/* 801AC310 001A9250  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC314 001A9254  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC318 001A9258  7C 08 03 A6 */	mtlr r0
/* 801AC31C 001A925C  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC320 001A9260  4E 80 00 20 */	blr 
.endfn doViewCalc__Q24Game12GeneratorMgrFv

.fn __dt__Q24Game12GeneratorMgrFv, weak
/* 801AC324 001A9264  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801AC328 001A9268  7C 08 02 A6 */	mflr r0
/* 801AC32C 001A926C  90 01 00 14 */	stw r0, 0x14(r1)
/* 801AC330 001A9270  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801AC334 001A9274  7C 9F 23 78 */	mr r31, r4
/* 801AC338 001A9278  93 C1 00 08 */	stw r30, 8(r1)
/* 801AC33C 001A927C  7C 7E 1B 79 */	or. r30, r3, r3
/* 801AC340 001A9280  41 82 00 28 */	beq .L_801AC368
/* 801AC344 001A9284  3C A0 80 4B */	lis r5, __vt__Q24Game12GeneratorMgr@ha
/* 801AC348 001A9288  38 80 00 00 */	li r4, 0
/* 801AC34C 001A928C  38 05 55 FC */	addi r0, r5, __vt__Q24Game12GeneratorMgr@l
/* 801AC350 001A9290  90 1E 00 00 */	stw r0, 0(r30)
/* 801AC354 001A9294  48 26 52 35 */	bl __dt__5CNodeFv
/* 801AC358 001A9298  7F E0 07 35 */	extsh. r0, r31
/* 801AC35C 001A929C  40 81 00 0C */	ble .L_801AC368
/* 801AC360 001A92A0  7F C3 F3 78 */	mr r3, r30
/* 801AC364 001A92A4  4B E7 7D 51 */	bl __dl__FPv
.L_801AC368:
/* 801AC368 001A92A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801AC36C 001A92AC  7F C3 F3 78 */	mr r3, r30
/* 801AC370 001A92B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801AC374 001A92B4  83 C1 00 08 */	lwz r30, 8(r1)
/* 801AC378 001A92B8  7C 08 03 A6 */	mtlr r0
/* 801AC37C 001A92BC  38 21 00 10 */	addi r1, r1, 0x10
/* 801AC380 001A92C0  4E 80 00 20 */	blr 
.endfn __dt__Q24Game12GeneratorMgrFv

.fn render__Q24Game9GenObjectFR8GraphicsPQ24Game9Generator, weak
/* 801AC384 001A92C4  4E 80 00 20 */	blr 
.endfn render__Q24Game9GenObjectFR8GraphicsPQ24Game9Generator

.fn getShape__Q24Game7GenBaseFv, weak
/* 801AC388 001A92C8  38 60 00 00 */	li r3, 0
/* 801AC38C 001A92CC  4E 80 00 20 */	blr 
.endfn getShape__Q24Game7GenBaseFv

.fn update__Q24Game7GenBaseFPQ24Game9Generator, weak
/* 801AC390 001A92D0  4E 80 00 20 */	blr 
.endfn update__Q24Game7GenBaseFPQ24Game9Generator

.fn render__Q24Game7GenBaseFR8GraphicsPQ24Game9Generator, weak
/* 801AC394 001A92D4  4E 80 00 20 */	blr 
.endfn render__Q24Game7GenBaseFR8GraphicsPQ24Game9Generator

.fn __sinit_gameGenerator_cpp, local
/* 801AC398 001A92D8  3C 80 80 51 */	lis r4, __float_nan@ha
/* 801AC39C 001A92DC  38 00 FF FF */	li r0, -1
/* 801AC3A0 001A92E0  C0 04 48 B0 */	lfs f0, __float_nan@l(r4)
/* 801AC3A4 001A92E4  3C 60 80 4B */	lis r3, govNAN___Q24Game5P2JST@ha
/* 801AC3A8 001A92E8  90 0D 93 98 */	stw r0, gu32NAN___Q24Game5P2JST@sda21(r13)
/* 801AC3AC 001A92EC  D4 03 55 F0 */	stfsu f0, govNAN___Q24Game5P2JST@l(r3)
/* 801AC3B0 001A92F0  D0 0D 93 9C */	stfs f0, gfNAN___Q24Game5P2JST@sda21(r13)
/* 801AC3B4 001A92F4  D0 03 00 04 */	stfs f0, 4(r3)
/* 801AC3B8 001A92F8  D0 03 00 08 */	stfs f0, 8(r3)
/* 801AC3BC 001A92FC  4E 80 00 20 */	blr 
.endfn __sinit_gameGenerator_cpp
