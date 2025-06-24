//
// GameOverView.cpp
//

#include "GameOverView.h"

using namespace HE;

void GameOverView::Load()
{
	draftFont_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf");
	RenderingPath->AddFont(&draftFont_, 1200);

	draftSprite_ = HE::Sprite("");
	RenderingPath->AddSprite(&draftSprite_, 1000);
}

void GameOverView::Initialize()
{
	draftSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
	draftSprite_.params.color = HE::Color(255, 255, 255, 125); // 半透明の黒色
	draftFont_.params.size = 72;
	draftFont_.params.color = Color(0, 0, 0, 255); // 灰色のフォント
	draftFont_.SetText("Game Over");
	draftFont_.params.posX = RenderingPath->GetLogicalWidth() / 2,
	draftFont_.params.posY = RenderingPath->GetLogicalHeight() / 2;
	HideGameOver(); // ゲームオーバー画面を非表示にする
}

void GameOverView::ShowGameOver()
{
	draftFont_.SetHidden(false); // フォントを表示
	draftSprite_.SetHidden(false); // ゲームオーバー画面のスプライトを表示
}

void GameOverView::HideGameOver()
{
	draftFont_.SetHidden(true); // フォントを非表示
	draftSprite_.SetHidden(true); // ゲームオーバー画面のスプライトを非表示
}

