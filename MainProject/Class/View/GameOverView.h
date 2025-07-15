#pragma once

#include "../../HuEngine.h"

class GameOverView {
public:
	void Load();
	void Initialize();
	void ShowGameOver(int gameState,float aliveTime);
	void HideGameOver();



private:
	HE::SpriteFont gameOverFont_[2]; // �t�H���g�X�v���C�g
	HE::Sprite draftSprite_; // �Q�[���I�[�o�[��ʂ̃X�v���C�g
};