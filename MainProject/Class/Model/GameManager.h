#pragma once

#include <vector> 
#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"
#include "MoveEnemy.h"
#include "SilentEnemy.h"
#include "SuitonEnemy.h"


class GameManager {
public:
	void Load();
	void Initialize(float timelimit,int floorCount,int silentEnemyCount,int moveEnemyCount,int suitonEnemyCount,int suitonAttackCount);
	void PlayerSetup(HE::Math::Vector2 initialPos, float leftEdge, float rightEdge, bool isMovingToRightFirst, bool isGravityUpwardFirst, float playerWidth, float playerHeight);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth,bool isBreakable);
	void MoveEnemySetup(int enemyID,float timeToActive, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos);
	void SuitonEnemyPositionSetup(int enemyID, HE::Math::Vector2 initialPos,float collisionHeight,float collisionWidth);
	void SuitonEnemyAttackSetup(int atkNo, float activateTime, float timeToAttack, float attackDuration, float attackAfterTime,float attackEnemyAmount);

	const PlayerModel& GetPlayerModel() const { return playerModel_; }
	const TimerModel& GetTimerModel() const { return timerModel_; }
	const MoveEnemy& GetMoveEnemy(int enemyID) const { return moveEnemy_[enemyID]; }
	const SuitonEnemy& GetSuitonEnemy(int enemyID) const { return suitonEnemy_[enemyID]; }
	void Update();
	void SuitonEnemyAttack(); // 水遁の術の攻撃を更新
	void GravityChange() { playerModel_.GravityChange(); } // プレイヤーの移動方向を変更する
	void GroundCollisionCheck();
	void EnemyCollisionCheck(); 
	void MonitorPlayerOnGround();
	int GetGameState() const { return gameState_; } // ゲームの状態を取得

	


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorModel floorModel_[23]; // 床のモデル 全ステージの最大の数を配列数に記入
	TimerModel timerModel_; // タイマーのモデル
	MoveEnemy moveEnemy_[2]; // 手裏剣のモデル 全ステージの最大の数を配列数に記入
	SilentEnemy silentEnemy_[12]; // まきびしのモデル 全ステージの最大の数を配列数に記入
	SuitonEnemy suitonEnemy_[5]; // 水遁の術のモデル
	float suitonEnemyActivateTime_[5]; // 水遁の術がアクティブになる時間
	float suitonEnemyTimeToAttack_[5]; // 水遁の術の攻撃までの時間
	float suitonEnemyAttackDuration_[5]; // 水遁の術の攻撃の持続時間
	float suitonEnemyAttackAfterTime_[5]; // 水遁の術の攻撃後の待機時間
	int attackSuitonEnemyAmount_[5]; // 水遁の術の攻撃で出現する敵の数
	bool isAtttackedSuitonEnemy_[5]; // 水遁の術の攻撃が行われたかどうか
	

	int floorCount_ ; // 床の数
	int silentEnemyCount_; // まきびしの数
	int moveEnemyCount_; // 手裏剣の数
	int suitonEnemyCount_; // 水遁の術の敵の数
	int suitonAttackCount_; // 水遁の術の攻撃の回数

	int gameState_; // ゲームの状態、0 = ゲーム中　1 = ゲームオーバー 2 = ゲームクリア
	bool prevIsOnGround_ ; // 前回の床に乗っている状態

	int onPlayerFloorID_ ; // プレイヤーが乗っている床のID

	float leftEdge ; // ゲームウィンドウの左端の位置
	float rightEdge ; // ゲームウィンドウの右端の位置

	HE::Math::Vector2 initialPlayerPosition_ ; // 初期プレイヤー位置	
};