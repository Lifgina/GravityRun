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
	void Initialize(float timelimit,HE::Math::Vector2 initialPos,float leftEdge,float rightEdge);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth,bool isBreakable);
	void MoveEnemySetup(int enemyID,float timeToActive, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos);
	void Update();
	void GravityChange() { playerModel_.GravityChange(); } // �v���C���[�̈ړ�������ύX����
	void GroundCollisionCheck();
	void EnemyCollisionCheck(); 
	void MonitorPlayerOnGround();
	bool GetIsGameOver() const { return isGameOver_; } // �Q�[���I�[�o�[��Ԃ��擾


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorModel floorModel_[23]; // ���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	TimerModel timerModel_; // �^�C�}�[�̃��f��
	MoveEnemy moveEnemy_[6]; // �藠���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	SilentEnemy silentEnemy_[4]; // �܂��т��̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��

	bool isGameOver_ ; // �Q�[���I�[�o�[���
	bool prevIsOnGround_ ; // �O��̏��ɏ���Ă�����

	int onPlayerFloorID_ ; // �v���C���[������Ă��鏰��ID

	float leftEdge ; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge ; // �Q�[���E�B���h�E�̉E�[�̈ʒu

	HE::Math::Vector2 initialPlayerPosition_ ; // �����v���C���[�ʒu	
};