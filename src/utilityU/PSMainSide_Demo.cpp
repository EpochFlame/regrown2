#include "PSM/Demo.h"
#include "SoundID.h"
#include "utilityU.h"
#include "PSM/Scene.h"
#include "PSSystem/PSGame.h"
#include "PSM/ObjCalc.h"

static inline bool streq(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
		return false;
	if (strcmp(a, b) == 0)
		return true;
	else
		return false;
}

namespace PSM {

inline DemoInitiator::DemoInitiator(u8* pByte, const char* pName, u32& rAST_ID, char* pBuffer)
    : mAST_ID(rAST_ID)
{
	P2ASSERTLINE(256, pName);

	mName   = pName;
	mAST_ID = rAST_ID;
	b2      = pBuffer;
	mByte   = pByte;

	mSongChosen = false;
}

inline void DemoInitiator::setDefaultValues()
{
	P2ASSERTLINE(41, isInitialized());

	mAST_ID = -1;
	strcpy(b2, "");
	*mByte = -1;
}

inline bool DemoInitiator::isInitialized() { return mByte && mName; }

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void DemoInitiator::equalSet(const char*, const char*, u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void DemoInitiator::equalSetStream(const char* buffer, u32 AST_ID, u8 byte)
{
	mSongChosen = false;
	bool check  = false;
	if (mByte && mName) {
		check = true;
	}
	P2ASSERTLINE(41, check);

	mAST_ID = AST_ID;
	strcpy((char*)buffer, "");
	*mByte = byte;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void DemoInitiator::equalSetEx(const char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void DemoInitiator::equalSetExStream(const char*, bool, u32, u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void DemoInitiator::is(const char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void DemoInitiator::numberSet(const char*, const char*, u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */

inline void DemoInitiator::setDefault(const char* comp, u32 id, bool extraCondition)
{
	if (extraCondition && !mSongChosen && strcmp(mName, comp) == 0) {
		mSongChosen = true;
		mAST_ID     = id;
		*mByte      = -1;
		// OSReport("demo_arg is value: %lu\n", demo_arg);
	}
}

/*
 * --INFO--
 * Address:	80463FE8
 * Size:	00005C
 */
Demo::Demo()
{
	_18               = 0;
	mDoStartWithAudio = 1;
	mSoundID          = (SoundID)-1;
	mSystemSE         = (SoundID)-1;
	mFuncptr          = nullptr;
};

/*
 * --INFO--
 * Address:	80464044
 * Size:	00020C
 */
void Demo::init(Vec*, Vec*, Mtx, PSM::DemoArg)
{
	/*
	stwu     r1, -0x40(r1)
	mflr     r0
	lis      r8, lbl_8049D080@ha
	stw      r0, 0x44(r1)
	stmw     r25, 0x24(r1)
	mr       r30, r3
	mr       r25, r4
	mr       r27, r5
	mr       r26, r6
	mr       r31, r7
	addi     r29, r8, lbl_8049D080@l
	li       r3, 0x38
	bl       __nw__FUl
	or.      r28, r3, r3
	beq      lbl_80464088
	bl       __ct__Q26PSGame9SceneInfoFv
	mr       r28, r3

lbl_80464088:
	mr       r3, r28
	li       r4, 1
	li       r5, 2
	bl
setStageFlag__Q26PSGame9SceneInfoFQ36PSGame9SceneInfo7FlagDefQ36PSGame9SceneInfo12FlagBitShift
	li       r0, 1
	li       r8, 0xff
	stb      r0, 7(r28)
	mr       r3, r30
	addi     r4, r1, 0xc
	addi     r5, r1, 8
	stw      r25, 8(r28)
	stw      r27, 0x10(r28)
	stw      r26, 0x18(r28)
	stb      r8, 6(r28)
	lwz      r7, 0(r31)
	lwz      r6, 4(r31)
	lwz      r0, 8(r31)
	stb      r8, 8(r1)
	stw      r7, 0xc(r1)
	stw      r6, 0x10(r1)
	stw      r0, 0x14(r1)
	lwz      r12, 0(r30)
	lwz      r12, 0x10(r12)
	mtctr    r12
	bctrl
	mr       r0, r3
	lwz      r3, 4(r31)
	mr       r26, r0
	bl       strlen
	addi     r3, r3, 1
	bl       __nwa__FUl
	stw      r3, 0x28(r30)
	lwz      r3, 0x28(r30)
	lwz      r4, 4(r31)
	bl       strcpy
	li       r3, 0x2c
	bl       __nw__FUl
	or.      r27, r3, r3
	beq      lbl_80464134
	lbz      r4, 8(r1)
	mr       r5, r28
	bl       __ct__Q23PSM10Scene_DemoFUcPQ26PSGame9SceneInfo
	mr       r27, r3

lbl_80464134:
	cmplwi   r27, 0
	bne      lbl_80464150
	addi     r3, r29, 0
	addi     r5, r29, 0x14
	li       r4, 0xc7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80464150:
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80464170
	addi     r3, r29, 0x20
	addi     r5, r29, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80464170:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80464190
	addi     r3, r29, 0x20
	addi     r5, r29, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80464190:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_804641B0
	addi     r3, r29, 0x2c
	addi     r5, r29, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804641B0:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_804641D4
	addi     r3, r29, 0x2c
	addi     r5, r29, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804641D4:
	mr       r3, r28
	mr       r4, r27
	bl       adaptChildScene__Q28PSSystem5SceneFPQ28PSSystem5Scene
	cmplwi   r27, 0
	bne      lbl_804641FC
	addi     r3, r29, 0
	addi     r5, r29, 0x14
	li       r4, 0xcb
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804641FC:
	cmplwi   r26, 0
	beq      lbl_80464210
	mr       r3, r27
	mr       r4, r26
	bl       appendSeq__Q28PSSystem5SceneFPQ28PSSystem7SeqBase

lbl_80464210:
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	mr       r5, r27
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	li       r0, 1
	mr       r3, r30
	stb      r0, 0x18(r30)
	bl       demo1stLoadSync__Q23PSM4DemoFv
	lmw      r25, 0x24(r1)
	lwz      r0, 0x44(r1)
	mtlr     r0
	addi     r1, r1, 0x40
	blr
	*/
}

/*
 * --INFO--
 * Address:	80464250
 * Size:	0000EC
 */
void Demo::demo1stLoadSync()
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r3, lbl_8049D080@ha
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	addi     r31, r3, lbl_8049D080@l
	stw      r30, 8(r1)
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8046428C
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046428C:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_804642AC
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804642AC:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_804642CC
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804642CC:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_804642F0
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804642F0:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80464310
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5b
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80464310:
	lwz      r3, 4(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	8046433C
 * Size:	000048
 */
void Demo::initDemoScene(PSM::DemoArg&, PSM::Scene_Demo*)
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r6, lbl_8049D0DC@ha
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	mr       r31, r5
	lwz      r3, 4(r4)
	addi     r4, r6, lbl_8049D0DC@l
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80464370
	li       r0, 1
	stb      r0, 0x28(r31)

lbl_80464370:
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

const char* filler3 = "PSGame.h";
const char* filler4 = "PSScene.h";
const char* filler5 = "get sound scene at\ninvalid timming\n";
const char* filler6 = "s21_dayend_takeoff";

/*
 * --INFO--
 * Address:	80464384
 * Size:	001DA4
 */
PSSystem::BgmSeq* Demo::initiate(DemoArg demoArg, u8* unk)
{
	PSSystem::BgmSeq* seq;
	u32 AST_ID;
	char buffer[32];
	JAInter::SoundInfo audio_info = { 0x00000000, 0x7F030000, 0x3F800000, 0x3C000000 };

	seq       = nullptr;
	buffer[0] = '\0';
	AST_ID    = -1;

	DemoInitiator init = DemoInitiator(unk, demoArg.mName, AST_ID, buffer);
	init.setDefaultValues();

	init.setDefault("s02_dayend_result", 0xc0011012);
	init.setDefault("s01_dayend", demoArg.mBgmID);
	init.setDefault("s03_orimadown", 0xc0011005);
	init.setDefault("s05_pikminzero", 0xc0011006);
	init.setDefault("s11_dope_first_b", 0xc0011001);
	init.setDefault("s11_dope_first_r", 0xc0011001);
	init.setDefault("s11_dopebin_first_b", 0xc0011008);
	init.setDefault("s11_dopebin_first_r", 0xc0011008);

	if (!streq("s01_dayend", init.mName)) {
		bool is_key = demoArg.mPelletName && streq(demoArg.mPelletName, "key");

		init.setDefault("s17_suck_equipment", demoArg.mBgmID, !is_key);
		init.setDefault("s17_suck_equipment", 0xc0011007, is_key);

		init.setDefault("s22_cv_suck_equipment", demoArg.mBgmID, !is_key);
		init.setDefault("s22_cv_suck_equipment", 0xc0011007, is_key);

		init.setDefault("s10_suck_treasure", 0xc0011001, !is_key);
		init.setDefault("s10_suck_treasure", 0xc0011007, is_key);

		init.setDefault("s22_cv_suck_treasure", 0xc0011007, is_key);
		init.setDefault("s22_cv_suck_treasure", 0xc0011001, !is_key);
	}

	init.setDefault("s04_dayend_orimadown", 0xc001101d);
	init.setDefault("s06_dayend_pikminzero", 0xc001101d);

	init.setDefault("g1A_red_doping", 0xc0011009);
	init.setDefault("g1A_red_doping", 0xc0011009);
	init.setDefault("g1B_black_doping", 0xc0011047);
	init.setDefault("g02_boot_onyonR", 0xc001100c);
	init.setDefault("g1E_boot_onyonY", 0xc001100c);
	init.setDefault("g20_boot_onyonB", 0xc001100c);
	init.setDefault("g03_meet_redpikmin", 0xc001100d);
	init.setDefault("g1F_meet_yellowpikmin", 0xc001100d);
	init.setDefault("g21_meet_bluepikmin", 0xc001100d);
	init.setDefault("g24_meet_blackpikmin", 0xc001100d);
	init.setDefault("g27_meet_whitepikmin", 0xc001100d);
	init.setDefault("g33_camera_demo", 0xc0011024);

	if (PSMGetGameSceneA()->isCave()) {
		init.setDefault("s09_holein", 0xc0011046);
	} else {
		init.setDefault("s09_holein", 0xc0011026);
	}

	init.setDefault("s16_find_item_00", 0xc0011027);
	init.setDefault("s16_find_item_01", 0xc0011027);
	init.setDefault("s16_find_item_02", 0xc0011027);
	init.setDefault("s16_find_item_03", 0xc0011027);
	init.setDefault("s16_find_item_04", 0xc0011027);
	init.setDefault("s16_find_item_05", 0xc0011027);
	init.setDefault("s16_find_item_06", 0xc0011027);
	init.setDefault("s16_find_item_07", 0xc0011027);
	init.setDefault("s16_find_item_08", 0xc0011027);
	init.setDefault("s16_find_item_09", 0xc0011027);
	init.setDefault("s16_find_item_10", 0xc0011027);
	init.setDefault("s16_find_item_11", 0xc0011027);
	init.setDefault("s16_find_item_12", 0xc0011027);

	init.setDefault("s0C_cv_escape", 0xc0011028);

	init.setDefault("g01_pick_me", 0xc0011029);

	init.setDefault("g04_find_treasure", 0xc0011027);

	init.setDefault("g05_find_cave_f_01", 0xc0011029);
	init.setDefault("g05_find_cave_f_02", 0xc0011029);
	init.setDefault("g05_find_cave_f_03", 0xc0011029);
	init.setDefault("g05_find_cave_f_04", 0xc0011029);
	init.setDefault("g05_find_cave_l_01", 0xc0011029);
	init.setDefault("g05_find_cave_l_02", 0xc0011029);
	init.setDefault("g05_find_cave_l_03", 0xc0011029);
	init.setDefault("g05_find_cave_t_01", 0xc0011029);
	init.setDefault("g05_find_cave_t_02", 0xc0011029);
	init.setDefault("g05_find_cave_t_03", 0xc0011029);
	init.setDefault("g05_find_cave_y_01", 0xc0011029);
	init.setDefault("g05_find_cave_y_02", 0xc0011029);
	init.setDefault("g05_find_cave_y_03", 0xc0011029);
	init.setDefault("g05_find_cave_y_04", 0xc0011029);

	init.setDefault("g0A_cv_find_hole", 0xc0011029);
	init.setDefault("g0B_cv_find_fountain", 0xc0011029);

	init.setDefault("g18_find_gate", 0xc001102a);
	init.setDefault("g19_find_rock", 0xc0011029);
	init.setDefault("g2D_red_extract", 0xc0011027);
	init.setDefault("g2E_black_extract", 0xc0011027);
	init.setDefault("g34_yellow_extract", 0xc001102b);
	init.setDefault("g37_get_louie", 0xc0011027);
	init.setDefault("g38_find_whitepom", 0xc0011029);
	init.setDefault("g39_find_blackpom", 0xc0011029);

	init.setDefault("x01_gamestart", 0xc001102c);
	init.setDefault("x02_watch_red_pikmin", 0xc001102d);
	init.setDefault("x06_join", 0xc001102e);
	init.setDefault("x12_drain_water", 0xc001102a);
	init.setDefault("x10_find_yellow_onyon", 0xc001102f);
	init.setDefault("x11_find_blue_onyon", 0xc0011030);
	init.setDefault("x16_hiba", 0xc0011031);
	init.setDefault("x13_exp_leafchappy", 0xc001102a);
	init.setDefault("x20_blackman", 0xc0011032);

	init.setDefault("s13_pikmin_supply", 0xc0011033);
	init.setDefault("s0B_cv_coursein", 0xc0011036);
	init.setDefault("s0E_return_cave", 0xc0011037);

	init.setDefault("e00_E3_cavestart", 0xc0011039);

	init.setDefault("g07_cv_gamestart", 0xc001103a);
	init.setDefault("g08_first_return", 0xc001103b);
	init.setDefault("g09_first_sunset", 0xc0011033);
	init.setDefault("g16_100_pikmin", 0xc0011033);
	init.setDefault("g16_95_pikmin", 0xc0011033);
	init.setDefault("g26_inout_black", 0xc001104a);
	init.setDefault("g29_inout_white", 0xc0011048);
	init.setDefault("g2B_white_poison", 0xc0011031);
	init.setDefault("g2C_inout_red", 0xc0011033);
	init.setDefault("g36_find_louie", 0xc0011031);

	init.setDefault("x01_coursein_forest", 0xc0011034);
	init.setDefault("x01_coursein_yakushima", 0xc0011034);
	init.setDefault("x01_coursein_last", 0xc0011034);
	init.setDefault("x04_exp_y", 0xc0011049);
	init.setDefault("x05_louiestart", 0xc0011035);
	init.setDefault("x07_first_recovery", 0xc0011049);
	init.setDefault("x08_cv_suck_carcass", 0xc0011033);
	init.setDefault("x09_exp_detector", 0xc0011033);
	init.setDefault("x14_white_dig", 0xc0011033);

	init.setDefault("g32_get_map", 0xc0011048);
	init.setDefault("g35_president_gamestart", 0xc0011033);

	init.setDefault("x15_exp_x", 0xc0011033);
	init.setDefault("x17_join_guide", 0xc0011033);
	init.setDefault("x18_exp_pellet", 0xc0011033);

	init.setDefault("x03_find_red_onyon", 0xc001103c);

	if (streq("s02_dayend_result", init.mName)) {
		audio_info.volume.v2 -= 0xf;
	}
	// clang-format off
  if (streq("s10_suck_treasure",        init.mName) || 
      streq("s11_dope_first_b",         init.mName) || 
      streq("s11_dope_first_r",         init.mName) || 
      streq("s11_dopebin_first_b",      init.mName) || 
      streq("s11_dopebin_first_r",      init.mName) || 
      streq("s17_suck_equipment",       init.mName) || 
      streq("s22_cv_suck_equipment",    init.mName) || 
      streq("s22_cv_suck_treasure",     init.mName) || 
      streq("x19_vs_bedama",            init.mName))
	// clang-format on
	{
		mDoStartWithAudio = false;
		mSoundID          = PSSE_EV_HOME_PELLET_BACUUM;
	} else if (streq("g2F_appear_hole", init.mName)) { // change BGM in challenge mode when hole/fountain appear
		mSoundID = PSSE_SY_WORK_FINISH;
		mFuncptr = PSChangeBgm_ChallengeGame;
	} else if (streq("g30_appear_fountain", init.mName)) {
		mFuncptr = PSChangeBgm_ChallengeGame;
	} else if (streq("x20_blackman", init.mName) || streq("x03_find_red_onyon", init.mName)) {
		mDoStartWithAudio = false;
	} else if (streq("s01_dayend", init.mName)) {
		switch ((u32)demoArg.mPelletName) {
		case 1:
			mSoundID = PSSE_PL_DAYEND_KAISAN_LUI;
			break;
		case 2:
			mSoundID = PSSE_PL_DAYEND_KAISAN_SHA;
			break;
		default:
		case 0:
			mSoundID = PSSE_PL_DAYEND_KAISAN_ORI;
			break;
		}
	}

	if (streq("x20_blackman", init.mName)) {
		mSoundID = PSSE_EN_TIRE_FALL;
	}

	if (AST_ID != -1) {
		PSGame::PikSceneMgr* scene_mgr = (PSGame::PikSceneMgr*)PSSystem::getSceneMgr();
		PSSystem::checkSceneMgr(scene_mgr);

		seq  = scene_mgr->newStreamBgm(AST_ID, audio_info);
		*unk = -1;
	} else if (buffer[0] != '\0') {
		PSGame::PikSceneMgr* scene_mgr = (PSGame::PikSceneMgr*)PSSystem::getSceneMgr();
		PSSystem::checkSceneMgr(scene_mgr);

		seq = scene_mgr->newBgmSeq(buffer, audio_info);
		P2ASSERTLINE(632, seq);
	}
	return seq;
}

/*
 * --INFO--
 * Address:	80466128
 * Size:	000184
 */
Demo::~Demo()
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r5, lbl_8049D080@ha
	stw      r0, 0x24(r1)
	stmw     r27, 0xc(r1)
	or.      r27, r3, r3
	mr       r28, r4
	addi     r31, r5, lbl_8049D080@l
	beq      lbl_80466294
	lis      r4, __vt__Q23PSM4Demo@ha
	addi     r0, r4, __vt__Q23PSM4Demo@l
	stw      r0, 0(r27)
	bl       becomeSceneCamera__Q23PSM4DemoFv
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8046617C
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046617C:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_8046619C
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046619C:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_804661BC
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804661BC:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_804661E0
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804661E0:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80466200
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5a
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466200:
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	lwz      r30, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80466224
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466224:
	lwz      r29, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r29, 0
	bne      lbl_80466244
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466244:
	mr       r3, r29
	mr       r4, r30
	bl       deleteScene__Q28PSSystem8SceneMgrFPQ28PSSystem5Scene
	lwz      r3, 0x28(r27)
	bl       __dl__FPv
	cmplwi   r30, 0
	beq      lbl_80466278
	mr       r3, r30
	li       r4, 1
	lwz      r12, 0(r30)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl

lbl_80466278:
	mr       r3, r27
	li       r4, 0
	bl       __dt__11JKRDisposerFv
	extsh.   r0, r28
	ble      lbl_80466294
	mr       r3, r27
	bl       __dl__FPv

lbl_80466294:
	mr       r3, r27
	lmw      r27, 0xc(r1)
	lwz      r0, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	804662AC
 * Size:	0006C0
 */
void Demo::onDemoTop()
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r4, lbl_8049D080@ha
	stw      r0, 0x24(r1)
	stmw     r27, 0xc(r1)
	mr       r29, r3
	addi     r31, r4, lbl_8049D080@l
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_804662E8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804662E8:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466308
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466308:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466328
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466328:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_8046634C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046634C:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_8046636C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5b
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046636C:
	lwz      r3, 4(r28)
	lwz      r12, 0(r3)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	lwz      r0,
"sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13) cmplwi
r0, 0 bne      lbl_804663A0 addi     r3, r31, 0x86c addi     r5, r31, 0x14 li
r4, 0x89 crclr    6 bl       panic_f__12JUTExceptionFPCciPCce

lbl_804663A0:
	lwz      r3,
"sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13) li r4, 1
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_804663D8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804663D8:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_804663F8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804663F8:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466418
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466418:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_8046643C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046643C:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x4c(r12)
	mtctr    r12
	bctrl
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466470
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466470:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466490
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466490:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_804664B0
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804664B0:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_804664D4
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804664D4:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	or.      r27, r3, r3
	beq      lbl_804664F8
	li       r0, 0
	sth      r0, 0x10(r27)

lbl_804664F8:
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466518
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466518:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466538
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466538:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466558
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466558:
	lwz      r3, 4(r28)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_8046657C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046657C:
	lwz      r12, 0(r30)
	mr       r3, r30
	lwz      r12, 0x40(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_804665AC
	addi     r3, r31, 0x858
	addi     r5, r31, 0x14
	li       r4, 0x177
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804665AC:
	lwz      r28, 0x28(r29)
	addi     r4, r31, 0x94
	mr       r3, r28
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x80
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x168
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0xb0
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x180
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x26c
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x37c
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x878
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466664
	mr       r3, r28
	addi     r4, r31, 0x5c
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_804666FC

lbl_80466664:
	addi     r3, r30, 0x10
	li       r4, 0xf
	bl       stopAllSound__Q28PSSystem6SeqMgrFUl
	cmplwi   r27, 0
	beq      lbl_8046671C
	mr       r3, r27
	bl       off__Q28PSSystem8EnvSeMgrFv
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x58(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_804666D8
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_804666D8
	mr       r3, r27
	li       r4, 0x3079
	li       r5, 1
	bl       on__Q28PSSystem8EnvSeMgrFUlb
	mr       r3, r27
	li       r4, 0x307a
	li       r5, 1
	bl       on__Q28PSSystem8EnvSeMgrFUlb

lbl_804666D8:
	mr       r3, r27
	li       r4, 0x4014
	li       r5, 1
	bl       off__Q28PSSystem8EnvSeMgrFUlb
	mr       r3, r27
	li       r4, 0x4015
	li       r5, 1
	bl       off__Q28PSSystem8EnvSeMgrFUlb
	b        lbl_8046671C

lbl_804666FC:
	addi     r3, r30, 0x10
	li       r4, 1
	bl       pauseOnAllSeq__Q28PSSystem6SeqMgrFQ38PSSystem7SeqBase9PauseMode
	cmplwi   r27, 0
	beq      lbl_8046671C
	mr       r3, r27
	li       r4, 2
	bl       setAllPauseFlag__Q28PSSystem8EnvSeMgrFUc

lbl_8046671C:
	mr       r3, r28
	addi     r4, r31, 0x824
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80466740
	addi     r3, r30, 0x10
	li       r4, 0xf
	bl       stopAllSound__Q28PSSystem6SeqMgrFUl
	b        lbl_804668C8

lbl_80466740:
	mr       r3, r28
	addi     r4, r31, 0x5a8
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80466838
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466774
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466774:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466794
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466794:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_804667B4
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xc7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804667B4:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_804667D8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1e5
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804667D8:
	addi     r3, r28, 0x10
	li       r4, 1
	bl       getSeq__Q28PSSystem6SeqMgrFUl
	or.      r28, r3, r3
	bne      lbl_80466800
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1e7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466800:
	cmplwi   r28, 0
	bne      lbl_8046681C
	addi     r3, r31, 0
	addi     r5, r31, 0x14
	li       r4, 0x2db
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046681C:
	mr       r3, r28
	li       r4, 5
	lwz      r12, 0x10(r28)
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	b        lbl_804668C8

lbl_80466838:
	mr       r3, r28
	addi     r4, r31, 0x580
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_804668C8
	lwz      r0,
"sInstance__Q28PSSystem49SingletonBase<Q36PSGame10SoundTable11CategoryMgr>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8046686C
	addi     r3, r31, 0x86c
	addi     r5, r31, 0x14
	li       r4, 0x89
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046686C:
	lwz      r28,
"sInstance__Q28PSSystem49SingletonBase<Q36PSGame10SoundTable11CategoryMgr>"@sda21(r13)
	lwz      r0, 0x18(r28)
	cmplwi   r0, 0
	bne      lbl_80466890
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x5d
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466890:
	lwz      r3, 0x18(r28)
	li       r0, 1
	stb      r0, 0x15(r3)
	lwz      r0, 0xc(r28)
	cmplwi   r0, 0
	bne      lbl_804668BC
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x5d
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804668BC:
	lwz      r3, 0xc(r28)
	li       r0, 1
	stb      r0, 0x15(r3)

lbl_804668C8:
	lwz      r4, 0x1c(r29)
	addis    r0, r4, 1
	cmplwi   r0, 0xffff
	beq      lbl_804668E4
	lwz      r3, spSysIF__8PSSystem@sda21(r13)
	li       r5, 0
	bl       playSystemSe__Q28PSSystem5SysIFFUlUl

lbl_804668E4:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80466904
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5b
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466904:
	lwz      r3, 4(r30)
	addi     r3, r3, 0x10
	bl       getFirstSeq__Q28PSSystem6SeqMgrFv
	cmplwi   r3, 0
	beq      lbl_80466958
	lbz      r0, 0x19(r29)
	cmplwi   r0, 0
	beq      lbl_80466958
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80466944
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5b
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466944:
	lwz      r3, 4(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80466958:
	lmw      r27, 0xc(r1)
	lwz      r0, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	8046696C
 * Size:	000104
 */
void Demo::becomeSceneCamera()
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r3, lbl_8049D080@ha
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	addi     r31, r3, lbl_8049D080@l
	stw      r30, 8(r1)
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_804669A8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804669A8:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_804669C8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804669C8:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_804669E8
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804669E8:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_80466A0C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466A0C:
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	lwz      r0,
"sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13) cmplwi
r0, 0 bne      lbl_80466A40 addi     r3, r31, 0x86c addi     r5, r31, 0x14 li
r4, 0x89 crclr    6 bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466A40:
	lwz      r3,
"sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13) li r4, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	80466A70
 * Size:	0000FC
 */
void Demo::onDemoFadeoutStart(unsigned long)
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r3, lbl_8049D080@ha
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	addi     r31, r3, lbl_8049D080@l
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r29, r4
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466AB4
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466AB4:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_80466AD4
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466AD4:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80466AF4
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466AF4:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_80466B18
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466B18:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80466B38
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5b
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466B38:
	lwz      r3, 4(r30)
	addi     r4, r29, -2
	lwz      r12, 0(r3)
	lwz      r12, 0x24(r12)
	mtctr    r12
	bctrl
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80466B6C
 * Size:	000664
 */
void Demo::onDemoEnd()
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	lis      r4, lbl_8049D080@ha
	stw      r0, 0x24(r1)
	stmw     r27, 0xc(r1)
	mr       r29, r3
	addi     r31, r4, lbl_8049D080@l
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466BA8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466BA8:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466BC8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466BC8:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466BE8
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466BE8:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_80466C0C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466C0C:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x3c(r12)
	mtctr    r12
	bctrl
	lwz      r0,
"sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13) cmplwi
r0, 0 bne      lbl_80466C40 addi     r3, r31, 0x86c addi     r5, r31, 0x14 li
r4, 0x89 crclr    6 bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466C40:
	lwz      r3,
"sInstance__Q28PSSystem34SingletonBase<Q23PSM11ObjCalcBase>"@sda21(r13) li r4, 0
	lwz      r12, 0(r3)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466C78
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466C78:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466C98
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466C98:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466CB8
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466CB8:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_80466CDC
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466CDC:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x50(r12)
	mtctr    r12
	bctrl
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466D10
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466D10:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466D30
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466D30:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466D50
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466D50:
	lwz      r3, 4(r28)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_80466D74
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466D74:
	lwz      r12, 0(r30)
	mr       r3, r30
	lwz      r12, 0x40(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_80466DA4
	addi     r3, r31, 0x858
	addi     r5, r31, 0x14
	li       r4, 0x177
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466DA4:
	lwz      r12, 0(r30)
	mr       r3, r30
	lwz      r28, 0x28(r29)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	or.      r27, r3, r3
	beq      lbl_80466EF0
	mr       r3, r28
	addi     r4, r31, 0x94
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x80
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x168
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0xb0
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x180
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x26c
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x37c
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x878
	bl       strcmp
	cmpwi    r3, 0
	beq      lbl_80466E78
	mr       r3, r28
	addi     r4, r31, 0x5c
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80466EE8

lbl_80466E78:
	mr       r3, r27
	bl       off__Q28PSSystem8EnvSeMgrFv
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x58(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_80466ED8
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x6c(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_80466ED8
	mr       r3, r27
	li       r4, 0x3079
	li       r5, 1
	bl       on__Q28PSSystem8EnvSeMgrFUlb
	mr       r3, r27
	li       r4, 0x307a
	li       r5, 1
	bl       on__Q28PSSystem8EnvSeMgrFUlb

lbl_80466ED8:
	mr       r3, r27
	li       r4, 0
	bl       setAllPauseFlag__Q28PSSystem8EnvSeMgrFUc
	b        lbl_80466EF0

lbl_80466EE8:
	mr       r3, r27
	bl       reservePauseOff__Q28PSSystem8EnvSeMgrFv

lbl_80466EF0:
	mr       r3, r28
	addi     r4, r31, 0x5a8
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80466FA0
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466F24
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466F24:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466F44
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466F44:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80466F64
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466F64:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_80466F88
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466F88:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80467184

lbl_80466FA0:
	mr       r3, r28
	addi     r4, r31, 0x1ec
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80467094
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80466FD4
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466FD4:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_80466FF4
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80466FF4:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80467014
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xc7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467014:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_80467038
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1e5
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467038:
	addi     r3, r28, 0x10
	li       r4, 1
	bl       getSeq__Q28PSSystem6SeqMgrFUl
	or.      r28, r3, r3
	bne      lbl_80467060
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1e7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467060:
	cmplwi   r28, 0
	bne      lbl_8046707C
	addi     r3, r31, 0
	addi     r5, r31, 0x14
	li       r4, 0x342
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046707C:
	mr       r3, r28
	lwz      r12, 0x10(r28)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	b        lbl_80467184

lbl_80467094:
	mr       r3, r28
	addi     r4, r31, 0x610
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80467184
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_804670C8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804670C8:
	lwz      r28, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r28, 0
	bne      lbl_804670E8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804670E8:
	lwz      r0, 4(r28)
	cmplwi   r0, 0
	bne      lbl_80467108
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xc7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467108:
	lwz      r3, 4(r28)
	lwz      r28, 4(r3)
	cmplwi   r28, 0
	bne      lbl_8046712C
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1e5
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046712C:
	addi     r3, r28, 0x10
	li       r4, 1
	bl       getSeq__Q28PSSystem6SeqMgrFUl
	or.      r28, r3, r3
	bne      lbl_80467154
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1e7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467154:
	cmplwi   r28, 0
	bne      lbl_80467170
	addi     r3, r31, 0
	addi     r5, r31, 0x14
	li       r4, 0x346
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467170:
	mr       r3, r28
	lwz      r12, 0x10(r28)
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl

lbl_80467184:
	addi     r3, r30, 0x10
	bl       reservePauseOffAllSeq__Q28PSSystem6SeqMgrFv
	lwz      r12, 0x24(r29)
	cmplwi   r12, 0
	beq      lbl_804671A0
	mtctr    r12
	bctrl

lbl_804671A0:
	lwz      r4, 0x20(r29)
	addis    r0, r4, 1
	cmplwi   r0, 0xffff
	beq      lbl_804671BC
	lwz      r3, spSysIF__8PSSystem@sda21(r13)
	li       r5, 0
	bl       playSystemSe__Q28PSSystem5SysIFFUlUl

lbl_804671BC:
	lmw      r27, 0xc(r1)
	lwz      r0, 0x24(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	804671D0
 * Size:	000268
 */
void Demo::onMessageEnd(int)
{
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r29, r4
	lwz      r30, 0x28(r3)
	lis      r3, lbl_8049D080@ha
	addi     r31, r3, lbl_8049D080@l
	mr       r3, r30
	addi     r4, r31, 0x580
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_80467348
	lwz      r0,
"sInstance__Q28PSSystem49SingletonBase<Q36PSGame10SoundTable11CategoryMgr>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8046722C
	addi     r3, r31, 0x86c
	addi     r5, r31, 0x14
	li       r4, 0x89
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046722C:
	lwz      r30,
"sInstance__Q28PSSystem49SingletonBase<Q36PSGame10SoundTable11CategoryMgr>"@sda21(r13)
	lwz      r0, 0x18(r30)
	cmplwi   r0, 0
	bne      lbl_80467250
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x5d
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467250:
	lwz      r3, 0x18(r30)
	li       r0, 0
	stb      r0, 0x15(r3)
	lwz      r0, 0xc(r30)
	cmplwi   r0, 0
	bne      lbl_8046727C
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x5d
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046727C:
	lwz      r3, 0xc(r30)
	li       r0, 0
	stb      r0, 0x15(r3)
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_804672A8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804672A8:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_804672C8
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804672C8:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_804672E8
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804672E8:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_8046730C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046730C:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_8046732C
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5a
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8046732C:
	lwz      r3, 4(r30)
	li       r4, 5
	lwz      r12, 0(r3)
	lwz      r12, 0x20(r12)
	mtctr    r12
	bctrl
	b        lbl_8046741C

lbl_80467348:
	mr       r3, r30
	addi     r4, r31, 0x810
	bl       strcmp
	cmpwi    r3, 0
	bne      lbl_8046741C
	cmpwi    r29, 0
	bne      lbl_8046741C
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80467384
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467384:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_804673A4
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804673A4:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_804673C4
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804673C4:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_804673E8
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804673E8:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80467408
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0x5a
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467408:
	lwz      r3, 4(r30)
	lwz      r12, 0(r3)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_8046741C:
	lwz      r0, 0x24(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

} // namespace PSM

/*
 * --INFO--
 * Address:	80467438
 * Size:	0000E4
 */
void PSMCancelToPauseOffMainBgm()
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r3, lbl_8049D080@ha
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	addi     r31, r3, lbl_8049D080@l
	stw      r30, 8(r1)
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80467474
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467474:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_80467494
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467494:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_804674B4
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804674B4:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_804674D8
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804674D8:
	addi     r3, r30, 0x10
	bl       cancelPauseOffAllSeq__Q28PSSystem6SeqMgrFv
	mr       r3, r30
	lwz      r12, 0(r30)
	lwz      r12, 0x2c(r12)
	mtctr    r12
	bctrl
	cmplwi   r3, 0
	beq      lbl_80467504
	li       r0, 0
	sth      r0, 0x10(r3)

lbl_80467504:
	lwz      r0, 0x14(r1)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	8046751C
 * Size:	0000EC
 */
PSM::Scene_Game* PSMGetGameSceneA()
{
	/*
	stwu     r1, -0x10(r1)
	mflr     r0
	lis      r3, lbl_8049D080@ha
	stw      r0, 0x14(r1)
	stw      r31, 0xc(r1)
	addi     r31, r3, lbl_8049D080@l
	stw      r30, 8(r1)
	lwz      r0, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80467558
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1d3
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467558:
	lwz      r30, spSceneMgr__8PSSystem@sda21(r13)
	cmplwi   r30, 0
	bne      lbl_80467578
	addi     r3, r31, 0x20
	addi     r5, r31, 0x14
	li       r4, 0x1dc
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467578:
	lwz      r0, 4(r30)
	cmplwi   r0, 0
	bne      lbl_80467598
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x14
	li       r4, 0xcf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80467598:
	lwz      r3, 4(r30)
	lwz      r30, 4(r3)
	cmplwi   r30, 0
	bne      lbl_804675BC
	addi     r3, r31, 0x2c
	addi     r5, r31, 0x38
	li       r4, 0xd1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804675BC:
	lwz      r12, 0(r30)
	mr       r3, r30
	lwz      r12, 0x40(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_804675EC
	addi     r3, r31, 0x858
	addi     r5, r31, 0x14
	li       r4, 0x177
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_804675EC:
	lwz      r0, 0x14(r1)
	mr       r3, r30
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x10
	blr
	*/
}

/*
 * --INFO--
 * Address:	80467608
 * Size:	000018
 */
bool PSM::Scene_Cave::isPollutUp()
{
	return (mPollutUpTimer != -1);
	/*
	lwz      r4, 0x64(r3)
	subfic   r3, r4, -1
	addi     r0, r4, 1
	or       r0, r3, r0
	srwi     r3, r0, 0x1f
	blr
	*/
}

/*
 * --INFO--
 * Address:	80467620
 * Size:	000008
 */
PSSystem::EnvSeBase* PSM::SceneBase::getEnvSe() { return nullptr; }

/*
 * --INFO--
 * Address:	80467628
 * Size:	000008
 */
void PSM::ObjCalcBase::setMode(PSM::ObjCalcBase::Mode mode) { mMode = mode; }
