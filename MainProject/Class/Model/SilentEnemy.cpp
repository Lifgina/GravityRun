//
// SilentEnemy.cpp
//

#include "SilentEnemy.h"

using namespace HE;

void SilentEnemy::Load()
{
	//draftSprite_ = HE::Sprite("");
	//draftSprite_.params.siz = Math::Vector2(enemyWidth_, enemyHeight_);
	//draftSprite_.params.color = HE::Color(255, 0, 0, 255); // �ԐF�̃X�v���C�g
	//RenderingPath->AddSprite(&draftSprite_, 0);
}

void SilentEnemy::Initialize(Math::Vector2 initialPos,float activateTime,float activateDuration)
{
	enemyPosition_ = initialPos;
	activateTime_ = activateTime; // �G���A�N�e�B�u�ɂȂ鎞�Ԃ�ݒ�
	if (activateTime_ <= 0.0f) {
		isActive_ = true; // �A�N�e�B�u�ɂȂ鎞�Ԃ�0�ȉ��Ȃ瑦���ɃA�N�e�B�u�ɂ���
	}
	else {
		isActive_ = false; // ����ȊO�͔�A�N�e�B�u�ɂ���
	}
	activateDuration_ = activateDuration; // �G���A�N�e�B�u�Ȏ��Ԃ�ݒ�
	draftSprite_.params.pos = enemyPosition_;
}

void SilentEnemy::Update(float timer)
{
	if (timer >= activateDuration_+activateTime_) {
		isActive_ = false; // �A�N�e�B�u�Ȏ��Ԃ��o�߂�����G���A�N�e�B�u�ɂ���
		return;
	}
	if (timer >= activateTime_) {
		isActive_ = true; // �A�N�e�B�u�Ȏ��Ԃ��o�߂�����G���A�N�e�B�u�ɂ���
	}

}

Math::Rectangle SilentEnemy::GetCollision()
{
	if (!isActive_) return Math::Rectangle(); // �G����A�N�e�B�u�ȏꍇ�͏Փ˔����Ԃ��Ȃ�

	Math::Rectangle collision;
	collision.x = enemyPosition_.x;
	collision.y = enemyPosition_.y;
	collision.width = enemyWidth_;
	collision.height = enemyHeight_;

	return collision;
}