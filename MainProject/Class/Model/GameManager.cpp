//
// GameManager.cpp
//

#include "GameManager.h"
#include <array>

using namespace HE;

void GameManager::Load()
{
	playerModel_.Load();
	timerModel_.Load();
	
}

void GameManager::Initialize(float timelimit,int floorCount, int silentEnemyCount, int moveEnemyCount, int suitonEnemyCount, int suitonAttackCount)
{
	timerModel_.Initialize(timelimit);
	floorCount_ = floorCount; // ���̐���ݒ�
	silentEnemyCount_ = silentEnemyCount; // �܂��т��̐���ݒ�
	moveEnemyCount_ = moveEnemyCount; // �藠���̐���ݒ�
	suitonEnemyCount_ = suitonEnemyCount; // ���ق̏p�̓G�̐���ݒ�
	suitonAttackCount_ = suitonAttackCount; // ���ق̏p�̍U���̉񐔂�ݒ�
	isGameOver_ = false; // �Q�[���I�[�o�[��Ԃ�������
	onPlayerFloorID_ = -1; // �v���C���[������Ă��鏰��ID��������
}

void GameManager::PlayerSetup(HE::Math::Vector2 initialPos, float leftEdge, float rightEdge, bool isMovingToRightFirst, bool isGravityUpwardFirst, float playerWidth, float playerHeight)
{
	playerModel_.Initialize(initialPos, leftEdge, rightEdge, isMovingToRightFirst, isGravityUpwardFirst, playerWidth, playerHeight);
}
void GameManager::FloorSetup(int floorID, HE::Math::Vector2 floorPos, float floorHeight, float floorWidth,bool isBreakable)
{ 
	
	floorModel_[floorID].Initialize(floorPos, floorWidth, floorHeight,isBreakable);
}

void GameManager::MoveEnemySetup(int enemyID, float timeToActive,float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange)
{
	moveEnemy_[enemyID].Initialize(timeToActive,enemySpeed, firstDirection,initialPos, maxRange, minRange);
}

void GameManager::SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos)
{
	silentEnemy_[enemyID].Load();
	silentEnemy_[enemyID].Initialize(initialPos);
}

void GameManager::SuitonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos)
{
	suitonEnemy_[enemyID].Initialize(initialPos);
}
void GameManager::SuitonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime,float attackEnemyAmount)
{
	suitonEnemyActivateTime_[atkNo] = activateTime; // �A�N�e�B�u�ɂȂ鎞�Ԃ�ݒ�
	suitonEnemyTimeToAttack_[atkNo] = timeToAttack; // �U���܂ł̎��Ԃ�ݒ�
	suitonEnemyAttackDuration_[atkNo] = attackDuration; // �U���̎������Ԃ�ݒ�
	suitonEnemyAttackAfterTime_[atkNo] = attackAfterTime; // �U����̑ҋ@���Ԃ�ݒ�
	attackSuitonEnemyAmount_[atkNo] = attackEnemyAmount; // �U���ŏo������G�̐���ݒ�
	isAtttackedSuitonEnemy_[atkNo] = false; // �U�����s��ꂽ���ǂ�����������
}

void GameManager::Update()
{
	timerModel_.Update();
	playerModel_.Update(timerModel_.GetTimer());
	GroundCollisionCheck();
	EnemyCollisionCheck();
	for (int i = 0; i < moveEnemyCount_; i++)
	{
		moveEnemy_[i].Update(timerModel_.GetTimer());
	}
	for (int i = 0; i < suitonEnemyCount_; i++)
	{
		suitonEnemy_[i].Update(timerModel_.GetTimer());
	}
	SuitonEnemyAttack(); // ���ق̏p�̍U�����X�V
	MonitorPlayerOnGround(); // �v���C���[�����ɏ���Ă��邩�ǂ������Ď�

}

void GameManager::GroundCollisionCheck()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	for (int i = 0; i < floorCount_; i++)
	{
		Math::Rectangle floor_collision = floorModel_[i].GetCollision();
		if (player_collision.Intersects(floor_collision))
		{
			playerModel_.OnCollisionGround(floorModel_[i].GetFloorPosition(), floorModel_[i].GetFloorHeight(), floorModel_[i].GetFloorWidth());
			onPlayerFloorID_ = i; // �v���C���[������Ă��鏰��ID���X�V
		}
	}


}

void GameManager::EnemyCollisionCheck()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	for (int i = 0; i < moveEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = moveEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // �v���C���[���藠���ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
	for (int i = 0; i < silentEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = silentEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // �v���C���[���܂��т��ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
	for (int i = 0; i < suitonEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = suitonEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // �v���C���[�����ق̏p�̓G�ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
}

void GameManager::MonitorPlayerOnGround()
{
	bool isOnGround = playerModel_.GetIsOnGround();
	if (prevIsOnGround_ && isOnGround != prevIsOnGround_) {
		floorModel_[onPlayerFloorID_].BreakFloor(); 
	}
	prevIsOnGround_ = isOnGround; // �O��̏��ɏ���Ă����Ԃ��X�V
}

void GameManager::SuitonEnemyAttack()
{
	for (int i = 0; i < suitonAttackCount_; i++)
	{
		if (!isAtttackedSuitonEnemy_[i] && timerModel_.GetTimer() >= suitonEnemyActivateTime_[i]) // �A�N�e�B�u�ɂȂ�����
		{
			std::vector<int> selectedIndices;
			std::vector<int> availableIndices;

			// ���p�\�ȃC���f�b�N�X�i0�`suitonEnemy�̔z��T�C�Y-1�j��������
			for (int j = 0; j < std::size(suitonEnemy_); j++) {
				availableIndices.push_back(j);
			}

			// attackSuitonEnemyAmount_[i]�̃����_���ȃC���f�b�N�X��I��
			for (int j = 0; j < attackSuitonEnemyAmount_[i] && !availableIndices.empty(); j++) {
				int randomIndex = rand() % availableIndices.size();
				selectedIndices.push_back(availableIndices[randomIndex]);
				availableIndices.erase(availableIndices.begin() + randomIndex);
			}

			// �I�����ꂽ�C���f�b�N�X��SuitonEnemy���A�N�e�B�u��
			for (int enemyIndex : selectedIndices) {
				suitonEnemy_[enemyIndex].Activate(
					timerModel_.GetTimer(),
					suitonEnemyTimeToAttack_[i],
					suitonEnemyAttackDuration_[i],
					suitonEnemyAttackAfterTime_[i]
				);
			}
			isAtttackedSuitonEnemy_[i] = true; // �U�����s��ꂽ���Ƃ��L�^
		}
	}
	

}