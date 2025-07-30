#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize();
	void NotifiCateTime(float timer);
	int GetCurrentFrame() { return timerSprite_10.anim.drawRectAnim._currentFrame; } // 現在のフレームを取得する
	void HideNotification();// タイマーの通知を非表示にする


private:
	HE::Sprite timerSprite_10; 
	HE::Sprite timerSprite_30; // タイマーのスプライト
};