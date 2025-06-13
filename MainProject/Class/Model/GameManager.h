#pragma once

#include "../../HuEngine.h"
#include "PlayerModel.h"
#include "FloarData.h"


class GameManager {
public:
	void Load();
	void Initialize();
	void Update();


private:
	PlayerModel playerModel_; // プレイヤーのモデル
	FloorData floorData_; // 床のデータを管理するクラス
	HE::Math::Vector2 initialPlayerPosition_ = HE::Math::Vector2(100.0f, 300.0f); // 初期プレイヤー位置	
};