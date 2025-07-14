//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("player.png");
	playerSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f,1000.0f
	));
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	RenderingPath->AddSprite(&playerSprite_, 0); // スプライトをレンダリングパスに追加
}

void PlayerView::Initialize()
{
	// アニメーションの設定
	playerSprite_.anim = Sprite::Anim();
	playerSprite_.anim.repeatable = true;                       // ループするかしないか
	playerSprite_.anim.drawRectAnim.frameRate = 10;             // アニメーションの速度
	playerSprite_.anim.drawRectAnim.frameCount = 6;             // 画像にアニメーションが何コマあるか
	playerSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // 横に並んでいるコマ数
}
void PlayerView::Update(Math::Vector2 playerPos,bool isMovingRight,bool isGravityUp)
{
	playerSprite_.params.pos.x = playerPos.x; // プレイヤーの位置を更新
	if (isGravityUp) {
        playerSprite_.params.scale.y = -1.0;
		playerSprite_.params.pos.y = playerPos.y+playerHeight_;
	}
	else
	{
		playerSprite_.params.scale.y = 1.0;
		playerSprite_.params.pos.y = playerPos.y ;
	}

	if (isMovingRight) {
		playerSprite_.params.enableMirror();
	}
	else {
		playerSprite_.params.disableMirror();
	}



}