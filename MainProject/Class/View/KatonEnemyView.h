#pragma once

#include "../../HuEngine.h"

class KatonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos, HE::Math::Vector2 attackPos);
	void Update(bool isActive,int suitonEnemyState);


private:
	
	HE::Sprite katonEnemySprite_; // ���ق̏p�̓G�̃X�v���C�g
	HE::Sprite katonEnemyAttackSprite_; // ���ق̏p�̍U���̃X�v���C�g
};