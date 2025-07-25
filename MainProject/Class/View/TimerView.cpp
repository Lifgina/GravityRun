//
// TimerView.cpp
//

#include "TimerView.h"

using namespace HE;

void TimerView::Load()
{
	timerSprite_10 = HE::Sprite("timer_10.png");
	timerSprite_30 = HE::Sprite("timer_30.png");
	RenderingPath->AddSprite(&timerSprite_10, 1000);
	RenderingPath->AddSprite(&timerSprite_30, 1000);
}

void TimerView::Initialize()
{
	timerSprite_10.params.siz = HE::Math::Vector2(512.0f, 512.0f); // スプライトのサイズを設定
	timerSprite_30.params.siz = HE::Math::Vector2(512.0f, 512.0f); // スプライトのサイズを設定
	timerSprite_10.params.pos = HE::Math::Vector2(640.0f-256.0f,360.0f-256.0f); // スプライトの位置を設定
	timerSprite_30.params.pos = HE::Math::Vector2(640.0f - 256.0f, 360.0f - 256.0f); // スプライトの位置を設定
	timerSprite_10.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	)); 
	timerSprite_30.params.enableDrawRect(Rectf(
		0.0f, 0.0f, 512.0f, 512.0f
	)); // スプライトの描画矩形を設定

	// アニメーションの設定
	timerSprite_10.anim = Sprite::Anim();
	timerSprite_10.anim.repeatable = false;                       // ループするかしないか
	timerSprite_10.anim.drawRectAnim.frameCount = 80;             // 画像にアニメーションが何コマあるか
	timerSprite_10.anim.drawRectAnim.horizontalFrameCount = 10;   // 横に並んでいるコマ数

	timerSprite_30.anim = Sprite::Anim();
	timerSprite_30.anim.repeatable = false;                       // ループするかしないか
	timerSprite_30.anim.drawRectAnim.frameCount = 80;             // 画像にアニメーションが何コマあるか
	timerSprite_30.anim.drawRectAnim.horizontalFrameCount = 10;   // 横に並んでいるコマ数

	HideNotification(); // 初期状態ではタイマーの通知を非表示にする


}

void TimerView::NotifiCateTime(float timer)
{
	if (timer == 30) {
		timerSprite_30.SetHidden(false); // 30秒のタイマーを表示
		timerSprite_30.anim.drawRectAnim.frameRate = 15; // アニメーションの速度を設定
	}
	else if (timer == 10) {
		timerSprite_10.SetHidden(false); // 10秒のタイマーを表示
		timerSprite_10.anim.drawRectAnim.frameRate = 15; // アニメーションの速度を設定

	}
}

void TimerView::HideNotification()
{
	timerSprite_10.SetHidden(true); // 10秒のタイマーを非表示
	timerSprite_30.SetHidden(true); // 30秒のタイマーを非表示
	timerSprite_10.anim.drawRectAnim.frameRate = 0; // アニメーションの速度をリセット
	timerSprite_30.anim.drawRectAnim.frameRate = 0; // アニメーションの速度をリセット
}