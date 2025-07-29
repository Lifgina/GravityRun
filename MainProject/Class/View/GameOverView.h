#pragma once

#include "../../HuEngine.h"

class GameOverView {
public:
	void Load();
	void Initialize();
	void ShowGameOver(int gameState,float aliveTime);
	void HideGameOver();



private:
	
	HE::Sprite genin_resultSprite_;
	HE::Sprite tyunin_resultSprite_;
	HE::Sprite jonin_resultSprite_;
	HE::Sprite sakanin_resultSprite_; 

	HE::SpriteFont gameOverTime_; // ゲームオーバーのフォント


};