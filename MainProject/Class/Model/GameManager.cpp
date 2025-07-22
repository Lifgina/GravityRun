//
// GameManager.cpp
//

#include "GameManager.h"
#include <array>
#include <random>

using namespace HE;

void GameManager::Load()
{
	playerModel_.Load();
	
}

void GameManager::Initialize(float timelimit,int floorCount, int silentEnemyCount, int moveEnemyCount, int suitonEnemyCount, int suitonAttackCount,int katonEnemyCount, int katonAttackCount)
{
	timerModel_.Initialize(timelimit);
	playerInvincible_.Initialize(); // �v���C���[�̖��G��Ԃ�������
	floorCount_ = floorCount; // ���̐���ݒ�
	silentEnemyCount_ = silentEnemyCount; // �܂��т��̐���ݒ�
	moveEnemyCount_ = moveEnemyCount; // �藠���̐���ݒ�
	suitonEnemyCount_ = suitonEnemyCount; // ���ق̏p�̓G�̐���ݒ�
	suitonAttackCount_ = suitonAttackCount; // ���ق̏p�̍U���̉񐔂�ݒ�
	katonEnemyCount_ = katonEnemyCount; // �Γق̏p�̓G�̐���ݒ�
	katonAttackCount_ = katonAttackCount; // �Γق̏p�̍U���̉񐔂�ݒ�
	gameState_ = 0; // �Q�[����Ԃ�������
	isInvincibleItemAppered_ = false; // ���G�A�C�e�����o�����Ă��Ȃ���Ԃ�������
}

void GameManager::PlayerSetup(HE::Math::Vector2 initialPos, float leftEdge, float rightEdge, bool isMovingToRightFirst, bool isGravityUpwardFirst, float playerWidth, float playerHeight)
{
	playerModel_.Initialize(initialPos, leftEdge, rightEdge, isMovingToRightFirst, isGravityUpwardFirst, playerWidth, playerHeight);
}
void GameManager::FloorSetup(int floorID, HE::Math::Vector2 floorPos, float floorHeight, float floorWidth,bool isBreakable,float breakTime)
{ 
	
	floorModel_[floorID].Initialize(floorPos, floorWidth, floorHeight,isBreakable,breakTime);
}

void GameManager::MoveEnemySetup(int enemyID, float timeToActive,float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange)
{
	moveEnemy_[enemyID].Initialize(timeToActive,enemySpeed, firstDirection,initialPos, maxRange, minRange);
}

void GameManager::SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos, float activateTime, float activateDuration)
{
	silentEnemy_[enemyID].Load();
	silentEnemy_[enemyID].Initialize(initialPos,activateTime,activateDuration);
}

void GameManager::SuitonEnemyPositionSetup(int enemyID, float posY, float collisionHeight, float collisionWidth,float attackDirection)
{
	suitonEnemy_[enemyID].Initialize(posY,collisionHeight,collisionWidth,attackDirection);
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

void GameManager::KatonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos, float collisionHeight, float collisionWidth)
{
	katonEnemy_[enemyID].Initialize(initialPos, collisionHeight, collisionWidth);
}

void GameManager::KatonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime, float attackEnemyAmount)
{
	katonEnemyActivateTime_[atkNo] = activateTime; // �A�N�e�B�u�ɂȂ鎞�Ԃ�ݒ�
	katonEnemyTimeToAttack_[atkNo] = timeToAttack; // �U���܂ł̎��Ԃ�ݒ�
	katonEnemyAttackDuration_[atkNo] = attackDuration; // �U���̎������Ԃ�ݒ�
	katonEnemyAttackAfterTime_[atkNo] = attackAfterTime; // �U����̑ҋ@���Ԃ�ݒ�
	attackKatonEnemyAmount_[atkNo] = attackEnemyAmount; // �U���ŏo������G�̐���ݒ�
	isAtttackedKatonEnemy_[atkNo] = false; // �U�����s��ꂽ���ǂ�����������
}

void GameManager::Update()
{
	timerModel_.Update();
	playerModel_.Update(timerModel_.GetTimer());
	playerInvincible_.Update(timerModel_.GetTimer()); // �v���C���[�̖��G��Ԃ��X�V
	invincibleItemModel_.Update(timerModel_.GetTimer()); // ���G�A�C�e���̍X�V
	GroundCollisionCheck();
	EnemyCollisionCheck();
	ItemCollisionCheck(); // �A�C�e���Ƃ̏Փ˃`�F�b�N
	for (int i = 0; i < floorCount_; i++)
	{
		floorModel_[i].Update(timerModel_.GetTimer());
	}
	for (int i = 0; i < silentEnemyCount_; i++)
	{
		silentEnemy_[i].Update(timerModel_.GetTimer());
	}
	for (int i = 0; i < moveEnemyCount_; i++)
	{
		moveEnemy_[i].Update(timerModel_.GetTimer());
	}
	for (int i = 0; i < suitonEnemyCount_; i++)
	{
		suitonEnemy_[i].Update(timerModel_.GetTimer());
	}
	for (int i = 0; i < katonEnemyCount_; i++)
	{
		katonEnemy_[i].Update(timerModel_.GetTimer());
	}
	SuitonEnemyAttack(); // ���ق̏p�̍U�����X�V
	KatonEnemyAttack(); // �Γق̏p�̍U�����X�V
	InvincibleItemAperance(); // ���G�A�C�e���̏o������
	ClearCheck(); // �Q�[���N���A�̃`�F�b�N

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
		}
	}


}

void GameManager::EnemyCollisionCheck()
{
	if (playerInvincible_.GetIsInvincible())return;
	Math::Rectangle player_collision = playerModel_.GetCollision();
	for (int i = 0; i < moveEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = moveEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // �v���C���[���藠���ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
	for (int i = 0; i < silentEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = silentEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // �v���C���[���܂��т��ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
	for (int i = 0; i < suitonEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = suitonEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // �v���C���[�����ق̏p�̓G�ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
	for (int i = 0; i < katonEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = katonEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // �v���C���[���Γق̏p�̓G�ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
}
void GameManager::ItemCollisionCheck()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	Math::Rectangle item_collision = invincibleItemModel_.GetCollision();
	if (player_collision.Intersects(item_collision))
	{
		playerInvincible_.SetInvincible(timerModel_.GetTimer()); // �v���C���[�𖳓G��Ԃɂ���
		invincibleItemModel_.SetInactive(); // �A�C�e�����A�N�e�B�u�ɂ���
		
	}
}

void GameManager::SuitonEnemyAttack()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());

	for (int i = 0; i < suitonAttackCount_; i++)
	{
		if (!isAtttackedSuitonEnemy_[i] && timerModel_.GetTimer() >= suitonEnemyActivateTime_[i])
		{
			std::vector<int> availableIndices;
			for (int j = 0; j < suitonEnemyCount_; j++) {
				availableIndices.push_back(j);
			}

			// �V���b�t�����Đ擪����I��
			std::shuffle(availableIndices.begin(), availableIndices.end(), gen);

			int selectCount = std::min<int>(attackSuitonEnemyAmount_[i], availableIndices.size());
			for (int j = 0; j < selectCount; j++) {
				int enemyIndex = availableIndices[j];
				suitonEnemy_[enemyIndex].Activate(
					timerModel_.GetTimer(),
					suitonEnemyTimeToAttack_[i],
					suitonEnemyAttackDuration_[i],
					suitonEnemyAttackAfterTime_[i]
				);
			}
			isAtttackedSuitonEnemy_[i] = true;
		}
	}
}

void GameManager::KatonEnemyAttack()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());

	for (int i = 0; i < katonAttackCount_; i++)
	{
		if (!isAtttackedKatonEnemy_[i] && timerModel_.GetTimer() >= katonEnemyActivateTime_[i])
		{
			std::vector<int> availableIndices;
			for (int j = 0; j < katonEnemyCount_; j++) {
				availableIndices.push_back(j);
			}

			// �V���b�t�����Đ擪����I��
			std::shuffle(availableIndices.begin(), availableIndices.end(), gen);

			int selectCount = std::min<int>(attackKatonEnemyAmount_[i], availableIndices.size());
			for (int j = 0; j < selectCount; j++) {
				int enemyIndex = availableIndices[j];
				katonEnemy_[enemyIndex].Activate(
					timerModel_.GetTimer(),
					katonEnemyTimeToAttack_[i],
					katonEnemyAttackDuration_[i],
					katonEnemyAttackAfterTime_[i]
				);
			}
			isAtttackedKatonEnemy_[i] = true;
		}
	}
}

void GameManager::InvincibleItemAperance()
{
	if (timerModel_.GetTimer() >= 10.0f &&!isInvincibleItemAppered_) 
	{
		isInvincibleItemAppered_ = true; 
		invincibleItemModel_.SetActive(Math::Vector2 (340.0f,370.0f),timerModel_.GetTimer()); // 10�b�o�߂����疳�G�A�C�e�����o��������
	}
}

void GameManager::ClearCheck()
{
	if (timerModel_.GetTimer() >= timerModel_.GetTimeLimit())
	{
		gameState_ = 2; // �Q�[���N���A��Ԃɂ���
	}
}