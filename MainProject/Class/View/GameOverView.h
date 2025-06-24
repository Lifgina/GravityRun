#pragma once

#include "../../HuEngine.h"

class GameOverView {
public:
	void Load();
	void Initialize();
	void ShowGameOver();
	void HideGameOver();



private:
	HE::SpriteFont draftFont_; // フォントスプライト
	HE::Sprite draftSprite_; // ゲームオーバー画面のスプライト
};