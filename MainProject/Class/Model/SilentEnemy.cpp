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
	isActive_ = false; // 初期状態では非アクティブ
	activateTime_ = activateTime; // 敵がアクティブになる時間を設定
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