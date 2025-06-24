#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"


class GameManager {
public:
	void Load();
	void Initialize(float timelimit);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void Update();


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorModel floorModel_[16]; // ���̃��f�� 
	TimerModel timerModel_; // �^�C�}�[�̃��f��

	float leftEdge = 10.0f; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge = 1280.0f-10.0f-60.0f; // �Q�[���E�B���h�E�̉E�[�̈ʒu

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // �����v���C���[�ʒu	
};