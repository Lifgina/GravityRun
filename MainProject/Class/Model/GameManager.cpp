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

void GameManager::Initialize(float timelimit)
{
	playerModel_.Initialize(initialPlayerPosition_, leftEdge, rightEdge); 
	timerModel_.Initialize(timelimit);
	isGameOver_ = false; // �Q�[���I�[�o�[��Ԃ�������
}
void GameManager::FloorSetup(int floorID, HE::Math::Vector2 floorPos, float floorHeight, float floorWidth)
{ 
	floorModel_[floorID].Initialize(floorPos, floorWidth, floorHeight);
}

void GameManager::MoveEnemySetup(int enemyID, float timeToActive,float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange)
{
	moveEnemy_[enemyID].Load();
	moveEnemy_[enemyID].Initialize(timeToActive,enemySpeed, firstDirection,initialPos, maxRange, minRange);
}

void GameManager::SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos)
{
	silentEnemy_[enemyID].Load();
	silentEnemy_[enemyID].Initialize(initialPos);
}

void GameManager::Update()
{
	timerModel_.Update();
	playerModel_.Update(timerModel_.GetTimer());
	GroundCollisionCheck();
	EnemyCollisionCheck();
	for (int i = 0; i < std::size(moveEnemy_); i++)
	{
		moveEnemy_[i].Update(timerModel_.GetTimer());
	}

}

void GameManager::GroundCollisionCheck()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	for (int i = 0; i < std::size(floorModel_); i++)
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
	Math::Rectangle player_collision = playerModel_.GetCollision();
	for (int i = 0; i < std::size(moveEnemy_); i++)
	{
		Math::Rectangle enemy_collision = moveEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // �v���C���[���藠���ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
	for (int i = 0; i < std::size(silentEnemy_); i++)
	{
		Math::Rectangle enemy_collision = silentEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // �v���C���[���܂��т��ɏՓ˂����ꍇ�A�Q�[���I�[�o�[��Ԃɂ���
			return;
		}
	}
}