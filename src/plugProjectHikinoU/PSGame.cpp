#include "PSGame/BASARC.h"
#include "PSSystem/PSSystemIF.h"
#include "PSAutoBgm/PSAutoBgm.h"
#include "PSGame/CameraMgr.h"
#include "PSGame/EnvSe.h"
#include "PSGame/PikScene.h"
#include "PSGame/SceneInfo.h"
#include "PSGame/SoundTable.h"
#include "PSGame/SysFactory.h"
#include "PSM/BossSeq.h"
#include "PSSystem/ConductorList.h"
#include "PSGame/SeMgr.h"
#include "PSGame/Global.h"
#include "PSSystem/PSGame.h"
#include "JSystem/JAudio/JALCalc.h"
#include "JSystem/JAudio/JAI/JAInter/SeMgr.h"
#include "Game/gamePlayData.h"
#include "PSGame/PSSe.h"
#include "PSM/Scene.h"

bool PSGame::ConductorList::sToolMode;
PSGame::ConductorList* PSSystem::SingletonBase<PSGame::ConductorList>::sInstance;

namespace PSGame {
char newSeqName[32];

/**
 * @note Address: 0x80334268
 * @note Size: 0x28
 */
u8 CaveFloorInfo::getCaveNoFromID()
{
	if (mCaveID.fullView == 'test') {
		return 0;
	}
	return (u8)(mCaveID.byteView[3] - '1');
}

/**
 * @note Address: N/A
 * @note Size: 0x70
 */
ConductorList::ConductorList()
    : SingletonBase()
{
	mCaveInfos = nullptr;
	mCaveCount = 255;
}

/**
 * @note Address: 0x80334290
 * @note Size: 0xD4
 */
ConductorList::~ConductorList()
{
	for (u8 i = 0; i < mCaveCount; i++) {
		// works, but theres something weird going on here
		delete[](&mCaveInfos->mFileNames)[i * 2];
	}

	delete[] mCaveInfos;
}

/**
 * @note Address: 0x80334364
 * @note Size: 0x1AC
 */
bool ConductorList::read(Stream& input)
{
	mCaveCount = input.readByte();
	P2ASSERTLINE(140, !mCaveInfos);
	mCaveInfos = new (JKRGetCurrentHeap(), 0xffffffe0) CaveInfo[mCaveCount];
	P2ASSERTLINE(144, mCaveInfos);

	for (u8 i = 0; i < mCaveCount; i++) {
		u8 floors                    = input.readByte();
		mCaveInfos[i].mFileNameCount = floors;
		mCaveInfos[i].mFileNames     = new (JKRGetCurrentHeap(), 0xffffffe0) char[floors * 32];
		for (u8 j = 0; j < floors; j++) {
			char* str = &mCaveInfos[i].mFileNames[j * 32];
			input.readString(str, 32);
			P2ASSERTLINE(156, strcmp(str, "endoffile"));
			P2ASSERTBOOLLINE(158, str[0] < '0' || str[0] > '9');
		}
	}

	return true;
}

/**
 * @note Address: N/A
 * @note Size: 0xF4
 */
char* ConductorList::getInfo(u8 caves, u8 floor)
{
	if (sToolMode && (caves >= mCaveCount || floor >= mCaveInfos[caves].mFileNameCount)) {
		return &mCaveInfos[0].mFileNames[0];
	}

	P2ASSERTLINE(175, caves < mCaveCount);
	P2ASSERTLINE(176, floor < mCaveInfos[caves].mFileNameCount);
	return &mCaveInfos[caves].mFileNames[floor * 32];
}

/**
 * @note Address: N/A
 * @note Size: 0x12C
 */
u8 ConductorList::getAutoBgmInfo(u8 id1, u8 id2)
{
	if (newSeqName[5] >= '0' && newSeqName[5] <= '9') {
		id1 = newSeqName[5] - '0';
	} else {
		id1 = 255;
	}
	P2ASSERTLINE(258, id1 != 0xffff);

	if (newSeqName[4] >= '0' && newSeqName[4] <= '9') {
		id2 = newSeqName[4] - '0';
	} else {
		id2 = 255;
	}
	P2ASSERTLINE(260, id2 != 0xffff);

	return u8(id1 + (id2 * 10));
}

/**
 * @note Address: 0x80334524
 * @note Size: 0x3D4
 */
void ConductorList::getSeqAndWaveFromConductor(char const* cndName, u8* wScene, char** bmsName)
{
	// CAVESOIL UNITS
	if (!strncmp("cavesoil", cndName, strlen("cavesoil"))) {
		*bmsName = "cavesoil.bms";
		cndName += strlen("cavesoil_");
		if (!strncmp(cndName, "00", 2)) {
			*wScene = PSSystem::WaveScene::WSCENE22_CaveSoil_00;
		} else if (!strncmp(cndName, "05", 2)) {
			*wScene = PSSystem::WaveScene::WSCENE33_CaveSoil_05;
		} else {
			*wScene = PSSystem::WaveScene::WSCENE34_CaveSoil_10;
		}
		return;
	}

	// CAVEMETAL UNITS
	if (!strncmp("cavemetal", cndName, strlen("cavemetal"))) {
		*bmsName = "cavemetal.bms";
		cndName += strlen("cavemetal_");
		if (!strncmp(cndName, "00", 2)) {
			*wScene = PSSystem::WaveScene::WSCENE10_CaveMetal_00;
		} else if (!strncmp(cndName, "05", 2)) {
			*wScene = PSSystem::WaveScene::WSCENE29_CaveMetal_05;
		} else {
			*wScene = PSSystem::WaveScene::WSCENE30_CaveMetal_10;
		}
		return;
	}

	// CAVECONC UNITS
	if (!strncmp("caveconc", cndName, strlen("caveconc"))) {
		*bmsName = "caveconc.bms";
		cndName += strlen("caveconc_");
		if (!strncmp(cndName, "00", 2)) {
			*wScene = PSSystem::WaveScene::WSCENE26_CaveConc_00;
		} else if (!strncmp(cndName, "05", 2)) {
			*wScene = PSSystem::WaveScene::WSCENE31_CaveConc_05;
		} else {
			*wScene = PSSystem::WaveScene::WSCENE32_CaveConc_10;
		}
		return;
	}

	// NEW UNITS
	if (!strncmp("new", cndName, strlen("new"))) {
		strcpy(newSeqName, cndName);
		strcpy(&newSeqName[6], ".bms");
		*bmsName = newSeqName;
		*wScene  = PSSystem::WaveScene::WSCENE37_EmergenceCave + getAutoBgmInfo(0, 0);
		return;
	}

	// CAVETILE UNITS
	if (!strncmp("cavetile", cndName, strlen("cavetile"))) {
		*bmsName = "cavetile.bms";
		*wScene  = PSSystem::WaveScene::WSCENE24_CaveTile;
		return;
	}

	// CAVEGLASS UNITS
	if (!strncmp("caveglass", cndName, strlen("caveglass"))) {
		*bmsName = "caveglass.bms";
		*wScene  = PSSystem::WaveScene::WSCENE23_CaveOutside;
		return;
	}

	// CAVETSUMIKI UNITS
	if (!strncmp("cavetsumiki", cndName, strlen("cavetsumiki"))) {
		*bmsName = "cavetsumiki.bms";
		*wScene  = PSSystem::WaveScene::WSCENE25_CaveToy;
		return;
	}

	// CAVERELAX UNITS
	if (!strncmp("caverelax", cndName, strlen("caverelax"))) {
		*bmsName = "caverelax.bms";
		*wScene  = PSSystem::WaveScene::WSCENE28_CaveRestFloor;
		return;
	}

	JUT_PANICLINE(289, cndName);
}

/**
 * @note Address: 0x803348F8
 * @note Size: 0xE0
 */
SoundTable::CategoryMgr::CategoryMgr()
    : SingletonBase(this)
{
	for (u8 i = 0; i < SoundCat_COUNT; i++) {
		mPerspInfo[i] = new SePerspInfo;
		P2ASSERTLINE(312, mPerspInfo[i]);
		initiate(i);
	}
}

/**
 * @note Address: 0x803349D8
 * @note Size: 0x174
 */
void SoundTable::CategoryMgr::initiate(u8 id)
{
	P2ASSERTLINE(319, mPerspInfo[id]);

	switch (id) {
	case SoundCat0_Navi:
		mPerspInfo[id]->set(1.0f, 700.0f, 0.18f, 2600.0f, 200.0f);
		break;
	case SoundCat1_System:
		mPerspInfo[id]->set(1.0f, 700.0f, 0.18f, 2600.0f, 200.0f);
		break;
	case SoundCat2_Piki:
		mPerspInfo[id]->set(1.0f, 700.0f, 0.18f, 2600.0f, 200.0f);
		break;
	case SoundCat3_Item:
		mPerspInfo[id]->set(1.0f, 700.0f, 0.18f, 2600.0f, 200.0f);
		break;
	case SoundCat4_Env:
		mPerspInfo[id]->set(1.0f, 684.0f, 0.197f, 4012.5f, 200.0f);
		break;
	case SoundCat5_Enemy:
		mPerspInfo[id]->set(1.0f, 700.0f, 0.18f, 2600.0f, 200.0f);
		break;
	default:
		P2ASSERTLINE(341, false);
	}
}

/**
 * @note Address: 0x80334B4C
 * @note Size: 0x18
 */
void SoundTable::SePerspInfo::set(f32 defDist, f32 baseDist, f32 a3, f32 a4, f32 forcedDist)
{
	mDefaultDistance = defDist;
	mBaseDistance    = baseDist;
	_08              = a3;
	_0C              = a4;
	mForcedDistance  = forcedDist;
}

/**
 * @note Address: 0x80334B64
 * @note Size: 0x164
 */
f32 SoundTable::SePerspInfo::getDistVol(f32 factor, u8 flag)
{
	if (mDisabled) {
		return 0.0f;
	} else {
		f32 mult = mBaseDistance;
		switch (flag) {
		case 0:
		case 1:
		case 2:
			break;
		case 3:
			mult *= 2.0f;
			break;
		case 4:
			mult *= 0.0f;
			break;
		case 5:
			mult *= 0.5f;
			break;
		case 6:
			mult *= 0.25f;
			break;
		case 7:
			mult = mForcedDistance;
			break;
		default:
			JUT_PANICLINE(403, "P2Assert");
		}

		if (factor < JAIGlobalParameter::getParamMaxVolumeDistance()) {
			return mDefaultDistance;
		} else if (factor < mult) {
			return JALCalc::linearTransform(factor, JAIGlobalParameter::getParamMaxVolumeDistance(), mult, mDefaultDistance, _08, false);
		} else if (factor < _0C) {
			return JALCalc::linearTransform(factor, mult, _0C, _08, JAIGlobalParameter::getParamMinDistanceVolume(), false);
		}
		return 0.0f;
	}
}

const f32 CameraMgr::sDefaultVol = 0.8f;

/**
 * @note Address: 0x80334CC8
 * @note Size: 0xA8
 */
CameraMgr::CameraMgr()
{
	mIsSpecial[0]        = false;
	mIsSpecial[1]        = false;
	mMinDistance         = 61.66f;
	mMidDistance         = 131.25f;
	mFarDistance         = 215.04f;
	mMaxDistance         = 330.18f;
	mMinDistVolume       = 1.0f;
	mMidVolume           = 0.8f;
	mFarVolume           = 0.71f;
	mMaxDistVolume       = 0.62f;
	mZoomCamVolumeMod    = 0.45f;
	mCamDistVolume[0]    = mMidDistance;
	mCamDistVolume[1]    = mMidDistance;
	mDistVolumeFactor[0] = 1.0f;
	mDistVolumeFactor[1] = 1.0f;
}

/**
 * @note Address: 0x80334D70
 * @note Size: 0x60
 */
CameraMgr::~CameraMgr() { }

/**
 * @note Address: 0x80334DD0
 * @note Size: 0x24
 */
f32 CameraMgr::getBgmCamVol(u8 id)
{
	if (mIsSpecial[id]) {
		return mZoomCamVolumeMod;
	}

	return 1.0f;
}

/**
 * @note Address: 0x80334DF4
 * @note Size: 0x4C
 */
void CameraMgr::update(u8 id, f32 distance)
{
	f32 volume            = getVol_DistBetweenCamAndLookat(distance);
	mCamDistVolume[id]    = volume;
	mDistVolumeFactor[id] = 1.0f;
}

/**
 * @note Address: 0x80334E40
 * @note Size: 0x10
 */
f32 CameraMgr::getCurrentCamDistVol(u8 id) { return mCamDistVolume[id]; }

/**
 * @note Address: 0x80334E50
 * @note Size: 0x88
 */
f32 CameraMgr::getVol_DistBetweenCamAndLookat(f32 dist)
{
	if (dist <= mMidDistance) {
		return JALCalc::linearTransform(dist, mMinDistance, mMidDistance, mMinDistVolume, mMidVolume, false);
	} else if (dist <= mFarDistance) {
		return JALCalc::linearTransform(dist, mMidDistance, mFarDistance, mMidVolume, mFarVolume, false);
	} else {
		return JALCalc::linearTransform(dist, mFarDistance, mMaxDistance, mFarVolume, mMaxDistVolume, false);
	}
}

/**
 * @note Address: 0x80334ED8
 * @note Size: 0x34
 */
SysFactory::SysFactory()
{
	mHeap          = nullptr;
	mHeapSize      = 0;
	mAafFile       = nullptr;
	mMakeSeFunc    = nullptr;
	mSolidHeapSize = 0x151800;
	mSolidHeap     = nullptr;
}

/**
 * @note Address: 0x80334F0C
 * @note Size: 0x404
 */
void SysFactory::newSoundSystem()
{
	P2ASSERTLINE(715, mHeap);
	P2ASSERTLINE(716, mHeapSize);
	P2ASSERTLINE(717, mAafFile);
	preInitJAI();

	JKRHeap* backupheap = JKRGetCurrentHeap();
	mHeap->becomeCurrentHeap();

	JKRSolidHeap* newheap = makeSolidHeap(mHeap->getFreeSize(), mHeap, false);
	P2ASSERTLINE(741, newheap);
	newheap->becomeCurrentHeap();
	PSSystem::SingletonBase<SoundTable::CategoryMgr>::newInstance();
	P2ASSERTLINE(748, mSolidHeapSize < newheap->getFreeSize());

	mSolidHeap = makeSolidHeap(mSolidHeapSize, newheap, false);
	P2ASSERTLINE(754, mSolidHeap);

	PSSystem::SetupArg arg = { mSolidHeap, mHeapSize, 231, seqCpuSync, mAafFile, "/SeqTest/" };
	P2ASSERTLINE(769, !PSSystem::spSysIF);
	PSSystem::SysIF::sMakeJAISeCallback = mMakeSeFunc;
	PSSystem::SysIF* sysif              = new PSSystem::SysIF(arg);
	P2ASSERTLINE(773, sysif);

	PSSystem::spSceneMgr = (PSSystem::SceneMgr*)newSceneMgr();
	P2ASSERTLINE(776, PSSystem::spSceneMgr);

	postInitJAI();

	PSAutoBgm::ConductorArcMgr::createInstance();
	PSSystem::ArcMgr<BASARC>::createInstance();

	PSSystem::SingletonBase<SeMgr>::newInstance();

	backupheap->becomeCurrentHeap();
	newheap->adjustSize();
	OSLockMutex(&sysif->mChecker.mMutex);
	sysif->mChecker._18 = true;
	OSUnlockMutex(&sysif->mChecker.mMutex);
	OSDisableInterrupts();
	PSSystem::spSysIF = sysif;
	OSEnableInterrupts();
}

/**
 * @note Address: 0x80335310
 * @note Size: 0x80
 */
void SysFactory::preInitJAI()
{
	JAIGlobalParameter::setParamInitDataFileName("PSGame.aaf");
	JAIGlobalParameter::setParamSequenceArchivesFileName("Seq.arc");
	JAIGlobalParameter::setParamAudioCameraMax(2);
	JAIGlobalParameter::setParamSystemTrackMax(0xe7);
	JAIGlobalParameter::setParamSeqPlayTrackMax(5);
	JAIGlobalParameter::setParamSeqControlBufferMax(10);
	JAIGlobalParameter::setParamSystemRootTrackMax(10);
	JAIGlobalParameter::setParamStayHeapSize(0xf000);
	JAIGlobalParameter::setParamAutoHeapMax(3);
	JAIGlobalParameter::setParamAutoHeapRoomSize(0xa2ff);
	JAIGlobalParameter::setParamStayHeapMax(1);
}

/**
 * @note Address: 0x80335390
 * @note Size: 0x120
 */
void SysFactory::postInitJAI()
{
	f32 max = 0.0f;
	for (u8 i = 0; i < (u8)JAIGlobalParameter::getParamSeCategoryMax(); i++) {
		if (JAInter::SoundTable::getSoundMax(i)) {
			f32 calc = getSoundCategoryInfo(PSSystem::SingletonBase<PSGame::SoundTable::CategoryMgr>::sInstance, i)->_0C;
			if (max < calc) {
				max = calc;
			}
			JAInter::SeMgr::seCategoryVolume[i]
			    = getSoundCategoryInfo(PSSystem::SingletonBase<PSGame::SoundTable::CategoryMgr>::sInstance, i)->mDefaultDistance;
		}
	}

	JAIGlobalParameter::setParamDistanceMax(max);
	JAIGlobalParameter::setParamMinDistanceVolume(0.0f);
	JAIGlobalParameter::setParamMaxVolumeDistance(120.0f);
}

/**
 * @note Address: 0x803354B0
 * @note Size: 0x38
 */
SceneInfo::SceneInfo()
    : mStageFlags(0)
    , mSceneType(0)
    , mCameras(0)
{
	for (int i = 0; i < 2; i++) {
		mCam1Position[i] = nullptr;
		mCam2Position[i] = nullptr;
		mCameraMtx[i]    = nullptr;
	}
}

/**
 * @note Address: 0x803354E8
 * @note Size: 0x78
 */
void SceneInfo::setStageFlag(SceneInfo::FlagDef flag, SceneInfo::FlagBitShift shift)
{
	if (flag == 0) {
		mStageFlags &= ~(1 << shift);
	} else if (flag == 1) {
		mStageFlags |= (1 << shift);
	} else {
		JUT_PANICLINE(906, "flag��0 or1�ł�");
	}
}

/**
 * @note Address: 0x80335560
 * @note Size: 0x10
 */
SceneInfo::FlagDef SceneInfo::getFlag(SceneInfo::FlagBitShift shift) const { return (SceneInfo::FlagDef)(mStageFlags >> shift & 1); }

/**
 * @note Address: 0x80335570
 * @note Size: 0x74
 */
void SceneInfo::setStageCamera() const
{
	for (u8 i = 0; i < mCameras; i++) {
		JAIBasic::msBasic->setCameraInfo((Vec*)mCam1Position[i], (Vec*)mCam2Position[i], mCameraMtx[i]->mMatrix.mtxView, i);
	}
}

/**
 * @note Address: 0x803355E4
 * @note Size: 0x3C
 */
PikScene::PikScene(u8 id)
    : PSSystem::Scene(id)
{
}

/**
 * @note Address: 0x80335620
 * @note Size: 0x60
 */
PikScene::~PikScene() { }

/**
 * @note Address: 0x80335680
 * @note Size: 0xA8
 */
PSM::MiddleBossSeq* PikScene::getMiddleBossBgm()
{
	char* name;
	PSM::MiddleBossSeq* seq = static_cast<PSM::MiddleBossSeq*>(mSeqMgr.getSeq(1));
	if (!seq) {
		return nullptr;
	}

	name = seq->mBmsFileName;
	if ((!strcmp(name, "m_boss.bms") || !strcmp(name, "l_boss.bms")) && seq->getCastType() == 4) {
		return seq;
	}
	return nullptr;
}

/**
 * @note Address: N/A
 * @note Size: 0x7C
 */
void PikScene::getJumpMainBgm()
{
	// UNUSED FUNCTION
}

/**
 * @note Address: 0x80335728
 * @note Size: 0x378
 */
PSSystem::Scene* PikSceneMgr::newAndSetGlobalScene()
{
	JUT_ASSERTLINE(1002, !mScenes, "2�d�ɃO���[�o���V�[�����쐬���悤�Ƃ���"); // 'I tried to create a global scene twice'
	SceneInfo info;
	info.mSceneType = 0;
	info.mCameras   = 0;
	info.setStageFlag(SceneInfo::SCENEFLAG_Unk0, SceneInfo::SFBS_1);

	mScenes = newGameScene(0, &info);
	P2ASSERTLINE(1015, mScenes);
	mScenes->adaptTo(&mScenes);
	mEndScene = mScenes;

	PSSystem::SingletonBase<PSSystem::StreamDataList>::newInstance();
	P2ASSERTLINE(1024, PSSystem::SingletonBase<PSSystem::StreamDataList>::getInstance()->onlyLoad("/user/Totaka/StreamList.txt",
	                                                                                              JKRDvdRipper::ALLOC_DIR_TOP));
	PSSystem::SingletonBase<PSSystem::SeqDataList>::newInstance();
	P2ASSERTLINE(1028, PSSystem::SingletonBase<PSSystem::SeqDataList>::getInstance()->onlyLoad("/user/Totaka/BgmList.txt",
	                                                                                           JKRDvdRipper::ALLOC_DIR_TOP));

	JAInter::SoundInfo sound = { 0x00001f00, 255, 0, 0, 0x3F800000, 0x7f000000 };
	P2ASSERTLINE(1040, sound.mVolume.c <= 0x7f);
	PSSystem::SeSeq* seq = new PSSystem::SeSeq("se.bms", sound);
	P2ASSERTLINE(1043, seq);
	seq->init();
	mScenes->appendSeq(seq);

	JAInter::SoundInfo sound2 = { 0x00000000, 0x7F, 1, 0, 0x3F800000, 0x32000000 };
	PSSystem::BgmSeq* seq2    = newStreamBgm(0xc0011011, sound2);
	P2ASSERTLINE(1061, seq2);
	seq2->init();
	mScenes->appendSeq(seq2);
	return mScenes;
}

/**
 * @note Address: 0x80335AA0
 * @note Size: 0x4AC
 */
PSSystem::Scene* PikSceneMgr::newAndSetCurrentScene(SceneInfo& info)
{
	u8 sceneType = info.getSceneType();
	P2ASSERTLINE(1093, sceneType != SceneInfo::SCENE_NULL);
	JUT_ASSERTLINE(1094, sceneType < SceneInfo::SCENE_COUNT, "scene no���s��");

	checkScene();

	JUT_ASSERTLINE(1095, !mScenes->mChild, "�O���mCurrentScene�̌㏈�����s��");

	info.setStageCamera();

	P2ASSERTLINE(1105, mScenes);
	P2ASSERTLINE(1106, !mScenes->mChild);

	u8 wScene                      = 255;
	PSAutoBgm::ConductorMgr::sHeap = JKRGetCurrentHeap();
	PSSystem::BgmSeq* seq          = initMainBgm(info, &wScene);
	P2ASSERTLINE(1132, seq);

	bool needboss              = false;
	PSSystem::SeqBase* bossSeq = nullptr;
	if ((u8)info.mSceneType == SceneInfo::CHALLENGE_MODE || (u8)info.mSceneType == SceneInfo::TWO_PLAYER_BATTLE
	    || u8(info.mSceneType - 1) <= 3 || info.isCaveFloor()) {
		needboss = true;
	}

	// Check for submerged castle theme
	if (info.isCaveFloor() && info.mSceneType == SceneInfo::COURSE_YAKUSHIMA) {
		if (static_cast<CaveFloorInfo&>(info).getCaveNoFromID() == 3 && !static_cast<CaveFloorInfo&>(info).isBossFloor()) {
			needboss = false;
		}
	}

	if (needboss) {
		bossSeq = initBossBgm(info, &wScene);
		P2ASSERTLINE(1163, bossSeq);
	}

	SceneInfo* newinfo;
	if (info.isCaveFloor()) {
		newinfo = new CaveFloorInfo(static_cast<CaveFloorInfo&>(info));
	} else {
		newinfo = new SceneInfo(info);
	}

	PSSystem::Scene* newscene = newGameScene(wScene, newinfo);

	// dumb workaround for lack of PSMainSide_Scene
	// making this null tricks the game to think its submerged castle (disable some boss bgm stuff)
	if (info.isCaveFloor() && info.mSceneType == SceneInfo::COURSE_LAST && static_cast<CaveFloorInfo&>(info).mFloorNum == 29) {
		if (static_cast<CaveFloorInfo&>(info).getCaveNoFromID() == 3 && !static_cast<CaveFloorInfo&>(info).isBossFloor()) {
			static_cast<PSM::Scene_Cave*>(newscene)->mBossFaderMgr = nullptr;
		}
	}

	P2ASSERTLINE(1185, seq);
	newscene->appendSeq(seq);

	if (needboss) {
		P2ASSERTLINE(1191, bossSeq);
		newscene->appendSeq(bossSeq);
	}

	initAdditionalBgm(info, newscene);
	P2ASSERTLINE(1214, newscene);
	mScenes->adaptChildScene(newscene);
	return newscene;
}

/**
 * @note Address: 0x80335F4C
 * @note Size: 0x98
 */
PSSystem::BgmSeq* PikSceneMgr::newBgmSeq(char const* bmsFilePath, JAInter::SoundInfo& info)
{
	PSSystem::BgmSeq* seq = new PSSystem::BgmSeq(bmsFilePath, info);
	P2ASSERTLINE(1223, seq);
	seq->init();
	return seq;
}

/**
 * @note Address: 0x80335FE4
 * @note Size: 0x88
 */
PSSystem::BgmSeq* PikSceneMgr::newStreamBgm(u32 id, JAInter::SoundInfo& info)
{
	info.mFlag            = 0;
	PSSystem::BgmSeq* seq = new PSSystem::StreamBgm(id, info);
	P2ASSERTLINE(1234, seq);
	return seq;
}

/**
 * @note Address: 0x8033606C
 * @note Size: 0x150
 */
PSSystem::BgmSeq* PikSceneMgr::initBossBgm(SceneInfo& info, u8* wScene)
{
	JAInter::SoundInfo sound = { 0x00000000, 0x7F, 0x02, 0, 0x3F800000, 0x28000000 };

	PSSystem::DirectedBgm* seq;
	if (curSceneIsBigBossFloor()) {
		seq     = (PSSystem::DirectedBgm*)newDirectedBgm("l_boss.bms", sound);
		*wScene = PSSystem::WaveScene::WSCENE35_TitanDweevil;
	} else {
		seq = (PSSystem::DirectedBgm*)newDirectedBgm("m_boss.bms", sound);
	}

	P2ASSERTLINE(1264, seq);

	seq->assertValidTrack();

	seq->mRootTrack->_3E = 60;
	P2ASSERTLINE(1267, sound.mVolume.c <= 0x7f);
	return seq;
}

/**
 * @note Address: 0x803361BC
 * @note Size: 0x400
 */
void PikSceneMgr::initAdditionalBgm(SceneInfo& info, PSSystem::Scene* scene)
{
	JAInter::SoundInfo sound = { 0x00000000, 0x7F, 0x01, 0, 0x3F800000, 0x32000000 };

	PSSystem::BgmSeq* seq;
	switch (info.mSceneType) {
	case SceneInfo::TITLE_SCREEN:
		seq = newStreamBgm(0xc0011011, sound);
		P2ASSERTLINE(1290, seq);
		scene->appendSeq(seq);

		seq = newBgmSeq("hiscore.bms", sound);
		P2ASSERTLINE(1296, seq);
		scene->appendSeq(seq);

		seq = newStreamBgm(0xc0011010, sound);
		P2ASSERTLINE(1302, seq);
		scene->appendSeq(seq);
		break;
	case SceneInfo::COURSE_TUTORIALDAY1:
		seq = newBgmSeq("n_tutorial_1stday.bms", sound);
		P2ASSERTLINE(1318, seq);
		scene->appendSeq(seq);
		break;
	case SceneInfo::CHALLENGE_MODE:
		sound._05                     = 0x04;
		sound.mVolume.c               = 0x23;
		sound.mFlag                   = 0x1f00;
		JADUtility::AccessMode flag   = (JADUtility::AccessMode)mAccessMode;
		PSSystem::DirectedBgm* seqold = (PSSystem::DirectedBgm*)scene->mSeqMgr.getFirstSeq();
		seq                           = newAutoBgm("cavekeyget.cnd", "cavekeyget.bms", sound, flag, info, seqold->mDirectorMgr);
		scene->appendSeq(seq);
		scene->setSecondaryWaveScene(PSSystem::WaveScene::WSCENE5_Challenge_KeyGet);
		P2ASSERTLINE(1342, seq == scene->mSeqMgr.getSeq(2));
		break;
	}

	CaveFloorInfo& cinfo = static_cast<CaveFloorInfo&>(info);
	// Check for submerged castle theme
	// FOR REGROWN: Add an extra check to play it in the final cave floor 30
	if (info.isCaveFloor() && !cinfo.isBossFloor()) {
		if ((cinfo.getCaveNoFromID() == 3 && info.mSceneType == SceneInfo::COURSE_YAKUSHIMA)
		    || (cinfo.getCaveNoFromID() == 3 && info.mSceneType == SceneInfo::COURSE_LAST && cinfo.mFloorNum == 29)) {
			seq = newBgmSeq("kuro_post.bms", sound);
			P2ASSERTLINE(1353, seq);
			scene->appendSeq(seq);
		}
	}
}

/**
 * @note Address: 0x803365BC
 * @note Size: 0xD24
 */
PSSystem::BgmSeq* PikSceneMgr::initMainBgm(SceneInfo& info, u8* wScene)
{
	P2ASSERTLINE(1378, wScene);
	JADUtility::AccessMode mode = (JADUtility::AccessMode)mAccessMode;
	PSSystem::BgmSeq* bgm       = nullptr;

	JAInter::SoundInfo sound = { 0x00001f00, 0x7F, 0xFF, 0, 0x3F800000, 0x32000000 };
	sound._05                = 1;

	CaveFloorInfo& cinfo = static_cast<CaveFloorInfo&>(info);
	P2ASSERTLINE(1393, sound._05 < 5);

	if (info.isCaveFloor()) {
		switch (info.mSceneType) {
		case SceneInfo::CHALLENGE_MODE:
			const char* path = "/user/Totaka/ChallengeBgmList.txt";
			PSSystem::SingletonBase<ConductorList>::newHeapInstance();

			ConductorList* list = PSSystem::SingletonBase<ConductorList>::getInstance();
			bool loaded         = list->load(path, JKRDvdRipper::ALLOC_DIR_BOTTOM);
			P2ASSERTLINE(1417, loaded);
			char* name = list->getInfo(cinfo.mChallengeModeStageNum, cinfo.mFloorNum);
			// getInfo might be returning some sort of wacky struct, with all the stack stuff
			u8 wScene2;
			char* bmsName;
			list->getSeqAndWaveFromConductor(name, &wScene2, &bmsName);
			*wScene = wScene2;
			bgm     = newAutoBgm(name, bmsName, sound, (JADUtility::AccessMode)mode, info, nullptr);
			delete PSSystem::SingletonBase<ConductorList>::sInstance;
			PSSystem::SingletonBase<ConductorList>::sInstance = nullptr;
			break;

		case SceneInfo::TWO_PLAYER_BATTLE:
			bgm     = newDirectedBgm("battle_t.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE6_2P_Battle;
			break;
		}

		if (!bgm) {
			switch (cinfo.mBetaType) {
			case 1: // Floor without music for bosses, apparently it loads caveconc_00 by default
				bgm = newAutoBgm("caveconc_00_0.cnd", "caveconc.bms", sound, (JADUtility::AccessMode)mode, info, nullptr);
				break;
			case 2:
				bgm     = newAutoBgm("caverelax.cnd", "caverelax.bms", sound, (JADUtility::AccessMode)mode, info, nullptr);
				*wScene = PSSystem::WaveScene::WSCENE28_CaveRestFloor;
				break;
			}
		}

		// Check for submerged castle theme
		// FOR REGROWN: Add an extra check to play it in the final cave floor 30
		if (info.isCaveFloor() && !cinfo.isBossFloor()) {
			if ((cinfo.getCaveNoFromID() == 3 && info.mSceneType == SceneInfo::COURSE_YAKUSHIMA)
			    || (cinfo.getCaveNoFromID() == 3 && info.mSceneType == SceneInfo::COURSE_LAST && cinfo.mFloorNum == 29)) {
				bgm = newBgmSeq("kuro_pre.bms", sound);
				P2ASSERTLINE(1566, bgm);
				*wScene = PSSystem::WaveScene::WSCENE48_SubmergedCastle;
			}
		}

		// story mode cave bgm settings
		if (!bgm) {
			P2ASSERTLINE(1574, !cinfo.mBetaType);
			char* txtpath = nullptr;
			switch (info.mSceneType) {
			case SceneInfo::COURSE_TUTORIAL:
			case SceneInfo::COURSE_TUTORIALDAY1:
				txtpath = "/user/Totaka/BgmList_Tutorial.txt";
				break;
			case SceneInfo::COURSE_FOREST:
				txtpath = "/user/Totaka/BgmList_Forest.txt";
				break;
			case SceneInfo::COURSE_YAKUSHIMA:
				txtpath = "/user/Totaka/BgmList_Yakushima.txt";
				break;
			case SceneInfo::COURSE_LAST:
				txtpath = "/user/Totaka/BgmList_Last.txt";
				break;
			case SceneInfo::COURSE_TEST:
				txtpath = "/user/Totaka/BgmList_BgmTest.txt";
				break;
			}
			PSSystem::SingletonBase<PSGame::ConductorList>::newHeapInstance();
			ConductorList* list = PSSystem::SingletonBase<PSGame::ConductorList>::getInstance();
			bool loaded         = list->load(txtpath, JKRDvdRipper::ALLOC_DIR_BOTTOM);
			P2ASSERTLINE(1601, loaded);
			OSReport("caveID==%d\n", cinfo.getCaveNoFromID());
			char* name = list->getInfo(cinfo.getCaveNoFromID(), cinfo.mFloorNum);
			u8 wScene2;
			char* bmsName;
			list->getSeqAndWaveFromConductor(name, &wScene2, &bmsName);
			*wScene = wScene2;
			bgm     = newAutoBgm(name, bmsName, sound, (JADUtility::AccessMode)mode, info, nullptr);
			delete PSSystem::SingletonBase<ConductorList>::sInstance;
			PSSystem::SingletonBase<ConductorList>::sInstance = nullptr;
		}
	} else {
		switch (info.mSceneType) {
		case SceneInfo::COURSE_TUTORIAL:
		case SceneInfo::COURSE_TUTORIALDAY1:
			bgm     = newMainBgm("n_tutorial.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE15_Valley_of_Repose;
			break;
		case SceneInfo::COURSE_FOREST:
			bgm     = newMainBgm("forest.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE2_Awakening_Wood;
			break;
		case SceneInfo::COURSE_YAKUSHIMA:
			bgm     = newMainBgm("yakushima.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE3_Perplexing_Pool;
			P2ASSERTLINE(1640, bgm);
			static_cast<PSSystem::DirectedBgm*>(bgm)->assertValidTrack();
			static_cast<PSSystem::DirectedBgm*>(bgm)->mRootTrack->_3E = 30;
			break;
		case SceneInfo::COURSE_LAST:
			bgm     = newMainBgm("last.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE4_Wistful_Wild;
			P2ASSERTLINE(1650, bgm);
			static_cast<PSSystem::DirectedBgm*>(bgm)->assertValidTrack();
			static_cast<PSSystem::DirectedBgm*>(bgm)->mRootTrack->_3E = 30;
			break;
		case SceneInfo::TITLE_SCREEN:
			bgm     = newStreamBgm(0xc0011000, sound);
			*wScene = PSSystem::WaveScene::WSCENE21_HighScores;
			break;
		case SceneInfo::CAVE_RESULTS:
			bgm = newStreamBgm(0xc0011013, sound);
			break;
		case SceneInfo::CHALLENGE_RESULTS:
			bgm = newStreamBgm(0xc0011014, sound);
			break;
		case SceneInfo::FILE_SELECT:
			bgm = newStreamBgm(0xc001101e, sound);
			break;
		case SceneInfo::WORLD_MAP_NORMAL:
			bgm     = newBgmSeq("worldmap.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE16_WorldMap;
			break;
		case SceneInfo::WORLD_MAP_NEWLEVEL:
			bgm     = newBgmSeq("worldmap_intro.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE16_WorldMap;
			break;
		case SceneInfo::CHALLENGE_MENU:
			bgm     = newBgmSeq("c_menu.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE20_ChallengeSelect;
			break;
		case SceneInfo::PIKLOPEDIA:
			bgm     = newBgmSeq("book.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE36_Piklopedia;
			break;
		case SceneInfo::ENDING_COMPLETE:
			bgm     = newBgmSeq("comp_result.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE19_Final_Result;
			break;
		case SceneInfo::ENDING_DEBTRESULT:
			bgm     = newBgmSeq("f_result.bms", sound);
			*wScene = PSSystem::WaveScene::WSCENE19_Final_Result;
			break;
		case SceneInfo::VERSUS_MENU:
			bgm = newStreamBgm(0xc001100f, sound);
			break;
		default:
			JUT_PANICLINE(1745, "P2Assert");
		}
	}

	P2ASSERTLINE(1749, bgm);
	P2ASSERTLINE(1750, sound.mVolume.c <= 127);

	return bgm;
	/*
	stwu     r1, -0x70(r1)
	mflr     r0
	stw      r0, 0x74(r1)
	stmw     r24, 0x50(r1)
	or.      r30, r5, r5
	lis      r5, lbl_8048F918@ha
	mr       r27, r3
	mr       r28, r4
	addi     r31, r5, lbl_8048F918@l
	bne      lbl_803365F8
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x562
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803365F8:
	lbz      r29, 0xc(r27)
	li       r0, 1
	lwz      r3, 0x2fc(r31)
	cmplwi   r0, 5
	lwz      r5, 0x2f8(r31)
	li       r24, 0
	stw      r3, 0x3c(r1)
	lwz      r4, 0x300(r31)
	lwz      r3, 0x304(r31)
	stw      r5, 0x38(r1)
	stw      r4, 0x40(r1)
	stw      r3, 0x44(r1)
	stb      r0, 0x3d(r1)
	blt      lbl_80336644
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x571
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336644:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_80336D38
	lbz      r0, 6(r28)
	cmpwi    r0, 7
	beq      lbl_803368A4
	bge      lbl_803368CC
	cmpwi    r0, 6
	bge      lbl_8033667C
	b        lbl_803368CC

lbl_8033667C:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	addi     r24, r31, 0x308
	cmplwi   r0, 0
	beq      lbl_803366A0
	addi     r3, r31, 0x178
	addi     r5, r31, 0xc
	li       r4, 0x7e
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803366A0:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8033670C
	lwz      r4, sCurrentHeap__7JKRHeap@sda21(r13)
	li       r3, 0x28
	li       r5, -4
	bl       __nw__FUlP7JKRHeapi
	or.      r25, r3, r3
	beq      lbl_80336708
	bl       __ct__Q28PSSystem12TextDataBaseFv
	lis      r3, "__vt__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@ha
	addic.   r4, r25, 0x1c
	addi     r0, r3,
"__vt__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@l stw      r0,
0x1c(r25) beq      lbl_803366E0 addi     r4, r4, -28

lbl_803366E0:
	lis      r3, __vt__Q26PSGame13ConductorList@ha
	stw      r4,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	addi     r4, r3, __vt__Q26PSGame13ConductorList@l
	li       r3, 0
	stw      r4, 0(r25)
	addi     r4, r4, 0x10
	li       r0, 0xff
	stw      r4, 0x1c(r25)
	stw      r3, 0x24(r25)
	stb      r0, 0x20(r25)

lbl_80336708:
	stw      r25,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)

lbl_8033670C:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8033672C
	addi     r3, r31, 0x178
	addi     r5, r31, 0xc
	li       r4, 0x81
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8033672C:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_8033674C
	addi     r3, r31, 0x178
	addi     r5, r31, 0xc
	li       r4, 0x89
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8033674C:
	lwz      r25,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13) mr
r4, r24 li       r5, 2 mr       r3, r25 bl
load__Q28PSSystem12TextDataBaseFPCcQ212JKRDvdRipper15EAllocDirection clrlwi. r0,
r3, 0x18 bne      lbl_8033677C addi     r3, r31, 0 addi     r5, r31, 0xc li r4,
0x589 crclr    6 bl       panic_f__12JUTExceptionFPCciPCce

lbl_8033677C:
	lbz      r0, sToolMode__Q26PSGame13ConductorList@sda21(r13)
	lbz      r26, 0x40(r28)
	cmplwi   r0, 0
	lbz      r24, 0x49(r28)
	beq      lbl_803367BC
	lbz      r0, 0x20(r25)
	cmplw    r24, r0
	bge      lbl_803367B0
	lwz      r3, 0x24(r25)
	rlwinm   r0, r24, 3, 0x15, 0x1c
	lbzx     r0, r3, r0
	cmplw    r26, r0
	blt      lbl_803367BC

lbl_803367B0:
	lwz      r3, 0x24(r25)
	lwz      r4, 4(r3)
	b        lbl_80336818

lbl_803367BC:
	lbz      r0, 0x20(r25)
	cmplw    r24, r0
	blt      lbl_803367DC
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0xaf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803367DC:
	lwz      r3, 0x24(r25)
	rlwinm   r24, r24, 3, 0x15, 0x1c
	lbzx     r0, r3, r24
	cmplw    r26, r0
	blt      lbl_80336804
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0xb0
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336804:
	lwz      r3, 0x24(r25)
	rlwinm   r0, r26, 5, 0x13, 0x1a
	add      r3, r3, r24
	lwz      r3, 4(r3)
	add      r4, r3, r0

lbl_80336818:
	stw      r4, 0x18(r1)
	mr       r3, r25
	addi     r5, r1, 0x1c
	addi     r6, r1, 0x14
	bl       getSeqAndWaveFromConductor__Q26PSGame13ConductorListFPCcPUcPPc
	lwz      r0, 0x1c(r1)
	mr       r3, r27
	lwz      r5, 0x14(r1)
	mr       r7, r29
	stw      r0, 0x34(r1)
	mr       r8, r28
	lwz      r4, 0x18(r1)
	addi     r6, r1, 0x38
	lbz      r0, 0x34(r1)
	li       r9, 0
	stw      r5, 0x2c(r1)
	stb      r0, 0(r30)
	lwz      r12, 0(r27)
	stw      r4, 0x30(r1)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13) mr
r24, r3 cmplwi   r0, 0 beq      lbl_80336898 mr       r3, r0 li       r4, 1 lwz
r12, 0(r3) lwz      r12, 8(r12) mtctr    r12 bctrl

lbl_80336898:
	li       r0, 0
	stw      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13) b
lbl_803368CC

lbl_803368A4:
	mr       r3, r27
	addi     r4, r31, 0x32c
	lwz      r12, 0(r27)
	addi     r5, r1, 0x38
	lwz      r12, 0x18(r12)
	mtctr    r12
	bctrl
	li       r0, 6
	mr       r24, r3
	stb      r0, 0(r30)

lbl_803368CC:
	cmplwi   r24, 0
	bne      lbl_8033695C
	lwz      r0, 0x3c(r28)
	cmpwi    r0, 2
	beq      lbl_80336924
	bge      lbl_8033695C
	cmpwi    r0, 1
	bge      lbl_803368F0
	b        lbl_8033695C

lbl_803368F0:
	mr       r3, r27
	mr       r7, r29
	lwz      r12, 0(r27)
	mr       r8, r28
	addi     r4, r31, 0x33c
	addi     r5, r31, 0x80
	lwz      r12, 0x1c(r12)
	addi     r6, r1, 0x38
	li       r9, 0
	mtctr    r12
	bctrl
	mr       r24, r3
	b        lbl_8033695C

lbl_80336924:
	mr       r3, r27
	mr       r7, r29
	lwz      r12, 0(r27)
	mr       r8, r28
	addi     r4, r31, 0x350
	addi     r5, r31, 0xfc
	lwz      r12, 0x1c(r12)
	addi     r6, r1, 0x38
	li       r9, 0
	mtctr    r12
	bctrl
	li       r0, 0x1c
	mr       r24, r3
	stb      r0, 0(r30)

lbl_8033695C:
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	beq      lbl_80336A44
	lbz      r0, 6(r28)
	cmplwi   r0, 3
	bne      lbl_80336A44
	lwz      r3, 0x44(r28)
	addis    r0, r3, 0x8b9b
	cmplwi   r0, 0x7374
	bne      lbl_8033699C
	li       r0, 0
	b        lbl_803369A8

lbl_8033699C:
	lbz      r3, 0x47(r28)
	addi     r0, r3, -49
	clrlwi   r0, r0, 0x18

lbl_803369A8:
	clrlwi   r0, r0, 0x18
	cmplwi   r0, 3
	bne      lbl_80336A44
	mr       r3, r28
	lwz      r12, 0(r28)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	clrlwi.  r0, r3, 0x18
	bne      lbl_80336A44
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_803369F0
	addi     r4, r31, 0x360
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_803369F0:
	cmplwi   r24, 0
	bne      lbl_80336A0C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336A0C:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	cmplwi   r24, 0
	bne      lbl_80336A3C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x61e
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336A3C:
	li       r0, 0x30
	stb      r0, 0(r30)

lbl_80336A44:
	cmplwi   r24, 0
	bne      lbl_8033728C
	lwz      r0, 0x3c(r28)
	cmpwi    r0, 0
	beq      lbl_80336A6C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x626
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336A6C:
	lbz      r0, 6(r28)
	li       r25, 0
	cmplwi   r0, 0x14
	bgt      lbl_80336AB8
	lis      r3, lbl_804DA974@ha
	slwi     r0, r0, 2
	addi     r3, r3, lbl_804DA974@l
	lwzx     r0, r3, r0
	mtctr    r0
	bctr
	.global  lbl_80336A94

lbl_80336A94:
	addi     r25, r31, 0x370
	b        lbl_80336AB8
	.global  lbl_80336A9C

lbl_80336A9C:
	addi     r25, r31, 0x394
	b        lbl_80336AB8
	.global  lbl_80336AA4

lbl_80336AA4:
	addi     r25, r31, 0x3b4
	b        lbl_80336AB8
	.global  lbl_80336AAC

lbl_80336AAC:
	addi     r25, r31, 0x3d8
	b        lbl_80336AB8
	.global  lbl_80336AB4

lbl_80336AB4:
	addi     r25, r31, 0x3f8
	.global  lbl_80336AB8

lbl_80336AB8:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	beq      lbl_80336AD8
	addi     r3, r31, 0x178
	addi     r5, r31, 0xc
	li       r4, 0x7e
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336AD8:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80336B44
	lwz      r4, sCurrentHeap__7JKRHeap@sda21(r13)
	li       r3, 0x28
	li       r5, -4
	bl       __nw__FUlP7JKRHeapi
	or.      r24, r3, r3
	beq      lbl_80336B40
	bl       __ct__Q28PSSystem12TextDataBaseFv
	lis      r3, "__vt__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@ha
	addic.   r4, r24, 0x1c
	addi     r0, r3,
"__vt__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@l stw      r0,
0x1c(r24) beq      lbl_80336B18 addi     r4, r4, -28

lbl_80336B18:
	lis      r3, __vt__Q26PSGame13ConductorList@ha
	stw      r4,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	addi     r4, r3, __vt__Q26PSGame13ConductorList@l
	li       r3, 0
	stw      r4, 0(r24)
	addi     r4, r4, 0x10
	li       r0, 0xff
	stw      r4, 0x1c(r24)
	stw      r3, 0x24(r24)
	stb      r0, 0x20(r24)

lbl_80336B40:
	stw      r24,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)

lbl_80336B44:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80336B64
	addi     r3, r31, 0x178
	addi     r5, r31, 0xc
	li       r4, 0x81
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336B64:
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13)
	cmplwi   r0, 0
	bne      lbl_80336B84
	addi     r3, r31, 0x178
	addi     r5, r31, 0xc
	li       r4, 0x89
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336B84:
	lwz      r24,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13) mr
r4, r25 li       r5, 2 mr       r3, r24 bl
load__Q28PSSystem12TextDataBaseFPCcQ212JKRDvdRipper15EAllocDirection clrlwi. r0,
r3, 0x18 bne      lbl_80336BB4 addi     r3, r31, 0 addi     r5, r31, 0xc li r4,
0x641 crclr    6 bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336BB4:
	lwz      r4, 0x44(r28)
	addi     r3, r31, 0x41c
	addis    r0, r4, 0x8b9b
	cmplwi   r0, 0x7374
	bne      lbl_80336BD0
	li       r0, 0
	b        lbl_80336BDC

lbl_80336BD0:
	lbz      r4, 0x47(r28)
	addi     r0, r4, -49
	clrlwi   r0, r0, 0x18

lbl_80336BDC:
	clrlwi   r4, r0, 0x18
	crclr    6
	bl       OSReport
	lwz      r3, 0x44(r28)
	lbz      r26, 0x40(r28)
	addis    r0, r3, 0x8b9b
	cmplwi   r0, 0x7374
	bne      lbl_80336C04
	li       r25, 0
	b        lbl_80336C10

lbl_80336C04:
	lbz      r3, 0x47(r28)
	addi     r0, r3, -49
	clrlwi   r25, r0, 0x18

lbl_80336C10:
	lbz      r0, sToolMode__Q26PSGame13ConductorList@sda21(r13)
	cmplwi   r0, 0
	beq      lbl_80336C4C
	lbz      r0, 0x20(r24)
	clrlwi   r3, r25, 0x18
	cmplw    r3, r0
	bge      lbl_80336C40
	lwz      r3, 0x24(r24)
	rlwinm   r0, r25, 3, 0x15, 0x1c
	lbzx     r0, r3, r0
	cmplw    r26, r0
	blt      lbl_80336C4C

lbl_80336C40:
	lwz      r3, 0x24(r24)
	lwz      r4, 4(r3)
	b        lbl_80336CAC

lbl_80336C4C:
	lbz      r0, 0x20(r24)
	clrlwi   r3, r25, 0x18
	cmplw    r3, r0
	blt      lbl_80336C70
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0xaf
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336C70:
	lwz      r3, 0x24(r24)
	rlwinm   r25, r25, 3, 0x15, 0x1c
	lbzx     r0, r3, r25
	cmplw    r26, r0
	blt      lbl_80336C98
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0xb0
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336C98:
	lwz      r3, 0x24(r24)
	rlwinm   r0, r26, 5, 0x13, 0x1a
	add      r3, r3, r25
	lwz      r3, 4(r3)
	add      r4, r3, r0

lbl_80336CAC:
	stw      r4, 0xc(r1)
	mr       r3, r24
	addi     r5, r1, 0x10
	addi     r6, r1, 8
	bl       getSeqAndWaveFromConductor__Q26PSGame13ConductorListFPCcPUcPPc
	lwz      r0, 0x10(r1)
	mr       r3, r27
	lwz      r5, 8(r1)
	mr       r7, r29
	stw      r0, 0x28(r1)
	mr       r8, r28
	lwz      r4, 0xc(r1)
	addi     r6, r1, 0x38
	lbz      r0, 0x28(r1)
	li       r9, 0
	stw      r5, 0x20(r1)
	stb      r0, 0(r30)
	lwz      r12, 0(r27)
	stw      r4, 0x24(r1)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	lwz      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13) mr
r24, r3 cmplwi   r0, 0 beq      lbl_80336D2C mr       r3, r0 li       r4, 1 lwz
r12, 0(r3) lwz      r12, 8(r12) mtctr    r12 bctrl

lbl_80336D2C:
	li       r0, 0
	stw      r0,
"sInstance__Q28PSSystem39SingletonBase<Q26PSGame13ConductorList>"@sda21(r13) b
lbl_8033728C

lbl_80336D38:
	lbz      r0, 6(r28)
	cmplwi   r0, 0x14
	bgt      lbl_80337278
	lis      r3, lbl_804DA920@ha
	slwi     r0, r0, 2
	addi     r3, r3, lbl_804DA920@l
	lwzx     r0, r3, r0
	mtctr    r0
	bctr
	.global  lbl_80336D5C

lbl_80336D5C:
	mr       r3, r27
	addi     r4, r31, 0x428
	lwz      r12, 0(r27)
	addi     r5, r1, 0x38
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	li       r0, 0xf
	mr       r24, r3
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_80336D88

lbl_80336D88:
	mr       r3, r27
	addi     r4, r31, 0x438
	lwz      r12, 0(r27)
	addi     r5, r1, 0x38
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	li       r0, 2
	mr       r24, r3
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_80336DB4

lbl_80336DB4:
	mr       r3, r27
	addi     r4, r31, 0x444
	lwz      r12, 0(r27)
	addi     r5, r1, 0x38
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	li       r0, 3
	or.      r24, r3, r3
	stb      r0, 0(r30)
	bne      lbl_80336DF4
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x668
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336DF4:
	lbz      r0, 0xb4(r24)
	li       r3, 0
	cmplwi   r0, 1
	bne      lbl_80336E14
	lwz      r0, 0x70(r24)
	cmplwi   r0, 0
	beq      lbl_80336E14
	li       r3, 1

lbl_80336E14:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80336E30
	addi     r5, r31, 0xc
	addi     r3, r2, lbl_8051E13C@sda21
	li       r4, 0x19f
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336E30:
	lwz      r3, 0x70(r24)
	li       r0, 0x1e
	sth      r0, 0x3e(r3)
	b        lbl_8033728C
	.global  lbl_80336E40

lbl_80336E40:
	mr       r3, r27
	addi     r4, r31, 0x454
	lwz      r12, 0(r27)
	addi     r5, r1, 0x38
	lwz      r12, 0x14(r12)
	mtctr    r12
	bctrl
	li       r0, 4
	or.      r24, r3, r3
	stb      r0, 0(r30)
	bne      lbl_80336E80
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x672
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336E80:
	lbz      r0, 0xb4(r24)
	li       r3, 0
	cmplwi   r0, 1
	bne      lbl_80336EA0
	lwz      r0, 0x70(r24)
	cmplwi   r0, 0
	beq      lbl_80336EA0
	li       r3, 1

lbl_80336EA0:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80336EBC
	addi     r5, r31, 0xc
	addi     r3, r2, lbl_8051E13C@sda21
	li       r4, 0x19f
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336EBC:
	lwz      r3, 0x70(r24)
	li       r0, 0x1e
	sth      r0, 0x3e(r3)
	b        lbl_8033728C
	.global  lbl_80336ECC

lbl_80336ECC:
	li       r0, 0
	li       r3, 0x74
	stw      r0, 0x38(r1)
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80336EF8
	lis      r4, 0xC0011000@ha
	addi     r5, r1, 0x38
	addi     r4, r4, 0xC0011000@l
	bl       __ct__Q28PSSystem9StreamBgmFUlRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80336EF8:
	cmplwi   r24, 0
	bne      lbl_80336F14
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4d2
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80336F14:
	li       r0, 0x15
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_80336F20

lbl_80336F20:
	li       r0, 0
	li       r3, 0x74
	stw      r0, 0x38(r1)
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80336F4C
	lis      r4, 0xC0011013@ha
	addi     r5, r1, 0x38
	addi     r4, r4, 0xC0011013@l
	bl       __ct__Q28PSSystem9StreamBgmFUlRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80336F4C:
	cmplwi   r24, 0
	bne      lbl_8033728C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4d2
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_8033728C
	.global  lbl_80336F6C

lbl_80336F6C:
	li       r0, 0
	li       r3, 0x74
	stw      r0, 0x38(r1)
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80336F98
	lis      r4, 0xC0011014@ha
	addi     r5, r1, 0x38
	addi     r4, r4, 0xC0011014@l
	bl       __ct__Q28PSSystem9StreamBgmFUlRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80336F98:
	cmplwi   r24, 0
	bne      lbl_8033728C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4d2
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_8033728C
	.global  lbl_80336FB8

lbl_80336FB8:
	li       r0, 0
	li       r3, 0x74
	stw      r0, 0x38(r1)
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80336FE4
	lis      r4, 0xC001101E@ha
	addi     r5, r1, 0x38
	addi     r4, r4, 0xC001101E@l
	bl       __ct__Q28PSSystem9StreamBgmFUlRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80336FE4:
	cmplwi   r24, 0
	bne      lbl_8033728C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4d2
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_8033728C
	.global  lbl_80337004

lbl_80337004:
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80337024
	addi     r4, r31, 0x460
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80337024:
	cmplwi   r24, 0
	bne      lbl_80337040
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80337040:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	li       r0, 0x10
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_80337060

lbl_80337060:
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80337080
	addi     r4, r31, 0x470
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80337080:
	cmplwi   r24, 0
	bne      lbl_8033709C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8033709C:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	li       r0, 0x10
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_803370BC

lbl_803370BC:
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_803370DC
	addi     r4, r31, 0x484
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_803370DC:
	cmplwi   r24, 0
	bne      lbl_803370F8
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803370F8:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	li       r0, 0x14
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_80337118

lbl_80337118:
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80337138
	addi     r4, r31, 0x490
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80337138:
	cmplwi   r24, 0
	bne      lbl_80337154
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_80337154:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	li       r0, 0x24
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_80337174

lbl_80337174:
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80337194
	addi     r4, r31, 0x49c
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80337194:
	cmplwi   r24, 0
	bne      lbl_803371B0
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803371B0:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	li       r0, 0x13
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_803371D0

lbl_803371D0:
	li       r3, 0x6c
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_803371F0
	addi     r4, r31, 0x4ac
	addi     r5, r1, 0x38
	bl       __ct__Q28PSSystem6BgmSeqFPCcRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_803371F0:
	cmplwi   r24, 0
	bne      lbl_8033720C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4c7
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8033720C:
	mr       r3, r24
	lwz      r12, 0x10(r24)
	lwz      r12, 0xc(r12)
	mtctr    r12
	bctrl
	li       r0, 0x13
	stb      r0, 0(r30)
	b        lbl_8033728C
	.global  lbl_8033722C

lbl_8033722C:
	li       r0, 0
	li       r3, 0x74
	stw      r0, 0x38(r1)
	bl       __nw__FUl
	or.      r24, r3, r3
	beq      lbl_80337258
	lis      r4, 0xC001100F@ha
	addi     r5, r1, 0x38
	addi     r4, r4, 0xC001100F@l
	bl       __ct__Q28PSSystem9StreamBgmFUlRCQ27JAInter9SoundInfo
	mr       r24, r3

lbl_80337258:
	cmplwi   r24, 0
	bne      lbl_8033728C
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x4d2
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce
	b        lbl_8033728C
	.global  lbl_80337278

lbl_80337278:
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x6d1
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_8033728C:
	cmplwi   r24, 0
	bne      lbl_803372A8
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x6d5
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803372A8:
	lbz      r0, 0x44(r1)
	cmplwi   r0, 0x7f
	ble      lbl_803372C8
	addi     r3, r31, 0
	addi     r5, r31, 0xc
	li       r4, 0x6d6
	crclr    6
	bl       panic_f__12JUTExceptionFPCciPCce

lbl_803372C8:
	mr       r3, r24
	lmw      r24, 0x50(r1)
	lwz      r0, 0x74(r1)
	mtlr     r0
	addi     r1, r1, 0x70
	blr
	*/
}

/**
 * @note Address: N/A
 * @note Size: 0x1A8
 */
void ConductorSelector::getConductorFile(char const* path, CaveFloorInfo&, u8*, char*)
{
	JUT_PANICLINE(999, "%s_%02d_0.cnd");
	JUT_PANICLINE(999, "\nnot find Seq\n");
	JUT_PANICLINE(999, "%s_%02d_%1d.cnd");
	// UNUSED FUNCTION
}

/**
 * @note Address: 0x803372E0
 * @note Size: 0x94C
 */
u16 seqCpuSync(JASTrack* track, u16 command)
{
	switch (command) {
	case 0x3000:
		// even though the inline already HAS an assertion
		P2ASSERTLINE(1875, Rappa::getRappa(0));
		return Rappa::getRappa(0)->syncCpu_TblNo(track);
	case 0x3001:
		P2ASSERTLINE(1879, Rappa::getRappa(0));
		return Rappa::getRappa(0)->syncCpu_WaitChk(track);
	case 0x3002:
		P2ASSERTLINE(1883, Rappa::getRappa(1));
		return Rappa::getRappa(1)->syncCpu_TblNo(track);
	case 0x3003:
		P2ASSERTLINE(1887, Rappa::getRappa(1));
		return Rappa::getRappa(1)->syncCpu_WaitChk(track);
	case 0x5000:
		return Game::playData->mStoryFlags & Game::STORY_DebtPaid;
	case 0:
		u16 ret = 0;
		u8 com  = command;
		for (int i = 0; i < JAIGlobalParameter::getParamSeqPlayTrackMax(); i++) {
			if (JAInter::SequenceMgr::getPlayTrackInfo(i)->mSequence) {
				JAISequence* seq = JAInter::SequenceMgr::getPlayTrackInfo(i)->mSequence;
				JASTrack* temp;
				JASTrack* ref = &seq->mSeqParameter.mTrack;
				if (JAInter::SequenceMgr::getPlayTrackInfo(i)->mSequence->mSoundID & 0x800) {
					temp = track->mParentTrack->mParentTrack;
				} else {
					temp = track->mParentTrack;
				}
				if (ref == temp) {
					u32 route                   = JAInter::routeToTrack(track->_348);
					PSSystem::SeqBase* childSeq = PSMGetSceneMgrCheck()->findSeq(track);
					P2ASSERTLINE(1923, childSeq);
					JAInter::SystemInterface::outerInit(JAInter::SequenceMgr::getPlayTrackInfo(i), temp, route,
					                                    childSeq->mSoundInfo.mFlag >> 8, com);
					JAInter::SequenceMgr::getPlayTrackInfo(i)->_04 |= 1 << route;
					ret = 0;
					i   = JAIGlobalParameter::getParamSeqPlayTrackMax(); // stupid way to break but ok
				}
			}
		}
		return ret;
	case 1:
		return JAIBasic::setParameterSeqSync(track, command);
	}

	P2ASSERTLINE(1948, PSSystem::spSceneMgr);
	u32 testID     = track->_348;
	JASTrack* root = track;
	while (root->mParentTrack) {
		root = root->mParentTrack;
	}
	PSSystem::SeqBase* seq = PSSystem::spSceneMgr->getPlayingSeq(root);
	P2ASSERTLINE(1957, seq);
	JAISound** se = seq->getHandleP();
	u32 seExists  = *se != nullptr;
	if (seExists == 0) {
		switch (command) {
		case 0x2e00:
			return 30;
		case 0x900:
			return 1;
		case 0xc00:
			return 4;
		case 0xd00:
			return 1;
		case 0x300:
			return 0;
		case 0x800:
		case 0x600:
			return 10;
		default:
			return 0;
		}
	} else {
		switch (command) {
		case 0x1e00: {
			PSSystem::SeqTrackRoot* roottrack = (PSSystem::SeqTrackRoot*)PSSystem::getObject(track, 18);
			return roottrack->update();
		}
		case 0x1f00: {
			if (seExists <= 0) {
				return 0;
			}
			PSSystem::SeqTrackRoot* roottrack = (PSSystem::SeqTrackRoot*)PSSystem::getObject(track, 18);
			return roottrack->update();
		}
		case 0x2e00: {
			PSSystem::SeqTrackRoot* roottrack = (PSSystem::SeqTrackRoot*)PSSystem::getObject(track, 18);
			return roottrack->beatUpdate();
		}
		case 0x900: {
			PSAutoBgm::Module* module = (PSAutoBgm::Module*)PSSystem::getObject(track, 20);
			P2ASSERTLINE(2028, module);
			return module->cycleLoop(track);
		}
		case 0xa00: {
			PSAutoBgm::Module* module = (PSAutoBgm::Module*)PSSystem::getObject(track, 20);
			P2ASSERTLINE(2036, module);
			return module->_2B8[module->_2C0]->cycleTop(track);
		}
		case 0xc00: {
			PSAutoBgm::Module* module = (PSAutoBgm::Module*)PSSystem::getObject(track, 20);
			P2ASSERTLINE(2043, module);
			return module->_2B8[module->_2C0]->play(track);
		}
		case 0xd00: {
			PSAutoBgm::Module* module = (PSAutoBgm::Module*)PSSystem::getObject(track, 20);
			P2ASSERTLINE(2049, module);
			return module->_2B8[module->_2C0]->checkCloser(track);
		}
		case 0xb00: {
			PSAutoBgm::Module* module = (PSAutoBgm::Module*)PSSystem::getObject(track, 20);
			P2ASSERTLINE(2055, module);
			module->_2B6 = -1;
			return 0;
		}
		}
	}

	if (!seq) {
		seq = PSSystem::spSceneMgr->findSeq(track);
	}

	switch (command) {
	case 0x4000:
		P2ASSERTLINE(2085, seq->getCastType() == 4);
		return static_cast<PSSystem::JumpBgmSeq*>(seq)->getSeqStartPoint();
	case 0x4001:
		P2ASSERTLINE(2095, seq->getCastType() == 4);
		return static_cast<PSSystem::JumpBgmSeq*>(seq)->outputJumpRequest();
	case 0xe00:
		P2ASSERTBOOLLINE(2107, seq->getCastType() == 2 || seq->getCastType() == 4 || seq->getCastType() == 3);
		static_cast<PSSystem::DirectedBgm*>(seq)->initRootTrack_onPlaying(track);
		return 0;
	case 0xf00:
		P2ASSERTBOOLLINE(2117, seq->getCastType() == 2 || seq->getCastType() == 4 || seq->getCastType() == 3);
		static_cast<PSSystem::DirectedBgm*>(seq)->initChildTrack_onPlaying(track, track->_348 & 0xf);
		return 0;
	case 0x600:
	case 0x300:
	case 0x800:
		JADUtility::PrmSetRc<PSAutoBgm::Track>* prm = static_cast<PSAutoBgm::AutoBgm*>(seq)->mConductorMgr.mPrmSetRc;
		P2ASSERTLINE(2128, prm);
		return ((PSAutoBgm::Conductor*)prm)->seqCpuSync_AutoBgm(track, command, testID, root);
	default:
		return 0;
	}
}

} // namespace PSGame

/**
 * @note Address: 0x80337C2C
 * @note Size: 0x7C
 */
void PSPlayerChangeToOrimer()
{
	PSSystem::DirectedBgm* bgm = PSGetDirectedMainBgm();
	if (bgm) {
		bgm->assertValidTrack();
		bgm->mRootTrack->mSwingState = 0;
	}
}

/**
 * @note Address: 0x80337CA8
 * @note Size: 0x124
 */
PSSystem::DirectedBgm* PSGetDirectedMainBgm()
{
	PSSystem::SceneMgr* mgr = PSSystem::getSceneMgr();
	PSSystem::checkSceneMgr(mgr);
	mgr->checkScene();
	PSSystem::Scene* scene = mgr->mScenes->mChild;
	if (!scene) {
		return nullptr;
	}

	PSSystem::DirectedBgm* seq = (PSSystem::DirectedBgm*)scene->mSeqMgr.getFirstSeq();
	if (seq && (seq->getCastType() == 2 || seq->getCastType() == 3 || seq->getCastType() == 4)) {
		return seq;
	}
	return nullptr;
}

/**
 * @note Address: 0x80337DCC
 * @note Size: 0x170
 */
void PSPlayerChangeToLugie()
{
	PSSystem::DirectedBgm* bgm = PSGetDirectedMainBgm();
	if (bgm) {
		bgm->assertValidTrack();
		bgm->mRootTrack->mSwingState = 1;
	}
}

/**
 * @note Address: 0x80337F3C
 * @note Size: 0x170
 */
PSSystem::DirectedBgm* PSGetDirectedMainBgmA()
{
	PSSystem::DirectedBgm* seq = (PSSystem::DirectedBgm*)PSMGetSceneMgrCheck()->getChildScene()->getSeqMgr()->getFirstSeqA();
	if (seq) {
		// P2ASSERTLINE(2241, seq->isDirectedType());
		return seq;
	} else {
		P2ASSERTLINE(2244, false);
	}
	return nullptr;
}

/**
 * @note Address: N/A
 * @note Size: 0xC
 */
void PSSetBgmSelectAsToolMode() { PSSystem::DirectorBase::sToolMode = true; }
