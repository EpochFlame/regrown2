#include "efx/Arg.h"
#include "efx/TSyncGroup.h"
#include "types.h"
#include "efx/TBaba.h"
#include "efx/TChibi.h"
#include "efx/TChou.h"
#include "efx/TDenki.h"
#include "efx/TDnkms.h"
#include "efx/TGasuHiba.h"
#include "efx/THebi.h"
#include "efx/THibaFire.h"
#include "efx/TImo.h"
#include "efx/TJgm.h"
#include "efx/TKechappy.h"
#include "efx/TKogane.h"
#include "efx/TKurage.h"
#include "efx/TNewkurage.h"
#include "efx/TOta.h"
#include "efx/TPan.h"
#include "efx/TQuri.h"
#include "efx/TTank.h"
#include "efx/TUmi.h"
#include "efx/TUjinko.h"
#include "efx/TYaki.h"
#include "JSystem/JParticle/JPAMath.h"

namespace efx {

static void _Print(char* format, ...) { OSReport(format, __FILE__); }

/*
 * --INFO--
 * Address:	803B2D84
 * Size:	000124
 */
bool TChibiHit::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(23, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple4::create(arg)) {
		volatile f32 test[3];
		test[0] = scale;
		mEmitters[0]->setScale(scale);
		test[1] = scale;
		mEmitters[1]->setScale(scale);
		test[2] = scale;
		mEmitters[2]->setScale(scale);
		mEmitters[3]->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B2EA8
 * Size:	0000E0
 */
bool TChouDown::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgChou", arg->getName()) == 0;
	P2ASSERTLINE(43, nameCheck);
	int type = static_cast<ArgChou*>(arg)->mType;

	switch (type) {
	case 0:
		mEffectID = PID_ChouDown_3;
		break;
	case 1:
		mEffectID = PID_ChouDown_2;
		break;
	case 2:
		mEffectID = PID_ChouDown_1;
		break;
	}
	return (u8)TSync::create(arg);
}

/*
 * --INFO--
 * Address:	803B2F88
 * Size:	000044
 */
void TUmiHamon::setGlobalScale(f32 scale)
{
	for (int i = 0; i < 2; i++) {
		if (mItems[i].mEmitter) {
			mItems[i].mEmitter->setScale(scale);
		}
	}
}

/*
 * --INFO--
 * Address:	803B2FCC
 * Size:	000100
 */
bool TUmiFlick::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(80, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple3::create(arg)) {
		for (int i = 0; i < 3; i++) {
			mEmitters[i]->setScale(scale);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B30CC
 * Size:	0000D0
 */
bool TUmiAttack::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(97, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple1::create(arg)) { // supposed to inherit TSimpleMtx1?
		mEmitters[0]->setScale(scale);
		return true;
	}
	return false;
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	stw      r0, 0x34(r1)
	stfd     f31, 0x20(r1)
	psq_st   f31, 40(r1), 0, qr0
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r30, r4
	mr       r29, r3
	mr       r3, r30
	lis      r4, lbl_80495898@ha
	lwz      r12, 0(r30)
	addi     r31, r4, lbl_80495898@l
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r31, 0x10
	bl       strcmp
	cntlzw   r0, r3
	rlwinm.  r0, r0, 0x1b, 0x18, 0x1f
	bne      lbl_803B313C
	addi     r3, r31, 0
	addi     r5, r31, 0x1c
	li       r4, 0x61
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B313C:
	lfs      f31, 0x10(r30)
	mr       r3, r29
	mr       r4, r30
	bl       create__Q23efx11TSimpleMtx1FPQ23efx3Arg
	clrlwi.  r0, r3, 0x18
	beq      lbl_803B3174
	lwz      r4, 8(r29)
	li       r3, 1
	stfs     f31, 0x98(r4)
	stfs     f31, 0x9c(r4)
	stfs     f31, 0xa0(r4)
	stfs     f31, 0xb0(r4)
	stfs     f31, 0xb4(r4)
	b        lbl_803B3178

lbl_803B3174:
	li       r3, 0

lbl_803B3178:
	psq_l    f31, 40(r1), 0, qr0
	lwz      r0, 0x34(r1)
	lfd      f31, 0x20(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B319C
 * Size:	000024
 */
void TUmiEat::setGlobalScale(f32 scale)
{
	if (mEmitter) {
		mEmitter->setScale(scale);
	}
}

/*
 * --INFO--
 * Address:	803B31C0
 * Size:	000024
 */
void TUmiDeadawa::setGlobalScale(f32 scale)
{
	if (mEmitter) {
		mEmitter->setScale(scale);
	}
}

/*
 * --INFO--
 * Address:	803B31E4
 * Size:	0000D0
 */
bool TUmiDeadmelt::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(134, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple1::create(arg)) {
		mEmitters[0]->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B32B4
 * Size:	0000E8
 */
bool TJgmAttack::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(153, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSyncGroup2<TChasePos>::create(arg)) {
		for (int i = 0; i < 2; i++) {
			mItems[i].mEmitter->setScale(scale);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B339C
 * Size:	000100
 */
bool TJgmAttackW::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(169, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSyncGroup3<TChasePosYRot>::create(arg)) {
		for (int i = 0; i < 3; i++) {
			mItems[i].mEmitter->setScale(scale);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B349C
 * Size:	0000D0
 */
bool TJgmBack::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(185, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSync::create(arg)) {
		mEmitter->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B356C
 * Size:	0000E8
 */
bool TJgmBackW::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(199, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSyncGroup2<TChasePosYRot>::create(arg)) {
		for (int i = 0; i < 2; i++) {
			mItems[i].mEmitter->setScale(scale);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B3654
 * Size:	0000C0
 */
bool TImoEat::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgImoEat", arg->getName()) == 0;
	P2ASSERTLINE(217, nameCheck);
	ArgImoEat* sarg = static_cast<ArgImoEat*>(arg);

	switch (sarg->mType) {
	case 0:
		mEffectID = PID_ImoEat_2;
		break;
	case 1:
		mEffectID = PID_ImoEat_1;
		break;
	}
	return TSync::create(sarg);
}

/*
 * --INFO--
 * Address:	803B3714
 * Size:	000074
 */
bool TUjinkoHd_Imo::create(Arg* arg)
{
	if (TSimpleMtx2::create(arg)) {
		for (int i = 0; i < 2; i++) {
			mEmitters[i]->setScale(1.3f);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B3788
 * Size:	000074
 */
bool TUjinkoAp_Imo::create(Arg* arg)
{
	if (TSimpleMtx2::create(arg)) {
		for (int i = 0; i < 2; i++) {
			mEmitters[i]->setScale(1.3f);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B37FC
 * Size:	0000D0
 */
bool TImoSmoke::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(263, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSync::create(arg)) {
		mEmitter->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B38CC
 * Size:	0000D0
 */
bool TOtaPartsoff::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(279, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple1::create(arg)) {
		mEmitters[0]->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B399C
 * Size:	000040
 */
void TNewkurageSui::setGlobalTranslation(Vector3f& pos)
{
	f32 x = pos.x;
	f32 y = pos.y;
	f32 z = pos.z;
	for (int i = 0; i < 2; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->setTranslation(x, y, z);
	}
}

/*
 * --INFO--
 * Address:	803B39DC
 * Size:	000034
 */
void TNewkurageHire::setLifeTime(s16 time)
{
	for (int i = 0; i < 3; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->mLifeTime = time;
	}
}

/*
 * --INFO--
 * Address:	803B3A10
 * Size:	000040
 */
void TKurageSui::setGlobalTranslation(Vector3f& pos)
{
	f32 x = pos.x;
	f32 y = pos.y;
	f32 z = pos.z;
	for (int i = 0; i < 2; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->setTranslation(x, y, z);
	}
}

/*
 * --INFO--
 * Address:	803B3A50
 * Size:	000034
 */
void TKurageHire::setLifeTime(s16 time)
{
	for (int i = 0; i < 3; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->mLifeTime = time;
	}
}

/*
 * --INFO--
 * Address:	803B3A84
 * Size:	000024
 */
void TQuriGlow::setGlobalScale(f32 scale)
{
	if (mEmitter) {
		mEmitter->setScale(scale);
	}
}

/*
 * --INFO--
 * Address:	803B3AA8
 * Size:	0000A4
 */
bool THebiAphd_base::create(Arg* arg)
{
	P2ASSERTLINE(358, arg != nullptr);
	if (TSimple4::create(arg)) {
		for (int i = 0; i < 4; i++) {
			mEmitters[i]->_24 = _1C;
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B3B4C
 * Size:	000034
 */
void TKechappyTest::setGlobalAlpha(u8 alpha)
{
	for (int i = 0; i < 3; i++) {
		if (mItems[i].mEmitter) {
			mItems[i].mEmitter->mColor1.a = alpha;
		}
	}
}

/*
 * --INFO--
 * Address:	803B3B80
 * Size:	000024
 */
void TKechappyTest::setGlobalParticleScale(f32 scale)
{
	for (int i = 1; i < 3; i++) {
		if (mItems[i].mEmitter) {
			mItems[i].mEmitter->_B4 = scale;
		}
	}
}

/*
 * --INFO--
 * Address:	803B3BA4
 * Size:	000024
 */
void TKechappyTest::setAwayFromCenterSpeed(f32 speed)
{
	for (int i = 1; i < 3; i++) {
		if (mItems[i].mEmitter) {
			mItems[i].mEmitter->_34 = speed;
		}
	}
}

/*
 * --INFO--
 * Address:	803B3BC8
 * Size:	000024
 */
void TKechappyTest::setSpread(f32 spread)
{
	for (int i = 1; i < 3; i++) {
		if (mItems[i].mEmitter) {
			mItems[i].mEmitter->_40 = spread;
		}
	}
}

/*
 * --INFO--
 * Address:	803B3BEC
 * Size:	00004C
 */
void TKechappyTest::setGlobalDynamicsScale(Vector3f& scale)
{
	for (int i = 1; i < 3; i++) {
		if (mItems[i].mEmitter) {
			mItems[i].mEmitter->setScaleOnly(scale);
		}
	}
}

/*
 * --INFO--
 * Address:	803B3C38
 * Size:	0000DC
 */
void TYakiBody::setRateLOD(int id)
{
	JPABaseEmitter* emit;
	f32 lods[4][3] = {
		{ 0.2f, 0.2f, 0.2f },
		{ 1.0f, 1.0f, 1.0f },
		{ 0.082f, 0.05f, 0.0f },
		{ 2.3f, 1.7f, 0.0f },
	};

	for (int i = 0; i < 4; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->_28 = lods[i][id];
	}
	/*
	stwu     r1, -0x50(r1)
	lis      r5, lbl_804958CC@ha
	slwi     r0, r4, 2
	stmw     r27, 0x3c(r1)
	addi     r29, r5, lbl_804958CC@l
	addi     r27, r1, 8
	add      r27, r27, r0
	lwz      r28, 0xc(r3)
	lwz      r30, 0(r29)
	lwz      r31, 4(r29)
	cmplwi   r28, 0
	lwz      r12, 8(r29)
	lwz      r11, 0xc(r29)
	lwz      r10, 0x10(r29)
	lwz      r9, 0x14(r29)
	lwz      r8, 0x18(r29)
	lwz      r7, 0x1c(r29)
	lwz      r6, 0x20(r29)
	lwz      r5, 0x24(r29)
	lwz      r4, 0x28(r29)
	lwz      r0, 0x2c(r29)
	stw      r30, 8(r1)
	stw      r31, 0xc(r1)
	stw      r12, 0x10(r1)
	stw      r11, 0x14(r1)
	stw      r10, 0x18(r1)
	stw      r9, 0x1c(r1)
	stw      r8, 0x20(r1)
	stw      r7, 0x24(r1)
	stw      r6, 0x28(r1)
	stw      r5, 0x2c(r1)
	stw      r4, 0x30(r1)
	stw      r0, 0x34(r1)
	beq      lbl_803B3CC8
	lfs      f0, 0(r27)
	stfs     f0, 0x28(r28)

lbl_803B3CC8:
	lwz      r28, 0x20(r3)
	cmplwi   r28, 0
	beq      lbl_803B3CDC
	lfs      f0, 0xc(r27)
	stfs     f0, 0x28(r28)

lbl_803B3CDC:
	addi     r3, r3, 0x28
	lwz      r28, 0xc(r3)
	cmplwi   r28, 0
	beq      lbl_803B3CF4
	lfs      f0, 0x18(r27)
	stfs     f0, 0x28(r28)

lbl_803B3CF4:
	lwz      r28, 0x20(r3)
	cmplwi   r28, 0
	beq      lbl_803B3D08
	lfs      f0, 0x24(r27)
	stfs     f0, 0x28(r28)

lbl_803B3D08:
	lmw      r27, 0x3c(r1)
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B3D14
 * Size:	0000D0
 */
bool TPanApp::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(456, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple1::create(arg)) {
		mEmitters[0]->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B3DE4
 * Size:	0000D0
 */
bool TPanHide::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(473, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSync::create(arg)) {
		mEmitter->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B3EB4
 * Size:	0000D0
 */
bool TPanSmoke::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(489, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSync::create(arg)) {
		mEmitter->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B3F84
 * Size:	0000D0
 */
bool TBabaFly_ver01::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(506, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSync::create(arg)) {
		mEmitter->setScale(scale);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B4054
 * Size:	000184
 */
bool TBabaHe::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgRotY", arg->getName()) == 0;
	P2ASSERTLINE(521, nameCheck);
	ArgRotY* sarg = static_cast<ArgRotY*>(arg);
	Mtx mtx;
	f32 x = arg->mPosition.x;
	f32 y = arg->mPosition.y;
	f32 z = arg->mPosition.z;
	PSMTXRotRad(mtx, 'y', sarg->mFaceDir);
	mtx[0][3] = x;
	mtx[1][3] = y;
	mtx[2][3] = z;

	if (TSimple2::create(arg)) {
		for (int i = 0; i < 2; i++) {
			JPASetRMtxTVecfromMtx(mtx, mEmitters[i]->mMatrix, &mEmitters[i]->mPosition);
		}
		mEmitters[0]->mPosition.x = (mtx[0][2] * -35.0f) + x;
		mEmitters[0]->mPosition.y = (mtx[1][2] * -35.0f) + y;
		mEmitters[0]->mPosition.z = (mtx[2][2] * -35.0f) + z;
		return true;
	}
	return false;
	/*
	stwu     r1, -0x90(r1)
	mflr     r0
	stw      r0, 0x94(r1)
	stfd     f31, 0x80(r1)
	psq_st   f31, 136(r1), 0, qr0
	stfd     f30, 0x70(r1)
	psq_st   f30, 120(r1), 0, qr0
	stfd     f29, 0x60(r1)
	psq_st   f29, 104(r1), 0, qr0
	stw      r31, 0x5c(r1)
	stw      r30, 0x58(r1)
	stw      r29, 0x54(r1)
	mr       r30, r4
	mr       r29, r3
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r2, lbl_8051F62C@sda21
	bl       strcmp
	cntlzw   r0, r3
	rlwinm.  r0, r0, 0x1b, 0x18, 0x1f
	bne      lbl_803B40D4
	lis      r3, lbl_80495898@ha
	lis      r5, lbl_804958B4@ha
	addi     r3, r3, lbl_80495898@l
	li       r4, 0x209
	addi     r5, r5, lbl_804958B4@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B40D4:
	lfs      f31, 4(r30)
	addi     r3, r1, 0x14
	lfs      f30, 8(r30)
	li       r4, 0x79
	lfs      f29, 0xc(r30)
	lfs      f1, 0x10(r30)
	bl       PSMTXRotRad
	stfs     f31, 0x20(r1)
	mr       r3, r29
	mr       r4, r30
	stfs     f30, 0x30(r1)
	stfs     f29, 0x40(r1)
	bl       create__Q23efx8TSimple2FPQ23efx3Arg
	clrlwi.  r0, r3, 0x18
	beq      lbl_803B41A0
	li       r30, 0
	mr       r31, r29

lbl_803B4118:
	lwz      r5, 8(r31)
	addi     r3, r1, 0x14
	addi     r4, r5, 0x68
	addi     r5, r5, 0xa4
	bl       "JPASetRMtxTVecfromMtx__FPA4_CfPA4_fPQ29JGeometry8TVec3<f>"
	addi     r30, r30, 1
	addi     r31, r31, 4
	cmpwi    r30, 2
	blt      lbl_803B4118
	lfs      f1, 0x1c(r1)
	li       r3, 1
	lfs      f0, lbl_8051F634@sda21(r2)
	lfs      f5, 0x2c(r1)
	fmuls    f3, f1, f0
	lfs      f4, 0x3c(r1)
	fmuls    f2, f5, f0
	stfs     f1, 8(r1)
	fmuls    f1, f4, f0
	lwz      r4, 0xc(r29)
	fadds    f0, f3, f31
	stfs     f5, 0xc(r1)
	fadds    f5, f2, f30
	stfs     f4, 0x10(r1)
	fadds    f4, f1, f29
	stfs     f0, 0xa4(r4)
	stfs     f3, 8(r1)
	stfs     f2, 0xc(r1)
	stfs     f1, 0x10(r1)
	stfs     f5, 0xa8(r4)
	stfs     f0, 8(r1)
	stfs     f5, 0xc(r1)
	stfs     f4, 0x10(r1)
	stfs     f4, 0xac(r4)
	b        lbl_803B41A4

lbl_803B41A0:
	li       r3, 0

lbl_803B41A4:
	psq_l    f31, 136(r1), 0, qr0
	lfd      f31, 0x80(r1)
	psq_l    f30, 120(r1), 0, qr0
	lfd      f30, 0x70(r1)
	psq_l    f29, 104(r1), 0, qr0
	lfd      f29, 0x60(r1)
	lwz      r31, 0x5c(r1)
	lwz      r30, 0x58(r1)
	lwz      r0, 0x94(r1)
	lwz      r29, 0x54(r1)
	mtlr     r0
	addi     r1, r1, 0x90
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B41D8
 * Size:	0000E8
 */
bool TKoganeHit::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(546, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple2::create(arg)) {
		for (int i = 0; i < 2; i++) {
			mEmitters[i]->setScale(scale);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B42C0
 * Size:	0000E8
 */
bool TKoganeDive::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgScale", arg->getName()) == 0;
	P2ASSERTLINE(562, nameCheck);
	f32 scale = static_cast<ArgScale*>(arg)->mScale;
	if (TSimple2::create(arg)) {
		for (int i = 0; i < 2; i++) {
			mEmitters[i]->setScale(scale);
		}
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	803B43A8
 * Size:	000004
 */
void TParticleCallBack_TankFire::init(JPABaseEmitter*, JPABaseParticle*) { }

/*
 * --INFO--
 * Address:	803B43AC
 * Size:	000144
 */
void TParticleCallBack_TankFire::execute(JPABaseEmitter* emit, JPABaseParticle* particle)
{
	f32 z = particle->getCalcCurrentPositionZ(emit);
	f32 y = particle->getCalcCurrentPositionY(emit);
	f32 x = particle->getCalcCurrentPositionX(emit);
	Vector3f tgt(x, y, z);
	if (tgt.distance(emit->mPosition) < _04) {
		particle->mFlags |= 2;

		TTankFireHit* hit = mEfxHit;
		if (hit && hit->_14 < hit->_18) {
			Vector3f* pos = &hit->_10[hit->_14];
			pos->x        = x;
			pos->y        = y;
			pos->z        = z;
			hit->_14++;
		}
	}
	/*
	stwu     r1, -0x40(r1)
	mflr     r0
	stw      r0, 0x44(r1)
	stfd     f31, 0x30(r1)
	psq_st   f31, 56(r1), 0, qr0
	stfd     f30, 0x20(r1)
	psq_st   f30, 40(r1), 0, qr0
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r31, r5
	mr       r29, r3
	mr       r30, r4
	mr       r3, r31
	bl       getCalcCurrentPositionZ__15JPABaseParticleCFPC14JPABaseEmitter
	fmr      f30, f1
	mr       r3, r31
	mr       r4, r30
	bl       getCalcCurrentPositionY__15JPABaseParticleCFPC14JPABaseEmitter
	fmr      f31, f1
	mr       r3, r31
	mr       r4, r30
	bl       getCalcCurrentPositionX__15JPABaseParticleCFPC14JPABaseEmitter
	lfs      f0, 0xa4(r30)
	lfs      f2, 0xa8(r30)
	fsubs    f4, f0, f1
	lfs      f3, 0xac(r30)
	fsubs    f2, f2, f31
	lfs      f0, lbl_8051F638@sda21(r2)
	fsubs    f5, f3, f30
	fmuls    f3, f4, f4
	fmuls    f2, f2, f2
	fmuls    f4, f5, f5
	fadds    f2, f3, f2
	fadds    f4, f4, f2
	fcmpo    cr0, f4, f0
	cror     2, 0, 2
	bne      lbl_803B4448
	b        lbl_803B446C

lbl_803B4448:
	frsqrte  f5, f4
	lfs      f3, lbl_8051F63C@sda21(r2)
	lfs      f0, lbl_8051F640@sda21(r2)
	frsp     f5, f5
	fmuls    f2, f5, f5
	fmuls    f3, f3, f5
	fnmsubs  f0, f4, f2, f0
	fmuls    f0, f3, f0
	fmuls    f4, f4, f0

lbl_803B446C:
	lfs      f0, 4(r29)
	fcmpo    cr0, f4, f0
	ble      lbl_803B44C4
	lwz      r0, 0x7c(r31)
	ori      r0, r0, 2
	stw      r0, 0x7c(r31)
	lwz      r4, 8(r29)
	cmplwi   r4, 0
	beq      lbl_803B44C4
	lwz      r3, 0x14(r4)
	lwz      r0, 0x18(r4)
	cmpw     r3, r0
	bge      lbl_803B44C4
	mulli    r0, r3, 0xc
	lwz      r3, 0x10(r4)
	add      r3, r3, r0
	stfs     f1, 0(r3)
	stfs     f31, 4(r3)
	stfs     f30, 8(r3)
	lwz      r3, 0x14(r4)
	addi     r0, r3, 1
	stw      r0, 0x14(r4)

lbl_803B44C4:
	psq_l    f31, 56(r1), 0, qr0
	lfd      f31, 0x30(r1)
	psq_l    f30, 40(r1), 0, qr0
	lfd      f30, 0x20(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r0, 0x44(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x40
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B44F0
 * Size:	000090
 */
bool TTankFireABC::create(Arg* arg)
{
	mParticleCallBack.mEfxHit = &mEfxFireHit;
	mParticleCallBack.mEfxHit->create(nullptr);
	mParticleCallBack._04 = 1000.0f;
	if (TSyncGroup3<TChaseMtx>::create(arg)) {
		for (int i = 0; i < 3; i++) {
			mItems[i].mEmitter->mParticleCallback = &mParticleCallBack;
		}
	}
	return true;
}

/*
 * --INFO--
 * Address:	803B4580
 * Size:	000044
 */
bool TTankFireIND::create(Arg* arg)
{
	if (TSync::create(arg)) {
		mEmitter->mParticleCallback = &mParticleCallBack;
	}
	return true;
}

/*
 * --INFO--
 * Address:	803B45C4
 * Size:	000084
 */
bool TTankFire::create(Arg* arg)
{
	bool ret = false;
	if (mEfxABC.create(arg) && mEfxIND.create(arg)) {
		ret = true;
	}
	return ret;
}

/*
 * --INFO--
 * Address:	803B4648
 * Size:	000098
 */
bool TTankWat::create(Arg* arg)
{
	// mParticleCallBack.mEfxHit = &mEfxHit; // something sus here
	mParticleCallBack.mEfxHit->create(nullptr);
	mParticleCallBack._04 = 1000.0f;
	if (TSyncGroup4<TChaseMtx>::create(arg)) {
		for (int i = 0; i < 4; i++) {
			mItems[i].mEmitter->mParticleCallback = &mParticleCallBack;
		}
	}
	return true;
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r4
	li       r4, 0
	stw      r30, 8(r1)
	mr       r30, r3
	addi     r0, r30, 0x60
	stw      r0, 0x5c(r3)
	lwz      r3, 0x5c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f0, lbl_8051F644@sda21(r2)
	mr       r3, r30
	mr       r4, r31
	stfs     f0, 0x58(r30)
	bl       "create__Q23efx29TSyncGroup4<Q23efx9TChaseMtx>FPQ23efx3Arg"
	clrlwi.  r0, r3, 0x18
	beq      lbl_803B46C4
	lwz      r3, 0xc(r30)
	addi     r0, r30, 0x54
	stw      r0, 0xf0(r3)
	lwz      r3, 0x20(r30)
	stw      r0, 0xf0(r3)
	lwz      r3, 0x34(r30)
	stw      r0, 0xf0(r3)
	lwz      r3, 0x48(r30)
	stw      r0, 0xf0(r3)

lbl_803B46C4:
	lwz      r0, 0x14(r1)
	li       r3, 1
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B46E0
 * Size:	000168
 */
void TDnkmsThunderA::doExecuteEmitterOperation(JPABaseEmitter* emit)
{
	/*
	stwu     r1, -0x70(r1)
	mflr     r0
	stw      r0, 0x74(r1)
	stw      r31, 0x6c(r1)
	mr       r31, r4
	stw      r30, 0x68(r1)
	mr       r30, r3
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	bne      lbl_803B4724
	lis      r3, lbl_80495898@ha
	lis      r5, lbl_804958B4@ha
	addi     r3, r3, lbl_80495898@l
	li       r4, 0x284
	addi     r5, r5, lbl_804958B4@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B4724:
	lwz      r0, 0x14(r30)
	cmplwi   r0, 0
	bne      lbl_803B474C
	lis      r3, lbl_80495898@ha
	lis      r5, lbl_804958B4@ha
	addi     r3, r3, lbl_80495898@l
	li       r4, 0x285
	addi     r5, r5, lbl_804958B4@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B474C:
	lwz      r6, 0x10(r30)
	addi     r3, r1, 0x2c
	addi     r4, r1, 0x20
	addi     r5, r1, 0x14
	lfs      f0, 0(r6)
	stfs     f0, 0x20(r1)
	lfs      f0, 4(r6)
	stfs     f0, 0x24(r1)
	lfs      f0, 8(r6)
	stfs     f0, 0x28(r1)
	lwz      r6, 0x14(r30)
	lfs      f0, 0(r6)
	stfs     f0, 0x14(r1)
	lfs      f0, 4(r6)
	stfs     f0, 0x18(r1)
	lfs      f0, 8(r6)
	stfs     f0, 0x1c(r1)
	bl       "makeMtxZAxisAlongPosPos__3efxFPA4_fR10Vector3<f>R10Vector3<f>"
	addi     r3, r1, 0x2c
	addi     r4, r31, 0x68
	addi     r5, r31, 0xa4
	bl       "JPASetRMtxTVecfromMtx__FPA4_CfPA4_fPQ29JGeometry8TVec3<f>"
	lwz      r4, 0x14(r30)
	lwz      r3, 0x10(r30)
	lfs      f0, 4(r4)
	lfs      f1, 4(r3)
	lfs      f3, 0(r3)
	fsubs    f4, f1, f0
	lfs      f2, 0(r4)
	lfs      f1, 8(r3)
	lfs      f0, 8(r4)
	fsubs    f3, f3, f2
	fmuls    f4, f4, f4
	fsubs    f2, f1, f0
	lfs      f0, lbl_8051F638@sda21(r2)
	fmadds   f1, f3, f3, f4
	fmuls    f2, f2, f2
	fadds    f1, f2, f1
	fcmpo    cr0, f1, f0
	ble      lbl_803B47FC
	ble      lbl_803B4800
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_803B4800

lbl_803B47FC:
	fmr      f1, f0

lbl_803B4800:
	lfs      f0, lbl_8051F648@sda21(r2)
	lfs      f3, 0(r31)
	fdivs    f0, f1, f0
	lfs      f2, 4(r31)
	lfs      f1, 8(r31)
	stfs     f3, 8(r1)
	stfs     f3, 0(r31)
	stfs     f1, 0x10(r1)
	stfs     f2, 4(r31)
	stfs     f2, 0xc(r1)
	stfs     f0, 0x10(r1)
	stfs     f0, 8(r31)
	lwz      r31, 0x6c(r1)
	lwz      r30, 0x68(r1)
	lwz      r0, 0x74(r1)
	mtlr     r0
	addi     r1, r1, 0x70
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B4848
 * Size:	000168
 */
void TDnkmsThunderB::doExecuteEmitterOperation(JPABaseEmitter*)
{
	/*
	stwu     r1, -0x70(r1)
	mflr     r0
	stw      r0, 0x74(r1)
	stw      r31, 0x6c(r1)
	mr       r31, r4
	stw      r30, 0x68(r1)
	mr       r30, r3
	lwz      r0, 0x10(r3)
	cmplwi   r0, 0
	bne      lbl_803B488C
	lis      r3, lbl_80495898@ha
	lis      r5, lbl_804958B4@ha
	addi     r3, r3, lbl_80495898@l
	li       r4, 0x29a
	addi     r5, r5, lbl_804958B4@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B488C:
	lwz      r0, 0x14(r30)
	cmplwi   r0, 0
	bne      lbl_803B48B4
	lis      r3, lbl_80495898@ha
	lis      r5, lbl_804958B4@ha
	addi     r3, r3, lbl_80495898@l
	li       r4, 0x29b
	addi     r5, r5, lbl_804958B4@l
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B48B4:
	lwz      r6, 0x10(r30)
	addi     r3, r1, 0x2c
	addi     r4, r1, 0x20
	addi     r5, r1, 0x14
	lfs      f0, 0(r6)
	stfs     f0, 0x20(r1)
	lfs      f0, 4(r6)
	stfs     f0, 0x24(r1)
	lfs      f0, 8(r6)
	stfs     f0, 0x28(r1)
	lwz      r6, 0x14(r30)
	lfs      f0, 0(r6)
	stfs     f0, 0x14(r1)
	lfs      f0, 4(r6)
	stfs     f0, 0x18(r1)
	lfs      f0, 8(r6)
	stfs     f0, 0x1c(r1)
	bl       "makeMtxZAxisAlongPosPos__3efxFPA4_fR10Vector3<f>R10Vector3<f>"
	addi     r3, r1, 0x2c
	addi     r4, r31, 0x68
	addi     r5, r31, 0xa4
	bl       "JPASetRMtxTVecfromMtx__FPA4_CfPA4_fPQ29JGeometry8TVec3<f>"
	lwz      r4, 0x14(r30)
	lwz      r3, 0x10(r30)
	lfs      f0, 4(r4)
	lfs      f1, 4(r3)
	lfs      f3, 0(r3)
	fsubs    f4, f1, f0
	lfs      f2, 0(r4)
	lfs      f1, 8(r3)
	lfs      f0, 8(r4)
	fsubs    f3, f3, f2
	fmuls    f4, f4, f4
	fsubs    f2, f1, f0
	lfs      f0, lbl_8051F638@sda21(r2)
	fmadds   f1, f3, f3, f4
	fmuls    f2, f2, f2
	fadds    f1, f2, f1
	fcmpo    cr0, f1, f0
	ble      lbl_803B4964
	ble      lbl_803B4968
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_803B4968

lbl_803B4964:
	fmr      f1, f0

lbl_803B4968:
	lfs      f0, lbl_8051F648@sda21(r2)
	lfs      f3, 0(r31)
	fdivs    f0, f1, f0
	lfs      f2, 4(r31)
	lfs      f1, 8(r31)
	stfs     f2, 0xc(r1)
	stfs     f3, 0(r31)
	stfs     f3, 8(r1)
	stfs     f0, 4(r31)
	stfs     f1, 0x10(r1)
	stfs     f0, 0xc(r1)
	stfs     f1, 8(r31)
	lwz      r31, 0x6c(r1)
	lwz      r30, 0x68(r1)
	lwz      r0, 0x74(r1)
	mtlr     r0
	addi     r1, r1, 0x70
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B49B0
 * Size:	0000DC
 */
void THibaFire::setRateLOD(int id)
{
	f32 lods[4][3] = {
		{ 0.2f, 0.2f, 0.2f },
		{ 1.0f, 1.0f, 1.0f },
		{ 0.082f, 0.05f, 0.0f },
		{ 2.3f, 1.7f, 0.0f },
	};

	for (int i = 0; i < 4; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->_28 = lods[i][id];
	}
	/*
	stwu     r1, -0x50(r1)
	lis      r5, lbl_804958FC@ha
	slwi     r0, r4, 2
	stmw     r27, 0x3c(r1)
	addi     r29, r5, lbl_804958FC@l
	addi     r27, r1, 8
	add      r27, r27, r0
	lwz      r28, 0xc(r3)
	lwz      r30, 0(r29)
	lwz      r31, 4(r29)
	cmplwi   r28, 0
	lwz      r12, 8(r29)
	lwz      r11, 0xc(r29)
	lwz      r10, 0x10(r29)
	lwz      r9, 0x14(r29)
	lwz      r8, 0x18(r29)
	lwz      r7, 0x1c(r29)
	lwz      r6, 0x20(r29)
	lwz      r5, 0x24(r29)
	lwz      r4, 0x28(r29)
	lwz      r0, 0x2c(r29)
	stw      r30, 8(r1)
	stw      r31, 0xc(r1)
	stw      r12, 0x10(r1)
	stw      r11, 0x14(r1)
	stw      r10, 0x18(r1)
	stw      r9, 0x1c(r1)
	stw      r8, 0x20(r1)
	stw      r7, 0x24(r1)
	stw      r6, 0x28(r1)
	stw      r5, 0x2c(r1)
	stw      r4, 0x30(r1)
	stw      r0, 0x34(r1)
	beq      lbl_803B4A40
	lfs      f0, 0(r27)
	stfs     f0, 0x28(r28)

lbl_803B4A40:
	lwz      r28, 0x1c(r3)
	cmplwi   r28, 0
	beq      lbl_803B4A54
	lfs      f0, 0xc(r27)
	stfs     f0, 0x28(r28)

lbl_803B4A54:
	addi     r3, r3, 0x20
	lwz      r28, 0xc(r3)
	cmplwi   r28, 0
	beq      lbl_803B4A6C
	lfs      f0, 0x18(r27)
	stfs     f0, 0x28(r28)

lbl_803B4A6C:
	lwz      r28, 0x1c(r3)
	cmplwi   r28, 0
	beq      lbl_803B4A80
	lfs      f0, 0x24(r27)
	stfs     f0, 0x28(r28)

lbl_803B4A80:
	lmw      r27, 0x3c(r1)
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B4A8C
 * Size:	0000C0
 */
bool TGasuHiba::create(Arg* arg)
{
	bool nameCheck = strcmp("ArgGasuHiba", arg->getName()) == 0;
	P2ASSERTLINE(714, nameCheck);

	if (static_cast<ArgGasuHiba*>(arg)->mIsUnderground) {
		mItems[0].mEffectID = PID_GasuHiba_3;
		mItems[1].mEffectID = PID_GasuHiba_4;
	} else {
		mItems[0].mEffectID = PID_GasuHiba_1;
		mItems[1].mEffectID = PID_GasuHiba_2;
	}

	return TSyncGroup2<TForever>::create(arg);
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	mr       r30, r4
	lis      r4, lbl_80495898@ha
	stw      r29, 0x14(r1)
	mr       r29, r3
	mr       r3, r30
	addi     r31, r4, lbl_80495898@l
	lwz      r12, 0(r30)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r31, 0x94
	bl       strcmp
	cntlzw   r0, r3
	rlwinm.  r0, r0, 0x1b, 0x18, 0x1f
	bne      lbl_803B4AF4
	addi     r3, r31, 0
	addi     r5, r31, 0x1c
	li       r4, 0x2ca
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B4AF4:
	lbz      r0, 0x10(r30)
	mr       r4, r30
	cmplwi   r0, 0
	beq      lbl_803B4B18
	li       r3, 0x2b4
	li       r0, 0x2b5
	sth      r3, 0x10(r29)
	sth      r0, 0x20(r29)
	b        lbl_803B4B28

lbl_803B4B18:
	li       r3, 0x74
	li       r0, 0x75
	sth      r3, 0x10(r29)
	sth      r0, 0x20(r29)

lbl_803B4B28:
	mr       r3, r29
	bl       "create__Q23efx28TSyncGroup2<Q23efx8TForever>FPQ23efx3Arg"
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B4B4C
 * Size:	000078
 */
void TGasuHiba::setRateLOD(int id)
{
	f32 lods[2][3] = {
		{ 0.5f, 0.4f, 0.25f },
		{ 0.35f, 0.2f, 0.1f },
	};

	for (int i = 0; i < 2; i++) {
		if (mItems[i].mEmitter)
			mItems[i].mEmitter->_28 = lods[i][id];
	}
	/*
	stwu     r1, -0x20(r1)
	lis      r5, lbl_80495938@ha
	addi     r9, r5, lbl_80495938@l
	slwi     r0, r4, 2
	lwz      r10, 0xc(r3)
	addi     r11, r1, 8
	lwz      r8, 0(r9)
	add      r11, r11, r0
	lwz      r7, 4(r9)
	cmplwi   r10, 0
	lwz      r6, 8(r9)
	lwz      r5, 0xc(r9)
	lwz      r4, 0x10(r9)
	lwz      r0, 0x14(r9)
	stw      r8, 8(r1)
	stw      r7, 0xc(r1)
	stw      r6, 0x10(r1)
	stw      r5, 0x14(r1)
	stw      r4, 0x18(r1)
	stw      r0, 0x1c(r1)
	beq      lbl_803B4BA8
	lfs      f0, 0(r11)
	stfs     f0, 0x28(r10)

lbl_803B4BA8:
	lwz      r10, 0x1c(r3)
	cmplwi   r10, 0
	beq      lbl_803B4BBC
	lfs      f0, 0xc(r11)
	stfs     f0, 0x28(r10)

lbl_803B4BBC:
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B4BC4
 * Size:	000218
 */
bool TDenkiHiba::create(Arg*)
{
	/*
	stwu     r1, -0x80(r1)
	mflr     r0
	stw      r0, 0x84(r1)
	stmw     r27, 0x6c(r1)
	mr       r27, r4
	lis      r4, lbl_80495898@ha
	mr       r31, r3
	mr       r3, r27
	addi     r30, r4, lbl_80495898@l
	lwz      r12, 0(r27)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r30, 0xb8
	bl       strcmp
	cntlzw   r0, r3
	rlwinm.  r0, r0, 0x1b, 0x18, 0x1f
	bne      lbl_803B4C24
	addi     r3, r30, 0
	addi     r5, r30, 0x1c
	li       r4, 0x2ef
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B4C24:
	lfs      f0, 0x10(r27)
	mr       r3, r31
	mr       r4, r27
	stfs     f0, 0x2c(r1)
	lfs      f0, 0x14(r27)
	stfs     f0, 0x30(r1)
	lfs      f0, 0x18(r27)
	stfs     f0, 0x34(r1)
	lfs      f0, 0x1c(r27)
	stfs     f0, 0x20(r1)
	lfs      f0, 0x20(r27)
	stfs     f0, 0x24(r1)
	lfs      f0, 0x24(r27)
	stfs     f0, 0x28(r1)
	bl       "create__Q23efx28TSyncGroup3<Q23efx8TForever>FPQ23efx3Arg"
	clrlwi.  r0, r3, 0x18
	beq      lbl_803B4DC4
	addi     r3, r1, 0x38
	addi     r4, r1, 0x2c
	addi     r5, r1, 0x20
	bl       "makeMtxZAxisAlongPosPos__3efxFPA4_fR10Vector3<f>R10Vector3<f>"
	li       r28, 0
	mr       r29, r31

lbl_803B4C80:
	lwz      r30, 0xc(r29)
	cmplwi   r30, 0
	beq      lbl_803B4CF4
	addi     r3, r1, 0x38
	addi     r4, r30, 0x68
	addi     r5, r30, 0xa4
	bl       "JPASetRMtxTVecfromMtx__FPA4_CfPA4_fPQ29JGeometry8TVec3<f>"
	lwz      r0, 0x28(r27)
	cmpwi    r0, 1
	bne      lbl_803B4CCC
	li       r3, 0xff
	li       r0, 0
	stb      r3, 0xb8(r30)
	stb      r0, 0xb9(r30)
	stb      r0, 0xba(r30)
	stb      r3, 0xbc(r30)
	stb      r0, 0xbd(r30)
	stb      r0, 0xbe(r30)
	b        lbl_803B4CF4

lbl_803B4CCC:
	cmpwi    r0, 2
	bne      lbl_803B4CF4
	li       r3, 0
	li       r0, 0xff
	stb      r3, 0xb8(r30)
	stb      r3, 0xb9(r30)
	stb      r0, 0xba(r30)
	stb      r3, 0xbc(r30)
	stb      r3, 0xbd(r30)
	stb      r0, 0xbe(r30)

lbl_803B4CF4:
	addi     r28, r28, 1
	addi     r29, r29, 0x10
	cmpwi    r28, 3
	blt      lbl_803B4C80
	lfs      f1, 0x30(r1)
	lfs      f0, 0x24(r1)
	lfs      f3, 0x2c(r1)
	fsubs    f4, f1, f0
	lfs      f2, 0x20(r1)
	lfs      f1, 0x34(r1)
	lfs      f0, 0x28(r1)
	fsubs    f3, f3, f2
	fmuls    f4, f4, f4
	fsubs    f2, f1, f0
	lfs      f0, lbl_8051F638@sda21(r2)
	fmadds   f1, f3, f3, f4
	fmuls    f2, f2, f2
	fadds    f2, f2, f1
	fcmpo    cr0, f2, f0
	ble      lbl_803B4D54
	ble      lbl_803B4D58
	frsqrte  f0, f2
	fmuls    f2, f0, f2
	b        lbl_803B4D58

lbl_803B4D54:
	fmr      f2, f0

lbl_803B4D58:
	lfs      f0, lbl_8051F648@sda21(r2)
	li       r3, 1
	lfs      f1, lbl_8051F64C@sda21(r2)
	fdivs    f4, f2, f0
	lwz      r4, 0xc(r31)
	stfs     f1, 0x14(r1)
	stfs     f1, 0(r4)
	stfs     f1, 4(r4)
	stfs     f1, 0x18(r1)
	stfs     f4, 8(r4)
	lwz      r4, 0x1c(r31)
	stfs     f4, 0x1c(r1)
	stfs     f1, 0(r4)
	stfs     f4, 4(r4)
	stfs     f1, 8(r4)
	lwz      r4, 0x2c(r31)
	stfs     f1, 8(r1)
	lfs      f2, 4(r4)
	lfs      f3, 8(r4)
	lfs      f0, 0(r4)
	fmuls    f2, f2, f4
	stfs     f4, 0xc(r1)
	stfs     f0, 0(r4)
	stfs     f2, 4(r4)
	stfs     f1, 0x10(r1)
	stfs     f3, 8(r4)
	b        lbl_803B4DC8

lbl_803B4DC4:
	li       r3, 0

lbl_803B4DC8:
	lmw      r27, 0x6c(r1)
	lwz      r0, 0x84(r1)
	mtlr     r0
	addi     r1, r1, 0x80
	blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void TDenkiHiba::setRateLOD(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	803B4DDC
 * Size:	000128
 */
bool TDenkiHibaMgr::create(Arg*)
{
	/*
	stwu     r1, -0x40(r1)
	mflr     r0
	stw      r0, 0x44(r1)
	stw      r31, 0x3c(r1)
	stw      r30, 0x38(r1)
	mr       r30, r4
	lis      r4, lbl_80495898@ha
	stw      r29, 0x34(r1)
	mr       r29, r3
	mr       r3, r30
	addi     r31, r4, lbl_80495898@l
	lwz      r12, 0(r30)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r3
	addi     r3, r31, 0xb8
	bl       strcmp
	cntlzw   r0, r3
	rlwinm.  r0, r0, 0x1b, 0x18, 0x1f
	bne      lbl_803B4E44
	addi     r3, r31, 0
	addi     r5, r31, 0x1c
	li       r4, 0x340
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803B4E44:
	lfs      f0, 0x10(r30)
	lis      r3, __vt__Q23efx3Arg@ha
	addi     r0, r3, __vt__Q23efx3Arg@l
	addi     r3, r29, 0x80
	stfs     f0, 0xa0(r29)
	addi     r4, r1, 0x18
	lfs      f0, 0x14(r30)
	stfs     f0, 0xa4(r29)
	lfs      f0, 0x18(r30)
	stfs     f0, 0xa8(r29)
	lfs      f0, 0x1c(r30)
	stfs     f0, 0xac(r29)
	lfs      f0, 0x20(r30)
	stfs     f0, 0xb0(r29)
	lfs      f0, 0x24(r30)
	stfs     f0, 0xb4(r29)
	stw      r0, 0x18(r1)
	lfs      f0, 0xa0(r29)
	stfs     f0, 0x1c(r1)
	lfs      f0, 0xa4(r29)
	stfs     f0, 0x20(r1)
	lfs      f0, 0xa8(r29)
	stfs     f0, 0x24(r1)
	stw      r0, 8(r1)
	lfs      f0, 0xac(r29)
	stfs     f0, 0xc(r1)
	lfs      f0, 0xb0(r29)
	stfs     f0, 0x10(r1)
	lfs      f0, 0xb4(r29)
	stfs     f0, 0x14(r1)
	lwz      r12, 0x80(r29)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	addi     r3, r29, 0x90
	addi     r4, r1, 8
	lwz      r12, 0x90(r29)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x44(r1)
	li       r3, 1
	lwz      r31, 0x3c(r1)
	lwz      r30, 0x38(r1)
	lwz      r29, 0x34(r1)
	mtlr     r0
	addi     r1, r1, 0x40
	blr
	*/
}

/*
 * --INFO--
 * Address:	803B4F04
 * Size:	000178
 */
void TDenkiHibaMgr::createHiba(int)
{
	/*
	stwu     r1, -0x80(r1)
	mflr     r0
	lis      r6, __vt__Q23efx3Arg@ha
	stw      r0, 0x84(r1)
	addi     r6, r6, __vt__Q23efx3Arg@l
	stw      r31, 0x7c(r1)
	mr       r31, r3
	lwz      r12, 0xac(r3)
	lis      r3, "zero__10Vector3<f>"@ha
	lwz      r11, 0xb0(r31)
	addi     r5, r3, "zero__10Vector3<f>"@l
	lwz      r10, 0xb4(r31)
	lis      r3, __vt__Q23efx12ArgDenkiHiba@ha
	lwz      r9, 0xa0(r31)
	addi     r0, r3, __vt__Q23efx12ArgDenkiHiba@l
	lwz      r8, 0xa4(r31)
	addi     r3, r31, 4
	lwz      r7, 0xa8(r31)
	stw      r12, 8(r1)
	lfs      f8, 0(r5)
	stw      r11, 0xc(r1)
	lfs      f7, 4(r5)
	stw      r10, 0x10(r1)
	lfs      f6, 8(r5)
	stw      r9, 0x14(r1)
	lfs      f2, 8(r1)
	stw      r8, 0x18(r1)
	lfs      f5, 0x14(r1)
	stw      r7, 0x1c(r1)
	lfs      f4, 0x18(r1)
	stw      r6, 0x40(r1)
	lfs      f3, 0x1c(r1)
	lfs      f1, 0xc(r1)
	lfs      f0, 0x10(r1)
	stw      r4, 0x68(r1)
	addi     r4, r1, 0x40
	stfs     f8, 0x44(r1)
	stfs     f7, 0x48(r1)
	stfs     f6, 0x4c(r1)
	stw      r0, 0x40(r1)
	stfs     f5, 0x50(r1)
	stfs     f4, 0x54(r1)
	stfs     f3, 0x58(r1)
	stfs     f2, 0x5c(r1)
	stfs     f1, 0x60(r1)
	stfs     f0, 0x64(r1)
	lwz      r12, 4(r31)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lis      r4, __vt__Q23efx3Arg@ha
	addi     r3, r31, 0x38
	addi     r0, r4, __vt__Q23efx3Arg@l
	addi     r4, r1, 0x30
	stw      r0, 0x30(r1)
	lfs      f0, 0xa0(r31)
	stfs     f0, 0x34(r1)
	lfs      f0, 0xa4(r31)
	stfs     f0, 0x38(r1)
	lfs      f0, 0xa8(r31)
	stfs     f0, 0x3c(r1)
	stw      r0, 0x20(r1)
	lfs      f0, 0xac(r31)
	stfs     f0, 0x24(r1)
	lfs      f0, 0xb0(r31)
	stfs     f0, 0x28(r1)
	lfs      f0, 0xb4(r31)
	stfs     f0, 0x2c(r1)
	lwz      r12, 0x38(r31)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	addi     r3, r31, 0x5c
	addi     r4, r1, 0x20
	lwz      r12, 0x5c(r31)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	addi     r3, r31, 0x80
	lwz      r12, 0x80(r31)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	addi     r3, r31, 0x90
	lwz      r12, 0x90(r31)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x84(r1)
	li       r3, 1
	lwz      r31, 0x7c(r1)
	mtlr     r0
	addi     r1, r1, 0x80
	blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000174
 */
void TDenkiHibaMgr::createHiba()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	803B507C
 * Size:	00008C
 */
void TDenkiHibaMgr::forceKill()
{
	mHiba.forceKill();
	mPoles[0].forceKill();
	mPoles[1].forceKill();
	mPolesigns[0].forceKill();
	mPolesigns[1].forceKill();
}

/*
 * --INFO--
 * Address:	803B5108
 * Size:	00008C
 */
void TDenkiHibaMgr::fade()
{
	mHiba.fade();
	mPoles[0].fade();
	mPoles[1].fade();
	mPolesigns[0].fade();
	mPolesigns[1].fade();
}

/*
 * --INFO--
 * Address:	803B5194
 * Size:	0000B4
 */
void TDenkiHibaMgr::setRateLOD(int)
{
	/*
	stwu     r1, -0x40(r1)
	lis      r5, lbl_80495960@ha
	addi     r12, r5, lbl_80495960@l
	slwi     r0, r4, 2
	stw      r31, 0x3c(r1)
	stw      r30, 0x38(r1)
	addi     r30, r1, 8
	add      r30, r30, r0
	lwz      r31, 0x10(r3)
	lwz      r11, 0(r12)
	lwz      r10, 4(r12)
	cmplwi   r31, 0
	lwz      r9, 8(r12)
	lwz      r8, 0xc(r12)
	lwz      r7, 0x10(r12)
	lwz      r6, 0x14(r12)
	lwz      r5, 0x18(r12)
	lwz      r4, 0x1c(r12)
	lwz      r0, 0x20(r12)
	stw      r11, 8(r1)
	stw      r10, 0xc(r1)
	stw      r9, 0x10(r1)
	stw      r8, 0x14(r1)
	stw      r7, 0x18(r1)
	stw      r6, 0x1c(r1)
	stw      r5, 0x20(r1)
	stw      r4, 0x24(r1)
	stw      r0, 0x28(r1)
	beq      lbl_803B5210
	lfs      f0, 0(r30)
	stfs     f0, 0x28(r31)

lbl_803B5210:
	lwz      r31, 0x20(r3)
	cmplwi   r31, 0
	beq      lbl_803B5224
	lfs      f0, 0xc(r30)
	stfs     f0, 0x28(r31)

lbl_803B5224:
	lwz      r31, 0x30(r3)
	cmplwi   r31, 0
	beq      lbl_803B5238
	lfs      f0, 0x18(r30)
	stfs     f0, 0x28(r31)

lbl_803B5238:
	lwz      r31, 0x3c(r1)
	lwz      r30, 0x38(r1)
	addi     r1, r1, 0x40
	blr
	*/
}

} // namespace efx
