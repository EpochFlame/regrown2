#ifndef _EBI_TYESNOCURSOR_H
#define _EBI_TYESNOCURSOR_H

#include "efx2d/T2DCursor.h"
#include "System.h"

struct J2DPane;

namespace ebi {
struct TYesNoCursor {
	TYesNoCursor()
	    : mCursor(&mPos)
	    , mSpeed(5.0f * sys->mDeltaTime)
	    , mTimer(0.0f)
	{
		mPane1 = nullptr;
		mPane2 = nullptr;
	}

	void update();

	inline void setPanes(J2DPane* pane1, J2DPane* pane2)
	{
		mPane1 = pane1;
		mPane2 = pane2;
	}

	efx2d::T2DCursor mCursor; // _00
	Vector2f mPos;            // _1C
	f32 mSpeed;               // _24
	f32 mTimer;               // _28
	bool mSelected;           // _2C
	J2DPane* mPane1;          // _30
	J2DPane* mPane2;          // _34
};
} // namespace ebi

#endif
