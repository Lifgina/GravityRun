#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize(float timeLimit_);
	void Update(float timer);


private:
	
	float timeLimit_ ; // �^�C�����~�b�g
	HE::Sprite timerSprite_; // �^�C�}�[�\���p�̃X�v���C�g
	HE::Sprite timerBackgroundSprite_; // �^�C�}�[�w�i�p�̃X�v���C�g

};