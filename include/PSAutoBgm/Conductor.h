#ifndef _PSAUTOBGM_CONDUCTOR_H
#define _PSAUTOBGM_CONDUCTOR_H

#include "JSystem/JAudio/JAD/JADDataMgr.h"
#include "types.h"
#include "JSystem/JAudio/JAD/JADUtility.h"
#include "PSAutoBgm/Track.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/JAudio/JAS/JASTrack.h"

namespace PSAutoBgm {
struct AutoBgm;

/**
 * @size = 0x11C
 */
struct Conductor : JADUtility::PrmSetRc<PSAutoBgm::Track> {
	virtual ~Conductor();         // _08
	virtual void* getEraseLink(); // _1C (weak)

	void removeCallback(u8, void*);
	void seqCpuSync_AutoBgm(JASTrack*, u16, u32, JASTrack*);
	void createTables(JASTrack*);

	// _00      = VTABLE
	// _04-_98  = PrmSetRc
	JSUPtrLink _98;                     // _98
	u32 _A8;                            // _A8
	u32 _AC;                            // _AC
	u8 _B0[0x4];                        // _B0 - unknown
	u32 _B4;                            // _B4
	JADUtility::PrmSlider<u8> _B8;      // _B8
	JADUtility::PrmRadioButton<u8> _E8; // _E8
	u8 _118[0x4];                       // _118 - unknown
};

/**
 * @size = 0x8
 */
struct ConductorArcMgr {
	virtual ~ConductorArcMgr(); // _08 (weak)

	JKRArchive* mArchive; // _04
};

/**
 * @size = 0x270
 */
struct ConductorMgr : JADUtility::PrmDataMgrNode<PSAutoBgm::Conductor, PSAutoBgm::AutoBgm> {
	virtual ~ConductorMgr();            // _08 (weak)
	virtual JKRHeap* getObjHeap();      // _14 (weak)
	virtual JKRHeap* getDataHeap();     // _18 (weak)
	virtual JKRHeap* getSaveTempHeap(); // _2C (weak)

	// virtual void _30() = 0;         // _30 - possibly
	// virtual void _34() = 0;         // _34 - possibly

	static JKRHeap* sHeap;
};

} // namespace PSAutoBgm

#endif
