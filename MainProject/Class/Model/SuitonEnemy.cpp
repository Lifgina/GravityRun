//
// SuitonEnemy.cpp
//

#include "SuitonEnemy.h"

using namespace HE;

void SuitonEnemy::Load()
{

}

void SuitonEnemy::Initialize(float enemyPosY, float collisionHeight, float collisionWidth,float attackDirection)
{
	attackDirection_ = attackDirection; // �U���̕�����ݒ�i1: �E, -1: ���j
	if (attackDirection_ == 1) {
		enemyPosition_.x = -collisionWidth;
	}
	else if (attackDirection == -1) {
		enemyPosition_.x = RenderingPath->GetLogicalWidth();
	}
	enemyPosition_.y = enemyPosY; // �G�̏����ʒu��ݒ�
	collisionHeight_ = collisionHeight; // �G�̏Փ˔���̍�����ݒ�
	collisionWidth_ = collisionWidth; // �G�̏Փ˔���̕���ݒ�
	isActive_ = false; // �G�͏�����Ԃł͔�A�N�e�B�u
	suitonEnemyState_ = 0; // �G�̏�Ԃ�ҋ@�ɐݒ�
}

void SuitonEnemy::Update(float timer)
{
	if (!isActive_) return;

	// �G���A�N�e�B�u�ȏꍇ�̏���
	switch (suitonEnemyState_)
	{
	case 0: // �ҋ@���
		if (timer - activateTime_ >= timeToAttack_) {
			suitonEnemyState_ = 1; // �U����ԂɈڍs
		}
		break;
	case 1: // �U�����
		enemyPosition_.x += ((RenderingPath->GetLogicalWidth() + collisionWidth_) / attackDuration_) * attackDirection_ * Time.deltaTime;
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_) {	
			suitonEnemyState_ = 2; // �U�����ԂɈڍs
		}
		break;
	case 2: // �U������
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_ + attackAfterTime_) {
			isActive_ = false; // �G���A�N�e�B�u�ɂ���
			suitonEnemyState_ = 0; // ��Ԃ�ҋ@�ɖ߂�
		}
		break;

	}


}

void SuitonEnemy::Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime)
{
	if (!isActive_) {
		isActive_ = true; // �G���A�N�e�B�u�ɂ���
		activateTime_ = timer; // �A�N�e�B�u�ɂȂ������Ԃ��L�^
		timeToAttack_ = timeToAttack; // �U���܂ł̎��Ԃ�ݒ�
		attackDuration_ = attackDuration; // �U���̎������Ԃ�ݒ�
		attackAfterTime_ = attackAfterTime; // �U����̑ҋ@���Ԃ�ݒ�
	}
}

Math::Rectangle SuitonEnemy::GetCollision()
{
	if (isActive_&&suitonEnemyState_==1) {
		Math::Rectangle collision;
		collision.x = enemyPosition_.x;
		collision.y = enemyPosition_.y;
		collision.width = collisionWidth_;
		collision.height = collisionHeight_;
		return collision; // �G���A�N�e�B�u�ōU����Ԃ̏ꍇ�A�Փ˔����Ԃ�
	}
}