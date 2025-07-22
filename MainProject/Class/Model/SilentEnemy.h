#pragma once

#include "../../HuEngine.h"

class SilentEnemy {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initialPos,float activateTime,float activateDuation);
	void Update(float timer);
	bool GetIsActive() const { return isActive_; } // �G���A�N�e�B�u���ǂ������擾
	HE::Math::Rectangle GetCollision();


private:
	HE::Sprite draftSprite_; // �X�v���C�g
	HE::Math::Vector2 enemyPosition_; // �G�̈ʒu
	float enemyHeight_ = 32.0f; // �G�̍���
	float enemyWidth_ = 64.0f; // �G�̕�
	bool isActive_ ; // �G���A�N�e�B�u���ǂ���
	float activateDuration_ ; // �G���A�N�e�B�u�Ȏ���
	float activateTime_; // �G���A�N�e�B�u�ɂȂ鎞��
};