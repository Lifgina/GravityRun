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
	void Initialize(float timelimit);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void MoveEnemySetup(int enemyID, float enemySpeed, float firstDirection,HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void SilentEnemySetup(int enemyID, HE::Math::Vector2 initialPos);
	void Update();
	void CollisionCheck();
	bool GetIsGameOver() const { return isGameOver_; } // ゲームオーバー状態を取得


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorModel floorModel_[16]; // 床のモデル 全ステージの最大の数を配列数に記入
	TimerModel timerModel_; // タイマーのモデル
	MoveEnemy moveEnemy_[6]; // 手裏剣のモデル EnemyData.hで定義されている敵の数に合わせる
	SilentEnemy silentEnemy_[4]; // まきびしのモデル  EnemyData.hで定義されている敵の数に合わせる

	bool isGameOver_ ; // ゲームオーバー状態

	float leftEdge = 10.0f; // ゲームウィンドウの左端の位置
	float rightEdge = 1280.0f-10.0f-60.0f; // ゲームウィンドウの右端の位置

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(510.0f, 284.0f-50.0f); // 初期プレイヤー位置	
};