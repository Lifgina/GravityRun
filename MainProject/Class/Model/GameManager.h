#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "TimerModel.h"


class GameManager {
public:
	void Load();
	void Initialize(float timelimit);
	void FloorSetup(int floorID,HE::Math::Vector2 floorPos,float floorHeight,float floorWidth);
	void Update();


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorModel floorModel_[16]; // 床のモデル 
	TimerModel timerModel_; // タイマーのモデル

	float leftEdge = 10.0f; // ゲームウィンドウの左端の位置
	float rightEdge = 1280.0f-10.0f-60.0f; // ゲームウィンドウの右端の位置

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // 初期プレイヤー位置	
};