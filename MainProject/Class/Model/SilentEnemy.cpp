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

void SilentEnemy::Initialize(Math::Vector2 initialPos)
{
	enemyPosition_ = initialPos;
	draftSprite_.params.pos = enemyPosition_;
}

Math::Rectangle SilentEnemy::GetCollision()
{
	Math::Rectangle collision;
	collision.x = enemyPosition_.x;
	collision.y = enemyPosition_.y;
	collision.width = enemyWidth_;
	collision.height = enemyHeight_;

	return collision;
}