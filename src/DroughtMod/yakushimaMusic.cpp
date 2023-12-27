#include "PSGame/PikScene.h"
#include "PSSystem/PSMainSide_Scene.h"

namespace PSGame
{

// useYakushima4__Q26PSGame13CaveFloorInfoFv
bool CaveFloorInfo::useYakushima4() {
    OSReport("%p CaveFloorInfo::useYakushima4()\n", this);
    OSReport("I HATE PIK2 SOUND I HATE\n");

    if (isCaveFloor()) {
        if (mSceneType == SceneInfo::COURSE_YAKUSHIMA) {
            if (getCaveNoFromID() == 3 && !isBossFloor()) {
                return true;
            }
        }
        else if (mSceneType == SceneInfo::COURSE_LAST) {
            if (getCaveNoFromID() == 3 && mFloorNum == 29) {
                OSReport("True!\n");
                return true;
            }
        }
    }
    return false;
}



} // namespace PSGame

namespace PSM
{

void Scene_Game::init()
{
	static_cast<SceneMgr*>(PSMGetSceneMgrCheck())->initEnvironmentSe(this);

	if (needBossBgm()) {
		attachBossFaderMgr();
	}
}

void Scene_Cave::init()
{
	if (isBossFloor()) {
		static_cast<SceneMgr*>(PSMGetSceneMgrCheck())->initEnvironmentSe(this);

		if (needBossBgm()) {
			mBossFaderMgr = PSSystem::SingletonBase<BossBgmFader::Mgr>::getInstance();
		}
		mBossFaderMgr = nullptr; // so much for what we just did?
		return;
	}

	Scene_Game::init();
}

} // namespace PSSystem
