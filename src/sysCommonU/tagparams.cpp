#include "Vector3.h"
#include "types.h"

#include "TagParm.h"
#include "string.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void TagParm::read(Stream& input) { doRead(input); }

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void TagParm::write(Stream& output)
{
	// TODO: There was clearly more to this one, given the length.
	doWrite(output);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void TagParm::dump() { doDump(); }

/*
 * --INFO--
 * Address:	8041BD38
 * Size:	000034
 */
template <>
void PrimTagParm<int>::doRead(Stream& stream)
{
	mData = stream.readInt();
}

/*
 * --INFO--
 * Address:	8041BD6C
 * Size:	00002C
 */
template <>
void PrimTagParm<int>::doWrite(Stream& stream)
{
	stream.writeInt(mData);
}

/*
 * --INFO--
 * Address:	8041BD98
 * Size:	000004
 */
template <>
void PrimTagParm<int>::doDump()
{
}

/*
 * --INFO--
 * Address:	8041BD9C
 * Size:	000034
 */
template <>
void PrimTagParm<u16>::doRead(Stream& stream)
{
	mData = stream.readShort();
}

/*
 * --INFO--
 * Address:	8041BDD0
 * Size:	00002C
 */
template <>
void PrimTagParm<u16>::doWrite(Stream& stream)
{
	stream.writeShort(mData);
}

/*
 * --INFO--
 * Address:	8041BDFC
 * Size:	000004
 */
template <>
void PrimTagParm<u16>::doDump()
{
}

/*
 * --INFO--
 * Address: 8041BE00
 * Size:    000078
 */
template <>
void PrimTagParm<u64>::doRead(Stream& stream)
{
	char* str = stream.readString(nullptr, 0);
	for (int i = 0; i < 8; i++) {
		((char*)&mData)[i] = str[i];
	}
}

/*
 * --INFO--
 * Address: 8041BE78
 * Size:    00006C
 */
template <>
void PrimTagParm<u64>::doWrite(Stream& stream)
{
	char data[8];
	for (int i = 0; i < 8; i++) {
		data[i] = ((char*)&mData)[i];
	}
	stream.writeString(data);
}

/*
 * --INFO--
 * Address:	8041BEE4
 * Size:	000004
 */
template <>
void PrimTagParm<u64>::doDump()
{
}

/*
 * --INFO--
 * Address:	8041BEE8
 * Size:	000034
 */
template <>
void PrimTagParm<f32>::doRead(Stream& stream)
{
	mData = stream.readFloat();
}

/*
 * --INFO--
 * Address:	8041BF1C
 * Size:	000028
 */
template <>
void PrimTagParm<f32>::doWrite(Stream& stream)
{
	stream.writeFloat(mData);
}

/*
 * --INFO--
 * Address:	8041BF44
 * Size:	000004
 */
template <>
void PrimTagParm<f32>::doDump()
{
}

/*
 * --INFO--
 * Address:	8041BF48
 * Size:	000024
 */
template <>
void PrimTagParm<Vector3f>::doRead(Stream& stream)
{
	mData.read(stream);
}

/*
 * --INFO--
 * Address:	8041BF6C
 * Size:	000024
 */
template <>
void PrimTagParm<Vector3f>::doWrite(Stream& stream)
{
	mData.write(stream);
}

/*
 * --INFO--
 * Address:	8041BF90
 * Size:	000004
 */
template <>
void PrimTagParm<Vector3f>::doDump()
{
}

/*
 * --INFO--
 * Address:	8041BF94
 * Size:	000044
 */
StringTagParm::StringTagParm(TagParameters* params, char* name)
    : TagParm(params, name)
{
	mData = nullptr;
}

/*
 * --INFO--
 * Address:	8041BFD8
 * Size:	000004
 */
void StringTagParm::flushValue() { }

/*
 * --INFO--
 * Address:	8041BFDC
 * Size:	00003C
 */
void StringTagParm::doRead(Stream& stream) { mData = stream.readString(nullptr, 0); }

/*
 * --INFO--
 * Address:	8041C018
 * Size:	00002C
 */
void StringTagParm::doWrite(Stream& stream) { stream.writeString(mData); }

/*
 * --INFO--
 * Address:	8041C044
 * Size:	000004
 */
void StringTagParm::doDump() { }

/*
 * --INFO--
 * Address:	8041C048
 * Size:	000054
 */
TagParameters::TagParameters(char* name)
{
	mHead = nullptr;
	mName = name;
}

/*
 * @matchedSize
 * --INFO--
 * Address:	........
 * Size:	000048
 */
// bool TagParameters::isEndToken(char* token)

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void TagParameters::add(TagParm*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8041C09C
 * Size:	000038
 */
TagParm::TagParm(TagParameters* container, char* name)
{
	mName = name;
	mNext = nullptr;
	if (container->mHead) {
		mNext            = container->mHead;
		container->mHead = this;
		return;
	}

	container->mHead = this;
}

/*
 * TODO: This probably uses isEndToken, but IDK how.
 * --INFO--
 * Address:	8041C0D4
 * Size:	0000D4
 */

void TagParameters::read(Stream& stream)
{
	// char* str;
	// while (str = stream.readString(nullptr, 0), !isEndToken(str)) {
	while (true) {
		char* str = stream.readString(nullptr, 0);
		// if (isEndToken(str)) {
		// 	return;
		// }
		int strLen  = strlen("end");
		bool is_end = ((strncmp("end", str, strLen)) == 0);
		if (is_end)
			break;

		for (TagParm* node = mHead; node; node = node->mNext) {
			strLen          = strlen(str);
			int nodeNameLen = strlen(node->mName);
			if (strLen != nodeNameLen) {
				continue;
			}

			strLen = strlen(str);
			if (strncmp(node->mName, str, strLen) == 0) {
				node->doRead(stream);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void TagParameters::write(Stream&)
{
	// Unused/inlined
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void TagParameters::dump()
{
	// Unused/inlined
}
