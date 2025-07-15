#pragma once

#include "../../HuEngine.h"

class KatonEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 ninjaPos, HE::Math::Vector2 attackPos);
	void Update(bool isActive,int suitonEnemyState);


private:
	
	HE::Sprite katonEnemySprite_; // �Γق̏p�̓G�̃X�v���C�g
	HE::Sprite katonEnemyAttackSprite_; // �Γق̏p�̍U���̃X�v���C�g
};