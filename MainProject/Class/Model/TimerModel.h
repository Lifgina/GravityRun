#pragma once

#include "../../HuEngine.h"

class TimerModel {
public:
	void Initialize(float timeLimit);
	void Update();
	float GetTimer() const { return timer_; } // �^�C�}�[�̒l���擾
	float GetTimeLimit() const { return timeLimit_; } // �^�C�����~�b�g�̒l���擾
private:
	float timer_;
	float timeLimit_;
};