#pragma once

#include "../../HuEngine.h"

class PlayerView {
public:
	void Load();
	void Initialize(); // �v���C���[�̃X�v���C�g��\������
	void Update(HE::Math::Vector2 playerPos, bool isMovingRight, bool isGravityUp,bool isInvincible,float invincibleRemainingTime);
	void AnimStop() { playerSprite_.anim.drawRectAnim.frameRate = 0; ; } // �A�j���[�V�������~����


private:
	float playerWidth_ = 60.0f; // �v���C���[�̕�
	float playerHeight_ = 60.0f; // �v���C���[�̍���

	bool isBlack; // �v���C���[�̃X�v���C�g�������Ȃ邩�ǂ���
	float prevColorChangeTime ; // �O��̐F�ύX����

	HE::Sprite playerSprite_; // �v���C���[�̃X�v���C�g
};