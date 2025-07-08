#pragma once

#include "../../HuEngine.h"

class TimerModel {
public:
	void Initialize(float timeLimit);
	void Update();
	float GetTimer() const { return timer_; } // タイマーの値を取得
	float GetTimeLimit() const { return timeLimit_; } // タイムリミットの値を取得
private:
	float timer_;
	float timeLimit_;
};