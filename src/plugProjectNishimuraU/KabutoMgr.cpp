#include "types.h"
#include "Game/Entities/Kabuto.h"
#include "Game/generalEnemyMgr.h"
#include "JSystem/JUtility/JUTNameTab.h"
#include "JSystem/J3D/J3DSys.h"

namespace Game {
namespace Kabuto {

const char filename[] = "246-KabutoMgr";

/**
 * @note Address: 0x802E3D68
 * @note Size: 0x50
 */
Mgr::Mgr(int p1, u8 p2)
    : EnemyMgrBase(p1, p2)
{
	mName = "ƒJƒuƒgƒ}ƒl[ƒWƒƒ"; // beetle manager
}

/**
 * @note Address: 0x802E3DB8
 * @note Size: 0xE8
 */
void Mgr::loadModelData()
{
	int ids[3] = { EnemyTypeID::EnemyID_Kabuto, EnemyTypeID::EnemyID_Rkabuto, EnemyTypeID::EnemyID_Fkabuto };

	for (int i = 0; i < 3; i++) {
		EnemyMgrBase* mgr = generalEnemyMgr->getEnemyMgr(ids[i]);
		if (mgr) {
			J3DModelData* storedModelData = mgr->getJ3DModelData();
			if (storedModelData) {
				mModelData = storedModelData;
				return;
			}
		}
	}

	EnemyMgrBase::loadModelData();

	for (u16 j = 0; j < mModelData->getShapeNum(); j++) {
		J3DShape* shape = mModelData->mShapeTable.mItems[j];
		shape->setTexMtxLoadType(0x2000);
	}
}

/**
 * @note Address: 0x802E3EA0
 * @note Size: 0xA0
 */
void Mgr::loadAnimData()
{
	int ids[4] = { EnemyTypeID::EnemyID_Kabuto, EnemyTypeID::EnemyID_Rkabuto, EnemyTypeID::EnemyID_Fkabuto, EnemyTypeID::EnemyID_Bkabuto };

	for (int i = 0; i < 4; i++) {
		EnemyMgrBase* mgr = generalEnemyMgr->getEnemyMgr(ids[i]);
		if (mgr) {
			SysShape::AnimMgr* storedAnimMgr = mgr->mAnimMgr;
			if (storedAnimMgr) {
				mAnimMgr = storedAnimMgr;
				return;
			}
		}
	}

	EnemyMgrBase::loadAnimData();
}

/**
 * @note Address: 0x802E3F40
 * @note Size: 0x14C
 */
SysShape::Model* Mgr::createModel()
{
	SysShape::Model* model = new SysShape::Model(mModelData, 0x80000, mModelType);
	P2ASSERTLINE(147, model != nullptr);

	for (u16 i = 0; i < mModelData->getMaterialNum(); i++) {
		const char* name = mModelData->mMaterialTable.mMaterialNames->getName(i);
		if (!strcmp(name, "mat_babykabuto_body") || !strcmp(name, "mat_babykabuto_eye") || !strcmp(name, "mat_babykabuto_head")) {
			model->mJ3dModel->mMatPackets[i].mShapePacket->newDifferedDisplayList(0x04020000);
		}
	}

	model->updateModel();
	return model;
}

} // namespace Kabuto
} // namespace Game
