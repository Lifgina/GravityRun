#pragma once

#include "../../HuEngine.h"

class PlayerInvincible {
public:
	void Initialize();
	void Update(float timer);
	void SetInvincible(float timer);
	bool GetIsInvincible() const { return isInvincible_; } // プレイヤーが無敵状態かどうかを取得

private:
	float invincibleDuration_ = 5.0f; // 無敵状態の持続時間

	bool isInvincible_; // プレイヤーが無敵状態かどうか
	float invincibleStartTime_; // 無敵状態が開始した時間
};