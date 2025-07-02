#pragma once

#include <vector> 
#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"
#include "MoveEnemy.h"
#include "SilentEnemy.h"
#include "JutsuEnemy.h"


class GameManager {
public:
	void Load();
	void Initialize(float timelimit,int floorCount,int silentEnemyCount,int moveEnemyCount,int suitonEnemyCount,int suitonAttackCount,int katonEnemyCount,int katonAttackCount);
	void PlayerSetup(HE::Math::Vector2 initialPos, float leftEdge, float rightEdge, bool isMovingToRightFirst, bool isGravityUpwardFirst, float playerWidth, float playerHeight);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth,bool isBreakable);
	void MoveEnemySetup(int enemyID,float timeToActive, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos);
	void SuitonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos,float collisionHeight,float collisionWidth);
	void SuitonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime,float attackEnemyAmount);
	void KatonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos, float collisionHeight, float collisionWidth);
	void KatonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime, float attackEnemyAmount);
	const PlayerModel& GetPlayerModel() const { return playerModel_; }
	const TimerModel& GetTimerModel() const { return timerModel_; }
	const MoveEnemy& GetMoveEnemy(int enemyID) const { return moveEnemy_[enemyID]; }
	const JutsuEnemy& GetSuitonEnemy(int enemyID) const { return suitonEnemy_[enemyID]; }
	const JutsuEnemy& GetKatonEnemy(int enemyID) const { return katonEnemy_[enemyID]; }
	void Update();
	void SuitonEnemyAttack(); // ���ق̏p�̍U�����X�V
	void KatonEnemyAttack(); // �Γق̏p�̍U�����X�V
	void GravityChange() { playerModel_.GravityChange(); } // �v���C���[�̈ړ�������ύX����
	void GroundCollisionCheck();
	void EnemyCollisionCheck(); 
	void MonitorPlayerOnGround();
	int GetGameState() const { return gameState_; } // �Q�[���̏�Ԃ��擾

	


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	FloorModel floorModel_[23]; // ���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	TimerModel timerModel_; // �^�C�}�[�̃��f��
	MoveEnemy moveEnemy_[2]; // �藠���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	SilentEnemy silentEnemy_[12]; // �܂��т��̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	JutsuEnemy suitonEnemy_[5]; // ���ق̏p�̃��f��
	JutsuEnemy katonEnemy_[8]; // �Γق̏p�̃��f��

	float suitonEnemyActivateTime_[5]; // ���ق̏p���A�N�e�B�u�ɂȂ鎞��
	float suitonEnemyTimeToAttack_[5]; // ���ق̏p�̍U���܂ł̎���
	float suitonEnemyAttackDuration_[5]; // ���ق̏p�̍U���̎�������
	float suitonEnemyAttackAfterTime_[5]; // ���ق̏p�̍U����̑ҋ@����
	int attackSuitonEnemyAmount_[5]; // ���ق̏p�̍U���ŏo������G�̐�
	bool isAtttackedSuitonEnemy_[5]; // ���ق̏p�̍U�����s��ꂽ���ǂ���

	float katonEnemyActivateTime_[4]; // �Γق̏p���A�N�e�B�u�ɂȂ鎞��
	float katonEnemyTimeToAttack_[4]; // �Γق̏p�̍U���܂ł̎���
	float katonEnemyAttackDuration_[4]; // �Γق̏p�̍U���̎�������
	float katonEnemyAttackAfterTime_[4]; // �Γق̏p�̍U����̑ҋ@����
	int attackKatonEnemyAmount_[4]; // �Γق̏p�̍U���ŏo������G�̐�
	bool isAtttackedKatonEnemy_[4]; // �Γق̏p�̍U�����s��ꂽ���ǂ���

	

	int floorCount_ ; // ���̐�
	int silentEnemyCount_; // �܂��т��̐�
	int moveEnemyCount_; // �藠���̐�
	int suitonEnemyCount_; // ���ق̏p�̓G�̐�
	int suitonAttackCount_; // ���ق̏p�̍U���̉�

	int katonAttackCount_; // �Γق̏p�̍U���̉�
	int katonEnemyCount_; // �Γق̏p�̓G�̐�

	int gameState_; // �Q�[���̏�ԁA0 = �Q�[�����@1 = �Q�[���I�[�o�[ 2 = �Q�[���N���A
	bool prevIsOnGround_ ; // �O��̏��ɏ���Ă�����

	int onPlayerFloorID_ ; // �v���C���[������Ă��鏰��ID

	float leftEdge ; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge ; // �Q�[���E�B���h�E�̉E�[�̈ʒu

	HE::Math::Vector2 initialPlayerPosition_ ; // �����v���C���[�ʒu	
};