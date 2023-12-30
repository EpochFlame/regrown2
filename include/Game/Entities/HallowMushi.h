#ifndef _GAME_ENTITIES_HALLOWMUSHI_H
#define _GAME_ENTITIES_HALLOWMUSHI_H

#include "Game/Entities/DangoMushi.h"
#include "efx/THallow.h"

namespace Game
{

namespace HallowMushi
{
// 15 (time elpased rolling) / 0.3 (trail in-between time) 
#define HALLOW_MAX_TRAIL_COUNT (50)
#define HALLOW_TRAIL_LINGER_TIME (16.0f)
#define TRAIL_RADIUS_SIZE (30.0f)
#define TRAIL_HEIGHT (5.0f)

struct Trail
{
	void create(Vector3f& position);
	void fade();
	void update(EnemyBase*);

	bool mActive;
	f32 mTimer;
	Vector3f mPosition;
	efx::THallow* mEffect;


};

struct Obj : public DangoMushi::Obj {
	Obj();

	//////////////// VTABLE
	virtual ~Obj() { }                                    // _1BC (weak)
	virtual f32 getDownSmokeScale() { return 1.3f; }      // _2EC (weak)
	virtual f32 getDamageCoeStoneState() { return 0.2f; } // _2AC (weak)
    virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() { return EnemyTypeID::EnemyID_HallowMushi; }
	virtual bool bombCallBack(Creature* source, Vector3f& direction, f32 damage);

	void flickHandCollision(Creature*);
	void setBodyCollision(bool check);
	void createCrashEnemy();
	void updateTrails();
	void createEffect();
	void addTrail(Vector3f& pos);

	virtual void doUpdate();

	Trail mTrailArray[HALLOW_MAX_TRAIL_COUNT];
	f32 mLastTrailTimer;
};

struct Mgr : public EnemyMgrBase {
	Mgr(int objLimit, u8 modelType);

	// virtual ~Mgr();                                     // _58 (weak)
	virtual void createObj(int);                       // _A0
	virtual EnemyBase* getEnemy(int idx);              // _A4
	virtual void doAlloc();                            // _A8
	virtual SysShape::Model* createModel();            // _B0
	virtual void loadModelData();                      // _C8
	virtual void loadTexData();                        // _D0
	virtual EnemyTypeID::EEnemyTypeID getEnemyTypeID() // _AC (weak)
	{
		return EnemyTypeID::EnemyID_HallowMushi;
	}
	virtual J3DModelData* doLoadBmd(void* filename) // _D4 (weak)
	{
		return J3DModelLoaderDataBase::load(filename, 0x01240030);
	}

	// _00 		= VTBL
	// _00-_44	= EnemyMgrBase
	Sys::MatTevRegAnimation* mTevRegAnimation; // _44
	Obj* mObj;                                 // _48, array of Objs
};

} // namespace HallowMushi

} // namespace Game




#endif