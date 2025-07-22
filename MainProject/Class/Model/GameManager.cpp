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
	playerInvincible_.Initialize(); // プレイヤーの無敵状態を初期化
	floorCount_ = floorCount; // 床の数を設定
	silentEnemyCount_ = silentEnemyCount; // まきびしの数を設定
	moveEnemyCount_ = moveEnemyCount; // 手裏剣の数を設定
	suitonEnemyCount_ = suitonEnemyCount; // 水遁の術の敵の数を設定
	suitonAttackCount_ = suitonAttackCount; // 水遁の術の攻撃の回数を設定
	katonEnemyCount_ = katonEnemyCount; // 火遁の術の敵の数を設定
	katonAttackCount_ = katonAttackCount; // 火遁の術の攻撃の回数を設定
	gameState_ = 0; // ゲーム状態を初期化
	isInvincibleItemAppered_ = false; // 無敵アイテムが出現していない状態を初期化
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
	playerInvincible_.Update(timerModel_.GetTimer()); // プレイヤーの無敵状態を更新
	invincibleItemModel_.Update(timerModel_.GetTimer()); // 無敵アイテムの更新
	GroundCollisionCheck();
	EnemyCollisionCheck();
	ItemCollisionCheck(); // アイテムとの衝突チェック
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
	SuitonEnemyAttack(); // 水遁の術の攻撃を更新
	KatonEnemyAttack(); // 火遁の術の攻撃を更新
	InvincibleItemAperance(); // 無敵アイテムの出現処理
	ClearCheck(); // ゲームクリアのチェック

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
void GameManager::ItemCollisionCheck()
{
	Math::Rectangle player_collision = playerModel_.GetCollision();
	Math::Rectangle item_collision = invincibleItemModel_.GetCollision();
	if (player_collision.Intersects(item_collision))
	{
		playerInvincible_.SetInvincible(timerModel_.GetTimer()); // プレイヤーを無敵状態にする
		invincibleItemModel_.SetInactive(); // アイテムを非アクティブにする
		
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

void GameManager::InvincibleItemAperance()
{
	if (timerModel_.GetTimer() >= 10.0f &&!isInvincibleItemAppered_) 
	{
		isInvincibleItemAppered_ = true; 
		invincibleItemModel_.SetActive(Math::Vector2 (340.0f,370.0f),timerModel_.GetTimer()); // 10秒経過したら無敵アイテムを出現させる
	}
}

void GameManager::ClearCheck()
{
	if (timerModel_.GetTimer() >= timerModel_.GetTimeLimit())
	{
		gameState_ = 2; // ゲームクリア状態にする
	}
}