#pragma once

#include "../../HuEngine.h"

class FusumaView {
public:
	void Load(int fusumaPattern,int fusumaColor);
	void Initialize(HE::Math::Vector2 fusumaPos);
	void Update(bool isOpened);


private:
	HE::Sprite fusumaSprite_; // ふすまのスプライト
	HE::Sprite fusumaBackgroundSprite_; // ふすまの背景スプライト
	float fusumaWidth_ = 256.0f; // ふすまの幅
	float fusumaHeight_ = 256.0f; // ふすまの高さ
	
};