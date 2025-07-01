#pragma once

#include "../../HuEngine.h"

class SuitonEnemy {
public:
	void Load();
	void Initialize(HE::Math::Vector2 enemyPos);
	void Update(float timer);
	void Activate(float timer,float timeToAttack,float attackDuration,float attackAfterTime); // 敵をアクティブにする
	HE::Math::Rectangle GetCollision();
	int GetSuitonEnemyState() const { return suitonEnemyState_; } // 敵の状態を取得
	bool GetIsActive() const { return isActive_; } // 敵がアクティブかどうかを取得


private:
	bool isActive_ ; // 敵がアクティブかどうか
	int suitonEnemyState_ ; // 敵の状態（0: 待機, 1: 攻撃中, 2: 攻撃後）
	HE::Math::Vector2 enemyPosition_; // 敵の位置
	float activateTime_; // 敵がアクティブになった時間
	float timeToAttack_ ; // 攻撃までの時間
	float attackDuration_ ; // 攻撃の持続時間
	float attackAfterTime_ ; // 攻撃後の待機時間

	float collisionHeight_ = 132.0f; // 敵の衝突判定の高さ
	float collisionWidth_ = 1280.0f; // 敵の衝突判定の幅
};