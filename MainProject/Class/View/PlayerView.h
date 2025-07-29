#pragma once

#include "../../HuEngine.h"

class PlayerView {
public:
	void Load();
	void Initialize(); // プレイヤーのスプライトを表示する
	void Update(HE::Math::Vector2 playerPos, bool isMovingRight, bool isGravityUp,bool isInvincible,float invincibleRemainingTime);
	void AnimStop() { playerSprite_.anim.drawRectAnim.frameRate = 0; ; } // アニメーションを停止する
	void AnimStart() { playerSprite_.anim.drawRectAnim.frameRate = 15; } // アニメーションを開始する


private:
	float playerWidth_ = 60.0f; // プレイヤーの幅
	float playerHeight_ = 60.0f; // プレイヤーの高さ

	bool isBlack; // プレイヤーのスプライトが黒くなるかどうか
	float prevColorChangeTime ; // 前回の色変更時間
	float startBlinkTime_ = 2.0f; // 点滅開始時間
	float blinkinterval_ = 0.2f; // 点滅間隔

	HE::Sprite playerSprite_; // プレイヤーのスプライト
	HE::Sprite effectSprite_; // プレイヤーのエフェクトスプライト
};