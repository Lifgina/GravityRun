#pragma once

#include "../../HuEngine.h"

class TutorialView {
public:
	void Load();
	void Initialize();
	void Update(bool isActive);


private:
	HE::Sprite tutorialSprite_; // �`���[�g���A���̃X�v���C�g
};