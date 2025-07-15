#pragma once

#include "../../HuEngine.h"

class MoveEnemyView {
public:
	void Load();
	void Initialize(HE::Math::Vector2 initialPos,float apeearTime); // 初期化メソッド
	void Update(HE::Math::Vector2 enemyPos,float timer);
	void AnimStop() { moveEnemySprite_.anim.drawRectAnim.frameRate = 0; } // アニメーションを停止する


private:
	float enemyWidth_ = 32.0f; // 敵の幅
	float enemyHeight_ = 32.0f; // 敵の高さ
	HE::Sprite moveEnemySprite_; // 敵のスプライト
	float apeearTime_ ; // 敵が表示されるまでの時間
	float apeearBafa_ = 3.0f; // 敵が表示されるまでの時間補正
};