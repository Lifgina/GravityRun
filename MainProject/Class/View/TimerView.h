#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize();
	void NotifiCateTime(float timer);
	void HideNotification() { timerSprite_.SetHidden(true); } // �^�C�}�[�̒ʒm���\���ɂ���


private:
	HE::SpriteFont timerSprite_; 
};