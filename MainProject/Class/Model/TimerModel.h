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
	HE::Sprite timerSprite_; // タイマー表示用のスプライト
	HE::Sprite timerBackgroundSprite_; // タイマー背景用のスプライト
};