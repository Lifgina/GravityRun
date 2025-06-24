#pragma once

#include "../../HuEngine.h"

class GameOverView {
public:
	void Load();
	void Initialize();
	void ShowGameOver();
	void HideGameOver();



private:
	HE::SpriteFont draftFont_; // �t�H���g�X�v���C�g
	HE::Sprite draftSprite_; // �Q�[���I�[�o�[��ʂ̃X�v���C�g
};