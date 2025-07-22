//
// InvincibleItemModel.cpp
//

#include "InvincibleItemModel.h"

using namespace HE;

void InvincibleItemModel::Initialize()
{
	isActive_ = false; // ������Ԃł͔�A�N�e�B�u
}

void InvincibleItemModel::Update(float timer)
{
	if (!isActive_) return; 
	if (timer >= itemActivateTime_ + itemActiveDuration_) {
		SetInactive(); // �A�N�e�B�u�Ȏ��Ԃ��o�߂������A�N�e�B�u�ɂ���
		return;
	}
}

void InvincibleItemModel::SetActive(HE::Math::Vector2 itemPos, float itemActivateTime)
{
	isActive_ = true; // �A�C�e�����A�N�e�B�u�ɂ���
	itemPosition_ = itemPos; // �A�C�e���̈ʒu��ݒ�
	itemActivateTime_ = itemActivateTime; // �A�C�e�����A�N�e�B�u�ɂȂ鎞�Ԃ�ݒ�
}

void InvincibleItemModel::SetInactive()
{
	isActive_ = false; // �A�C�e�����A�N�e�B�u�ɂ���
}

Math::Rectangle InvincibleItemModel::GetCollision()
{
	if (!isActive_) return Math::Rectangle(); // �A�C�e������A�N�e�B�u�ȏꍇ�͏Փ˔����Ԃ��Ȃ�

	Math::Rectangle collision;
	
	collision.x = (long)itemPosition_.x;
	collision.y = (long)itemPosition_.y;
	collision.width = (long)itemWidth_;
	collision.height = (long)itemHeight_;
	return collision;

}