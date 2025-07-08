//
// FloorModel.cpp
//

#include "FloorModel.h"

using namespace HE;

void FloorModel::Initialize(Math::Vector2 floorPosition, float floorWidth, float floorHeight,bool isBreakable)
{
	floorPosition_ = floorPosition;
	floorWidth_ = floorWidth;
	floorHeight_ = floorHeight;
	isBreakable_ = isBreakable; 

	isBroken_ = false; // 初期状態では壊れていない
	touchCount_ = 0; // タッチ数を初期化
	draftSprite_ = HE::Sprite("");
	draftSprite_.params.pos = floorPosition_;
	draftSprite_.params.siz = Math::Vector2(floorWidth_, floorHeight_);

	if (isBreakable_) {
	    //壊れる床は黄色
		draftSprite_.params.color = HE::Color(255, 255, 0, 255); // 黄色のスプライト
		floorHPDebug_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf"); // フォントスタイルを追加
		floorHPDebug_.params.size = 24; // フォントサイズを設定
		floorHPDebug_.params.color = HE::Color(255, 0, 0, 255); // フォントの色を設定
		floorHPDebug_.params.posX = floorPosition_.x ; // 床の中央に配置
		floorHPDebug_.params.posY = floorPosition_.y ; // 床の中央に配置
		RenderingPath->AddFont(&floorHPDebug_, 1000); // フォントをレンダリングパスに追加
		floorHPDebug_.SetText(std::to_wstring(touchCountToBreak_));
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

void FloorModel::BreakFloor()
{
	touchCount_++;
	floorHPDebug_.SetText(std::to_wstring(touchCountToBreak_ - touchCount_)); // 残りのタッチ数を表示
	if (touchCount_ < touchCountToBreak_) {
		return; // 壊れるまでのタッチ数に達していない場合は何もしない
	}
	if (isBreakable_ ) {
		isBroken_ = true; // 床を壊れた状態にする
		draftSprite_.SetHidden(true); // スプライトを非表示にする
	}
	else {
		return; // すでに壊れている場合は何もしない
	}
}