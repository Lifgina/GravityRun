#pragma once

#include "../../HuEngine.h"

class PlayerInvincible {
public:
	void Initialize();
	void Update(float timer);
	void SetInvincible(float timer);
	bool GetIsInvincible() const { return isInvincible_; } // �v���C���[�����G��Ԃ��ǂ������擾

private:
	float invincibleDuration_ = 5.0f; // ���G��Ԃ̎�������

	bool isInvincible_; // �v���C���[�����G��Ԃ��ǂ���
	float invincibleStartTime_; // ���G��Ԃ��J�n��������
};