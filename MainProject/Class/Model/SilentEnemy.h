#pragma once

#include "../../HuEngine.h"

class SilentEnemy {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initialPos);
	HE::Math::Rectangle GetCollision();


private:
	HE::Sprite draftSprite_; // スプライト
	HE::Math::Vector2 enemyPosition_; // 敵の位置
	float enemyHeight_ = 32.0f; // 敵の高さ
	float enemyWidth_ = 64.0f; // 敵の幅
};