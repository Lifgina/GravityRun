#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize();
	void NotifiCateTime(float timer);
	void HideNotification();// �^�C�}�[�̒ʒm���\���ɂ���


private:
	HE::Sprite timerSprite_10; 
	HE::Sprite timerSprite_30; // �^�C�}�[�̃X�v���C�g
};