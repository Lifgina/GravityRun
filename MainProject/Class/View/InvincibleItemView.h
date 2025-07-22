#pragma once

#include "../../HuEngine.h"

class InvincibleItemView {
public:
	void Load();
	void Initialize();
	void Update(HE::Math::Vector2 itemPos,bool isActive); // アイテムの表示


private:
	HE::Sprite	invincibleItemSprite_; // 無敵アイテムのスプライト
};