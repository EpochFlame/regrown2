#ifndef _PSGAME_CONDUCTORLIST_H
#define _PSGAME_CONDUCTORLIST_H

#include "types.h"
#include "stream.h"

namespace PSGame {
// as far as I can tell, should inherit one thing, then inherit
// PSSystem::SingletonBase<ConductorList> which is at _1C
struct ConductorList {
	struct CaveInfo {
		CaveInfo();

		u8 mFileNameCount; // _00, num file names in _04
		char** mFileNames; // _04, array of file names
	};

	inline ConductorList();

	virtual ~ConductorList();         // _08 (weak)
	virtual void read(Stream& input); // _0C
	// dtor thunk at _18, so something is getting smushed together here

	void getSeqAndWaveFromConductor(const char*, u8*, char**);

	// unused/inlined:
	void getInfo(unsigned char, unsigned char);
	void getAutoBgmInfo(unsigned char, unsigned char);

	// _00 = VTBL
	u8 _04[0x1C];         // _04, probably from inheritances?
	u8 mCaveCount;        // _20
	CaveInfo* mCaveInfos; // _24
};
} // namespace PSGame

#endif
