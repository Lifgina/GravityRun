//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("");
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	playerSprite_.params.color = HE::Color(255, 255, 255, 255); // 白色のスプライト
	RenderingPath->AddSprite(&playerSprite_, 0); // スプライトをレンダリングパスに追加
}


void PlayerView::Update(Math::Vector2 playerPos)
{
	playerSprite_.params.pos = playerPos; // プレイヤーの位置を更新
}