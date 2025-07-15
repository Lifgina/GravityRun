//
// FloorView.cpp
//

#include "FloorView.h"

using namespace HE;

void FloorView::Load(bool isBreakable)
{
	//壊れるかどうかで読み込む画像を変える
	if (isBreakable) {
		floorSprite_ = HE::Sprite("floor_break.png"); // 壊れる床のスプライト
	}
	else {
		floorSprite_ = HE::Sprite("floor.png"); // 壊れない床のスプライト
	}
	RenderingPath->AddSprite(&floorSprite_, 0); // スプライトをレンダリングパスに追加
}

void FloorView::Initialize(Math::Vector2 floorPos, float floorHeight, float floorWidth)
{
	floorSprite_.params.pos = floorPos; // 床の位置を設定
	floorSprite_.params.siz = Math::Vector2(floorWidth, floorHeight); // 床のサイズを設定
	floorSprite_.SetHidden(false); // 床を表示する
}
void FloorView::FloorBreak()
{
	floorSprite_.SetHidden(true); // 床を非表示にする
}
