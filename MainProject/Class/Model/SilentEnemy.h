#pragma once

#include "../../HuEngine.h"

class SilentEnemy {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initialPos,float activateTime,float activateDuation);
	void Update(float timer);
	bool GetIsActive() const { return isActive_; } // 敵がアクティブかどうかを取得
	HE::Math::Rectangle GetCollision();


private:
	HE::Sprite draftSprite_; // スプライト
	HE::Math::Vector2 enemyPosition_; // 敵の位置
	float enemyHeight_ = 32.0f; // 敵の高さ
	float enemyWidth_ = 64.0f; // 敵の幅
	bool isActive_ ; // 敵がアクティブかどうか
	float activateDuration_ ; // 敵がアクティブな時間
	float activateTime_; // 敵がアクティブになる時間
};