#pragma once

#include "../../HuEngine.h"

class TimerModel {
public:
	void Initialize(float timeLimit);
	void Update();
	float GetTimer() const { return timer_; } // �^�C�}�[�̒l���擾

private:
	float timer_;
	float timeLimit_;
};