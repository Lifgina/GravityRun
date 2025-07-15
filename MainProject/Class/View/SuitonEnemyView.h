#pragma once

#include "../../HuEngine.h"

class SuitonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos, HE::Math::Vector2 attackPos,float attackDirection);
	void Update(bool isActive,int suitonEnemyState);


private:
	
	HE::Sprite suitonEnemySprite_; // ���ق̏p�̓G�̃X�v���C�g
	HE::Sprite suitonEnemyAttackSprite_; // ���ق̏p�̍U���̃X�v���C�g
};