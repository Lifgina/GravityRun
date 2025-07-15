#pragma once

#include "../../HuEngine.h"

class SuitonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos,float attackDirection);
	void Update(bool isActive, int suitonEnemyState, HE::Math::Vector2 suitonAttackPos);


private:
	
	HE::Sprite suitonEnemySprite_; // 水遁の術の敵のスプライト
	HE::Sprite suitonEnemyAttackSprite_; // 水遁の術の攻撃のスプライト
};