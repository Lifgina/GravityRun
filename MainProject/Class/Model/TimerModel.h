#pragma once

#include "../../HuEngine.h"

class TimerModel {
public:
	void Load();
	void Initialize(float timeLimit);
	void Update();
	void UpdateTimerSprite();

private:
	float timer_;
	float timeLimit_;
	HE::Sprite timerSprite_; // �^�C�}�[�\���p�̃X�v���C�g
	HE::Sprite timerBackgroundSprite_; // �^�C�}�[�w�i�p�̃X�v���C�g
};