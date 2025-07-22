#pragma once

#include "../../HuEngine.h"

class InvincibleItemModel {
public:
	void Initialize();
	void Update(float timer); // アイテムの更新処理
	HE::Math::Rectangle GetCollision();
	void SetActive(HE::Math::Vector2 itemPos,float itemActivateTime); // アイテムをアクティブにする
	void SetInactive(); // アイテムを非アクティブにする
	bool GetIsActive() const { return isActive_; } // アイテムがアクティブかどうかを取得
	HE::Math::Vector2 GetItemPosition() const { return itemPosition_; } // アイテムの位置を取得


private:
	bool isActive_ = false; // アイテムがアクティブかどうか
	HE::Math::Vector2 itemPosition_; // アイテムの位置
	float itemActivateTime_ ; // アイテムがアクティブになった時間
	float itemActiveDuration_ = 10.0f; // アイテムがアクティブな時間
	float itemWidth_ = 100.0f; // アイテムの幅
	float itemHeight_ = 155.0f; // アイテムの高さ
};