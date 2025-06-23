#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "FloarData.h"
#include "TimerModel.h"


class GameManager {
public:
	void Load();
	void Initialize();
	void Update();


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorData floorData_; // ���̃f�[�^���Ǘ�����N���X
	FloorModel floorModel_[11]; // ���̃��f�� floorModel�̐��͕K�v�ɉ����ĕύX
	TimerModel timerModel_; // �^�C�}�[�̃��f��

	float timeLimit_ = 60.0f; // �^�C�����~�b�g�̐ݒ�
	float leftEdge = 10.0f; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge = 1280.0f-10.0f-60.0f; // �Q�[���E�B���h�E�̉E�[�̈ʒu

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // �����v���C���[�ʒu	
};