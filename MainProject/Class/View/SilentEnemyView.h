#pragma once

#include "../../HuEngine.h"

class SilentEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 pos,float spriteDirection);


private:
	HE::Sprite silentEnemySprite_; // �܂��т��̃X�v���C�g
	float spriteHeight_ = 30.0f; // �܂��т��̍���
	float spriteWidth_ = 80.0f; // �܂��т��̕�
};