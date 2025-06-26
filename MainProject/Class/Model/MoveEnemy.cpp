//
// MoveEnemy.cpp
//

#include "MoveEnemy.h"

using namespace HE;

void MoveEnemy::Load()
{
	draftSprite_ = HE::Sprite("");
	draftSprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_);
	draftSprite_.params.color = HE::Color(0, 255, 0, 255); //�ΐF�̃X�v���C�g
	RenderingPath->AddSprite(&draftSprite_, 0);
}

void MoveEnemy::Initialize(float timeToActive, float enemySpeed, float firstDirection, Math::Vector2 initialPos, float maxRange, float minRange)
{
	isActive_ = false;
	timeToActive_ = timeToActive;
	moveDirection_ = firstDirection; // 1: �E, -1: ��
	enemySpeed_ = enemySpeed;
	initialPosition_ = initialPos;
	maxRange_X_ = maxRange;
	minRange_X_ = minRange;
	enemyPosition_ = Math::Vector2(-1000.0f,-1000.0f);
}

void MoveEnemy::Update(float timer)
{
	draftSprite_.params.pos = enemyPosition_;
	if (!isActive_) {
		if (timer >= timeToActive_) {
			isActive_ = true; // �w�莞�Ԃ��o�߂�����A�N�e�B�u�ɂ���
			enemyPosition_ = initialPosition_; // �����ʒu�ɐݒ�
		}
		else {
			return; // �A�N�e�B�u�ɂȂ�܂ŉ������Ȃ�
		}
	}
	

	if (moveDirection_ == 1) { // �E�Ɉړ�
		enemyPosition_.x += enemySpeed_ * Time.deltaTime;
		if (enemyPosition_.x >= maxRange_X_) {
			moveDirection_ = -1; // �ړ��͈͂̉E�[�ɓ��B�����獶�Ɉړ�
		}
	}
	else { // ���Ɉړ�
		enemyPosition_.x -= enemySpeed_ * Time.deltaTime;
		if (enemyPosition_.x <= minRange_X_) {
			moveDirection_ = 1; // �ړ��͈͂̍��[�ɓ��B������E�Ɉړ�
		}
	}
}

Math::Rectangle MoveEnemy::GetCollision()
{
	Math::Rectangle collision;
	collision.x = enemyPosition_.x;
	collision.y = enemyPosition_.y;
	collision.width = enemyWidth_;
	collision.height = enemyHeight_;
	return collision;
}