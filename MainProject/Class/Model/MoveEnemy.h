#pragma once

#include "../../HuEngine.h"

class MoveEnemy {
public:
	void Load();
	void Initialize(float timeToActive, float enemySpeed, float firstDirection, HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void Update(float timer);
	HE::Math::Rectangle GetCollision();



private:
	//�ȉ��������Ă͂����Ȃ�
	bool isActive_;
	float enemySpeed_; // �ړ����x
	float timeToActive_; // �A�N�e�B�u�ɂȂ�܂ł̎���
	HE::Sprite draftSprite_;
	HE::Math::Vector2 initialPosition_; // �X�v���C�g�̈ʒu
	HE::Math::Vector2 enemyPosition_;
	float moveDirection_; // 1: �E, -1: �� �㉺���E�Ɉړ�����ꍇ�̓X�N���v�g�啝�ύX
	float enemyHeight_ = 32.0f; // �G�̍���
	float enemyWidth_ = 32.0f; // �G�̕�
	float maxRange_X_;
	float minRange_X_;
	
};