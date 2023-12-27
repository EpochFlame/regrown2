#include "PSGame/PikScene.h"

namespace PSGame
{

// useYakushima4__Q26PSGame13CaveFloorInfoFv
bool CaveFloorInfo::useYakushima4() {
    if (isCaveFloor() && mSceneType == SceneInfo::COURSE_YAKUSHIMA) {
		if (getCaveNoFromID() == 3 && !isBossFloor()) {
            return true;
        }
    }
    if (isCaveFloor() && mSceneType == SceneInfo::COURSE_LAST) {
        if (getCaveNoFromID() == 3 && mFloorNum == 29) {
            return true;
        }
    }
}

} // namespace PSGame
