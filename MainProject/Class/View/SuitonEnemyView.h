#pragma once

#include "../../HuEngine.h"

class SuitonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos, HE::Math::Vector2 attackPos,float attackDirection);
	void Update(bool isActive,int suitonEnemyState);


private:
	
	HE::Sprite suitonEnemySprite_; // 水遁の術の敵のスプライト
	HE::Sprite suitonEnemyAttackSprite_; // 水遁の術の攻撃のスプライト
};