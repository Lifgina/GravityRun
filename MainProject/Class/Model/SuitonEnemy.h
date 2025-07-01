#pragma once

#include "../../HuEngine.h"

class SuitonEnemy {
public:
	void Load();
	void Initialize(HE::Math::Vector2 enemyPos);
	void Update(float timer);
	void Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime); // �G���A�N�e�B�u�ɂ���
	HE::Math::Rectangle GetCollision();
	int GetSuitonEnemyState() const { return suitonEnemyState_; } // �G�̏�Ԃ��擾
	bool GetIsActive() const { return isActive_; } // �G���A�N�e�B�u���ǂ������擾


private:
	bool isActive_ ; // �G���A�N�e�B�u���ǂ���
	int suitonEnemyState_ ; // �G�̏�ԁi0: �ҋ@, 1: �U����, 2: �U����j
	HE::Math::Vector2 enemyPosition_; // �G�̈ʒu
	float activateTime_; // �G���A�N�e�B�u�ɂȂ�������
	float timeToAttack_ ; // �U���܂ł̎���
	float attackDuration_ ; // �U���̎�������
	float attackAfterTime_ ; // �U����̑ҋ@����

	float collisionHeight_ = 132.0f; // �G�̏Փ˔���̍���
	float collisionWidth_ = 1280.0f; // �G�̏Փ˔���̕�
};