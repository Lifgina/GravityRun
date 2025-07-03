//
// TimerView.cpp
//

#include "TimerView.h"

using namespace HE;

void TimerView::Load()
{
	timerSprite_ = HE::Sprite(""); // タイマー表示用のスプライトを読み込み
	RenderingPath->AddSprite(&timerSprite_, 100); // スプライトをレンダリングパスに追加

	timerBackgroundSprite_ = HE::Sprite(""); // タイマー背景用のスプライトを読み込み
	RenderingPath->AddSprite(&timerBackgroundSprite_, 99); // スプライトをレンダリングパスに追加
}

void TimerView::Initialize(float timeLimit)
{
	timeLimit_ = timeLimit; // タイムリミットを設定
	timerSprite_.params.color = HE::Color(0, 0, 255, 255); // タイマーの色を設定
	timerSprite_.params.siz = Math::Vector2(60, 720); // スプライトのサイズを設定
	timerSprite_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 60, 0); // スプライトの位置を設定

	timerBackgroundSprite_.params.color = HE::Color(255, 255, 255, 255); // タイマー背景の色を設定
	timerBackgroundSprite_.params.siz = Math::Vector2(60, 720); // タイマー背景のサイズを設定
	timerBackgroundSprite_.params.pos = Math::Vector2(RenderingPath->GetLogicalWidth() - 60, 0); // タイマー背景の位置を設定
}

void TimerView::Update(float timer)
{
	timerSprite_.params.siz.y = 720.0f * (1 - timer/ timeLimit_); // タイマーの高さを更新
	timerSprite_.params.pos.y = 720.0f * (timer / timeLimit_); // タイマーの位置を更新
}