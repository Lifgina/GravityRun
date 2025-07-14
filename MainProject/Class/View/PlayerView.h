#pragma once

#include "../../HuEngine.h"

class PlayerView {
public:
	void Load();
	void Initialize(); // プレイヤーのスプライトを表示する
	void Update(HE::Math::Vector2 playerPos, bool isMovingRight, bool isGravityUp);


private:
	float playerWidth_ = 60.0f; // プレイヤーの幅
	float playerHeight_ = 60.0f; // プレイヤーの高さ

	HE::Sprite playerSprite_; // プレイヤーのスプライト
};