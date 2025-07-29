//
// CountdownView.cpp
//

#include "CountdownView.h"

using namespace HE;

void CountdownView::Load()
{
	countdownSprite_ = Sprite("CountDown.png");
	RenderingPath->AddSprite(&countdownSprite_, 2000); // レンダリングパスに追加
}

void CountdownView::Initialize()
{
	countdownSprite_.params.siz = Math::Vector2(250.0f, 100.0f); // カウントダウンのサイズを設定
	countdownSprite_.params.pos = Math::Vector2(640.0f-125.0f, 200.0f); // カウントダウンの初期位置を設定
	countdownSprite_.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 500.0f, 200.0f
	)); 
	// アニメーションの設定
	countdownSprite_.anim = Sprite::Anim();
	countdownSprite_.anim.repeatable = false;                       // ループするかしないか
	countdownSprite_.anim.drawRectAnim.frameRate = 10;             // アニメーションの速度
	countdownSprite_.anim.drawRectAnim.horizontalFrameCount = 5;   // 横に並んでいるコマ数
}

void CountdownView::ShowCountDown()
{
	countdownSprite_.SetHidden(false); // カウントダウンを表示
	countdownSprite_.params.drawRect.x = 0.0f; 
	countdownSprite_.params.drawRect.y = 0.0f; 
	countdownSprite_.anim.drawRectAnim._currentFrame = 0; // アニメーションのフレームをリセット
	countdownSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // アニメーションの経過時間をリセット
	countdownSprite_.anim.drawRectAnim.frameCount = 30;             // 画像にアニメーションが何コマあるか
}

void CountdownView::ShowStart()
{
	countdownSprite_.anim.drawRectAnim._currentFrame = 0; // アニメーションのフレームをリセット
	countdownSprite_.anim.drawRectAnim._elapsedTime = 0.0f; // アニメーションの経過時間をリセット
	countdownSprite_.params.drawRect.x = 0.0f; 
	countdownSprite_.params.drawRect.y = 1200.0f; 
	countdownSprite_.anim.drawRectAnim.frameCount = 10;             // 画像にアニメーションが何コマあるか
}