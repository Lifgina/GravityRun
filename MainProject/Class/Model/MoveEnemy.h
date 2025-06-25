#pragma once

#include "../../HuEngine.h"

class MoveEnemy {
public:
	void Load();
	void Initialize(float enemySpeed,float firstDirection,HE::Math::Vector2 initialPos,float maxRange,float minRange);
	void Update();
	HE::Math::Rectangle GetCollision();



private:
	//以下いじってはいけない
	float enemySpeed_; // 移動速度 
	HE::Sprite draftSprite_;
	HE::Math::Vector2 enemyPosition_;
	float moveDirection_; // 1: 右, -1: 左 上下左右に移動する場合はスクリプト大幅変更
	float enemyHeight_ = 64.0f; // 敵の高さ
	float enemyWidth_ = 64.0f; // 敵の幅
	float maxRange_X_;
	float minRange_X_;
	
};