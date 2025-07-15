//
// KatonEnemy.cpp
//

#include "KatonEnemy.h"

using namespace HE;

void KatonEnemy::Load()
{

}

void KatonEnemy::Initialize(HE::Math::Vector2 enemyPos, float collisionHeight, float collisonWidth)
{
	enemyPosition_ = enemyPos; // �G�̏����ʒu��ݒ�
	collisionHeight_ = collisionHeight; // �G�̏Փ˔���̍�����ݒ�
	collisionWidth_ = collisonWidth; // �G�̏Փ˔���̕���ݒ�
	isActive_ = false; // �G�͏�����Ԃł͔�A�N�e�B�u
	katonEnemyState_ = 0; // �G�̏�Ԃ�ҋ@�ɐݒ�
}

void KatonEnemy::Update(float timer)
{
	if (!isActive_) return;

	// �G���A�N�e�B�u�ȏꍇ�̏���
	switch (katonEnemyState_)
	{
	case 0: // �ҋ@���
		if (timer - activateTime_ >= timeToAttack_) {
			katonEnemyState_ = 1; // �U����ԂɈڍs
		}
		break;
	case 1: // �U�����
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_) {
			katonEnemyState_ = 2; // �U�����ԂɈڍs
		}
		break;
	case 2: // �U������
		if (timer - activateTime_ >= timeToAttack_ + attackDuration_ + attackAfterTime_) {
			isActive_ = false; // �G���A�N�e�B�u�ɂ���
			katonEnemyState_ = 0; // ��Ԃ�ҋ@�ɖ߂�
		}
		break;

	}


}

void KatonEnemy::Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime)
{
	if (!isActive_) {
		isActive_ = true; // �G���A�N�e�B�u�ɂ���
		activateTime_ = timer; // �A�N�e�B�u�ɂȂ������Ԃ��L�^
		timeToAttack_ = timeToAttack; // �U���܂ł̎��Ԃ�ݒ�
		attackDuration_ = attackDuration; // �U���̎������Ԃ�ݒ�
		attackAfterTime_ = attackAfterTime; // �U����̑ҋ@���Ԃ�ݒ�
	}
}

Math::Rectangle KatonEnemy::GetCollision()
{
	if (isActive_&&katonEnemyState_==1) {
		Math::Rectangle collision;
		collision.x = enemyPosition_.x;
		collision.y = enemyPosition_.y;
		collision.width = collisionWidth_;
		collision.height = collisionHeight_;
		return collision; // �G���A�N�e�B�u�ōU����Ԃ̏ꍇ�A�Փ˔����Ԃ�
	}
}