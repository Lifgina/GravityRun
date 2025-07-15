#pragma once

#include "../../HuEngine.h"

class GameOverView {
public:
	void Load();
	void Initialize();
	void ShowGameOver(int gameState,float aliveTime);
	void HideGameOver();



private:
	HE::SpriteFont gameOverFont_[2]; // フォントスプライト
	HE::Sprite draftSprite_; // ゲームオーバー画面のスプライト
};