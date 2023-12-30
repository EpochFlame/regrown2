#include "efx/THallow.h"
#include "Game/Entities/HallowMushi.h"

namespace efx
{

bool THallow::create(Arg* arg) {
    if (TSimple1::create(arg)) {
        for (int i = 0; i < ARRAY_SIZE(mEmitters); i++) {
            mEmitters[i]->mScale = Vector3f(3.5f, 1.0f, 3.5f);
            mEmitters[i]->_B0 = 2.5f;
            mEmitters[i]->_B4 = 2.5f;
            mEmitters[i]->mLifeTime = (int)(HALLOW_TRAIL_LINGER_TIME * 30);
            
        }
    }
    return false;
}

} // namespace efx
