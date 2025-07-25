#pragma once

#include "../../HuEngine.h"

class TitleBG {
public:
	void Load();
	void Initialize();



private:
	HE::Sprite backgroundSprite_; // �w�i�̃X�v���C�g
	HE::Sprite ruleButtonSprite_; // ���[���{�^���̃X�v���C�g
	HE::Sprite startButtonSprite_; // �X�^�[�g�{�^���̃X�v���C�g
	HE::Sprite exitButtonSprite_; // �I���{�^���̃X�v���C�g
};