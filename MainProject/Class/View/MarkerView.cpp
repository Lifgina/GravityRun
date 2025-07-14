//
// ClassTemplete.cpp
//

#include "MarkerView.h"

using namespace HE;

void MarkerView::Load()
{
	markerSprite_ = Sprite("syuriken.png");
	markerSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	));

	RenderingPath->AddSprite(&markerSprite_, 0); // レンダリングパスに追加
	markerSprite_.params.siz = Math::Vector2(50.0f, 50.0f); // マーカーのサイズを設定
	markerSprite_.params.pos = Math::Vector2(-1000.0f, 0.0f); // 初期位置を設定

}

void MarkerView::UpdateMarker(Math::Vector2 pos)
{
	markerSprite_.params.pos = pos; // マーカーの位置を更新
	
}

void MarkerView::MarkerDelete()
{
	markerSprite_.params.pos = Math::Vector2(-1000.0f, 0.0f); // マーカーの位置を初期化
}
