#include "PikiAI.h"
#include "Game/Piki.h"
#include "Game/PikiState.h"
#include "Game/MapMgr.h"
#include "Game/routeMgr.h"

static const char className[] = "actRescue";

namespace PikiAI {
/*
 * --INFO--
 * Address:	80238EB0
 * Size:	0000B8
 */
ActRescue::ActRescue(Game::Piki* piki)
    : Action(piki)
{
	mFlag        = false;
	mName        = "Rescue";
	mApproachPos = new ActApproachPos(piki);
}

/*
 * --INFO--
 * Address:	80238F68
 * Size:	0000C4
 */
void ActRescue::init(ActionArg* arg)
{
	P2ASSERTLINE(46, arg);

	ActRescueArg* sarg = static_cast<ActRescueArg*>(arg);
	bool check         = false;
	if (sarg->mTarget) {
		if (sarg->mTarget->isPiki()) {
			check = true;
		}
	}
	P2ASSERTLINE(48, check);

	mTargetPiki = sarg->mTarget;
	mWayPoint   = nullptr;
	initApproach();
}

/*
 * --INFO--
 * Address:	8023902C
 * Size:	000060
 */
int ActRescue::exec()
{
	switch (mState) {
	case 0:
		return execApproach();
	case 1:
		return execGo();
	case 2:
		return execThrow();
	default:
		return ACTEXEC_Continue;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
int ActRescue::checkPikmin()
{
	if (!mTargetPiki->isAlive()) {
		return ACTEXEC_Fail;
	} else {
		int state = mTargetPiki->getStateID();
		if (state != Game::PIKISTATE_WaterHanged && state != Game::PIKISTATE_Drown && !mTargetPiki->inWater()) {
			return 0;
		} else {
			if (state == Game::PIKISTATE_WaterHanged
			    && static_cast<Game::PikiWaterHangedState*>(mTargetPiki->mCurrentState)->mPiki != mParent) {
				return 0;
			} else {
				return 1;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8023908C
 * Size:	0000AC
 */
void ActRescue::initApproach()
{
	mState       = 0;
	Vector3f pos = mTargetPiki->getPosition();
	ApproachPosActionArg arg(pos, 10.0f, -1.0f, 0, 0);
	mApproachPos->init(&arg);
}

/*
 * --INFO--
 * Address:	80239138
 * Size:	00013C
 */
int ActRescue::execApproach()
{
	int ret = checkPikmin();
	switch (ret) {
	case 1:
		Vector3f pos            = mTargetPiki->getPosition();
		mApproachPos->mPosition = pos;
		int state               = mApproachPos->exec();
		if (state == 0) {
			initGo();
		} else if (state == 2) {
			ret = ACTEXEC_Fail;
		} else {
			ret = ACTEXEC_Continue;
		}
		break;
	}
	return ret;
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	mr       r30, r3
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0xa8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_80239174
	li       r3, 2
	b        lbl_802391E0

lbl_80239174:
	lwz      r3, 0x1c(r30)
	bl       getStateID__Q24Game4PikiFv
	mr       r31, r3
	cmpwi    r31, 5
	beq      lbl_802391B4
	cmpwi    r31, 0xa
	beq      lbl_802391B4
	lwz      r3, 0x1c(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0x8c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_802391B4
	li       r3, 0
	b        lbl_802391E0

lbl_802391B4:
	cmpwi    r31, 5
	bne      lbl_802391DC
	lwz      r3, 0x1c(r30)
	lwz      r0, 4(r30)
	lwz      r3, 0x290(r3)
	lwz      r3, 0x14(r3)
	cmplw    r3, r0
	beq      lbl_802391DC
	li       r3, 0
	b        lbl_802391E0

lbl_802391DC:
	li       r3, 1

lbl_802391E0:
	cmpwi    r3, 1
	beq      lbl_802391EC
	b        lbl_8023925C

lbl_802391EC:
	lwz      r4, 0x1c(r30)
	addi     r3, r1, 8
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f1, 0xc(r1)
	lfs      f2, 0x10(r1)
	lwz      r3, 0x18(r30)
	lfs      f0, 8(r1)
	stfs     f0, 0x10(r3)
	stfs     f1, 0x14(r3)
	stfs     f2, 0x18(r3)
	lwz      r3, 0x18(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0
	bne      lbl_80239248
	mr       r3, r30
	bl       initGo__Q26PikiAI9ActRescueFv
	b        lbl_80239258

lbl_80239248:
	cmpwi    r3, 2
	bne      lbl_80239258
	li       r3, 2
	b        lbl_8023925C

lbl_80239258:
	li       r3, 1

lbl_8023925C:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80239274
 * Size:	000150
 */
void ActRescue::initGo()
{
	mState = 1;
	WPFindCond cond;
	Vector3f pos = mTargetPiki->getPosition();
	Game::WPSearchArg arg(pos, &cond, false, 10.0f);
	mWayPoint = Game::mapMgr->mRouteMgr->getNearestWayPoint(arg);
	if (mWayPoint) {
		ApproachPosActionArg arg(mWayPoint->mPosition, 250.0f, -1.0f, 0, 0);
		mApproachPos->init(&arg);
		Game::WaterHangedStateArg statearg(mParent);
		mTargetPiki->mFsm->transit(mTargetPiki, Game::PIKISTATE_WaterHanged, &statearg);
	}
	mTimeLimit = 100;
}

/*
 * --INFO--
 * Address:	802393C4
 * Size:	0001C0
 */
int ActRescue::execGo()
{
	int ret = checkPikmin();
	switch (ret) {
	case 1:
		if (!mWayPoint) {
			ret = ACTEXEC_Fail;
		} else {
			ret = mApproachPos->exec();
			if (!mTimeLimit--) {
				ret = ACTEXEC_Success;
			}

			if (ret == ACTEXEC_Success) {
				initThrow();
			} else if (ret == ACTEXEC_Fail) {
				return ACTEXEC_Fail;
			}

			SysShape::Joint* jnt = mParent->mModel->getJoint("rhandjnt");
			P2ASSERTLINE(220, jnt);
			Vector3f mod(0.0f, 3.0f, 0.0f);
			Matrixf* mtx = jnt->getWorldMatrix();
			Vec pos;
			PSMTXMultVec(mtx->mMatrix.mtxView, (Vec*)&mod, &pos);
			Vector3f newpos(pos.x, pos.y, pos.z);
			mTargetPiki->setPosition(newpos, false);
			ret = ACTEXEC_Continue;
		}
		break;
	}
	return ret;
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	lis      r4, lbl_80483CD0@ha
	stw      r0, 0x34(r1)
	stw      r31, 0x2c(r1)
	addi     r31, r4, lbl_80483CD0@l
	stw      r30, 0x28(r1)
	mr       r30, r3
	stw      r29, 0x24(r1)
	lwz      r3, 0x1c(r3)
	lwz      r12, 0(r3)
	lwz      r12, 0xa8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8023940C
	li       r3, 2
	b        lbl_80239478

lbl_8023940C:
	lwz      r3, 0x1c(r30)
	bl       getStateID__Q24Game4PikiFv
	mr       r29, r3
	cmpwi    r29, 5
	beq      lbl_8023944C
	cmpwi    r29, 0xa
	beq      lbl_8023944C
	lwz      r3, 0x1c(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0x8c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_8023944C
	li       r3, 0
	b        lbl_80239478

lbl_8023944C:
	cmpwi    r29, 5
	bne      lbl_80239474
	lwz      r3, 0x1c(r30)
	lwz      r0, 4(r30)
	lwz      r3, 0x290(r3)
	lwz      r3, 0x14(r3)
	cmplw    r3, r0
	beq      lbl_80239474
	li       r3, 0
	b        lbl_80239478

lbl_80239474:
	li       r3, 1

lbl_80239478:
	cmpwi    r3, 1
	beq      lbl_80239484
	b        lbl_80239568

lbl_80239484:
	lwz      r0, 0x20(r30)
	cmplwi   r0, 0
	bne      lbl_80239498
	li       r3, 2
	b        lbl_80239568

lbl_80239498:
	lwz      r3, 0x18(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	lbz      r4, 0x24(r30)
	addi     r4, r4, -1
	clrlwi.  r0, r4, 0x18
	stb      r4, 0x24(r30)
	bne      lbl_802394C4
	li       r3, 0

lbl_802394C4:
	cmpwi    r3, 0
	bne      lbl_802394D8
	mr       r3, r30
	bl       initThrow__Q26PikiAI9ActRescueFv
	b        lbl_802394E8

lbl_802394D8:
	cmpwi    r3, 2
	bne      lbl_802394E8
	li       r3, 2
	b        lbl_80239568

lbl_802394E8:
	lwz      r3, 4(r30)
	addi     r4, r31, 0x28
	lwz      r3, 0x174(r3)
	bl       getJoint__Q28SysShape5ModelFPc
	or.      r29, r3, r3
	bne      lbl_80239514
	addi     r3, r31, 0xc
	addi     r5, r31, 0x1c
	li       r4, 0xdc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80239514:
	lfs      f0, lbl_8051A508@sda21(r2)
	mr       r3, r29
	lfs      f1, lbl_8051A504@sda21(r2)
	stfs     f0, 0x18(r1)
	stfs     f1, 0x14(r1)
	stfs     f0, 0x1c(r1)
	bl       getWorldMatrix__Q28SysShape5JointFv
	addi     r4, r1, 0x14
	addi     r5, r1, 8
	bl       PSMTXMultVec
	lfs      f2, 8(r1)
	addi     r4, r1, 0x14
	lfs      f1, 0xc(r1)
	li       r5, 0
	lfs      f0, 0x10(r1)
	stfs     f2, 0x14(r1)
	stfs     f1, 0x18(r1)
	stfs     f0, 0x1c(r1)
	lwz      r3, 0x1c(r30)
	bl       "setPosition__Q24Game8CreatureFR10Vector3<f>b"
	li       r3, 1

lbl_80239568:
	lwz      r0, 0x34(r1)
	lwz      r31, 0x2c(r1)
	lwz      r30, 0x28(r1)
	lwz      r29, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	80239584
 * Size:	000064
 */
void ActRescue::initThrow()
{
	mState = 2;
	mParent->startMotion(Game::IPikiAnims::THROW, Game::IPikiAnims::THROW, this, nullptr);
	mFlag = 0;
}

/*
 * --INFO--
 * Address:	802395E8
 * Size:	000278
 */
int ActRescue::execThrow()
{
	if (!mParent->assertMotion(Game::IPikiAnims::THROW)) {
		return ACTEXEC_Fail;
	}

	if (!(mFlag & 1) && mFlag & 2) {
		return ACTEXEC_Success;
	}

	mTargetPiki->mBrain->start(1, nullptr);
	mTargetPiki->mFsm->transit(mTargetPiki, Game::PIKISTATE_Flying, nullptr);
	mState = 0;
	mTargetPiki->getPosition();
	// this rest of this seems to be a direct copy of Navi::throwPiki?
	return ACTEXEC_Continue;
	/*
	stwu     r1, -0x80(r1)
	mflr     r0
	stw      r0, 0x84(r1)
	stfd     f31, 0x70(r1)
	psq_st   f31, 120(r1), 0, qr0
	stfd     f30, 0x60(r1)
	psq_st   f30, 104(r1), 0, qr0
	stfd     f29, 0x50(r1)
	psq_st   f29, 88(r1), 0, qr0
	stfd     f28, 0x40(r1)
	psq_st   f28, 72(r1), 0, qr0
	stw      r31, 0x3c(r1)
	mr       r31, r3
	li       r4, 0x21
	lwz      r3, 4(r3)
	bl       assertMotion__Q24Game8FakePikiFi
	clrlwi.  r0, r3, 0x18
	bne      lbl_80239638
	li       r3, 2
	b        lbl_8023982C

lbl_80239638:
	lbz      r3, 0x14(r31)
	clrlwi.  r0, r3, 0x1f
	beq      lbl_80239818
	lwz      r3, 0x1c(r31)
	li       r4, 1
	li       r5, 0
	lwz      r3, 0x294(r3)
	bl       start__Q26PikiAI5BrainFiPQ26PikiAI9ActionArg
	lwz      r4, 0x1c(r31)
	li       r5, 6
	li       r6, 0
	lwz      r3, 0x28c(r4)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	li       r0, 0
	addi     r3, r1, 8
	stb      r0, 0x14(r31)
	lwz      r4, 4(r31)
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lwz      r3, 0x20(r31)
	lfs      f0, 0x10(r1)
	lfs      f2, 0x54(r3)
	lfs      f1, 0x4c(r3)
	fsubs    f2, f2, f0
	lfs      f0, 8(r1)
	lfs      f4, 0x50(r3)
	lfs      f3, 0xc(r1)
	fsubs    f1, f1, f0
	fmuls    f5, f2, f2
	lfs      f0, lbl_8051A508@sda21(r2)
	fsubs    f29, f4, f3
	fmadds   f30, f1, f1, f5
	fcmpo    cr0, f30, f0
	ble      lbl_802396E4
	ble      lbl_802396E8
	frsqrte  f0, f30
	fmuls    f30, f0, f30
	b        lbl_802396E8

lbl_802396E4:
	fmr      f30, f0

lbl_802396E8:
	lis      r3, atanTable___5JMath@ha
	addi     r3, r3, atanTable___5JMath@l
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	fmr      f31, f1
	bl       roundAng__Ff
	lwz      r3, 0x1c(r31)
	fabs     f29, f29
	lfs      f28, lbl_8051A50C@sda21(r2)
	stfs     f1, 0x1fc(r3)
	lwz      r3, 0x1c(r31)
	bl       getThrowHeight__Q24Game4PikiFv
	frsp     f2, f29
	lwz      r5, 0x1c(r31)
	lfs      f0, lbl_8051A510@sda21(r2)
	lbz      r0, 0x2b8(r5)
	fadds    f1, f1, f2
	cmpwi    r0, 3
	fadds    f2, f0, f1
	bne      lbl_8023973C
	lfs      f0, lbl_8051A50C@sda21(r2)
	fmuls    f28, f28, f0

lbl_8023973C:
	lfs      f1, lbl_8051A514@sda21(r2)
	fdivs    f2, f2, f28
	lwz      r3, _aiConstants__4Game@sda21(r13)
	lfs      f0, lbl_8051A508@sda21(r2)
	lfs      f4, lbl_8051A50C@sda21(r2)
	lfs      f3, 0x28(r3)
	fmuls    f1, f1, f28
	fmuls    f3, f4, f3
	fmr      f4, f31
	fdivs    f5, f30, f1
	fcmpo    cr0, f31, f0
	fmadds   f3, f28, f3, f2
	bge      lbl_80239774
	fneg     f4, f31

lbl_80239774:
	lfs      f2, lbl_8051A518@sda21(r2)
	lis      r3, sincosTable___5JMath@ha
	lfs      f0, lbl_8051A508@sda21(r2)
	addi     r4, r3, sincosTable___5JMath@l
	fmuls    f1, f4, f2
	fcmpo    cr0, f31, f0
	fctiwz   f0, f1
	stfd     f0, 0x18(r1)
	lwz      r0, 0x1c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	add      r3, r4, r0
	lfs      f0, 4(r3)
	fmuls    f1, f5, f0
	bge      lbl_802397D0
	lfs      f0, lbl_8051A51C@sda21(r2)
	fmuls    f0, f31, f0
	fctiwz   f0, f0
	stfd     f0, 0x20(r1)
	lwz      r0, 0x24(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r4, r0
	fneg     f0, f0
	b        lbl_802397E8

lbl_802397D0:
	fmuls    f0, f31, f2
	fctiwz   f0, f0
	stfd     f0, 0x28(r1)
	lwz      r0, 0x2c(r1)
	rlwinm   r0, r0, 3, 0x12, 0x1c
	lfsx     f0, r4, r0

lbl_802397E8:
	fmuls    f0, f5, f0
	stfs     f0, 0x200(r5)
	stfs     f3, 0x204(r5)
	stfs     f1, 0x208(r5)
	lwz      r3, 0x1c(r31)
	lfs      f0, 0x200(r3)
	stfs     f0, 0x1e4(r3)
	lfs      f0, 0x204(r3)
	stfs     f0, 0x1e8(r3)
	lfs      f0, 0x208(r3)
	stfs     f0, 0x1ec(r3)
	b        lbl_80239828

lbl_80239818:
	rlwinm.  r0, r3, 0, 0x1e, 0x1e
	beq      lbl_80239828
	li       r3, 0
	b        lbl_8023982C

lbl_80239828:
	li       r3, 1

lbl_8023982C:
	psq_l    f31, 120(r1), 0, qr0
	lfd      f31, 0x70(r1)
	psq_l    f30, 104(r1), 0, qr0
	lfd      f30, 0x60(r1)
	psq_l    f29, 88(r1), 0, qr0
	lfd      f29, 0x50(r1)
	psq_l    f28, 72(r1), 0, qr0
	lfd      f28, 0x40(r1)
	lwz      r0, 0x84(r1)
	lwz      r31, 0x3c(r1)
	mtlr     r0
	addi     r1, r1, 0x80
	blr
	*/
}

/*
 * --INFO--
 * Address:	80239860
 * Size:	00002C
 */
void ActRescue::onKeyEvent(SysShape::KeyEvent const& event)
{
	if (event.mType == 2) {
		mFlag |= 1;
	} else {
		mFlag |= 2;
	}
}

/*
 * --INFO--
 * Address:	8023988C
 * Size:	000004
 */
void ActRescue::emotion_success() { }

/*
 * --INFO--
 * Address:	80239890
 * Size:	000004
 */
void ActRescue::doDirectDraw(Graphics&) { }

/*
 * --INFO--
 * Address:	80239894
 * Size:	000004
 */
void ActRescue::cleanup() { }

/*
 * --INFO--
 * Address:	80239898
 * Size:	000004
 */
void ActRescue::collisionCallback(Game::Piki* piki, Game::CollEvent& event) { }

} // namespace PikiAI
