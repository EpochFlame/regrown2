#include "PSGame/PikScene.h"

namespace PSGame
{

// useYakushima4__Q26PSGame13CaveFloorInfoFv
bool CaveFloorInfo::useYakushima4() {
    OSReport("%p CaveFloorInfo::useYakushima4()\n", this);
    if (isCaveFloor()) {
        if (mSceneType == SceneInfo::COURSE_YAKUSHIMA) {
            if (getCaveNoFromID() == 3 && !isBossFloor()) {
                return true;
            }
        }
        else if (mSceneType == SceneInfo::COURSE_LAST) {
            if (getCaveNoFromID() == 3 && mFloorNum == 29) {
                return true;
            }
        }
    }
    return false;
}

} // namespace PSGame
