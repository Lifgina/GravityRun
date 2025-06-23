#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloorModel.h"
#include "FloarData.h"


class GameManager {
public:
	void Load();
	void Initialize();
	void Update();


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorData floorData_; // 床のデータを管理するクラス
	FloorModel floorModel_[11]; // 床のモデル floorModelの数は必要に応じて変更

	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // 初期プレイヤー位置	
};