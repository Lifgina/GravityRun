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
	timerModel_.Initialize(timelimit);
	isGameOver_ = false; // ゲームオーバー状態を初期化
	onPlayerFloorID_ = -1; // プレイヤーが乗っている床のIDを初期化
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
	MonitorPlayerOnGround(); // プレイヤーが床に乗っているかどうかを監視

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
			onPlayerFloorID_ = i; // プレイヤーが乗っている床のIDを更新
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
			isGameOver_ = true; // プレイヤーが手裏剣に衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
	for (int i = 0; i < std::size(silentEnemy_); i++)
	{
		Math::Rectangle enemy_collision = silentEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // プレイヤーがまきびしに衝突した場合、ゲームオーバー状態にする
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
	prevIsOnGround_ = isOnGround; // 前回の床に乗っている状態を更新
}