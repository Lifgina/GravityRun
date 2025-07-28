#pragma once

#include "../../HuEngine.h"

class PlayerView {
public:
	void Load();
	void Initialize(); // プレイヤーのスプライトを表示する
	void Update(HE::Math::Vector2 playerPos, bool isMovingRight, bool isGravityUp,bool isInvincible,float invincibleRemainingTime);
	void AnimStop() { playerSprite_.anim.drawRectAnim.frameRate = 0; ; } // アニメーションを停止する


private:
	float playerWidth_ = 60.0f; // プレイヤーの幅
	float playerHeight_ = 60.0f; // プレイヤーの高さ

	bool isBlack; // プレイヤーのスプライトが黒くなるかどうか
	float prevColorChangeTime ; // 前回の色変更時間

	HE::Sprite playerSprite_; // プレイヤーのスプライト
};