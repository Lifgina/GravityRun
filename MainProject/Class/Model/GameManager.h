#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "FloarData.h"


class GameManager {
public:
	void Load();
	void Initialize();
	void Update();


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorData floorData_; // ���̃f�[�^���Ǘ�����N���X
	FloorModel floorModel_[11]; // ���̃��f�� floorModel�̐��͕K�v�ɉ����ĕύX

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // �����v���C���[�ʒu	
};