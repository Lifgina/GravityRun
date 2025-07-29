#pragma once

#include "../../HuEngine.h"

class PlayerView {
public:
	void Load();
	void Initialize(); // �v���C���[�̃X�v���C�g��\������
	void Update(HE::Math::Vector2 playerPos, bool isMovingRight, bool isGravityUp,bool isInvincible,float invincibleRemainingTime);
	void AnimStop() { playerSprite_.anim.drawRectAnim.frameRate = 0; ; } // �A�j���[�V�������~����
	void AnimStart() { playerSprite_.anim.drawRectAnim.frameRate = 15; } // �A�j���[�V�������J�n����


private:
	float playerWidth_ = 60.0f; // �v���C���[�̕�
	float playerHeight_ = 60.0f; // �v���C���[�̍���

	bool isBlack; // �v���C���[�̃X�v���C�g�������Ȃ邩�ǂ���
	float prevColorChangeTime ; // �O��̐F�ύX����
	float startBlinkTime_ = 2.0f; // �_�ŊJ�n����
	float blinkinterval_ = 0.2f; // �_�ŊԊu

	HE::Sprite playerSprite_; // �v���C���[�̃X�v���C�g
	HE::Sprite effectSprite_; // �v���C���[�̃G�t�F�N�g�X�v���C�g
};