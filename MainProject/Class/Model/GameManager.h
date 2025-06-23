#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "FloarData.h"
#include "TimerModel.h"


class GameManager {
public:
	void Load();
	void Initialize();
	void Update();


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorData floorData_; // 床のデータを管理するクラス
	FloorModel floorModel_[11]; // 床のモデル floorModelの数は必要に応じて変更
	TimerModel timerModel_; // タイマーのモデル

	float timeLimit_ = 60.0f; // タイムリミットの設定
	float leftEdge = 10.0f; // ゲームウィンドウの左端の位置
	float rightEdge = 1280.0f-10.0f-60.0f; // ゲームウィンドウの右端の位置

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // 初期プレイヤー位置	
};