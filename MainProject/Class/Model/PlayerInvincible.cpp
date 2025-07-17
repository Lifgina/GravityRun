//
// PlayerInvincible.cpp
//

#include "PlayerInvincible.h"

using namespace HE;


void PlayerInvincible::Initialize()
{
	invincibleStartTime_ = 0.0f; // 無敵状態が開始した時間を初期化
	isInvincible_ = false; // プレイヤーは初期状態では無敵ではない
}

void PlayerInvincible::Update(float timer)
{
	if (timer -invincibleStartTime_>= invincibleDuration_) {
		isInvincible_ = false;
	}
}

void PlayerInvincible::SetInvincible(float timer)
{
	isInvincible_ = true; // プレイヤーを無敵状態にする
	invincibleStartTime_ = timer; // 無敵状態が開始した時間を記録する
}