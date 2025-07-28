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
	RenderingPath->AddSprite(&playerSprite_, 120); // スプライトをレンダリングパスに追加
}

void PlayerView::Initialize()
{
	prevColorChangeTime =INT_MAX;
	isBlack = true; // プレイヤーのスプライトが黒くなるかどうかの初期値
	// アニメーションの設定
	playerSprite_.anim = Sprite::Anim();
	playerSprite_.anim.repeatable = true;                       // ループするかしないか
	playerSprite_.anim.drawRectAnim.frameRate = 15;             // アニメーションの速度
	playerSprite_.anim.drawRectAnim.frameCount = 6;             // 画像にアニメーションが何コマあるか
	playerSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // 横に並んでいるコマ数
}
void PlayerView::Update(Math::Vector2 playerPos,bool isMovingRight,bool isGravityUp,bool isInvincible, float invincibleRemainingTime)
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

	if (isInvincible) {
		
		
		if  (invincibleRemainingTime <= 2.0f) {
			if (prevColorChangeTime - invincibleRemainingTime >= 0.2f)
			{
				isBlack = !isBlack; // 無敵状態の残り時間が2秒以下の場合、黒く点滅する
				prevColorChangeTime = invincibleRemainingTime; 
			}
		}
		else
		{
			isBlack = false; 
		}
	
	}
	else {
		isBlack = true; 
		prevColorChangeTime = INT_MAX; 
	}

	if (isBlack) {
		playerSprite_.params.drawRect.y = 0;
	}
	else
	{
		playerSprite_.params.drawRect.y = 1000;
	}

}