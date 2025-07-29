//
// SilentEnemy.cpp
//

#include "SilentEnemy.h"

using namespace HE;

void SilentEnemy::Load()
{
	//draftSprite_ = HE::Sprite("");
	//draftSprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_);
	//draftSprite_.params.color = HE::Color(255, 0, 0, 255); // 赤色のスプライト
	//RenderingPath->AddSprite(&draftSprite_, 0);
}

void SilentEnemy::Initialize(Math::Vector2 initialPos,float activateTime,float activateDuration)
{
	enemyPosition_ = initialPos;
	activateTime_ = activateTime; // 敵がアクティブになる時間を設定
	if (activateTime_ <= 0.0f) {
		isActive_ = true; // アクティブになる時間が0以下なら即座にアクティブにする
	}
	else {
		isActive_ = false; // それ以外は非アクティブにする
	}
	activateDuration_ = activateDuration; // 敵がアクティブな時間を設定
	draftSprite_.params.pos = enemyPosition_;
}

void SilentEnemy::Update(float timer)
{
	if (timer >= activateDuration_+activateTime_) {
		isActive_ = false; // アクティブな時間が経過したら敵を非アクティブにする
		return;
	}
	if (timer >= activateTime_) {
		isActive_ = true; // アクティブな時間が経過したら敵をアクティブにする
	}

}

Math::Rectangle SilentEnemy::GetCollision()
{
	if (!isActive_) return Math::Rectangle(); // 敵が非アクティブな場合は衝突判定を返さない

	Math::Rectangle collision;
	collision.x = enemyPosition_.x;
	collision.y = enemyPosition_.y;
	collision.width = enemyWidth_;
	collision.height = enemyHeight_;

	return collision;
}