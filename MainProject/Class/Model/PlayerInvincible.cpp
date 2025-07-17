//
// PlayerInvincible.cpp
//

#include "PlayerInvincible.h"

using namespace HE;


void PlayerInvincible::Initialize()
{
	invincibleStartTime_ = 0.0f; // ���G��Ԃ��J�n�������Ԃ�������
	isInvincible_ = false; // �v���C���[�͏�����Ԃł͖��G�ł͂Ȃ�
}

void PlayerInvincible::Update(float timer)
{
	if (timer -invincibleStartTime_>= invincibleDuration_) {
		isInvincible_ = false;
	}
}

void PlayerInvincible::SetInvincible(float timer)
{
	isInvincible_ = true; // �v���C���[�𖳓G��Ԃɂ���
	invincibleStartTime_ = timer; // ���G��Ԃ��J�n�������Ԃ��L�^����
}