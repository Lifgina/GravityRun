#pragma once

#include "../../HuEngine.h"

class FusumaView {
public:
	void Load(int fusumaPattern,int fusumaColor);
	void Initialize(HE::Math::Vector2 fusumaPos);
	void Update(bool isOpened);


private:
	HE::Sprite fusumaSprite_; // �ӂ��܂̃X�v���C�g
	HE::Sprite fusumaBackgroundSprite_; // �ӂ��܂̔w�i�X�v���C�g
	float fusumaWidth_ = 256.0f; // �ӂ��܂̕�
	float fusumaHeight_ = 256.0f; // �ӂ��܂̍���
	
};