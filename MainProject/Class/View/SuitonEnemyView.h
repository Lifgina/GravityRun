#pragma once

#include "../../HuEngine.h"

class SuitonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos,float attackDirection);
	void Update(bool isActive, int suitonEnemyState, HE::Math::Vector2 suitonAttackPos);


private:
	
	HE::Sprite suitonEnemySprite_; // ���ق̏p�̓G�̃X�v���C�g
	HE::Sprite suitonEnemyAttackSprite_; // ���ق̏p�̍U���̃X�v���C�g
};