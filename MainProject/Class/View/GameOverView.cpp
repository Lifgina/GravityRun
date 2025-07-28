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
	RenderingPath->AddSprite(&genin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&tyunin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&jonin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加
	RenderingPath->AddSprite(&sakanin_resultSprite_, 1000); // ゲームオーバー画面のスプライトをレンダリングパスに追加

}

void GameOverView::Initialize()
{
	genin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	tyunin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	jonin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定
	sakanin_resultSprite_.params.siz = HE::Math::Vector2(1280.0f, 720.0f); // ゲームオーバー画面のサイズを設定

    HideGameOver(); // ゲームオーバー画面を非表示にする
}

void GameOverView::ShowGameOver(int gameState, float aliveTime)
{
	switch (gameState)
	{
	case 0:
		break;
	case 1: // ゲームオーバー状態1
		if (aliveTime < 20.0f) {
			genin_resultSprite_.SetHidden(false); // ゲームオーバー画面を表示
			break;
		}
		else if (aliveTime < 40.0f) {
			tyunin_resultSprite_.SetHidden(false); // ゲームオーバー画面を表示
			break;
		}
		else if (aliveTime < 60.0f) {
			jonin_resultSprite_.SetHidden(false); // ゲームオーバー画面を表示
			break;
		}
	
	case 2:
		sakanin_resultSprite_.SetHidden(false);
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
}
