#pragma once

#include "../../HuEngine.h"

class TimerView {
public:
	void Load();
	void Initialize();
	void NotifiCateTime(float timer);
	int GetCurrentFrame() { return timerSprite_10.anim.drawRectAnim._currentFrame; } // ���݂̃t���[�����擾����
	void HideNotification();// �^�C�}�[�̒ʒm���\���ɂ���


private:
	HE::Sprite timerSprite_10; 
	HE::Sprite timerSprite_30; // �^�C�}�[�̃X�v���C�g
};