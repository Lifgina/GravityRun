//
// PlayerView.cpp
//

#include "PlayerView.h"

using namespace HE;

void PlayerView::Load()
{
	playerSprite_ = HE::Sprite("player.png");

	RenderingPath->AddSprite(&playerSprite_, 120); // スプライトをレンダリングパスに追加
	effectSprite_ = HE::Sprite("effect.png");
	RenderingPath->AddSprite(&effectSprite_, 130); // エフェクトスプライトをレンダリングパスに追加

}

void PlayerView::Initialize()
{
	playerSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f, 1000.0f
	));
	playerSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	effectSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 1000.0f, 1000.0f
	));
	effectSprite_.params.siz = Math::Vector2(playerWidth_, playerHeight_);
	prevColorChangeTime =INT_MAX;
	isBlack = true; // プレイヤーのスプライトが黒くなるかどうかの初期値
	// アニメーションの設定
	playerSprite_.anim = Sprite::Anim();
	playerSprite_.anim.repeatable = true;                       // ループするかしないか
	playerSprite_.anim.drawRectAnim.frameRate = 15;             // アニメーションの速度
	playerSprite_.anim.drawRectAnim.frameCount = 6;             // 画像にアニメーションが何コマあるか
	playerSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // 横に並んでいるコマ数

	effectSprite_.anim = Sprite::Anim();
	effectSprite_.anim.repeatable = true;                       // ループするかしないか
	effectSprite_.anim.drawRectAnim.frameRate = 15;             // アニメーションの速度
	effectSprite_.anim.drawRectAnim.frameCount = 30;             // 画像にアニメーションが何コマあるか
	effectSprite_.anim.drawRectAnim.horizontalFrameCount = 6;   // 横に並んでいるコマ数

	effectSprite_.SetHidden(true); // エフェクトスプライトを非表示にする
}
void PlayerView::Update(Math::Vector2 playerPos,bool isMovingRight,bool isGravityUp,bool isInvincible, float invincibleRemainingTime)
{
	playerSprite_.params.pos.x = playerPos.x; // プレイヤーの位置を更新
	effectSprite_.params.pos.x = playerPos.x; // エフェクトの位置を更新

	if (isGravityUp) {
        playerSprite_.params.scale.y = -1.0;
		effectSprite_.params.scale.y = -1.0; // エフェクトのスケールを更新
		playerSprite_.params.pos.y = playerPos.y+playerHeight_;
		effectSprite_.params.pos.y = playerPos.y + playerHeight_; // エフェクトの位置を更新
	}
	else
	{
		playerSprite_.params.scale.y = 1.0;
		effectSprite_.params.scale.y = 1.0; // エフェクトのスケールを更新
		playerSprite_.params.pos.y = playerPos.y ;
		effectSprite_.params.pos.y = playerPos.y; // エフェクトの位置を更新
	}

	if (isMovingRight) {
		playerSprite_.params.enableMirror();
	}
	else {
		playerSprite_.params.disableMirror();
	}



	if (isInvincible) {
		
		effectSprite_.SetHidden(false);
		if  (invincibleRemainingTime <= startBlinkTime_) {
			if (prevColorChangeTime - invincibleRemainingTime >=blinkinterval_ )
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
		effectSprite_.SetHidden(true); // 無敵状態でない場合、エフェクトを非表示にする
	}

	if (isBlack) {
		playerSprite_.params.drawRect.y = 0;
	}
	else
	{
		playerSprite_.params.drawRect.y = 1000;
	}

}