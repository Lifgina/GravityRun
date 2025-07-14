#pragma once

#include "../../HuEngine.h"

class PlayerView {
public:
	void Load();
	void Initialize(); // �v���C���[�̃X�v���C�g��\������
	void Update(HE::Math::Vector2 playerPos, bool isMovingRight, bool isGravityUp);


private:
	float playerWidth_ = 60.0f; // �v���C���[�̕�
	float playerHeight_ = 60.0f; // �v���C���[�̍���

	HE::Sprite playerSprite_; // �v���C���[�̃X�v���C�g
};