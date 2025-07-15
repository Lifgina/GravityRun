#pragma once

#include "../../HuEngine.h"

class SilentEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 pos,float spriteDirection);


private:
	HE::Sprite silentEnemySprite_; // まきびしのスプライト
	float spriteHeight_ = 30.0f; // まきびしの高さ
	float spriteWidth_ = 80.0f; // まきびしの幅
};