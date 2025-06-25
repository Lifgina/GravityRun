#pragma once

#include <vector> 
#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"
#include "MoveEnemy.h"
#include "SilentEnemy.h"


class GameManager {
public:
	void Load();
	void Initialize(float timelimit);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void MoveEnemySetup(int enemyID, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos);
	void Update();
	void CollisionCheck();
	bool GetIsGameOver() const { return isGameOver_; } // �Q�[���I�[�o�[��Ԃ��擾


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorModel floorModel_[16]; // ���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	TimerModel timerModel_; // �^�C�}�[�̃��f��
	MoveEnemy moveEnemy_[6]; // �藠���̃��f�� EnemyData.h�Œ�`����Ă���G�̐��ɍ��킹��
	SilentEnemy silentEnemy_[4]; // �܂��т��̃��f��  EnemyData.h�Œ�`����Ă���G�̐��ɍ��킹��

	bool isGameOver_ ; // �Q�[���I�[�o�[���

	float leftEdge = 10.0f; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge = 1280.0f-10.0f-60.0f; // �Q�[���E�B���h�E�̉E�[�̈ʒu

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(510.0f, 284.0f-50.0f); // �����v���C���[�ʒu	
};