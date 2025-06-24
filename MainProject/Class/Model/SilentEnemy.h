#pragma once

#include "../../HuEngine.h"

class SilentEnemy {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initialPos);
	HE::Math::Rectangle GetCollision();


private:
	HE::Sprite draftSprite_; // �X�v���C�g
	HE::Math::Vector2 enemyPosition_; // �G�̈ʒu
	float enemyHeight_ = 10.0f; // �G�̍���
	float enemyWidth_ = 50.0f; // �G�̕�
};