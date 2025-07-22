#pragma once

#include <vector> 
#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"
#include "MoveEnemy.h"
#include "SilentEnemy.h"
#include "KatonEnemy.h"
#include "SuitonEnemy.h"
#include "PlayerInvincible.h"
#include "InvincibleItemModel.h"

/// <summary>
/// GameManager�N���X��MainScene����Q�[���̐i�s���Ǘ����镔����؂藣���č���Ă�����̂Ȃ̂ł���͎����I��MainScene
/// </summary>

class GameManager {
public:
	void Load();
	void Initialize(float timelimit,int floorCount,int silentEnemyCount,int moveEnemyCount,int suitonEnemyCount,int suitonAttackCount,int katonEnemyCount,int katonAttackCount);
	void PlayerSetup(HE::Math::Vector2 initialPos, float leftEdge, float rightEdge, bool isMovingToRightFirst, bool isGravityUpwardFirst, float playerWidth, float playerHeight);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth,bool isBreakable,float breakTime);
	void MoveEnemySetup(int enemyID,float timeToActive, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos,float activateTime,float activateDuration);
	void SuitonEnemyPositionSetup(int enemyID,float posY,float collisionHeight,float collisionWidth,float attackDirection);
	void SuitonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime,float attackEnemyAmount);
	void KatonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos, float collisionHeight, float collisionWidth);
	void KatonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime, float attackEnemyAmount);
	const PlayerModel& GetPlayerModel() const { return playerModel_; }
	const TimerModel& GetTimerModel() const { return timerModel_; }
	const FloorModel& GetFloorModel(int floorID) const { return floorModel_[floorID]; } // ���̃��f�����擾
	const MoveEnemy& GetMoveEnemy(int enemyID) const { return moveEnemy_[enemyID]; }
	const SuitonEnemy& GetSuitonEnemy(int enemyID) const { return suitonEnemy_[enemyID]; }
	const KatonEnemy& GetKatonEnemy(int enemyID) const { return katonEnemy_[enemyID]; }
	const SilentEnemy& GetSilentEnemy(int enemyID) const { return silentEnemy_[enemyID]; }
	const InvincibleItemModel& GetInvincibleItemModel() const { return invincibleItemModel_; } // ���G�A�C�e���̃��f�����擾
	const PlayerInvincible& GetPlayerInvincible() const { return playerInvincible_; } // �v���C���[�̖��G��Ԃ̃��f�����擾
	void Update();
	void SuitonEnemyAttack(); // ���ق̏p�̍U�����X�V
	void KatonEnemyAttack(); // �Γق̏p�̍U�����X�V
	void InvincibleItemAperance(); // ���G�A�C�e���̏o������
	void GravityChange() { playerModel_.GravityChange(timerModel_.GetTimer()); } // �v���C���[�̈ړ�������ύX����
	void GroundCollisionCheck();
	void EnemyCollisionCheck(); 
	void ItemCollisionCheck(); // �A�C�e���Ƃ̏Փ˃`�F�b�N
	int GetGameState() const { return gameState_; } // �Q�[���̏�Ԃ��擾
	int GetFloorCount() const { return floorCount_; } // ���̐����擾
	float GetTimer() const { return timerModel_.GetTimer(); } // �^�C�}�[�̒l���擾
	void ClearCheck(); // �Q�[���N���A�̃`�F�b�N

	


private:
	PlayerModel playerModel_; // �v���C���[�̃��f��
	InvincibleItemModel invincibleItemModel_; // ���G�A�C�e���̃��f��
	PlayerInvincible playerInvincible_; // �v���C���[�̖��G��Ԃ̃��f��
	FloorModel floorModel_[128]; // ���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	TimerModel timerModel_; // �^�C�}�[�̃��f��
	MoveEnemy moveEnemy_[64]; // �藠���̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	SilentEnemy silentEnemy_[64]; // �܂��т��̃��f�� �S�X�e�[�W�̍ő�̐���z�񐔂ɋL��
	SuitonEnemy suitonEnemy_[5]; // ���ق̏p�̃��f��
	KatonEnemy katonEnemy_[64]; // �Γق̏p�̃��f��

	float suitonEnemyActivateTime_[32]; // ���ق̏p���A�N�e�B�u�ɂȂ鎞��
	float suitonEnemyTimeToAttack_[32]; // ���ق̏p�̍U���܂ł̎���
	float suitonEnemyAttackDuration_[32]; // ���ق̏p�̍U���̎�������
	float suitonEnemyAttackAfterTime_[32]; // ���ق̏p�̍U����̑ҋ@����
	int attackSuitonEnemyAmount_[32]; // ���ق̏p�̍U���ŏo������G�̐�
	bool isAtttackedSuitonEnemy_[32]; // ���ق̏p�̍U�����s��ꂽ���ǂ���

	float katonEnemyActivateTime_[32]; // �Γق̏p���A�N�e�B�u�ɂȂ鎞��
	float katonEnemyTimeToAttack_[32]; // �Γق̏p�̍U���܂ł̎���
	float katonEnemyAttackDuration_[32]; // �Γق̏p�̍U���̎�������
	float katonEnemyAttackAfterTime_[32]; // �Γق̏p�̍U����̑ҋ@����
	int attackKatonEnemyAmount_[32]; // �Γق̏p�̍U���ŏo������G�̐�
	bool isAtttackedKatonEnemy_[32]; // �Γق̏p�̍U�����s��ꂽ���ǂ���

	bool isInvincibleItemAppered_; // ���G�A�C�e�����o���������ǂ��� 

	int floorCount_ ; // ���̐�
	int silentEnemyCount_; // �܂��т��̐�
	int moveEnemyCount_; // �藠���̐�
	int suitonEnemyCount_; // ���ق̏p�̓G�̐�
	int suitonAttackCount_; // ���ق̏p�̍U���̉�

	int katonAttackCount_; // �Γق̏p�̍U���̉�
	int katonEnemyCount_; // �Γق̏p�̓G�̐�

	int gameState_; // �Q�[���̏�ԁA0 = �Q�[�����@1 = �Q�[���I�[�o�[ 2 = �Q�[���N���A

	float leftEdge ; // �Q�[���E�B���h�E�̍��[�̈ʒu
	float rightEdge ; // �Q�[���E�B���h�E�̉E�[�̈ʒu

	HE::Math::Vector2 initialPlayerPosition_ ; // �����v���C���[�ʒu	
};