//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("player.png");
	playerSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f, 900.0f
	));
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	RenderingPath->AddSprite(&playerSprite_, 0); // スプライトをレンダリングパスに追加
}

void PlayerView::Initialize()
{
	
}
void PlayerView::Update(Math::Vector2 playerPos)
{
	playerSprite_.params.pos = playerPos; // プレイヤーの位置を更新

}