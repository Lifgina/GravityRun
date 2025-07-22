//
// InvincibleItemModel.cpp
//

#include "InvincibleItemModel.h"

using namespace HE;

void InvincibleItemModel::Initialize()
{
	isActive_ = false; // 初期状態では非アクティブ
}

void InvincibleItemModel::Update(float timer)
{
	if (!isActive_) return; 
	if (timer >= itemActivateTime_ + itemActiveDuration_) {
		SetInactive(); // アクティブな時間が経過したら非アクティブにする
		return;
	}
}

void InvincibleItemModel::SetActive(HE::Math::Vector2 itemPos, float itemActivateTime)
{
	isActive_ = true; // アイテムをアクティブにする
	itemPosition_ = itemPos; // アイテムの位置を設定
	itemActivateTime_ = itemActivateTime; // アイテムがアクティブになる時間を設定
}

void InvincibleItemModel::SetInactive()
{
	isActive_ = false; // アイテムを非アクティブにする
}

Math::Rectangle InvincibleItemModel::GetCollision()
{
	if (!isActive_) return Math::Rectangle(); // アイテムが非アクティブな場合は衝突判定を返さない

	Math::Rectangle collision;
	
	collision.x = (long)itemPosition_.x;
	collision.y = (long)itemPosition_.y;
	collision.width = (long)itemWidth_;
	collision.height = (long)itemHeight_;
	return collision;

}