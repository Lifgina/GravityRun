//
// FloorModel.cpp
//

#include "FloorModel.h"

using namespace HE;

void FloorModel::Initialize(Math::Vector2 floorPosition, float floorWidth, float floorHeight,bool isBreakable,float breakTime)
{
	floorPosition_ = floorPosition;
	floorWidth_ = floorWidth;
	floorHeight_ = floorHeight;
	isBreakable_ = isBreakable; 
	breakTime_ = breakTime; // 床が壊れるまでの時間を設定

	isBroken_ = false; // 初期状態では壊れていない

	draftSprite_ = HE::Sprite("");
	draftSprite_.params.pos = floorPosition_;
	draftSprite_.params.siz = Math::Vector2(floorWidth_, floorHeight_);

	if (isBreakable_) {
	    //壊れる床は黄色
		draftSprite_.params.color = HE::Color(255, 255, 0, 255); // 黄色のスプライト
	}

	RenderingPath->AddSprite(&draftSprite_, 0);


}

Math::Rectangle FloorModel::GetCollision()
{
	if (isBroken_) return Math::Rectangle(); // 床が壊れている場合は衝突判定を返さない

	Math::Rectangle collision;
	collision.x = (long)floorPosition_.x ;
	collision.y = (long)floorPosition_.y ;
	collision.width = (long)floorWidth_ ;
	collision.height = (long)floorHeight_;
	return collision;
}

void FloorModel::Update(float timer)
{
	if (!isBreakable_) return; // 壊れない床は更新しない 
	if (isBroken_) return; // 既に壊れている床は更新しない
	if (timer >= breakTime_) { // 指定時間が経過したら床を壊す
		BreakFloor();
	}
}

void FloorModel::BreakFloor()
{
	if (!isBroken_ ) {
		isBroken_ = true; // 床を壊れた状態にする
		draftSprite_.SetHidden(true); // スプライトを非表示にする
	}
	else {
		return; 
	}
}