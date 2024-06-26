#include "og/newScreen/ogUtil.h"
#include "og/Screen/callbackNodes.h"
#include "og/Screen/ogScreen.h"
#include "og/Screen/TotalPokoScreen.h"
#include "og/Sound.h"
#include "System.h"
#include "trig.h"

namespace og {
namespace Screen {

/**
 * @note Address: 0x8032C3AC
 * @note Size: 0xA0
 */
TotalPokoScreen::TotalPokoScreen()
{
	mIsOpen            = false;
	mCurrentPokoCount  = 2469;
	mPreviousPokoCount = mCurrentPokoCount;
	mDisplayPokoCount  = mCurrentPokoCount;
	mCallBackCounterRV = nullptr;
	mPane              = nullptr;
	_160               = 0.0f;
	mStandardPos.x     = 0.0f;
	mStandardPos.y     = 0.0f;
	mCurrPos.x         = 0.0f;
	mCurrPos.y         = 0.0f;
	mTimer             = 0.0f;
	mNeedAdd           = false;
	mScaleMgr          = new ScaleMgr;
}

/**
 * @note Address: 0x8032C44C
 * @note Size: 0x70
 */
void TotalPokoScreen::showTotalPoko()
{
	if (!mIsOpen) {
		mIsOpen  = true;
		mTimer   = 0.8f;
		mNeedAdd = true;

		if (!newScreen::checkMovieActive()) {
			ogSound->setOpenTotalPoko();
		}

		mDisplayPokoCount = mPreviousPokoCount;
		mPane->show();
	}
}

/**
 * @note Address: 0x8032C4BC
 * @note Size: 0x70
 */
void TotalPokoScreen::setTotalPoko(u32 newPokoCount)
{
	mPreviousPokoCount = mCurrentPokoCount;
	mCurrentPokoCount  = newPokoCount;

	if (mIsOpen && !mNeedAdd) {
		mNeedAdd = true;

		if (!newScreen::checkMovieActive()) {
			ogSound->setPlusTotalPoko();
		}
	}
}

/**
 * @note Address: 0x8032C52C
 * @note Size: 0x44
 */
void TotalPokoScreen::closeTotalPoko()
{
	if (mIsOpen) {
		ogSound->setCloseTotalPoko();
		mIsOpen = false;
	}
}

/**
 * @note Address: 0x8032C570
 * @note Size: 0x10
 */
void TotalPokoScreen::hideTotalPoko() { mPane->hide(); }

/**
 * @note Address: 0x8032C580
 * @note Size: 0x138
 */
void TotalPokoScreen::setCallBack(JKRArchive* archive, f32 x, f32 y, f32 scaleX, f32 scaleY)
{
	mCallBackCounterRV = setCallBack_CounterRV(this, 'Ppoko01', &mDisplayPokoCount, 10, false, true, archive);
	mPane              = search('Npoko');
	_160               = 0.0f;
	mStandardPos.x     = x + mPane->mOffset.x;
	mStandardPos.y     = y + mPane->mOffset.y;
	mCurrPos.x         = mStandardPos.x;
	mCurrPos.y         = mStandardPos.y;

	mPane->move(mCurrPos.x, mCurrPos.y);
	J2DPane* pane  = mPane;
	pane->mScale.x = scaleX;
	pane->mScale.y = scaleY;
	pane->calcMtx();
}

/**
 * @note Address: 0x8032C6B8
 * @note Size: 0x144
 */
void TotalPokoScreen::update()
{
	P2DScreen::Mgr::update();

	if (mNeedAdd) {
		mDisplayPokoCount = mCurrentPokoCount;
		mCallBackCounterRV->startPuyoUp(20.0f);

		if (!newScreen::checkMovieActive()) {
			ogSound->setPlusTotalPoko();
		}

		mNeedAdd = false;
	}

	mPane->move(mCurrPos.x, mCurrPos.y);
}

} // namespace Screen
} // namespace og
