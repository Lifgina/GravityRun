#pragma once

#include "../../HuEngine.h"

class PlayerInvincible {
public:
	void Initialize();
	void Update(float timer);
	void SetInvincible(float timer);
	bool GetIsInvincible() const { return isInvincible_; } // プレイヤーが無敵状態かどうかを取得
	float GetInvincibleRemainingTime(float timer) const {
		if (isInvincible_) {
			return invincibleDuration_ - (timer - invincibleStartTime_);
		}
		return 0.0f; // 無敵状態でない場合は0を返す
	}

private:
	float invincibleDuration_ = 7.0f; // 無敵状態の持続時間

	bool isInvincible_; // プレイヤーが無敵状態かどうか
	float invincibleStartTime_; // 無敵状態が開始した時間
};