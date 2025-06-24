#pragma once

#include "../../HuEngine.h"

class MoveEnemy {
public:
	void Load();
	void Initialize(float enemySpeed,HE::Math::Vector2 initialPos,float maxRange,float minRange);
	void Update();
	HE::Math::Rectangle GetCollision();



private:
	//�ȉ��������Ă͂����Ȃ�
	float enemySpeed_; // �ړ����x 
	HE::Sprite draftSprite_;
	HE::Math::Vector2 enemyPosition_;
	int moveDirection_ = 1; // 1: �E, -1: �� �㉺���E�Ɉړ�����ꍇ�̓X�N���v�g�啝�ύX
	float enemyHeight_ = 50.0f; // �G�̍���
	float enemyWidth_ = 50.0f; // �G�̕�
	float maxRange_X_;
	float minRange_X_;
	
};