#pragma once

#include "../../HuEngine.h"

class MoveEnemy {
public:
	void Load();
	void Initialize(float timeToActive, float enemySpeed, float firstDirection, HE::Math::Vector2 initialPos, float maxRange, float minRange);
	void Update(float timer);
	HE::Math::Rectangle GetCollision();



private:
	//以下いじってはいけない
	bool isActive_;
	float enemySpeed_; // 移動速度
	float timeToActive_; // アクティブになるまでの時間
	HE::Sprite draftSprite_;
	HE::Math::Vector2 initialPosition_; // スプライトの位置
	HE::Math::Vector2 enemyPosition_;
	float moveDirection_; // 1: 右, -1: 左 上下左右に移動する場合はスクリプト大幅変更
	float enemyHeight_ = 32.0f; // 敵の高さ
	float enemyWidth_ = 32.0f; // 敵の幅
	float maxRange_X_;
	float minRange_X_;
	
};