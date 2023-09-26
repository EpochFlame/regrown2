#ifndef _MONOOBJECTMGR_H
#define _MONOOBJECTMGR_H

#include "types.h"
#include "ObjectMgr.h"

template <typename T>
struct MonoObjectMgr : public ObjectMgr<T> {
	MonoObjectMgr();

	////////////////// VTABLE
	virtual ~MonoObjectMgr() { }     // _08 (weak)
	virtual void* getNext(void* idx) // _14 (weak)
	{
		for (int i = (int)idx + 1; i < mMax; i++) {
			if (mOpenIds[i] == 0) {
				return (void*)i;
			}
		}

		return (void*)mMax;
	}
	virtual void* getStart() // _18 (weak)
	{
		return getNext((void*)-1);
	}
	virtual void* getEnd() // _1C (weak)
	{
		return (void*)mMax;
	}
	virtual T* get(void* idx) // _20 (weak)
	{
		return &mArray[(int)idx];
	}
	virtual T* getAt(int index) // _24 (weak)
	{
		return &mArray[index];
	}
	virtual int getTo() // _28 (weak)
	{
		return mMax;
	}
	virtual void doAnimation() // _64 (weak, thunk at _34)
	{
		for (int i = 0; i < mMax; i++) {
			if (mOpenIds[i] == false) {
				mArray[i].doAnimation();
			}
		}
	}
	virtual void doEntry() // _68 (weak, thunk at _38)
	{
		for (int i = 0; i < mMax; i++) {
			if (mOpenIds[i] == false) {
				mArray[i].doEntry();
			}
		}
	}
	virtual void doSetView(int viewportNumber) // _6C (weak, thunk at _3C)
	{
		for (int i = 0; i < mMax; i++) {
			if (mOpenIds[i] == false) {
				mArray[i].doSetView(viewportNumber);
			}
		}
	}
	virtual void doViewCalc() // _70 (weak, thunk at _40)
	{
		for (int i = 0; i < mMax; i++) {
			if (mOpenIds[i] == false) {
				mArray[i].doViewCalc();
			}
		}
	}
	virtual void doSimulation(f32 timeStep) // _74 (weak, thunk at _44)
	{
		for (int i = 0; i < mMax; i++) {
			if (mOpenIds[i] == false) {
				mArray[i].doSimulation(timeStep);
			}
		}
	}
	virtual void doDirectDraw(Graphics& gfx) // _78 (weak, thunk at _48)
	{
		for (int i = 0; i < mMax; i++) {
			if (mOpenIds[i] == false) {
				mArray[i].doDirectDraw(gfx);
			}
		}
	}
	virtual T* birth(); // _7C (weak)

	virtual void resetMgr() // _80 (weak, thunk at _54)
	{
		mArray       = nullptr;
		mMax         = 0;
		mActiveCount = 0;
		mOpenIds     = nullptr;
	}
	virtual void clearMgr() // _84 (weak)
	{
		mActiveCount = 0;
		for (int i = 0; i < mMax; i++) {
			mOpenIds[i] = true;
		}
	}
	virtual void onAlloc() { } // _88 (weak)
	////////////////// VTABLE END

	void kill(T* item);

	int getEmptyIndex();

	void alloc(int count);

	// _00		= VTBL
	// _00-_20  = ObjectMgr
	int mActiveCount; // _20
	int mMax;         // _24
	T* mArray;        // _28
	u8* mOpenIds;     // _2C
};

template <typename T>
MonoObjectMgr<T>::MonoObjectMgr()
{
	_18          = 1;
	mMax         = 0;
	mActiveCount = 0;
	mArray       = nullptr;
	mOpenIds     = nullptr;
}

template <typename T>
void MonoObjectMgr<T>::alloc(int count)
{
	mArray       = new T[count];
	mMax         = count;
	mActiveCount = 0;
	mOpenIds     = new u8[count];

	for (int i = 0; i < count; i++) {
		mOpenIds[i] = true;
	}

	onAlloc();

	for (int i = 0; i < count; i++) {
		mArray[i].constructor();
	}
}

template <typename T>
void MonoObjectMgr<T>::kill(T* item)
{
	for (int i = 0; i < mMax; i++) {
		if (&mArray[i] == item) {
			mOpenIds[i] = true;
			mActiveCount--;
			return;
		}
	}
}

template <typename T>
int MonoObjectMgr<T>::getEmptyIndex()
{
	for (int i = 0; i < mMax; i++) {
		if (mOpenIds[i] == true) {
			return i;
		}
	}
	return -1;
}

template <typename T>
T* MonoObjectMgr<T>::birth()
{ // non-matching
	int index = getEmptyIndex();
	T* result;
	if (index != -1) {
		T* array        = mArray;
		mOpenIds[index] = false;
		result          = &array[index];
		mActiveCount++;
	} else {
		result = nullptr;
	}
	return result;
}
#endif
