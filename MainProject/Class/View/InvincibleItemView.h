#pragma once

#include "../../HuEngine.h"

class InvincibleItemView {
public:
	void Load();
	void Initialize();
	void Update(HE::Math::Vector2 itemPos,bool isActive); // �A�C�e���̕\��


private:
	HE::Sprite	invincibleItemSprite_; // ���G�A�C�e���̃X�v���C�g
};