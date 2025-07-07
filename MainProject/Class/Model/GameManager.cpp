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

void GameManager::Initialize(float timelimit,int floorCount,int floorLinkCount, int silentEnemyCount, int moveEnemyCount, int suitonEnemyCount, int suitonAttackCount,int katonEnemyCount, int katonAttackCount)
{
	timerModel_.Initialize(timelimit);
	floorCount_ = floorCount; // 床の数を設定
	floorLinkCount_ = floorLinkCount; // 床のリンク数を設定
	silentEnemyCount_ = silentEnemyCount; // まきびしの数を設定
	moveEnemyCount_ = moveEnemyCount; // 手裏剣の数を設定
	suitonEnemyCount_ = suitonEnemyCount; // 水遁の術の敵の数を設定
	suitonAttackCount_ = suitonAttackCount; // 水遁の術の攻撃の回数を設定
	katonEnemyCount_ = katonEnemyCount; // 火遁の術の敵の数を設定
	katonAttackCount_ = katonAttackCount; // 火遁の術の攻撃の回数を設定
	gameState_ = 0; // ゲーム状態を初期化
	onPlayerFloorID_ = -1; // プレイヤーが乗っている床のIDを初期化
	lastOnPlayerFloorID_ = -1; // プレイヤーが最後に乗っていた床のIDを初期化
}

void GameManager::PlayerSetup(HE::Math::Vector2 initialPos, float leftEdge, float rightEdge, bool isMovingToRightFirst, bool isGravityUpwardFirst, float playerWidth, float playerHeight)
{
	playerModel_.Initialize(initialPos, leftEdge, rightEdge, isMovingToRightFirst, isGravityUpwardFirst, playerWidth, playerHeight);
}
void GameManager::FloorSetup(int floorID, HE::Math::Vector2 floorPos, float floorHeight, float floorWidth,bool isBreakable)
{ 
	
	floorModel_[floorID].Initialize(floorPos, floorWidth, floorHeight,isBreakable);
}

void GameManager::FloorLinkSetup(int linkID, HE::Math::Vector2 linkedFloorID)
{
	linkedFloorIDs_[linkID] = linkedFloorID; // 床のリンクを設定

	printf("[Link] %d: (%d, %d)\n", linkID, (int)linkedFloorIDs_[linkID].x, (int)linkedFloorIDs_[linkID].y);
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

void GameManager::SuitonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos, float collisionHeight, float collisionWidth)
{
	suitonEnemy_[enemyID].Initialize(initialPos,collisionHeight,collisionWidth);
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

void GameManager::KatonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos, float collisionHeight, float collisionWidth)
{
	katonEnemy_[enemyID].Initialize(initialPos, collisionHeight, collisionWidth);
}

void GameManager::KatonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime, float attackEnemyAmount)
{
	katonEnemyActivateTime_[atkNo] = activateTime; // アクティブになる時間を設定
	katonEnemyTimeToAttack_[atkNo] = timeToAttack; // 攻撃までの時間を設定
	katonEnemyAttackDuration_[atkNo] = attackDuration; // 攻撃の持続時間を設定
	katonEnemyAttackAfterTime_[atkNo] = attackAfterTime; // 攻撃後の待機時間を設定
	attackKatonEnemyAmount_[atkNo] = attackEnemyAmount; // 攻撃で出現する敵の数を設定
	isAtttackedKatonEnemy_[atkNo] = false; // 攻撃が行われたかどうかを初期化
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
	for (int i = 0; i < katonEnemyCount_; i++)
	{
		katonEnemy_[i].Update(timerModel_.GetTimer());
	}
	SuitonEnemyAttack(); // 水遁の術の攻撃を更新
	KatonEnemyAttack(); // 火遁の術の攻撃を更新
	MonitorPlayerOnGround(); // プレイヤーが床に乗っているかどうかを監視

}

void GameManager::GroundCollisionCheck()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	currentOnFloors_.clear();
	for (int i = 0; i < floorCount_; i++)
	{
		Math::Rectangle floor_collision = floorModel_[i].GetCollision();
		if (player_collision.Intersects(floor_collision))
		{
			playerModel_.OnCollisionGround(floorModel_[i].GetFloorPosition(), floorModel_[i].GetFloorHeight(), floorModel_[i].GetFloorWidth());
			currentOnFloors_.insert(i);
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
			gameState_ = 1; // プレイヤーが手裏剣に衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
	for (int i = 0; i < silentEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = silentEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // プレイヤーがまきびしに衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
	for (int i = 0; i < suitonEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = suitonEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // プレイヤーが水遁の術の敵に衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
	for (int i = 0; i < katonEnemyCount_; i++)
	{
		Math::Rectangle enemy_collision = katonEnemy_[i].GetCollision();
		if (player_collision.Intersects(enemy_collision))
		{
			gameState_ = 1; // プレイヤーが火遁の術の敵に衝突した場合、ゲームオーバー状態にする
			return;
		}
	}
}

void GameManager::MonitorPlayerOnGround()
{
	for (int floorID : prevOnFloors_) {
		if (currentOnFloors_.count(floorID) == 0) {
			// 離れた床を壊す
			printf("[BreakFloor] main: %d\n", floorID);
			floorModel_[floorID].BreakFloor();
			// リンク先も壊す
			for (int i = 0; i < floorLinkCount_; i++) {
				int idA = (int)linkedFloorIDs_[i].x;
				int idB = (int)linkedFloorIDs_[i].y;
				if (idA == floorID) {
					printf("[BreakFloor] linked: %d\n", idB);
					floorModel_[idB].BreakFloor();
				}
				else if (idB == floorID) {
					printf("[BreakFloor] linked: %d\n", idA);
					floorModel_[idA].BreakFloor();
				}
			}
		}
	}
	prevOnFloors_ = currentOnFloors_;
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

			// シャッフルして先頭から選ぶ
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

			// シャッフルして先頭から選ぶ
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