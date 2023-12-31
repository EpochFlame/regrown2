#include "Game/Entities/Pelplant.h"
#include "Game/EnemyAnimatorBase.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/EnemyFunc.h"
#include "Game/GameSystem.h"
#include "Game/MapMgr.h"

#include "Dolphin/rand.h"

#include "efx/TPplGrow.h"

#include "System.h"

namespace Game {
namespace Pelplant {
/*
 * --INFO--
 * Address:	8010AB38
 * Size:	0001E0
 */
void FSM::init(EnemyBase* enemy)
{
	create(PELPLANT_Count);

	registerState(new StateWait(PELPLANT_WaitSmall, 0));
	registerState(new StateWait(PELPLANT_WaitMiddle, 1));
	registerState(new StateWait(PELPLANT_WaitBig, 2));

	registerState(new StateGrow(PELPLANT_Grow1, 2, 1));
	registerState(new StateGrow(PELPLANT_Grow2, 3, 2));

	registerState(new StateDamage(PELPLANT_Damage, 0));
	registerState(new StateDead(PELPLANT_Dead, 1));

	registerState(new StateWither(PELPLANT_WitherBig, 0, 6, 4));
	registerState(new StateWither(PELPLANT_WitherMiddle, 0, 5, 4));
	registerState(new StateWither(PELPLANT_WitherSmall, 0, 4, 4));
}

/*
 * --INLINED--
 * NB: required to generate vtables in correct order.
 * --INFO--
 * Address:	........
 * Size:	000040
 */
StateBlendAnim::StateBlendAnim(int stateID, int a, int b, int c)
    : State(stateID)
    , _10(a)
    , _14(b)
    , _18(c)
{
}

/*
 * --INFO--
 * Address:	8010AD18
 * Size:	00003C
 */
void StateBlendAnim::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->startBlend(_14, _18, &EnemyBlendAnimatorBase::sBlendQuadraticFun, 30.0f, nullptr);
}

/*
 * --INFO--
 * Address:	8010AD54
 * Size:	00007C
 */
void StateBlendAnim::exec(EnemyBase* enemy)
{
	if (enemy->mCurAnim->mIsPlaying) {
		switch (enemy->mCurAnim->mType) {
		case KEYEVENT_END_BLEND:
			enemy->endBlend();
			transit(enemy, _10, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	8010ADD0
 * Size:	000098
 */
StateWither::StateWither(int stateID, int p1, int p2, int p3)
    : StateBlendAnim(stateID, p1, p2, p3)
{
	switch (stateID) {
	case PELPLANT_WitherBig:
		mName = "wither_big";
		return;
	case PELPLANT_WitherMiddle:
		mName = "wither_Middle";
		return;
	case PELPLANT_WitherSmall:
		mName = "wither_Small";
		return;
	}
}

/*
 * --INFO--
 * Address:	8010AE68
 * Size:	000070
 */
void StateWither::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->startBlend(_14, _18, &EnemyBlendAnimatorBase::sBlendQuadraticFun, 30.0f, nullptr);
	enemy->enableEvent(0, EB_Invulnerable);
	EnemyFunc::flickStickPikmin(enemy, 1.0f, 10.0f, 0.0f, -1000.0f, nullptr);
}

/*
 * --INFO--
 * Address:	8010AED8
 * Size:	00007C
 */
void StateWither::exec(EnemyBase* enemy)
{
	if (enemy->mCurAnim->mIsPlaying) {
		switch (enemy->mCurAnim->mType) {
		case KEYEVENT_END_BLEND:
			enemy->endBlend();
			transit(enemy, _10, 0);
		}
	}
}

/*
 * --INFO--
 * Address:	8010AF54
 * Size:	000028
 */
void StateWither::cleanup(EnemyBase* enemy) { static_cast<Obj*>(enemy)->updateLODSphereRadius(0); }

/*
 * --INFO--
 * Address:	8010AF7C
 * Size:	000088
 */
StateWait::StateWait(int stateID, int pelSize)
    : State(stateID)
{
	mPelSize = pelSize;
	switch (mPelSize) {
	case PELPLANT_SIZE_SMALL:
		mName = "wait_small";
		return;
	case PELPLANT_SIZE_MIDDLE:
		mName = "wait_middle";
		return;
	case PELPLANT_SIZE_BIG:
		mName = "wait_big";
		return;
	}
}

/*
 * --INFO--
 * Address:	8010B004
 * Size:	000144
 */
void StateWait::init(EnemyBase* e, StateArg* stateArg)
{
	Obj* pellet = static_cast<Obj*>(e);

	pellet->disableEvent(0, EB_Cullable);
	RESET_FLAG(pellet->mFlags, PELPLANT_FLAGS_UNK2);
	pellet->enableEvent(0, EB_Invulnerable);

	switch (mPelSize) {
	case PELPLANT_SIZE_SMALL:
		pellet->startMotion(4, nullptr);
		break;
	case PELPLANT_SIZE_MIDDLE:
		pellet->startMotion(5, nullptr);
		break;
	case PELPLANT_SIZE_BIG:
		SET_FLAG(pellet->mFlags, PELPLANT_FLAGS_UNK2);
		pellet->disableEvent(0, EB_Invulnerable);
		pellet->startMotion(6, nullptr);
		pellet->updateLODSphereRadius(2);
		pellet->enableEvent(0, EB_Cullable);
		break;
	}

	Vector3f position = pellet->getPosition();
	position.y        = mapMgr->getMinY(position);

	Obj::sCurrentObj = pellet;
	pellet->setPosition(position, false);
	Obj::sCurrentObj = nullptr;
}

/*
 * --INFO--
 * Address:	8010B148
 * Size:	000278
 */
void StateWait::exec(EnemyBase* enemy)
{
	float frameTime = sys->mDeltaTime;
	if (static_cast<Obj*>(enemy)->mFlags & 1) {
		static_cast<Obj*>(enemy)->_2C0 += frameTime;
	}

	if (enemy->mCurAnim->mIsPlaying) {
		switch (enemy->mCurAnim->mType) {
		case 1000:
		case 1:
			float growth;
			if (gameSystem->mMode == GSM_PIKLOPEDIA) {
				growth = 5.0f * randFloat();
			} else if (mPelSize == 0) {
				growth = CG_PARMS(enemy)->mPelplantParms.mSmallToMedGrowth.mValue;
			} else {
				growth = CG_PARMS(enemy)->mPelplantParms.mMedToLargeGrowth.mValue;
			}

			if ((static_cast<Obj*>(enemy)->_2C0 > growth) || (static_cast<Obj*>(enemy)->mFarmPow > 0)) {
				static_cast<Obj*>(enemy)->_2C0 = 0.0f;
				switch (mPelSize) {
				case PELPLANT_SIZE_SMALL:
					transit(enemy, 3, 0);
					break;
				case PELPLANT_SIZE_MIDDLE:
					transit(enemy, 4, 0);
					break;
				case PELPLANT_SIZE_BIG:
					break;
				}

			} else if (static_cast<Obj*>(enemy)->mFarmPow < 0) {
				switch (mPelSize) {
				case PELPLANT_SIZE_SMALL:
					break;
				case PELPLANT_SIZE_MIDDLE:
					transit(enemy, 8, 0);
					break;
				case PELPLANT_SIZE_BIG:
					transit(enemy, 7, 0);
					break;
				}
			}
		}
	} else {
		static_cast<Obj*>(enemy)->changePelletColor();
		if (enemy->injure()) {
			if (enemy->mHealth <= 0.0f) {
				switch (mPelSize) {
				case PELPLANT_SIZE_BIG:
					transit(enemy, 6, 0);
					return;
				}
			} else {
				switch (mPelSize) {
				case PELPLANT_SIZE_BIG:
					transit(enemy, 5, 0);
					return;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8010B3C0
 * Size:	000004
 */
void StateWait::cleanup(EnemyBase*) { }

/*
 * --INFO--
 * Address:	8010B3C4
 * Size:	000044
 */
StateGrow::StateGrow(int stateID, int p1, int p2)
    : State(stateID)
{
	_10   = p1;
	_14   = p2;
	mName = "grow";
}

/*
 * --INFO--
 * Address:	8010B408
 * Size:	0002E0
 */
void StateGrow::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->enableEvent(0, EB_Invulnerable);

	if (_10 == 3) {
		static_cast<Obj*>(enemy)->attachPellet();
	}

	Vector3f position = enemy->getPosition();
	efx::Arg effectArg(position);

	switch (_14) {
	case 1:
		efx::TPplGrow1 grow1;
		grow1.create(&effectArg);
		enemy->startMotion(_10, nullptr);
		return;
	case 2:
		switch (static_cast<Obj*>(enemy)->mSize) {
		case PELLET_NUMBER_ONE:
			efx::TPplGrow2 grow2;
			grow2.create(&effectArg);
			break;
		case PELLET_NUMBER_FIVE:
			efx::TPpl5Grow2 grow5;
			grow5.create(&effectArg);
			break;
		case PELLET_NUMBER_TEN:
			efx::TPpl10Grow2 grow10;
			grow10.create(&effectArg);
			break;
		case PELLET_NUMBER_TWENTY:
			efx::TPpl20Grow2 grow20;
			grow20.create(&effectArg);
			break;
		}

		static_cast<Obj*>(enemy)->updateLODSphereRadius(2);
		if ((static_cast<Obj*>(enemy)->mSize == 10) || (static_cast<Obj*>(enemy)->mSize == 20)) {
			enemy->startMotion(7, nullptr);
			return;
		}
		enemy->startMotion(_10, nullptr);
		return;
	}
}

/*
 * --INFO--
 * Address:	8010B6E8
 * Size:	000060
 */
void StateGrow::exec(EnemyBase* enemy)
{
	if (enemy->mCurAnim->mIsPlaying != 0) {
		switch (enemy->mCurAnim->mType) {
		case 1000:
		case 1:
			transit(enemy, _14, 0);
		}
	}
}

/*
 * --INFO--
 * Address:	8010B748
 * Size:	000004
 */
void StateGrow::cleanup(Game::EnemyBase*) { }

/*
 * --INFO--
 * Address:	8010B74C
 * Size:	000040
 */
StateDamage::StateDamage(int stateID, int p1)
    : State(stateID)
{
	mName = "damage";
	_10   = p1;
}

/*
 * --INFO--
 * Address:	8010B78C
 * Size:	00008C
 */
void StateDamage::init(EnemyBase* enemy, StateArg* stateArg)
{
	if (_10 != 5) {
		enemy->startMotion(_10, nullptr);
	} else if ((static_cast<Obj*>(enemy)->mSize == 10) || (static_cast<Obj*>(enemy)->mSize == 20)) {
		enemy->startMotion(8, nullptr);
	} else {
		enemy->startMotion(_10, nullptr);
	}

	enemy->disableEvent(0, EB_Invulnerable);
}

/*
 * --INFO--
 * Address:	8010B818
 * Size:	000068
 */
void StateDamage::exec(Game::EnemyBase* enemy)
{
	if ((enemy->mCurAnim->mIsPlaying != 0) && ((u32)enemy->mCurAnim->mType == 0x3E8)) {
		transit(enemy, mStateMachine->mPreviousID, 0);
	}
	static_cast<Obj*>(enemy)->changePelletColor();
}

/*
 * --INFO--
 * Address:	8010B880
 * Size:	000010
 */
void StateDamage::cleanup(EnemyBase* enemy) { enemy->enableEvent(0, EB_Invulnerable); }

/*
 * --INFO--
 * Address:	8010B890
 * Size:	000040
 */
StateDead::StateDead(int stateID, int p1)
    : State(stateID)
{
	mName = "dead";
	_10   = p1;
}

/*
 * --INFO--
 * Address:	8010B8D0
 * Size:	0000B4
 */
void StateDead::init(EnemyBase* enemy, StateArg* stateArg)
{
	if (_10 != 1) {
		enemy->startMotion(_10, nullptr);
	} else if ((static_cast<Obj*>(enemy)->mSize == PELLET_NUMBER_TEN) || (static_cast<Obj*>(enemy)->mSize == PELLET_NUMBER_TWENTY)) {
		enemy->startMotion(9, nullptr);
	} else {
		enemy->startMotion(_10, nullptr);
	}

	enemy->deathProcedure();

	if (_10 != 1) {
		if (static_cast<Obj*>(enemy)->mPellet) {
			static_cast<Obj*>(enemy)->mPellet->kill(nullptr);
			static_cast<Obj*>(enemy)->mPellet = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	8010B984
 * Size:	000068
 */
void StateDead::exec(EnemyBase* enemy)
{
	if ((enemy->mCurAnim->mIsPlaying) && ((u32)enemy->mCurAnim->mType == 1000)) {
		if (static_cast<Obj*>(enemy)->mPellet) {
			static_cast<Obj*>(enemy)->mPellet->endCapture();
			static_cast<Obj*>(enemy)->mPellet = nullptr;
		}
		enemy->kill(nullptr);
	}
}

/*
 * --INFO--
 * Address:	8010B9EC
 * Size:	000004
 */
void StateDead::cleanup(Game::EnemyBase*) { }

} // namespace Pelplant
} // namespace Game
