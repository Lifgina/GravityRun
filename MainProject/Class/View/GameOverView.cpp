//
// GameOverView.cpp
//

#include "GameOverView.h"

using namespace HE;

void GameOverView::Load()
{
    for (int i = 0; i < 2; i++) {
        gameOverFont_[i].params.style = Font::AddFontStyle("Fonts/meiryob004.ttf");
        RenderingPath->AddFont(&gameOverFont_[i], 1200);
    }
    draftSprite_ = HE::Sprite("");
    RenderingPath->AddSprite(&draftSprite_, 1000);
}

void GameOverView::Initialize()
{
    draftSprite_.params.siz = Math::Vector2(RenderingPath->GetLogicalWidth(), RenderingPath->GetLogicalHeight());
    draftSprite_.params.color = HE::Color(255, 255, 255, 125); // 半透明の黒色


        gameOverFont_[0].params.size = 128;
        gameOverFont_[0].params.posX = RenderingPath->GetLogicalWidth() / 2-320;
        gameOverFont_[0].params.posY = RenderingPath->GetLogicalHeight() / 2-200;
        gameOverFont_[1].params.size = 72;
        gameOverFont_[1].params.posX = RenderingPath->GetLogicalWidth() / 2-250;
        gameOverFont_[1].params.posY = RenderingPath->GetLogicalHeight() / 2 +64;
        
    
    HideGameOver(); // ゲームオーバー画面を非表示にする
}

void GameOverView::ShowGameOver(int gameState, float aliveTime)
{
    if (gameState == 0) {
        return; // ゲームオーバー状態でない場合は何もしない
    }
    else if (gameState == 1) {
        for (int i = 0; i < 2; i++) {
            gameOverFont_[i].params.color = Color(255, 0, 0, 255); // ゲームオーバーのフォント色を赤に変更
            gameOverFont_[i].SetHidden(false); // フォントを表示
        }
        gameOverFont_[0].SetText(L"Game Over");
		gameOverFont_[1].SetText(std::to_wstring(static_cast<int>(aliveTime)) + L"秒生き残りました。"); // 生存時間を表示
    }
    else if (gameState == 2) {
        for (int i = 0; i < 2; i++) {
            gameOverFont_[i].params.color = Color(0, 255, 0, 255); // ゲームクリアのフォント色を緑に変更
            gameOverFont_[i].SetHidden(false); // フォントを表示
        }
        gameOverFont_[0].SetText(L"Game Clear");
    }
    draftSprite_.SetHidden(false); // ゲームオーバー画面のスプライトを表示
}

void GameOverView::HideGameOver()
{
    for (int i = 0; i < 2; i++) {
        gameOverFont_[i].SetHidden(true); // フォントを非表示
    }
    draftSprite_.SetHidden(true); // ゲームオーバー画面のスプライトを非表示
}
