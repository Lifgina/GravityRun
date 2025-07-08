//
// TimerView.cpp
//

#include "TimerView.h"

using namespace HE;

void TimerView::Load()
{
	timerSprite_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf"); // フォントスタイルを追加
	RenderingPath->AddFont(&timerSprite_, 1200); // フォントをレンダリングパスに追加
}

void TimerView::Initialize()
{
	timerSprite_.params.color = HE::Color(0, 0, 0, 200); // タイマーの色を設定
	timerSprite_.params.size = 128; // タイマーのフォントサイズを設定
	timerSprite_.params.posX = 300; // タイマーの表示位置X
	timerSprite_.params.posY = 300; // タイマーの表示位置Y


}

void TimerView::NotifiCateTime(float timer)
{
	timerSprite_.SetHidden(false); // タイマーの通知を表示する
	//「残り○秒」と表示
	timerSprite_.SetText( L"残り" + std::to_wstring(static_cast<int>(timer)) + L"秒！！");
}