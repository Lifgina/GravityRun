//
// FloorModel.cpp
//

#include "FloorModel.h"

using namespace HE;

void FloorModel::Initialize(Math::Vector2 floorPosition, float floorWidth, float floorHeight)
{
	floorPosition_ = floorPosition;
	floorWidth_ = floorWidth;
	floorHeight_ = floorHeight;

	draftSprite_ = HE::Sprite("");
	draftSprite_.params.pos = floorPosition_;
	draftSprite_.params.siz = Math::Vector2(floorWidth_, floorHeight_);
	RenderingPath->AddSprite(&draftSprite_, 0);
}

Math::Rectangle FloorModel::GetCollision()
{
	Math::Rectangle collision;
	collision.x = (long)floorPosition_.x ;
	collision.y = (long)floorPosition_.y ;
	collision.width = (long)floorWidth_ ;
	collision.height = (long)floorHeight_;
	return collision;
}