#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize(float timeLimit_);
	void Update(float timer);


private:
	
	float timeLimit_ ; // タイムリミット
	HE::Sprite timerSprite_; // タイマー表示用のスプライト
	HE::Sprite timerBackgroundSprite_; // タイマー背景用のスプライト

};