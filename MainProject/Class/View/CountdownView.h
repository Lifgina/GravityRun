#pragma once

#include "../../HuEngine.h"

class CountdownView {
public:
	void Load();
	void Initialize();
	void ShowCountDown();
	void ShowStart();
	void HideCountDown() { countdownSprite_.SetHidden(true); } // �J�E���g�_�E�����\���ɂ���
	int GetCurrentFrame() const { return countdownSprite_.anim.drawRectAnim._currentFrame; } // ���݂̃t���[�����擾


private:
	HE::Sprite countdownSprite_; // �J�E���g�_�E���p�̃X�v���C�g
};