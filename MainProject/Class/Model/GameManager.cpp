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
	floorCount_ = floorCount; // 床の数を設定
	silentEnemyCount_ = silentEnemyCount; // まきびしの数を設定
	moveEnemyCount_ = moveEnemyCount; // 手裏剣の数を設定
	suitonEnemyCount_ = suitonEnemyCount; // 水遁の術の敵の数を設定
	suitonAttackCount_ = suitonAttackCount; // 水遁の術の攻撃の回数を設定
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

void GameManager::SuitonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos)
{
	suitonEnemy_[enemyID].Initialize(initialPos);
}
void GameManager::SuitonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime,float attackEnemyAmount)
{
	suitonEnemyActivateTime_[atkNo] = activateTime; // アクティブになる時間を設定
	suitonEnemyTimeToAttack_[atkNo] = timeToAttack; // 攻撃までの時間を設定
	suitonEnemyAttackDuration_[atkNo] = attackDuration; // 攻撃の持続時間を設定
	suitonEnemyAttackAfterTime_[atkNo] = attackAfterTime; // 攻撃後の待機時間を設定
	attackSuitonEnemyAmount_[atkNo] = attackEnemyAmount; // 攻撃で出現する敵の数を設定
	isAtttackedSuitonEnemy_[atkNo] = false; // 攻撃が行われたかどうかを初期化
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
	SuitonEnemyAttack(); // 水遁の術の攻撃を更新
	MonitorPlayerOnGround(); // プレイヤーが床に乗っているかどうかを監視

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
			onPlayerFloorID_ = i; // プレイヤーが乗っている床のIDを更新
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
			isGameOver_ = true; // プレイヤーが手裏剣に衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
	for (int i = 0; i < silentEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = silentEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // プレイヤーがまきびしに衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
	for (int i = 0; i < suitonEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = suitonEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			isGameOver_ = true; // プレイヤーが水遁の術の敵に衝突した場合、ゲームオーバー状態にする
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

void GameManager::SuitonEnemyAttack()
{
	for (int i = 0; i < suitonAttackCount_; i++)
	{
		if (!isAtttackedSuitonEnemy_[i] && timerModel_.GetTimer() >= suitonEnemyActivateTime_[i]) // アクティブになったら
		{
			std::vector<int> selectedIndices;
			std::vector<int> availableIndices;

			// 利用可能なインデックス（0～suitonEnemyの配列サイズ-1）を初期化
			for (int j = 0; j < std::size(suitonEnemy_); j++) {
				availableIndices.push_back(j);
			}

			// attackSuitonEnemyAmount_[i]個のランダムなインデックスを選択
			for (int j = 0; j < attackSuitonEnemyAmount_[i] && !availableIndices.empty(); j++) {
				int randomIndex = rand() % availableIndices.size();
				selectedIndices.push_back(availableIndices[randomIndex]);
				availableIndices.erase(availableIndices.begin() + randomIndex);
			}

			// 選択されたインデックスのSuitonEnemyをアクティブ化
			for (int enemyIndex : selectedIndices) {
				suitonEnemy_[enemyIndex].Activate(
					timerModel_.GetTimer(),
					suitonEnemyTimeToAttack_[i],
					suitonEnemyAttackDuration_[i],
					suitonEnemyAttackAfterTime_[i]
				);
			}
			isAtttackedSuitonEnemy_[i] = true; // 攻撃が行われたことを記録
		}
	}
	

}