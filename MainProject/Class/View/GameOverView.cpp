//
// GameOverView.cpp
//

#include "GameOverView.h"

using namespace HE;

void GameOverView::Load()
{
	genin_resultSprite_ = HE::Sprite("genin_result.png");
	tyunin_resultSprite_ = HE::Sprite("tyunin_result.png");
	jonin_resultSprite_ = HE::Sprite("jonin_result.png");
	sakanin_resultSprite_ = HE::Sprite("sakanin_result.png");
	gameOverTime_.params.style = Font::AddFontStyle("Fonts/meiryob004.ttf"); // ゲームオーバーのフォントスタイルを設定
	RenderingPath->AddSprite(&genin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&tyunin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&jonin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&sakanin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddFont(&gameOverTime_, 1000); // ゲームオーバーのフォントをレンダリングパスに追加

}

void GameOverView::Initialize()
{
	genin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	tyunin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	jonin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	sakanin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	gameOverTime_.params.size = 144; // ゲームオーバーのフォントのサイズを設定
	gameOverTime_.params.posX = 540.0f; // ゲームオーバーのフォントの位置を設定
	gameOverTime_.params.posY = 250.0f; // ゲームオーバーのフォントの位置を設定

    HideGameOver(); // ゲームオーバー画面を非表示にする
}

void GameOverView::ShowGameOver(int gameState, float aliveTime)
{
	int aliveTimeInt = static_cast<int>(aliveTime); // aliveTimeをintに変換
	switch (gameState)
	{
	case 0:
		break;
	case 1: // ゲームオーバー状態1
		
		if (aliveTime < 20.0f) {
			if (aliveTime < 10.0f) {
				gameOverTime_.params.posX = 580.0f;
			}
			genin_resultSprite_.SetHidden(false); // ゲームオーバー画面を表示
			gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
			gameOverTime_.SetHidden(false); // ゲームオーバーのフォントを表示
			break;
		}
		else if (aliveTime < 40.0f) {
			tyunin_resultSprite_.SetHidden(false); // ゲームオーバー画面を表示
			gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
			gameOverTime_.SetHidden(false); // ゲームオーバーのフォントを表示
			break;
		}
		else if (aliveTime < 60.0f) {
			jonin_resultSprite_.SetHidden(false); // ゲームオーバー画面を表示
			gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
			gameOverTime_.SetHidden(false); // ゲームオーバーのフォントを表示
			break;
		}
	
	case 2:
		sakanin_resultSprite_.SetHidden(false);
		gameOverTime_.SetText(std::to_wstring(aliveTimeInt));
		gameOverTime_.SetHidden(false); // ゲームオーバーのフォントを表示
		break;
	case 3:
		break;
	}

}

void GameOverView::HideGameOver()
{
	genin_resultSprite_.SetHidden(true); 
	tyunin_resultSprite_.SetHidden(true); 
	jonin_resultSprite_.SetHidden(true); 
	sakanin_resultSprite_.SetHidden(true); 
	gameOverTime_.SetHidden(true); // ゲームオーバーのフォントを非表示にする
}
