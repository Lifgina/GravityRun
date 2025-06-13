#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloarData.h"


class GameManager {
public:
	void Load();
	void Initialize();
	void Update();


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorData floorData_; // ���̃f�[�^���Ǘ�����N���X
	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // �����v���C���[�ʒu	
};