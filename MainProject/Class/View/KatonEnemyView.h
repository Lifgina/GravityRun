#pragma once

#include "../../HuEngine.h"

class KatonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos, HE::Math::Vector2 attackPos);
	void Update(bool isActive,int suitonEnemyState);


private:
	
	HE::Sprite katonEnemySprite_; // 火遁の術の敵のスプライト
	HE::Sprite katonEnemyAttackSprite_; // 火遁の術の攻撃のスプライト
};