#include "types.h"
#include "string.h"
#include "JSystem/JSupport/JSUStream.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 * Unused function.
 */
JSUOutputStream::~JSUOutputStream() { }

/*
 * --INFO--
 * Address:	800261E0
 * Size:	000058
 */
int JSUOutputStream::write(const void* data, long length)
{
	int len = writeData(data, length);
	if (len != length) {
		mIsEOFMaybe |= 1;
	}
	return len;
}

/*
 * --INFO--
 * Address:	80026238
 * Size:	0000F8
 */
void JSUOutputStream::write(const char* str)
{
	if (str == nullptr) {
		u16 val = 0;
		if (writeData(&val, 2) != sizeof(val)) {
			mIsEOFMaybe |= 1;
		}
	} else {
		int len = strlen((char*)str);
		if ((s32)len >= 0x10000) {
			mIsEOFMaybe |= 2;
		} else {
			u16 val = len;
			if (writeData(&val, 2) != sizeof(val) || (writeData(str, len) != len)) {
				mIsEOFMaybe |= 1;
			}
		}
	}
	return;
}
