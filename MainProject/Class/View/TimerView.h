#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize();
	void NotifiCateTime(float timer);
	void HideNotification() { timerSprite_.SetHidden(true); } // タイマーの通知を非表示にする


private:
	HE::SpriteFont timerSprite_; 
};