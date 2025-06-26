#pragma once

#include <vector> 
#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"
#include "MoveEnemy.h"
#include "SilentEnemy.h"


class GameManager {
public:
	void Load();
	void Initialize(float timelimit,HE::Math::Vector2 initialPos,float leftEdge,float rightEdge);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth,bool isBreakable);
	void MoveEnemySetup(int enemyID,float timeToActive, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos);
	void Update();
	void GravityChange() { playerModel_.GravityChange(); } // プレイヤーの移動方向を変更する
	void GroundCollisionCheck();
	void EnemyCollisionCheck(); 
	void MonitorPlayerOnGround();
	bool GetIsGameOver() const { return isGameOver_; } // ゲームオーバー状態を取得


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorModel floorModel_[23]; // 床のモデル 全ステージの最大の数を配列数に記入
	TimerModel timerModel_; // タイマーのモデル
	MoveEnemy moveEnemy_[6]; // 手裏剣のモデル 全ステージの最大の数を配列数に記入
	SilentEnemy silentEnemy_[4]; // まきびしのモデル 全ステージの最大の数を配列数に記入

	bool isGameOver_ ; // ゲームオーバー状態
	bool prevIsOnGround_ ; // 前回の床に乗っている状態

	int onPlayerFloorID_ ; // プレイヤーが乗っている床のID

	float leftEdge ; // ゲームウィンドウの左端の位置
	float rightEdge ; // ゲームウィンドウの右端の位置

	HE::Math::Vector2 initialPlayerPosition_ ; // 初期プレイヤー位置	
};